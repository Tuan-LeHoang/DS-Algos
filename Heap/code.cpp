#include <iostream>
using namespace std;

class MaxHeap {
    int* arr;
    int maxSize;
    int heapSize;

    public:
        MaxHeap(int maxSize);
        void MaxHeapify(int);

        void deleteKey(int i);
        void increaseKey(int i, int newVal);
        void inseartKey(int x);

        int parent(int i)
        {
            return (i-1)/2;
        }

        int lChild(int i)
        {
            return (2 * i + 1);
        }
        int rChild(int i)
        {
            return (2 * i + 2);
        }

        int removeMax();

        int getMax()
        {
            return arr[0];
        }

        int currentSize()
        {
            return heapSize;
        }

        
}


int main()
{
    return 0;
}

