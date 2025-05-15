#pragma once
#include <string>

namespace fcbyk{

    /**
     * @brief 高精度减法运算（仅支持非负整数）
     * @param minuend 被减数（必须为非负整数字符串，且无前导零）
     * @param subtrahend 减数（必须为非负整数字符串，且无前导零）
     * @return 结果的字符串表示（无前导零）
     */
    std::string highPrecisionSubtract(const std::string& minuend, const std::string& subtrahend);

    /**
     * int数组排序算法
     */
    class IntArrSort {
    public:
        /**
         * @brief 冒泡排序（升序）
         * @param arr 待排序数组
         * @param size 数组长度
         */
        static void bubbleSort(int arr[], int size);

        /**
         * @brief 选择排序（升序）
         * @param arr 待排序数组
         * @param size 数组长度
         */
        static void selectionSort(int arr[], int size);
    };

}