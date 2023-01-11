#include <iostream>

using namespace std;

int recursive_binary_search(int low, int high, int a[], int target)
{
    if(low <= high)
    {
        int mid = (low + high)/2;
        //Base case of recursion
        if (a[mid] == target)
        {
            return mid;
        } 

        // Recurse
        else if (target < a[mid])
        {
            return recursive_binary_search(low, mid - 1, a, target);
        }
        else 
        {
            return recursive_binary_search(mid + 1, high, a, target);
        }
    }
    return -1;
}

int iterative_binary_search(int low, int high,  int a[], int target)
{
    while(low <= high)
    {
        int mid = (low + high)/2;
        if (a[mid] == target)
        {
            return mid;
        }

        if(target < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid +  1;
        }
    }
    
    return -1;
}

int main()
{
    int a[] = {1,3,5,6,7,9,11,13,17,20,22,23,25};
    int N = sizeof(a)/sizeof(a[0]);

    cout << recursive_binary_search(0, N-1, a, 6) << endl;
    cout << recursive_binary_search(0, N-1, a, 100) << endl;

    cout << iterative_binary_search(0, N-1, a, 6) << endl;
    cout << iterative_binary_search(0, N-1, a, 100) << endl;

    return 0;
}