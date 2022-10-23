//TLE的PAC，只比C的快0.5秒
//C++

#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))

void mergeSort(long head, long tail);
void merge(long head, long mid, long tail);
void insertionSort(long num);
long goodSequence(long left, long right);

long sequence[2000000];
long arr[1000000];
//vector<long> arr;

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
    long i, j, k, temp;
    //long minNum;
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
        /*temp = mid-left+1;
        std::copy(sequence + left, sequence + left+temp, arr);*/
        for(i=0; i<temp; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
        std::sort(arr, arr+temp);

        k=j-1;
        for(i=0; i<k; i++)
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
        std::sort(arr, arr+right-mid);

        k=j-1;
        for(i=0; i<k; i++)
        {
            two = two + abs(arr[k]-arr[i]);
            k--;
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
