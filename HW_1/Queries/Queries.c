//PAC

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *queue, int head, int tail);
void merge(int *queue, int head, int mid, int tail);
void insertSort(int *queue, int head, int tail, int times);

int main()
{
    int i, num, queueNum, temp, home, end, remain, times=0;
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
    temp = 0;
    home = 0; //��J����m�]Last In�^
    end = 0; //�̶}�l����m�]First Out�^
    remain = 0; //queue�����X�ӼƦr
    times = 0; //���X�ӼƦr�ǳƻݭn�i��sort
    //queue�GFIFO
    for(i=0; i<num; i++)
    {
        if(queries[i][0] == 1)
        {
//printf("comman 1\n");
            queue[home] = queries[i][1];
//printf("queue[%d]=%d\n", home, queue[home]);
            home++; //��J��m++
//printf("home=%d\tend=%d\n", home, end);
            remain++; //queue���Ʀr++
            temp = 1; //�ݭn�i��sort
            times ++; //���ƦC�Ʀr++
        }else if(queries[i][0] == 2)
        {
//printf("comman 2\n");
//printf("home=%d\tend=%d\n", home, end);
//printf("Before sorting\n");
/*for(j=end;j<home; j++)
{
    printf("%d ", queue[j]);
}*/
            if(temp == 1) //�p�G�S����J�s���Ʀr�A�N���ݭn�i��sort
            {
                if(times<30 && remain>1) //�ƶq�p��30�ɡAinsertion sort�u��merge sort
                {
                    insertSort(queue, end, home, times);
                }else
                {
                    mergeSort(queue, end, home-1);
                }

            }
            temp = 0; //���ݭn�i��sort
            times = 0; //���ƦC�Ʀr�k�s
//printf("After sorting\n");
/*for(j=end;j<home; j++)
{
    printf("%d ", queue[j]);
}*/
        }else
        {
//printf("comman 3\n");
            if(remain == 0) //�p�Gqueue���S���F��
            {
                printf("Oh oh\n");
            }else
            {
//printf("queue[%d]=%d\n", end, queue[end]);
                printf("%d\n", queue[end]);
                end++; //��X��m++
                remain--; //queue�����Ʀr--
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

void insertSort(int *queue, int head, int tail, int times)
{
    int i, j, k, temp, tmp=0;

    tmp = tail-times-2;
    if(tmp < 0)
    {
        tmp = 0;
    }

    for(i=tail-1; i>=tail-times-2; i--)
    {
        temp = queue[i];
        j = tail-2;
        while(temp>queue[j])
        {
            queue[j+1] = queue[j];
            j--;
        }
        queue[j+1] = temp;
    }
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
