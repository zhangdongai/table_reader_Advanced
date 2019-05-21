#ifndef LINE_LOGIC_LINE_IMPL_H
#define LINE_LOGIC_LINE_IMPL_H

#include "line_logic/line_base.h"
#include "common/container/container_base.h"
#include "field/field_impl.h"

namespace line {

using field::Field;
using FieldBasePtr = std::shared_ptr<field::FieldBase>;
using common::container::ContainerBase;

class Line : public LineBase {
public:
    Line(ContainerBase* container)
    : container_(container) {}
    /**
    * @brief Read raw string in line, parse every field fro this string,
    *        for each field, a related Field object is created to store data.
    */
    void parse(const std::vector<std::string>&) override;

    template <typename T>
    const std::shared_ptr<Field<T>> operator [] (const std::string& title_name) {
        return get<T>(title_name);
    }

    /**
    * @brief Get Field pointer via title name
    */
    template <typename T>
    const std::shared_ptr<Field<T>> get(const std::string& title_name) {
        const int32_t field_index = container_->get_field_index(title_name);
        if (field_index < 0 || field_index >= field_con_.size()) {
            return nullptr;
        }
        return std::static_pointer_cast<Field<T>>(
            field_con_[field_index]);
    }

private:
    std::vector<FieldBasePtr> field_con_;
    common::container::ContainerBase* container_;
};

}  // namespace line

#endif // LINE_LOGIC_LINE_IMPL_H