#ifndef COMMON_CONTAINER_CONTAINER_IMPL_FILE_H
#define COMMON_CONTAINER_CONTAINER_IMPL_FILE_H

#include <unordered_map>
#include <string>

#include "common/container/container_base.h"
#include "common/utils.h"
#include "line_logic/line_impl.h"

namespace common {
namespace container {

using line::Line;
class ContainerImpl : public ContainerBase {
public:
    ContainerImpl() = default;
    virtual ~ContainerImpl() {};

    /**
    * @brief Interface. Load data type fields
    * @param con data type read from table in raw string
    */
    void load_datatype(const std::string& datatype_cont) override;

    /**
    * @brief Interface. Load title fields
    * @param title_cont title read from table in raw string
    */
    void load_title(const std::string& title_cont) override;

    /**
    * @brief Interface. Load each line from memory
    * @param con Each line content in raw string
    */
    void load_line(const std::string& line) override;

    /**
    * @brief Get Line object by id
    * @param id. id related to Line object, which is the first column in table
    * @return Object point if success, or nullptr
    */
    std::shared_ptr<line::Line> get_line_by_id(const int32_t id) const;

    /**
    * @brief Get Line object by index
    * @param id. Line index, begins 0
    * @return Object point if success, or nullptr
    */
    std::shared_ptr<Line> get_line_by_index(const int32_t index) const;

    /**
    * @brief Interface. Get data type vector
    */
    const std::vector<DataType>& get_datatype_con() const override{
        return datatype_con_;
    }

    /**
    * @brief Interface. Get index of a given title
    * @param title_name. title name
    * @return int32_t. Index of a given title
    */
    int32_t get_field_index(const std::string& title_name) override;

protected:
    std::vector<std::shared_ptr<Line>> content_con_raw_;
    std::unordered_map<int32_t, std::shared_ptr<Line>> content_con_indexed_;
    std::vector<DataType> datatype_con_;
    std::vector<std::string> dataitem_con_;
    std::unordered_map<std::string, int32_t, utils::EnumHashTemp> datatitle_con_;

private:
    std::shared_ptr<line::Line> create_line();
};

}  // namespace common
}  // namespace container


#define TABLE_GET_DECL(TABLE_NAME)                              \
std::shared_ptr<line::Line> Get##TABLE_NAME##ById(int id);      \
std::shared_ptr<line::Line> Get##TABLE_NAME##ByIndex(int index);

#define TABLE_GET_IMPL(TABLE_NAME)                                                              \
std::shared_ptr<line::Line> Get##TABLE_NAME##ById(int id) {                                     \
    const ContainerPtr container = ContainerFactory::instance()->get_container_ptr(#TABLE_NAME);\
    if (container) {                                                                            \
        return container->get_line_by_id(id);                                                   \
    }                                                                                           \
    return nullptr;                                                                             \
}                                                                                               \
std::shared_ptr<line::Line> Get##TABLE_NAME##ByIndex(int index) {                               \
    const ContainerPtr container = ContainerFactory::instance()->get_container_ptr(#TABLE_NAME);\
    if (container) {                                                                            \
        return container->get_line_by_index(index);                                             \
    }                                                                                           \
    return nullptr;                                                                             \
}

#endif // COMMON_CONTAINER_CONTAINER_IMPL_FILE_H