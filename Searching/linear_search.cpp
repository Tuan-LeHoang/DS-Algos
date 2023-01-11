#include <iostream>
using namespace std;

int linear_search(int a[], int size, int target)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(a[i] == target) return i;
    }
    return -1;
}

int main()
{
    int a[] = {4,6,78,3,7,5,23,11,20,8};
    int n = sizeof(a)/sizeof(a[0]);  

    //Find 6 in array, expect 1
    cout << linear_search(a, n, 6) << endl;

    //Find 1 in array, expect -1
    cout << linear_search(a, n, 1) << endl;

    return 0;
}