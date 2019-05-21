#include "line_logic/line_impl.h"

#include "common/factory/field_factory.h"
#include "common/log.h"

namespace line {

using common::factory::FieldFactory;

void Line::parse(const std::vector<std::string>& dataitem_con) {
    const std::vector<DataType>& datatype_con = container_->get_datatype_con();
    int32_t index = 0;
    for (const auto& e : dataitem_con) {
        FieldBasePtr ptr =
            FieldFactory::instance()->get_new_field(datatype_con[index]);
        if (ptr) {
            ptr->parse(e);
            field_con_.emplace_back(ptr);
        }
        ++index;
    }
}

}  // namespace line