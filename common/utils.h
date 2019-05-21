#ifndef COMMON_UTILS_FILE_H
#define COMMON_UTILS_FILE_H

#include <functional>
#include <string>
#include <vector>

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include "common/log.h"

namespace utils {

/**
* @brief split a given string
* @param raw_string. string object going to be splited
* @param vec. Container in which splited string are stored
* @param split_char. Splitting char，the defualt is '\t'
*/

void string_split(const std::string& raw_string,
                  std::vector<std::string>* const vec,
                  const char* const split_char = "\t");


struct EnumHashDataType {
    template <typename T>
    std::size_t operator()(T t) const {
        return static_cast<std::size_t>(t);
    }
};

struct EnumHashTemp {
    template <typename T>
    std::size_t operator()(T t) const {
        static std::hash<T> hash_func;
        return hash_func(t);
    }
};

}  // namespace utils

#endif // COMMON_UTILS_FILE_H