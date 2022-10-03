#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *price, int head, int tail);
void merge(int *price, int head, int mid, int tail);

int main()
{
    int i, num, temp=0;
    long long longTemp, longTmp=0;
    int *price = NULL;

    scanf("%d", &num);

    price = (int*)malloc(sizeof(int)*num);
    for(i=0; i<num; i++)
    {
        scanf("%d", &temp);
        *(price+i) = (int)(temp);
    }


    if(num>1)
    {
        mergeSort(price, 0, num-1);
    }else if(num == 0)
    {
        printf("0");
        return 0;
    }

    if(price[0] > num)
    {
        longTemp = num;
    }else
    {
        longTemp = price[0];
    }
    for(i=1; i<num; i++)
    {
        if(price[i] > num)
        {
            longTmp = num - i;
        }else
        {
            longTmp = price[i]-i;
        }
        longTemp = (longTemp%1000000007 * longTmp%1000000007) % 1000000007;
    }
    printf("%lld", longTemp);

    free(price);
    return 0;
}

void merge(int *price, int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int *leftSub = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSub = (int*)malloc(sizeof(int)*(lenB+1));

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = price[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = price[mid + 1 + rightIndex];
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
            price[writePointer] = leftSub[leftIndex++];
        }else
        {
            price[writePointer] = rightSub[rightIndex++];
        }
    }

    free(leftSub);
    free(rightSub);
}

void mergeSort(int *price, int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        mergeSort(price, head, mid);
        mergeSort(price, mid+1, tail);
        merge(price, head, mid, tail);
    }
}




/*
Description
The store sells nn items. The store manager wants to price each item with the following below.
There is a price ceiling Pi for each item i (1≤i≤n); that is, the price of the i-th item should not greater than Pi.
The price of each item should be a unique integer from 1 to n.

Input
The first line contains an integer n, which is the number of items in the store.
The second line contains n integers P1, P2, ... Pn, where Pi is the price ceiling of the i-th item.

Constraints:
1≤n≤2×10^5
1≤Pi≤10^9


Output
Print the total number of permutations that the store manager can price the items.
Since the answer might be large, output the answer mod 10^9 + 7

Sample Input 1
5
5 5 1 4 3

Sample Output 1
8
*/
