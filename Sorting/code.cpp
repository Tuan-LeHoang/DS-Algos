#include <iostream>

using namespace std;

void print_arr(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        
        while( j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int const left, int const mid, int const right)
{
    auto const sub_array_one = mid - left + 1;
    auto const sub_array_two = right - mid;

    auto *left_array = new int[sub_array_one];
    auto *right_array = new int[sub_array_two];

    //Copy data to temp arrays
    for(auto i = 0; i < sub_array_one; i++)
    {
        left_array[i] = arr[left+i];
    }
    for(auto j = 0; j < sub_array_two; j++)
    {
        right_array[j] = arr[mid + 1 + j];
    }

    auto index_of_sub_array_one  = 0, index_of_sub_array_two = 0;
    int index_of_merged_array = left;

    while(index_of_sub_array_one < sub_array_one && index_of_sub_array_two < sub_array_two)
    {
        if(left_array[index_of_sub_array_one] <= right_array[index_of_sub_array_two])
        {
            arr[index_of_merged_array] = left_array[index_of_sub_array_one];
            index_of_sub_array_one++;
        }
        else
        {
            arr[index_of_merged_array] = right_array[index_of_sub_array_two];
            index_of_sub_array_two++;
        }
        index_of_merged_array++;
    }

    while(index_of_sub_array_one < sub_array_one)
    {
        arr[index_of_merged_array] =  left_array[index_of_sub_array_one];
        index_of_sub_array_one++;
        index_of_merged_array++;
    }

    while(index_of_sub_array_two < sub_array_two)
    {
        arr[index_of_merged_array] = right_array[index_of_sub_array_two];
        index_of_sub_array_two++;
        index_of_merged_array++;
    }

    delete[] left_array;
    delete[] right_array;
}


void merge_sort(int arr[], int const begin, int const end)
{
    if(begin >= end)
    {
        return;
    }

    auto mid = (begin + end) / 2;
    merge_sort(arr,begin, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main()
{
    int arr[] = {4,6,7,2,67,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // insertion_sort(arr, n);
    merge_sort(arr,0,n-1);
    
    print_arr(arr,n);
    
    return 0;
}