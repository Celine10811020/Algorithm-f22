#include <stdio.h>
#include <stdlib.h>

void mergeSort(long head, long tail);
void merge(long head, long mid, long tail);
long cost(long left, long right);
long lowerBound(long left);
long upperBound(long right);

long data[4];
/*
data[0] = size;
data[1] = building;
data[2] = costA;
data[3] = costB;
*/
long arrBuilding[100000];

int main()
{
    long i, j;
    long ans;

    scanf("%ld", &data[0]);
    scanf("%ld", &data[1]);
    scanf("%ld", &data[2]);
    scanf("%ld", &data[3]);

    for(i=0; i<data[1]; i++)
    {
        scanf("%ld", &arrBuilding[i]);
    }

    mergeSort(0, data[1]-1);
    
    ans = cost(1, data[0]);
    
    printf("%ld", ans);

    return 0;
}

long one, two, three;
long minNum;

long cost(long left, long right)
{
    long upperBoundNum = upperBound(right);
    long lowerBoundNum = lowerBound(left);

    long buildingNum = upperBoundNum - lowerBoundNum + 1;
    long mid = left + (right-left)/2;

    if(right-left+1 > 2) //size > 2
    {
        one = cost(left, mid) + cost(mid+1, right);
        if(buildingNum > 0)
        {
            two = data[3] * (right-left+1) * buildingNum;
        }else
        {
            two = data[2];
        }

        minNum = one;
        if(two < minNum)
        {
            minNum = two;
        }

        return minNum;

    }else if(right-left+1 == 2) //size == 1
    {
        one = cost(left, mid) + cost(mid+1, right);
        
        //自己公司建設，假設並無分割
        if(buildingNum > 0)
        {
            two = data[3] * 2 * buildingNum;
        }else
        {
            two = data[2];
        }

        //自己公司建設，假設有分割成兩小區塊
        if(buildingNum > 0)
        {
            three = buildingNum*data[3];
        }else
        {
            three = data[2];
        }
        if(buildingNum > 0)
        {
            three = three + buildingNum*data[3];
        }else
        {
            three = three + data[2];
        }

        minNum = one;
        if(two < minNum)
        {
            minNum = two;
        }
        if(three < minNum)
        {
            minNum = three;
        }

        return minNum;

    }else //size == 1 
    {
        if(buildingNum > 0)
        {
            return buildingNum*data[3];
        }else
        {
            return  data[2];
        }
    }

    return 0;
}

long lowerBound(long left)
{
    long i;
    for(i=0; i<data[1]; i++)
    {
        if(left <= arrBuilding[i])
        {
            return i;
        }
    }
    return i;
}

long upperBound(long right)
{
    long i;
    for(i=data[1]-1; i>=0; i--)
    {
        if(right >= arrBuilding[i])
        {
            return i;
        }
    }
    return i;
}

long leftSub[50001];
long rightSub[50001];
long leftIndex, rightIndex, writePointer;

void merge(long head, long mid, long tail)
{
    long lenA = mid - head + 1;
    long lenB = tail - (mid+1) + 1;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = arrBuilding[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = arrBuilding[mid + 1 + rightIndex];
    }

    leftSub[lenA] = 2147483647;
    rightSub[lenB] = 2147483647;

    leftIndex = 0;
    rightIndex = 0;

    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if (leftSub[leftIndex] <= rightSub[rightIndex])
        {
            arrBuilding[writePointer] = leftSub[leftIndex++];
        }else
        {
            arrBuilding[writePointer] = rightSub[rightIndex++];
        }
    }
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
