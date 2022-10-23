//有WA和TLE的PAC

#include <stdio.h>
#include <stdlib.h>

void mergeSort(long head, long tail);
void merge(long head, long mid, long tail);
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
    long i, j, temp;
    long median, minNum;
    long one, two;
    long sequenceNum = right-left+1;
    long mid = left + (sequenceNum)/2 - 1;
//printf("left: %ld, right: %ld, sequenceNum: %ld\n", left, right, sequenceNum);

    if(sequenceNum > 4)
    {
printf("sequenceNum > 4\n");
        //leftNumSame
        one = goodSequence(mid+1, right);
        j=0;
        for(i=left; i<=mid; i++)
        {
            arr[j] = sequence[i];
            j++;
        }
        mergeSort(0, j-1);
        temp = j/2 - 1;
        /*if(j%2 == 0)
        {
            median = arr[temp];
printf("medianOfLeft: %ld\n", median);
        }else*/
        {
            median = arr[temp];
printf("medianOfLeft: %ld\n", median);
        }

        for(i=left; i<=mid; i++)
        {
            one = one + abs(sequence[i] - median);
        }

        //rightNumSame
        two = goodSequence(left, mid);
        j=0;
        for(i=mid+1; i<=right; i++)
        {
            arr[j] = sequence[i];
            j++;
        }
        mergeSort(0, j-1);
        temp = j/2 - 1;
        /*if(j%2 == 0)
        {
            median = arr[temp];
printf("medianOfRight: %ld\n", median);
        }else*/
        {
            median = arr[temp];
printf("medianOfRight: %ld\n", median);
        }

        for(i=mid+1; i<=right; i++)
        {
            two = two + abs(sequence[i] - median);
        }

        minNum = one;
        if(two < minNum)
        {
            minNum = two;
        }
//printf("leftNumSame: %ld, rightNumSame: %ld, min: %ld\n", one, two, minNum);
        return minNum;

    }else if(sequenceNum == 4)
    {
//printf("sequenceNum == 4\n");
        //leftNumSame
        one = abs(sequence[left+1] - sequence[left]);

        //rightNumSame
        two = abs(sequence[right-1] - sequence[right]);

        minNum = one;
        if(two < minNum)
        {
            minNum = two;
        }
//printf("leftNumSame: %ld, rightNumSame: %ld, min: %ld\n", one, two, minNum);
        return minNum;
    }

    return 0;
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
