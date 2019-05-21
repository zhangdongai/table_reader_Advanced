#include "common/factory/field_factory.h"

#include "custom/custom_array.h"
#include "custom/custom_data.h"
#include "field/field_impl.h"

namespace common {
namespace factory {

FieldFactory::FieldFactory() {}

void FieldFactory::register_all() {
    REGISTER_FIELD(TYPE_INT, field::IntField);
    REGISTER_FIELD(TYPE_FLOAT, field::FloatField);
    REGISTER_FIELD(TYPE_STRING, field::StringField);
    REGISTER_FIELD(TYPE_INTARRAY, field::CustomField<custom::Array<int32_t>>);
    REGISTER_FIELD(TYPE_FLOATARRAY, field::CustomField<custom::Array<float>>);
    REGISTER_FIELD(TYPE_CUSTOME, field::CustomField<custom::CustomData>);
}

void FieldFactory::register_field(const DataType& data_type, FieldCreator creator) {
    field_con_[data_type] = creator;
}

FieldBasePtr FieldFactory::get_new_field(const DataType& data_type) {
    if (field_con_.find(data_type) != field_con_.end()) {
        return field_con_[data_type]();
    }
    return nullptr;
}

} // namespace factory
} // namespace common