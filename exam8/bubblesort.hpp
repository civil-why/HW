#ifndef _bubblesort_hpp_
#define _bubblesort_hpp_

#include <iostream>
#include <vector>

using namespace std;

// 冒泡排序函数
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // 如果没有发生交换，表示数组已经有序，提前结束排序
        if (!swapped) {
            break;
        }
        
        cout << "第 " << i + 1 << " 轮排序结果：";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}

#endif