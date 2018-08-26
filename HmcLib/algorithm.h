#pragma once

#include <vector>

using namespace std;


//插入排序 增量法
template <typename T>
void insertion_sort(vector<T>& v)
{
    for (int i = 1; i < v.size(); i++)
    {
        T temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = temp;
    }
}

template <typename T>
void merge(vector<T>& v, typename vector<T>::iterator left, typename vector<T>::iterator mid, typename vector<T>::iterator right)
{
    vector<T> v1(left, mid+1);
    vector<T> v2(mid+1, right+1);
    auto beg1 = v1.begin();
    auto beg2 = v2.begin();
    for (auto it = left; it <= right; ++it)
    {
        if (beg1 == v1.end())
            *it = *beg2++;
        else if (beg2 == v2.end())
            *it = *beg1++;
        else if (*beg1 <= *beg2)
            *it = *beg1++;
        else
            *it = *beg2++;
    }
}

template <typename T>
void merge_sort__(vector<T>& v, typename vector<T>::iterator left, typename vector<T>::iterator right)
{
    if (left >= right)
        return;

    auto mid = left + (right - left) / 2;
    merge_sort__(v, left, mid);
    merge_sort__(v, mid+1, right);
    merge(v, left, mid, right);
}
//归并排序 分治法
template <typename T>
void merge_sort(vector<T>& v)
{
    merge_sort__(v, v.begin(), v.end()-1);
}