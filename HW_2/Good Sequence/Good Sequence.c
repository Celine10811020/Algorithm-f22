//TLE的PAC
//C

#include <stdio.h>
#include <stdlib.h>

void mergeSort(long head, long tail);
void merge(long head, long mid, long tail);
void insertionSort(long num);
long goodSequence(long left, long right);

long sequence[2000000];
long arr[1000000];

int main()
{
    long i, num;
    long ans;

    scanf("%ld", &num);
    for(i=0; i<num; i++)
    {
        scanf("%ld", &sequence[i]);
    }

    if(num <= 3)
    {
        ans = 0;
    }else
    {
        ans = goodSequence(0, num-1);
    }

    printf("%ld", ans);

    return 0;
}

long goodSequence(long left, long right)
{
    long i, j, k;
    long minNum;
    long one, two;
    long sequenceNum = right-left+1;
    long mid = (left+right) / 2;

    if(sequenceNum > 4)
    {
        //leftNumSame
        one = goodSequence(mid+1, right);
        
        j=0;
        for(i=left; i<=mid; i++)
        {
            arr[j] = sequence[i];
            j++;
        }
        if(j<30)
        {
            insertionSort(j);
        }else
        {
            mergeSort(0, j-1);
        }
        
        k=j-1;
        for(i=0; i<k; i++) //abs(an-median)+abs(a1-median) == abs(an-a1)
        {
            one = one + abs(arr[k]-arr[i]);
            k--;
        }

        //rightNumSame
        two = goodSequence(left, mid);
        
        j=0;
        for(i=mid+1; i<=right; i++)
        {
            arr[j] = sequence[i];
            j++;
        }
        if(j<30)
        {
            insertionSort(j);
        }else
        {
            mergeSort(0, j-1);
        }

        k=j-1;
        for(i=0; i<k; i++)
        {
            two = two + abs(arr[k]-arr[i]);
            k--;
        }

        minNum = one;
        if(two < minNum)
        {
            minNum = two;
        }
        return minNum;

    }else if(sequenceNum == 4)
    {
        //leftNumSame
        one = abs(sequence[left+1] - sequence[left]);

        //rightNumSame
        two = abs(sequence[right-1] - sequence[right]);

        minNum = one;
        if(two < minNum)
        {
            minNum = two;
        }
        return minNum;
    }

    return 0;
}

void insertionSort(long num)
{
    long i, j, temp;

    for (i=1; i<num; i++)
    {
        temp = arr[i];
        j = i - 1;
        while(temp<arr[j] && j>=0)
        {
        arr[j+1] = arr[j];
        j--;
        }
        arr[j+1] = temp;
    }
}

long leftSub[500001];
long rightSub[500001];
void merge(long head, long mid, long tail)
{
    long lenA = mid - head + 1;
    long lenB = tail - (mid+1) + 1;
    long leftIndex = 0;
    long rightIndex = 0;

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

    long writePointer=0;
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
