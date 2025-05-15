#include <fcbyk/algo.hpp>
#include <algorithm>

namespace fcbyk{

    // 冒泡排序
    void IntArrSort::bubbleSort(int arr[], int size){
        for (int i = 0; i < size - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    // 选择排序
    void IntArrSort::selectionSort(int arr[], int size) {
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

};
