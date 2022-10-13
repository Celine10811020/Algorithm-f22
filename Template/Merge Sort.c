#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int head, int tail);
void merge(int *arr, int head, int mid, int tail);

int main()
{
    int *arr;
    int num;

    arr = (int*)malloc(sizeof(int)*num);

    mergeSort(arr, 0, num-1);

    return 0;
}

void merge(int *arr, int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int *leftSub = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSub = (int*)malloc(sizeof(int)*(lenB+1));

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = arr[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = arr[mid + 1 + rightIndex];
    }
    leftSub[lenA] = 2147483647;
    rightSub[lenB] = 2147483647;

    leftIndex = 0;
    rightIndex = 0;

    int writePointer=0;
    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if (leftSub[leftIndex] <= rightSub[rightIndex])
        {
            arr[writePointer] = leftSub[leftIndex++];
        }else
        {
            arr[writePointer] = rightSub[rightIndex++];
        }
    }

    free(leftSub);
    free(rightSub);
}

void mergeSort(int *arr, int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        mergeSort(arr, head, mid);
        mergeSort(arr, mid+1, tail);
        merge(arr, head, mid, tail);
    }
}
