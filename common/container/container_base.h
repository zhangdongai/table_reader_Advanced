#ifndef COMMON_CONTAINER_CONTAINER_BASE_FILE_H
#define COMMON_CONTAINER_CONTAINER_BASE_FILE_H

#include <memory>
#include <string>
#include <vector>

#include "common/data_type/data_type.h"

namespace common {
namespace container {

class ContainerBase {
public:
    /**
    * @brief Interface. Load data type fields
    * @param con data type read from table in raw string
    */
    virtual void load_datatype(const std::string& datatype_cont) = 0;
    
    /**
    * @brief Interface. Load title fields
    * @param title_cont title read from table in raw string
    */
    virtual void load_title(const std::string& title_cont) = 0;

    /**
    * @brief Interface. Load each line from memory
    * @param con Each line content in raw string
    */
    virtual void load_line(const std::string& line_cont) = 0;

    /**
    * @brief Interface. Get data type vector
    */
    virtual const std::vector<DataType>& get_datatype_con() const = 0;
    
    /**
    * @brief Interface. Get index of a given title
    * @param title_name. title name
    * @return int32_t. Index of a given title
    */
    virtual int32_t get_field_index(const std::string& title_name) = 0;
};

}  // namespace container
}  // namespace common

#endif // COMMON_CONTAINER_CONTAINER_BASE_FILE_H