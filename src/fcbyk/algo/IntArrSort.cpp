#include <fcbyk/algo.hpp>

namespace fcbyk {

    // 冒泡排序（优化版：检测已有序时提前终止）
    void IntArrSort::bubbleSort(int arr[], int size) {
        if (size <= 1) return;

        for (int i = 0; i < size - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break; // 内层无交换说明已有序
        }
    }

    // 选择排序（每次选最小元素放到前面）
    void IntArrSort::selectionSort(int arr[], int size) {
        if (size <= 1) return;

        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(arr[i], arr[minIndex]);
            }
        }
    }

    // 计数排序（仅处理非负整数）
    void IntArrSort::countingSort(int arr[], int size) {
        if (size <= 1) return;

        // 找最大值
        int maxVal = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > maxVal) maxVal = arr[i];
        }

        // 创建并初始化计数数组
        int* count = new int[maxVal + 1]();

        // 统计元素频率
        for (int i = 0; i < size; ++i) {
            count[arr[i]]++;
        }

        // 重构原数组
        int index = 0;
        for (int val = 0; val <= maxVal; ++val) {
            while (count[val]-- > 0) {
                arr[index++] = val;
            }
        }

        delete[] count; // 释放内存
    }

    // 插入排序（适合小规模或部分有序数据）
    void IntArrSort::insertionSort(int arr[], int size) {
        if (size <= 1) return;

        for (int i = 1; i < size; ++i) {
            int key = arr[i];
            int j = i - 1;

            // 将比 key 大的元素向右移动
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key; // 插入 key 到正确位置
        }
    }

}