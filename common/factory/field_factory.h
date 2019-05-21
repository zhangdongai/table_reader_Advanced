#ifndef COMMON_FACTORY_PARSER_FACTORY_FILE_H
#define COMMON_FACTORY_PARSER_FACTORY_FILE_H

#include <unordered_map>

#include "common/base.h"
#include "common/data_type/data_type.h"
#include "common/utils.h"
#include "field/field_base.h"

namespace common {
namespace factory {

using FieldBasePtr = std::shared_ptr<field::FieldBase>;
using FieldCreator = std::function<FieldBasePtr (void)>;

class FieldFactory {
public:
    /**
    * @brief Register all Fields Type
    *        The newly added Field Type must be registered.
    */
    void register_all();

    /**
    * @brief Get Field pointer via DataType
    * @param data_type. Datatype object whichi is used to find a Field pointer 
    * @return. FieldBasePtr if found, or nullotr
    */
    FieldBasePtr get_new_field(const DataType& data_type);

private:
    void register_field(const DataType& data_type, FieldCreator creator);
    
    std::unordered_map<DataType, FieldCreator, utils::EnumHashDataType> field_con_;

    SINGLETION_DECLARE(FieldFactory);
};

#define REGISTER_FIELD(DATATYPE, CLASS)       \
    FieldFactory::instance()->register_field( \
        DATATYPE, []() -> FieldBasePtr {      \
            return FieldBasePtr(new CLASS);   \
    });

} // namespace factory
} // namespace common

#endif // COMMON_FACTORY_PARSER_FACTORY_FILE_H