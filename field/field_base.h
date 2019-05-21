#ifndef FIELD_BASE_FILE_H
#define FIELD_BASE_FILE_H

#include <iostream>
#include <memory>
#include <string>

namespace field {

class FieldBase {
public:
    virtual ~FieldBase() {}
    virtual void parse(const std::string& obj_content) = 0;
};

}  // namespace field

#endif // FIELD_BASE_FILE_H