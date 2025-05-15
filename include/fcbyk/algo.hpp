#pragma once
#include <string>
#include <algorithm>
#include "fcbyk/algo/IntArrSort.hpp"

namespace fcbyk{

    /**
     * @brief 高精度减法运算（仅支持非负整数）
     * @param minuend 被减数（必须为非负整数字符串，且无前导零）
     * @param subtrahend 减数（必须为非负整数字符串，且无前导零）
     * @return 结果的字符串表示（无前导零）
     */
    std::string highPrecisionSubtract(const std::string& minuend, const std::string& subtrahend);

}