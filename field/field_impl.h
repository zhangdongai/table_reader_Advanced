#ifndef FIELD_FIELD_FILE_H
#define FIELD_FIELD_FILE_H

#include "common/log.h"
#include "field/field_base.h"

namespace field {

template <typename T>
class Field : public FieldBase {
public:
    virtual ~Field() {}
    virtual void parse(const std::string& obj_content) = 0;
    virtual const T& get_data() const {return _data;}

protected:
    T _data;
};

class IntField : public Field<int32_t> {
public:
    void parse(const std::string& obj_content) override {
        TRY_ENTRY
        this->_data = std::stoi(obj_content.data());
        CATCH_EXIT
    }
};

class FloatField : public Field<float> {
public:
    void parse(const std::string& obj_content) override {
        TRY_ENTRY
        this->_data = std::stof(obj_content.data());
        CATCH_EXIT
    }
};

class StringField : public Field<std::string> {
public:
    void parse(const std::string& obj_content) override {
        this->_data = obj_content;
    }
};

template <typename T>
class CustomField : public Field<T> {
public:
    void parse(const std::string& obj_content) override {
        this->_data.parse(obj_content);
    }
};

}  // namespace field

#endif // FIELD_FIELD_FILE_H