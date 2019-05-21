#ifndef CUSTOM_CUSTOM_PLANNING_FILE_H
#define CUSTOM_CUSTOM_PLANNING_FILE_H

#include <string>

namespace custom {

class CustomData {
public:
    /**
    * @brief Customized Struct string parser
    * @param data. The raw string
    */
    void parse(const std::string& data);

    void format_out() const;
public:
    int _type = 0;
    int _time_interval = 0;
    float _distance = 0.0f;
};

}  // namespace custom

#endif // CUSTOM_CUSTOM_PLANNING_FILE_H