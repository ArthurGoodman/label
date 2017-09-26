#pragma once

#include "operators.hpp"
#include "valuewrapper.hpp"

using ValueType = ValueWrapper<int, oper::min, oper::plus>;
