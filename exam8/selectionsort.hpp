#ifndef _selectionsort_hpp_
#define _selectionsort_hpp_

#include <iostream>
#include <vector>

using namespace std;


// 直接选择排序函数
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // 找到未排序部分的最小元素的索引
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 将找到的最小元素放在已排序部分的末尾
        swap(arr[minIndex], arr[i]);

        cout << "第 " << i + 1 << " 轮排序结果：";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}

#endif