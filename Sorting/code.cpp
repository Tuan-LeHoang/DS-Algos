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

int main()
{
    int arr[] = {4,6,7,2,67,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertion_sort(arr, n);
    
    print_arr(arr,n);
    
    return 0;
}