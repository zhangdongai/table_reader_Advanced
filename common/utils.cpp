#include "common/utils.h"

namespace utils {

void string_split(const std::string& raw_string,
                  std::vector<std::string>* const vec,
                  const char* const split_char) {
    CHECK_NULL_RET(vec);
    boost::split(*vec, raw_string, boost::is_any_of(split_char));
}

}  // namespace utils