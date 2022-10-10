//TLE的PAC

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *queue, int head, int tail);
void merge(int *queue, int head, int mid, int tail);

int main()
{
    int i, num, queueNum, temp, home, end, remain=0;
    int *queue = NULL;
    int **queries = NULL;

    scanf("%d", &num);

    queries = (int**)malloc(sizeof(int*)*num); //num*2
    for(i=0; i<num; i++)
    {
        queries[i] = (int*)malloc(sizeof(int)*2);
    }

    queueNum = 0;
    remain = 0;
    for(i=0; i<num; i++)
    {
        scanf("%d", &temp);
        queries[i][0] = temp;
        if(temp == 1)
        {
            scanf("%d", &temp);
            queries[i][1] = temp;
            queueNum++;
            remain++;
        }
    }

    queue = (int*)malloc(sizeof(int)*queueNum);
    home = 0; //輸入的位置（Last In）
    end = 0; //最開始的位置（First Out）
    remain = 0; //queue中有幾個數字
    //queue：FIFO
    for(i=0; i<num; i++)
    {
        if(queries[i][0] == 1)
        {
            queue[home] = queries[i][1];
            home++; //輸入位置++
            remain++; //queue中數字++
        }else if(queries[i][0] == 2)
        {
            mergeSort(queue, end, home-1);
        }else
        {
            if(remain == 0) //如果queue中沒有東西
            {
                printf("Oh Oh\n");
            }else
            {
                printf("%d\n", queue[end]);
                end++; //輸出位置++
                remain--; //queue中的數字--
            }
        }
    }

    for(i=0; i<num; i++)
    {
        free(queries[i]);
    }
    free(queries);
    free(queue);

    return 0;
}


void merge(int *queue, int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int *leftSub = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSub = (int*)malloc(sizeof(int)*(lenB+1));

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = queue[head+leftIndex];
    }
    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = queue[mid+1+rightIndex];
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
            queue[writePointer] = leftSub[leftIndex++];
        }else
        {
            queue[writePointer] = rightSub[rightIndex++];
        }
    }

    free(leftSub);
    free(rightSub);
}

void mergeSort(int *queue, int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        mergeSort(queue, head, mid);
        mergeSort(queue, mid+1, tail);
        merge(queue, head, mid, tail);
    }
}
