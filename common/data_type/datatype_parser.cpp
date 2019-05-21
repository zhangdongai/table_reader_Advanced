#include "common/data_type/datatype_parser.h"

#include <unordered_map>

#include "common/log.h"

static const std::unordered_map<std::string, DataType> datatype_match = {
    {"INT", DataType::TYPE_INT},
    {"FLOAT", DataType::TYPE_FLOAT},
    {"STRING", DataType::TYPE_STRING},
    {"INTARRAY", DataType::TYPE_INTARRAY},
    {"FLOATARRAY", DataType::TYPE_FLOATARRAY},
    {"CUSTOM", DataType::TYPE_CUSTOME}
};

DataTypeParser::DataTypeParser() {}

void DataTypeParser::parse_datatype(
    const std::vector<std::string>& type_str_con,
    std::vector<DataType>* const type_con) {
    if (!type_con) {
        return;
    }
    
    for (const auto& type_str : type_str_con) {
        if (datatype_match.find(type_str) != datatype_match.end()) {
            type_con->push_back(datatype_match.at(type_str));
        }
        else {
            ASSERT_LOG(false, "cannot parse datatype, check the spelling!");
        }
    }
}