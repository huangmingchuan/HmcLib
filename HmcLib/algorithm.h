#pragma once

#include <vector>

using namespace std;

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