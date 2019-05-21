#ifndef COMMON_LOG_H
#define COMMON_LOG_H

#include <iostream>
#include <assert.h>

#define DEBUG_LOG(...)               \
{                                    \
    char debug_log[1024] = {0};      \
    snprintf(debug_log, sizeof(debug_log), __VA_ARGS__);  \
    std::cout << "Info: " << debug_log << std::endl; \
}

#define ERROR_LOG(...)               \
{                                    \
    char error_log[1024] = {0};      \
    snprintf(error_log, sizeof(error_log), __VA_ARGS__);  \
    std::cerr << "Error: " << error_log << std::endl; \
}

#define ASSERT_LOG(condition, ...) \
    if (!condition) {              \
        ERROR_LOG(__VA_ARGS__)     \
        assert(false);         \
    }


#define TRY_ENTRY \
    try {

#define CATCH_EXIT                                                                         \
    } catch (const std::exception& e) {                                                    \
        ASSERT_LOG(false, "Catch exception: %s, %s:%d", e.what(), __FILE__, __LINE__);     \
    }

#define CHECK_NULL_RETBOOL(ptr) \
    if (ptr == nullptr)         \
        return false;

#define CHECK_NULL_RET(ptr) \
    if (ptr == nullptr)     \
        return;
#endif //COMMON_LOG_H