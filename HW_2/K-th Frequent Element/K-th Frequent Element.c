#include <stdio.h>

void mergeSortFre(int head, int tail);
void mergeFre(int head, int mid, int tail);
void mergeSortEle(int head, int tail);
void mergeEle(int head, int mid, int tail);

int element[100000] = {};
int frequence[100000] = {};
int leftSub[50001] = {};
int rightSub[50001] = {};
int leftSubTwo[50001] = {};
int rightSubTwo[50001] = {};

int main()
{
    int i, j, k;
    int num, kth, temp, tmp;

    scanf("%d", &num);
    if(num == 0)
    {
        return 0;
    }

    scanf("%d", &kth);
    if(kth == 0)
    {
        return 0;
    }

    for(i=0; i<num; i++)
    {
        scanf("%d", &element[i]);
    }

    mergeSortEle(0, num-1); //所有element先排序一遍

    //把重複的element去掉，並計算每個element的frequence
    j=0;
    k=0;
    for(i=0; i<num; i++)
    {
        temp = element[i];
        if(i == 0)
        {
            element[k] = temp;
            k++;
        }else if(temp != tmp)
        {
            element[k] = temp;
            frequence[k-1] = j;
            k++;
            j=0;
        }
        tmp = temp;
        j++;
    }
    frequence[k-1] = j;

    mergeSortFre(0, k-1); //frequence從大排到小

    printf("%d\n", element[kth-1]); //輸出第k大的frequence

    return 0;
}


void mergeFre(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = frequence[head + leftIndex];
        leftSubTwo[leftIndex] = element[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = frequence[mid + 1 + rightIndex];
        rightSubTwo[rightIndex] = element[mid + 1 + rightIndex];
    }
    leftSub[lenA] = 0;
    rightSub[lenB] = 0;

    leftIndex = 0;
    rightIndex = 0;

    int writePointer=0;
    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if (leftSub[leftIndex] >= rightSub[rightIndex])
        {
            frequence[writePointer] = leftSub[leftIndex++];
            element[writePointer] = leftSubTwo[leftIndex-1];
        }else
        {
            frequence[writePointer] = rightSub[rightIndex++];
            element[writePointer] = rightSubTwo[rightIndex-1];
        }
    }
}

void mergeSortFre(int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        mergeSortFre(head, mid);
        mergeSortFre(mid+1, tail);
        mergeFre(head, mid, tail);
    }
}

void mergeEle(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = element[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = element[mid + 1 + rightIndex];
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
            element[writePointer] = leftSub[leftIndex++];
        }else
        {
            element[writePointer] = rightSub[rightIndex++];
        }
    }
}

void mergeSortEle(int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        mergeSortEle(head, mid);
        mergeSortEle(mid+1, tail);
        mergeEle(head, mid, tail);
    }
}
