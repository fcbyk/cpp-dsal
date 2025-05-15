#pragma once

namespace fcbyk {

    /**
     * @brief int数组排序算法工具类（所有方法均为静态）
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

        /**
         * @brief 计数排序（升序，仅适用于非负整数）
         * @param arr 待排序数组
         * @param size 数组长度
         * @note 时间复杂度：O(n + k)，k为数据范围
         */
        static void countingSort(int arr[], int size);

        /**
         * @brief 插入排序（升序）
         * @param arr 待排序数组
         * @param size 数组长度
         * @note 对小规模数据或接近有序数据效率高
         */
        static void insertionSort(int arr[], int size);
    };

}