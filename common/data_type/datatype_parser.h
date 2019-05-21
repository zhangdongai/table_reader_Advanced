/**
* @brief 转换规则为：
*        "INT"-->TYPE_INT
*        "FLOAT"-->TYPE_FLOAT
*        "STRING"-->TYPE_STRING
*        "INTARRAY"-->TYPE_INTARRAY
*        "CUSTOM"-->TYPE_CUSTOM
*/

#ifndef COMMON_DATATYPE_DATA_PARSER_FILE_H
#define COMMON_DATATYPE_DATA_PARSER_FILE_H

#include "common/base.h"

#include <string>
#include <vector>

#include "common/data_type/data_type.h"

class DataTypeParser {
public:
    /**
    * @brief transform data type in string to enum DataType（data_type.h）
    * @param type_str_con. The splited string stored in vector
    * @param type_con. Transfromed DataType objects
    */
    void parse_datatype(
        const std::vector<std::string>& type_str_con,
        std::vector<DataType>* const type_con);

    SINGLETION_DECLARE(DataTypeParser);
};

#endif // COMMON_DATATYPE_DATA_PARSER_FILE_H