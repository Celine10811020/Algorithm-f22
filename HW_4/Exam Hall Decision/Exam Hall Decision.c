#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int *arr, int head, int tail);
void merge(int *arr, int head, int mid, int tail);

int costA[10000];
int costB[10000];

int diffA[10000];
int diffB[10000];

int main()
{
    int i, temp;
    int num, sum;
    int numCostA, numCostB, diff;

    scanf("%d", &num);

    sum = 0;
    for(i=0; i<num; i++)
    {
        scanf("%d", &costA[i]);
        scanf("%d", &costB[i]);
    }

    sum = 0;
    numCostA = 0;
    numCostB = 0;
    for(i=0; i<num; i++)
    {
        if(costA[i] > costB[i])
        {
            sum = sum + costB[i];
            diffB[numCostB] = costA[i] - costB[i];
            numCostB++;
        }else
        {
            sum = sum + costA[i];
            diffA[numCostA] = costB[i] - costA[i];
            numCostA++;
        }
    }

    if(numCostA != numCostB)
    {
        diff = abs(numCostA - numCostB);
        diff = diff / 2;

        if(numCostA > numCostB)
        {
            mergeSort(diffA, 0, numCostA-1);

            temp = 0;
            for(i=0; i<diff; i++)
            {
                temp = temp + diffA[i];
            }

            sum = sum + temp;
        }else
        {
            mergeSort(diffB, 0, numCostB-1);

            temp = 0;
            for(i=0; i<diff; i++)
            {
                temp = temp + diffB[i];
            }

            sum = sum + temp;
        }
    }

    printf("%d", sum);

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
