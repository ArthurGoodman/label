#pragma once

#include <string>

#include "task.hpp"
#include "valuetype.hpp"

class JsonParser {
public:
    static Task<ValueType> parseFile(const std::string &fileName);
};
