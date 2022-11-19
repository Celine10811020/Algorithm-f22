#include <stdio.h>
#include <stdlib.h>

void mergeSort(long head, long tail);
void merge(long head, long mid, long tail);

long cost[100000];

int main()
{
    long i, temp;
    long num, extraItem;
    long long ans;

    scanf("%ld", &num);

    for(i=0; i<num; i++)
    {
        scanf("%ld", &cost[i]);
    }

    scanf("%ld", &extraItem);

    mergeSort(0, num-1);

    ans = 0;
    temp = 1;
    i = 0;
    while(extraItem > 0)
    {
        if(cost[i] == 0)
        {
            cost[i] = 2147483647;
        }

        if(temp < cost[i])
        {
            ans = ans + temp;
            temp++;
            extraItem--;
        }else if(temp == cost[i])
        {
            temp++;
            i++;
        }else
        {
            i++;
        }
    }

    printf("%lld", ans);

    return 0;
}

void merge(long head, long mid, long tail)
{
    long lenA = mid - head + 1;
    long lenB = tail - (mid+1) + 1;
    long *leftSub = (long*)malloc(sizeof(long)*(lenA+1));
    long *rightSub = (long*)malloc(sizeof(long)*(lenB+1));

    long leftIndex = 0;
    long rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = cost[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = cost[mid + 1 + rightIndex];
    }
    leftSub[lenA] = 2147483647;
    rightSub[lenB] = 2147483647;

    leftIndex = 0;
    rightIndex = 0;

    long writePointer=0;
    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if (leftSub[leftIndex] <= rightSub[rightIndex])
        {
            cost[writePointer] = leftSub[leftIndex++];
        }else
        {
            cost[writePointer] = rightSub[rightIndex++];
        }
    }

    free(leftSub);
    free(rightSub);
}

void mergeSort(long head, long tail)
{
    long mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        mergeSort(head, mid);
        mergeSort(mid+1, tail);
        merge(head, mid, tail);
    }
}

