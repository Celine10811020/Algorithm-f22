#include <stdio.h>

void mergeSort(long head, long tail);
void merge(long head, long mid, long tail);

long arr[100000];
long leftSub[50001];
long rightSub[50001];

long main()
{
    long i, temp, tempLeft, tempRight, tempUpper, tempLower;
    long upper, lower;
    long num, ans;
    long left, right;

    scanf("%ld", &num);
    scanf("%ld", &left);
    scanf("%ld", &right);

    for(i=0; i<num; i++)
    {
        scanf("%ld", &arr[i]);
    }

    mergeSort(0, num-1);

    i=0;
    ans=0;
    tempRight=num;
    tempLeft=num;
    tempLower=num-1;
    tempUpper=num-1;

    while(1)
    {
        upper = right/arr[i];
        lower = left/arr[i];
        if(upper==0 || i==num-1)
        {
            break;
        }

        while(1)
        {
            if(tempLeft==i)
            {
                tempLeft++;
                break;
            }else if(arr[tempLower]<lower && arr[tempLower+1]>=lower && tempLower<num-1)
            {
                if(arr[tempLower+1]*arr[i] >= left)
                {
                    tempLeft = tempLower+1;
                }else
                {
                    tempLower++;
                    tempLeft = tempLower+1;
                }
                break;
            }else if(tempLower==i && arr[tempLower]<lower)
            {
                tempLeft = 0;
                tempLower = num-1;
                break;
            }else if(tempLower==i && arr[tempLower]>=lower)
            {
                tempLower++;
                tempLeft = tempLower;
                break;
            }
            tempLower--;
        }

        while(1)
        {
            if(tempRight == i)
            {
                tempRight = 0;
                break;
            }
            if(arr[tempUpper] <= upper)
            {
                tempRight = tempUpper;
                break;
            }else if(tempUpper == i+1)
            {
                tempRight = 0;
                break;
            }
            tempUpper--;
        }

        if(tempLeft!=0 && tempRight!=0)
        {
            temp = tempRight - tempLeft + 1;
            ans = ans + temp;
        }else if(tempRight == 0)
        {
            break;
        }

        i++;
    }

    printf("%ld", ans);

    return 0;
}

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
