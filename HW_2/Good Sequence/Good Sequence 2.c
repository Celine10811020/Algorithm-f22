//C++

#include <cstdio>
#include <stdlib.h>
#include <algorithm> //for nth_element()

#define min(a,b) ((a) < (b) ? (a) : (b))

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
    long i, j, temp;
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
        
        temp = j/2;
        std::nth_element(arr, arr+temp, arr+j); //找出arr中第temp小的數（中位數）
        
        for(i=0; i<j; i++)
        {
            one = one + abs(arr[i]-arr[temp]);
        }

        //rightNumSame
        two = goodSequence(left, mid);
        j=0;
        for(i=mid+1; i<=right; i++)
        {
            arr[j] = sequence[i];
            j++;
        }
        
        temp = j/2;
        std::nth_element(arr, arr+temp, arr+j);

        for(i=0; i<j; i++)
        {
            two = two + abs(arr[i]-arr[temp]);
        }
        
        return min(one, two);

    }else if(sequenceNum == 4)
    {
        //leftNumSame
        one = abs(sequence[left+1] - sequence[left]);

        //rightNumSame
        two = abs(sequence[right-1] - sequence[right]);

        return min(one, two);
    }

    return 0;
}
