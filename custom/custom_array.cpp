#include "custom/custom_array.h"

namespace custom {

template <>
void Array<int32_t>::parse(const std::string& obj_content) {
    std::size_t cindex = obj_content.find_first_of(':');
    if (cindex == std::string::npos) {
        ERROR_LOG("error format!");
        return;
    }

    std::string countitem = obj_content.substr(0, cindex);
    int32_t count = std::stoi(countitem.data());
    _array.resize(count);

    std::vector<std::string> item_vec(count);
    std::string subitem = obj_content.substr(cindex + 1);
    utils::string_split(subitem, &item_vec, ",");

    int32_t index = 0;
    for (const auto& e : item_vec) {
        TRY_ENTRY
        _array[index] = std::stoi(e.data());
        CATCH_EXIT
        ++index;
    }
}

template <>
void Array<float>::parse(const std::string& obj_content) {
    std::size_t cindex = obj_content.find_first_of(':');
    if (cindex == std::string::npos) {
        ERROR_LOG("error format!");
        return;
    }

    std::string countitem = obj_content.substr(0, cindex);
    int32_t count = std::stoi(countitem.data());
    _array.resize(count);

    std::vector<std::string> item_vec(count);
    std::string subitem = obj_content.substr(cindex + 1);
    utils::string_split(subitem, &item_vec, ",");

    int32_t index = 0;
    for (const auto& e : item_vec) {
        TRY_ENTRY
        _array[index] = std::stof(e.data());
        CATCH_EXIT
        ++index;
    }
}

}  // namespace custom