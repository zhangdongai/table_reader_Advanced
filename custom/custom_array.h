#ifndef CUSTOM_CUSTOM_ARRAY_FILE_H
#define CUSTOM_CUSTOM_ARRAY_FILE_H

#include <iostream>
#include <string>
#include <vector>

#include "common/utils.h"

namespace custom {

template <typename T>
class Array {
public:
    virtual ~Array() {}
    /**
    * @brief Parse given string. This function should be specialized
    *        based on different type
    * @param obj_content. The raw string
    */
    void parse(const std::string& obj_content);
    
    const T& operator[] (const std::size_t index) const {
        static T invalid_T;
        if (index < 0 || index >= _array.size()) {
            return invalid_T;
        }
        return _array[index];
    }

private:
    std::vector<T> _array;
};

/**
* @brief Specialized version for int32_t
* @param obj_content. The raw string
*/
template <>
void Array<int32_t>::parse(const std::string& obj_content);

/**
* @brief Specialized version for float
* @param obj_content. The raw string
*/
template <>
void Array<float>::parse(const std::string& obj_content);

} // namespace custom

#endif // CUSTOM_CUSTOM_ARRAY_FILE_H