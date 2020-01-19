#pragma once
#include"dependies.h"
template<typename T>
int partition(T *arr, int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++)
    {
        
        if (arr[j] < pivot)
        {
            i++; 
            std::swap(arr[i], arr[j]);
        }
    }
   std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template<typename T>
void quickSort(T *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
template<typename T>
T maximum(T *arr,int lenght) {
    T max = arr[0];
    for (int i = 0; i < lenght; i++)
    {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}
template<typename T>
T manimum(T* arr, int lenght) {
    T min = arr[0];
    for (int i = 0; i < lenght; i++)
    {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}
template<typename T>
int Binary_search(T* arr, int lenght, T key) {
    quickSort(arr, 0, lenght - 1);
    int midle = (0 + lenght) / 2;
    while (true)
    {
        if (midle<0 || midle>lenght) {
            return -1;
        }
        if (arr[midle] == key) {
            return midle;
        }
        else if (arr[midle] > key) {
            midle--;
        }
        else if(arr[midle] < key)
        {
            midle++;
        }
    }
}
template<typename T>
bool Change(T* arr, int lenght, T elem, int index) {
    if (index > lenght || index < 0) {
        return false;
    }
    else
    {
        arr[index] = elem;
        return true;
    }

}


