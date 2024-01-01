#ifndef _search_h_
#define _search_h_

#include <iostream>
#include <vector>

// 二分查找算法
bool binarySearch(const std::vector<int>& sortedArray, int target) {
    int left = 0;
    int right = sortedArray.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedArray[mid] == target) {
            return true; // 找到目标值
        } else if (sortedArray[mid] < target) {
            left = mid + 1; // 在右侧继续查找
        } else {
            right = mid - 1; // 在左侧继续查找
        }
    }

    return false; // 未找到目标值
}

#endif