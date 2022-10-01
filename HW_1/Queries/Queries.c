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

//printf("queueNum=%d\n", queueNum);
    queue = (int*)malloc(sizeof(int)*queueNum);

    home = 0;
    end = 0;
    remain = 0;
    for(i=0; i<num; i++)
    {
        if(queries[i][0] == 1)
        {
//printf("comman 1\n");
            queue[home] = queries[i][1];
//printf("queue[%d]=%d\n", home, queue[home]);
            home++;
//printf("home=%d\tend=%d\n", home, end);
            remain++;
        }else if(queries[i][0] == 2)
        {
//printf("comman 2\n");
//printf("home=%d\tend=%d\n", home, end);
//printf("Before sorting\n");
/*for(j=end;j<home; j++)
{
    printf("%d ", queue[j]);
}*/
            mergeSort(queue, end, home-1);
//printf("After sorting\n");
/*for(j=end;j<home; j++)
{
    printf("%d ", queue[j]);
}*/
        }else
        {
//printf("comman 3\n");
            if(remain == 0)
            {
                printf("Oh oh\n");
            }else
            {
//printf("queue[%d]=%d\n", end, queue[end]);
                printf("%d\n", queue[end]);
                end++;
                remain--;
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
