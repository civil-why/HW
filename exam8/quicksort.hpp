#ifndef _quicksort_hpp_
#define _quicksort_hpp_

#include <iostream>
#include <vector>

using namespace std;

// 交换数组中两个元素的位置
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 分区函数：返回基准元素的索引位置
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = low - 1; // 记录小于基准的元素的索引

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

        cout << "当前数组：";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
        
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // 递归地对基准元素左右两侧的子数组进行排序
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


#endif