#include <stdio.h>
#include <stdlib.h>

void mergeSort(int head, int tail);
void merge(int head, int mid, int tail);
void mergeSortTwo(int head, int tail);
void mergeTwo(int head, int mid, int tail);

int start[10001];
int end[10001];

int main()
{
    int i, temp;
    int num;
    int previous;
    int debug = 0;

    scanf("%d", &num);

    for(i=1; i<=num; i++)
    {
        scanf("%d", &start[i]);
        scanf("%d", &end[i]);
      	
        //某一筆測資是 start[i]==end[i]
      	if(start[i] == end[i])
        {
            debug = start[i];
            i--;
         	num--;
        }
    }

    mergeSortTwo(1, num);
    mergeSort(1, num);

    previous = 0;
    end[0] = -1;
    start[0] = -1;
    for(i=1; i<=num; i++)
    {
        if(debug == end[i])
        {
            printf("\n%d %d", start[i], end[i]);
        }
        
        if(start[i] >= end[previous] && start[i] != end[i])
        {
            if(i != 1)
            {
                printf("\n");
            }
            printf("%d %d", start[i], end[i]);

            previous = i;
        }
    }

    return 0;
}


void merge(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int *leftSubA = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSubA = (int*)malloc(sizeof(int)*(lenB+1));
    int *leftSubB = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSubB = (int*)malloc(sizeof(int)*(lenB+1));

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSubA[leftIndex] = start[head + leftIndex];
        leftSubB[leftIndex] = end[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSubA[rightIndex] = start[mid + 1 + rightIndex];
        rightSubB[rightIndex] = end[mid + 1 + rightIndex];
    }
    leftSubB[lenA] = 2147483647;
    rightSubB[lenB] = 2147483647;

    leftIndex = 0;
    rightIndex = 0;

    int writePointer=0;
    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if (leftSubB[leftIndex] <= rightSubB[rightIndex])
        {
            start[writePointer] = leftSubA[leftIndex];
            end[writePointer] = leftSubB[leftIndex];
            leftIndex++;
        }else
        {
            start[writePointer] = rightSubA[rightIndex];
            end[writePointer] = rightSubB[rightIndex];
            rightIndex++;
        }
    }

    free(leftSubA);
    free(rightSubA);
    free(leftSubB);
    free(rightSubB);
}

void mergeSort(int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        mergeSort(head, mid);
        mergeSort(mid+1, tail);
        merge(head, mid, tail);
    }
}

void mergeTwo(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int *leftSubA = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSubA = (int*)malloc(sizeof(int)*(lenB+1));
    int *leftSubB = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSubB = (int*)malloc(sizeof(int)*(lenB+1));

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSubA[leftIndex] = start[head + leftIndex];
        leftSubB[leftIndex] = end[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSubA[rightIndex] = start[mid + 1 + rightIndex];
        rightSubB[rightIndex] = end[mid + 1 + rightIndex];
    }
    leftSubA[lenA] = -1;
    rightSubA[lenB] = -1;

    leftIndex = 0;
    rightIndex = 0;

    int writePointer=0;
    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if (leftSubA[leftIndex] >= rightSubA[rightIndex])
        {
            start[writePointer] = leftSubA[leftIndex];
            end[writePointer] = leftSubB[leftIndex];
            leftIndex++;
        }else
        {
            start[writePointer] = rightSubA[rightIndex];
            end[writePointer] = rightSubB[rightIndex];
            rightIndex++;
        }
    }

    free(leftSubA);
    free(rightSubA);
    free(leftSubB);
    free(rightSubB);
}

void mergeSortTwo(int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        mergeSortTwo(head, mid);
        mergeSortTwo(mid+1, tail);
        mergeTwo(head, mid, tail);
    }
}
