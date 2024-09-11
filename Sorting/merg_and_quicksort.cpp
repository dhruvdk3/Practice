#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e){
    int m = (s+e)/2, len1 = m-s+1, len2 = e-m;
    int* first = new int[len1];
    int* second = new int[len2];
    int main_array_index = s;

    for (int i = 0; i < len1; i++){
        first[i] = arr[main_array_index++];
    }

    main_array_index = m+1;
    for (int i = 0; i < len2; i++){
        second[i] = arr[main_array_index++];
    }

    int index1 = 0, index2 = 0;
    main_array_index = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2]){
            arr[main_array_index++] = first[index1++];
        }
        else{
            arr[main_array_index++] = second[index2++];
        }
    }
    while (index1 < len1){
        arr[main_array_index++] = first[index1++];
    }
    while (index2 < len2){
        arr[main_array_index++] = second[index2++];
    }
    delete []first;
    delete []second;
}

void merge_sort(int *arr, int s, int e){
    int m = (s+e)/2;
    if (s>=e) return;
    merge_sort(arr, s, m);
    merge_sort(arr, m+1, e);
    merge(arr, s, e);
}

int partion(int *arr, int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s+1; i <= e; i++){
        if (pivot>=arr[i]) cnt++;
    }
    int index = s+cnt;
    swap(arr[s], arr[index]);
    
    int i = s, j = e;
    while(i< index && j>index){
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < index && j > index) swap(arr[i++],arr[j--]);
    }
    return index;
}



void quick_sort(int* arr, int s, int e){
    if (s>=e) return;
    int p = partion(arr, s, e);
    quick_sort(arr, s, p-1);
    quick_sort(arr, p+1, e);
}



int main(int argc, char const *argv[])
{
    int arr[] = {9, 3, 7, 1, 8, 2, 5, 4, 6, 0, 3, 8, 1, 7, 2, 9, 4, 5, 6, 0};
    // int arr[] = {19, 3, 15, 7, 10, 1, 14, 8, 20, 5, 12, 9, 4, 17, 6, 18, 11, 13, 16, 2};
    // merge_sort(arr, 0, 19);
    quick_sort(arr,0,19);
    for(int i = 0; i<20; i++) cout<<arr[i]<<"   ";
    return 0;
}