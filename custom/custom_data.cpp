#include "custom_data.h"

#include <iostream>
#include <vector>

#include "common/utils.h"

namespace custom {

void CustomData::parse(const std::string& data) {
    std::vector<std::string> data_vec;
    utils::string_split(data, &data_vec, ",");
    TRY_ENTRY
    _type = std::stoi(data_vec[0].data());
    _time_interval = std::stoi(data_vec[1].data());
    _distance = std::stoi(data_vec[2].data());
    CATCH_EXIT
}

void CustomData::format_out() const {
    std::cout << "type = " << _type << '\t'
              << "time_interval = " << _time_interval << '\t'
              << "distance = " << _distance << '\t';
}

}  // namespace custom