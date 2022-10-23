//C++

#include <stdio.h>
#include <stdlib.h>
#include <vector> //for vector
#include <iostream>
#include <algorithm> //for upper_bound, and lower_bound
using namespace std;

void mergeSort(long head, long tail);
void merge(long head, long mid, long tail);
long cost(long left, long right, long costA, long costB);

vector<long> v;

int main()
{
    long size, building, costA, costB;
    long i, j, temp;
    long ans;

    scanf("%ld", &size);
    scanf("%ld", &building);
    scanf("%ld", &costA);
    scanf("%ld", &costB);

    for(i=0; i<building; i++)
    {
        scanf("%ld", &temp);
        v.push_back(temp);
    }

    mergeSort(0, building-1);

    ans = cost(1, size, costA, costB);

    printf("%ld", ans);

    return 0;
}

long one, two;
long minNum;

long cost(long left, long right, long costA, long costB)
{   
    //(left, right]
    auto upperBoundNum = upper_bound(v.begin(), v.end(), right); 
    auto lowerBoundNum = lower_bound(v.begin(), v.end(), left); 

    long buildingNum = upperBoundNum - lowerBoundNum;
    long mid = left + (right-left)/2;

    if(buildingNum == 0)
    {
        return costA;
    }else if(right-left+1 < 2)
    {
        return buildingNum*costB;
    }else
    {
        one = cost(left, mid, costA, costB) + cost(mid+1, right,costA, costB);
        if(buildingNum > 0)
        {
            two = costB * (right-left+1) * buildingNum;
        }else
        {
            two = costA;
        }

        minNum = one;
        if(two < minNum)
        {
            minNum = two;
        }

        return minNum;
    }
    
    return 0;
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
        leftSub[leftIndex] = v[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = v[mid + 1 + rightIndex];
    }

    leftSub[lenA] = 2147483647;
    rightSub[lenB] = 2147483647;

    leftIndex = 0;
    rightIndex = 0;

    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if (leftSub[leftIndex] <= rightSub[rightIndex])
        {
            v[writePointer] = leftSub[leftIndex++];
        }else
        {
            v[writePointer] = rightSub[rightIndex++];
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
