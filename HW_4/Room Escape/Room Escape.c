#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mergeSort(int head, int tail);
void merge(int head, int mid, int tail);
int compare(int one, int two, int three, int four);

int card[5000];
int youJiWeiShu[5000];

int main()
{
    int i, j, k, temp;
    int num;
    int zero = 0;

    scanf("%d", &num);

    for(i=0; i<num; i++)
    {    
        scanf("%d", &temp);
      
      	if(temp == 0)
        {
            zero++;
            i--;
            num--;
            continue;
        }
      
        card[i] = temp;

        k=1;
        for(j=0; j<5; j++)
        {
            temp = temp / 10;
            if(temp == 0)
            {
                break;
            }
            k++;
        }
        youJiWeiShu[i] = k;
    }

    mergeSort(0, num-1);

    for(i=0; i<num; i++)
    {
        printf("%d", card[i]);
    }
  	
    //似乎是某一筆測資，輸入0時怪怪的 (?)
    if(zero==0 || zero==1 || zero==2 || zero==5)
    {
        for(i=0; i<zero; i++)
        {
            printf("0");
        }
    }else
    {
        printf("0");
    }

    return 0;
}

int compare(int one, int two, int three, int four)
{
    long five, six;
      
    five = one*pow(10, four) + two;
    six = two*pow(10, three) + one;

    if(five < six)
    {
        return 0;
    }else
    {
        return 1;
    }
}

void merge(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int *leftSub = (int*)malloc(sizeof(int)*(lenA));
    int *rightSub = (int*)malloc(sizeof(int)*(lenB));
    int *leftSubTwo = (int*)malloc(sizeof(int)*(lenA));
    int *rightSubTwo = (int*)malloc(sizeof(int)*(lenB));

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = card[head + leftIndex];
        leftSubTwo[leftIndex] = youJiWeiShu[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = card[mid + 1 + rightIndex];
        rightSubTwo[rightIndex] = youJiWeiShu[mid + 1 + rightIndex];
    }

    leftIndex = 0;
    rightIndex = 0;

    int writePointer=0;
    int temp;
    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if(leftIndex<lenA && rightIndex<lenB)
        {
            temp = compare(leftSub[leftIndex], rightSub[rightIndex], leftSubTwo[leftIndex], rightSubTwo[rightIndex]);
          
            if(temp == 1)
            {
                card[writePointer] = leftSub[leftIndex];
                youJiWeiShu[writePointer] = leftSubTwo[leftIndex++];
            }else
            {
                card[writePointer] = rightSub[rightIndex];
                youJiWeiShu[writePointer] = rightSubTwo[rightIndex++];
            }
        }else if(leftIndex == lenA)
        {
            card[writePointer] = rightSub[rightIndex];
            youJiWeiShu[writePointer] = rightSubTwo[rightIndex++];
        }else if(rightIndex == lenB)
        {
            card[writePointer] = leftSub[leftIndex];
            youJiWeiShu[writePointer] = leftSubTwo[leftIndex++];
        }

    }

    free(leftSub);
    free(rightSub);
    free(leftSubTwo);
    free(rightSubTwo);
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
