#include <fcbyk/algo.hpp>
#include <algorithm>
#include <stdexcept>

using namespace std;

string fcbyk::highPrecisionSubtract(
        const string& minuend, const string& subtrahend){

    // 提前处理相等情况，避免不必要的计算
    if(minuend == subtrahend) return "0";

    // 允许的最大位数
    const size_t MAX_LEN = 1000;

    // 拷贝常量，用于后续操作
    string num1Str = minuend;
    string num2Str = subtrahend;

    // 判断结果是否负数
    bool isFu = false;
    if (num2Str.length() > num1Str.length()) {
        swap(num1Str, num2Str);
        isFu = true;
    } else if (num2Str.length() == num1Str.length()) {
        for (size_t i = 0; i < num1Str.length(); i++) {
            if (num2Str[i] > num1Str[i]) {
                swap(num1Str, num2Str);
                isFu = true;
                break;
            } else if (num2Str[i] < num1Str[i]) {
                break;
            }
        }
    }

    // 检查是否超过最大长度
    if (num1Str.length() > MAX_LEN || num2Str.length() > MAX_LEN) {
        throw runtime_error("Input numbers exceed maximum length");
    }

    // 定义两个整数数组，以及定义变量存储数字的长度
    int num1Arr[MAX_LEN] = {0};
    int num2Arr[MAX_LEN] = {0};
    size_t num1Len = num1Str.length();
    size_t num2Len = num2Str.length();

    // 字符串转整数数组（逆序）
    for (size_t i = 0; i < num1Len; i++) {
        num1Arr[i] = num1Str[num1Len-1-i]-'0';
    }
    for (size_t i = 0; i < num2Len; i++) {
        num2Arr[i] = num2Str[num2Len-1-i]-'0';
    }

    // 定义一个数组存储结果，以及确认要相减的位数
    int resultArr[MAX_LEN] = {0};
    size_t maxLen = max(num1Len, num2Len);

    // 逐位相减
    for (size_t i = 0; i < maxLen; i++) {
        resultArr[i] = num1Arr[i] - num2Arr[i];
    }

    // 处理借位
    for (size_t i = 0; i < maxLen; ++i) {
        if (resultArr[i] < 0) {
            resultArr[i] += 10;
            resultArr[i+1]--;
        }
    }

    // 去除前导零
    // 找到第一个非零位，即结果的最高位
    size_t resultLen = maxLen;
    while (resultLen > 1 && resultArr[resultLen-1] == 0) {
        resultLen--;
    }

    // 结果数组，转字符串
    string resultStr;
    for (size_t i = 0; i < resultLen; i++) {
        resultStr += static_cast<char>(resultArr[resultLen-1-i] + '0');
    }

    if (isFu) {
        resultStr = "-" + resultStr;
    }

    return resultStr;
}