#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#undef assert
#define assert(value)                                                                          \
    if (!(value))                                                                              \
        throw std::runtime_error(                                                              \
            "in file '" + std::string(__FILENAME__) + "': assertion `" + std::string(#value) + \
            "' failed'");
