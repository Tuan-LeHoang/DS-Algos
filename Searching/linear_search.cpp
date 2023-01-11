#include <iostream>
#define N 10
using namespace std;

int linear_search(int a[], int size, int target)
{
    int i = 0;
    for(; i < size; i++)
    {
        if(a[i] == target) break;
    }
    if ( i >= size) return -1;
    else return i;
}

int main()
{
    int n = N;
    int a[N] = {4,6,78,3,7,5,23,11,20,8};
    
    //Find 6 in array, expect 1
    cout << linear_search(a, n, 6) << endl;

    //Find 1 in array, expect -1
    cout << linear_search(a, n, 1) << endl;
    
    return 0;
}