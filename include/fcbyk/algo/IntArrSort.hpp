#pragma once

namespace fcbyk {

    /**
     * @brief int数组排序算法工具类（所有方法均为静态）
     */
    class IntArrSort {
    private:
        // 归并排序辅助函数
        static void mergeSortRecursive(int arr[], int left, int right, int temp[]);
        static void merge(int arr[], int left, int mid, int right, int temp[]);

        // 快速排序辅助函数
        static void quickSortRecursive(int arr[], int low, int high);
        static int partition(int arr[], int low, int high);

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

        /**
         * @brief 归并排序（升序）
         * @param arr 待排序数组
         * @param size 数组长度
         * @note 时间复杂度：O(n log n)，需要额外空间
         */
        static void mergeSort(int arr[], int size);

        /**
         * @brief 快速排序（升序）
         * @param arr 待排序数组
         * @param size 数组长度
         * @note 平均时间复杂度：O(n log n)，原地排序
         */
        static void quickSort(int arr[], int size);
    };

}