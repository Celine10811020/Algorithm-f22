#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    long long i, j, num, temp=0;
    long long *price = NULL;

    scanf("%lld", &num);

    price = (long long*)malloc(sizeof(long long)*num);
    for(i=0; i<num; i++)
    {
        scanf("%lld", &temp);
        *(price+i) = (long long)(temp);
    }



    for(i=0;i<num-1;i++)//氣泡排序每行進行排序
    {
        for(j=0;j<num-i-1;j++)
        {
            if(price[j]>price[j+1])
            {
                temp=price[j+1];
                price[j+1]=price[j];
                price[j]=temp;
            }
        }
    }

    temp = price[0];
    for(i=1; i<num; i++)
    {
        printf("%ld*%ld", temp, price[i]-i);
        temp = (temp%1000000007 * (price[i]-i)%1000000007) % 1000000007; //(A*B)%mod = (A%mod * B%mod)%mod
        //temp = temp % 100000007;
        printf("=%ld\n", temp);
    }
    if(num == 0)
    {
        temp = 0;
    }

    for(i=0; i<num; i++)
    {
        printf("%lld ", price[i]);
    }
    printf("\n");

    printf("%lld", temp);


    free(price);

    return 0;
}*/
































#define INT_MAX 2147483647

//void printArray(int *price, int num);
void mergeSort(int *price, int head, int tail);
void merge(int *price, int head, int mid, int tail);

int main()
{
    int i=0;
    int num=0;
    int temp=0;
    long long longTemp, longTmp=0;
    int *price = NULL;

    scanf("%d", &num);

    price = (int*)malloc(sizeof(int)*num);

    /*for(i=0; i<num; i++)
    {
        scanf("%d", &price[i]);
    }*/


    for(i=0; i<num; i++)
    {
        scanf("%d", &temp);
        *(price+i) = (int)(temp);
    }


    //printf("original\n");
    //printArray(price, num);
    if(num>1)
    {
        mergeSort(price, 0 , num-1);

    }else if(num == 0)
    {
        printf("0");
        return 0;
    }
    //printf("result\n");
    //printArray(price, num);

    //printf("%ld\n", price[0]);

    longTemp = price[0];
    for(i=1; i<num; i++)
    {
        longTmp = price[i]-i;
        //printf("%lld*%lld", longTemp, longTmp);
        longTemp = (longTemp%1000000007 * longTmp%1000000007) % 1000000007;
        //temp = temp % 100000007;
        //(A*B)%mod = (A%mod * B%mod)%mod
        //printf("=%lld\n", longTemp);
    }
    //prlong longf("\n");

    //tmp = temp;

    printf("%lld", longTemp);

    free(price);

    return 0;
}

void merge(int *price, int head, int mid, int tail)
{
//printf("merge:\n");
//printArray(price, 5);


    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int *leftSub = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSub = (int*)malloc(sizeof(int)*(lenB+1));

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        //printf("a %d\n", price[head + leftIndex]);
        leftSub[leftIndex] = price[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        //printf("b %d\n", price[mid + 1 + rightIndex]);
        rightSub[rightIndex] = price[mid + 1 + rightIndex];
    }

    leftSub[lenA] = INT_MAX;
    rightSub[lenB] = INT_MAX;


    leftIndex = 0;
    rightIndex = 0;


    int writePointer=0;

    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        //printf("c %d > %d\n", leftSub[leftIndex], rightSub[rightIndex]);
        if (leftSub[leftIndex] <= rightSub[rightIndex])
        {
            price[writePointer] = leftSub[leftIndex++];
        }else
        {
            price[writePointer] = rightSub[rightIndex++];
        }
    }

    free(leftSub);
    free(rightSub);
}

void mergeSort(int *price, int head, int tail)
{
    //printf("mergeSort\n");
    //printArray(price, 5);

    //int num = 2;
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        //printf("1.\n");
        mergeSort(price, head, mid);

        //printArray(price, num);
        //printf("2.\n");
        mergeSort(price, mid+1, tail);


        //printArray(price, num);
        //printf("3.\n");
        merge(price, head, mid, tail);


        //printArray(price, num);
    }
    //printf("END\n");
}

/*void printArray(int *price, int num)
{
    int i=0;

    for(i=0; i<num; i++)
    {
        printf("%ld ",price[i]);
        //printf("%p ", &price[i]);
    }

    printf("\n");
}*/



































/*// function to swap elements
void swap(long long *a, long long *b) {
  long long t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
long long partition(long long array[], long long low, long long high) {

  // select the rightmost element as pivot
  long long pivot = array[high];

  // pointer for greater element
  long long i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (long long j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(long long array[], long long low, long long high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    long long pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(long long array[], long long size)
{
    long long i=0;
    for(i = 0; i < size; ++i) {
        printf("%lld  ", array[i]);
    }
    printf("\n");
}

// main function
int main()
{
    long long i=0;
    long long num=0;
    long long temp=0;
    long long tmp=0;
    long long *price = NULL;

    scanf("%lld", &num);

    price = (long long*)malloc(sizeof(long long)*num);

    for(i=0; i<num; i++)
    {
        scanf("%d", &price[i]);
    }

    for(i=0; i<num; i++)
    {
        scanf("%lld", &temp);
        *(price+i) = (long long)(temp);
    }



    //printf("Unsorted Array\n");
    //printArray(price, num);

    // perform quicksort on price

    if(num>1)
    {
        quickSort(price, 0, num-1);

    }else if(num == 0)
    {
        printf("0");
        return 0;
    }
    //printf("Sorted array in ascending order: \n");
    //printArray(price, num);

    //printf("%ld\n", price[0]);

    temp = price[0];
    for(i=1; i<num; i++)
    {
        //printf("%lld*%lld", temp, price[i]-i);
        temp = (temp%1000000007 * (price[i]-i)%1000000007) % 1000000007;
        //temp = temp/1000000007;
        //printf("%d\t", temp);
        //tmp = tmp*1000000007;
        //printf("%d\n", temp);
        //temp = temp - tmp;
        //temp = temp % 100000007;
        //(A*B)%mod = (A%mod * B%mod)%mod
        //printf("=%lld\n", temp);
    }
    //prlong longf("\n");

    //tmp = temp;

    printf("%lld", temp);

    free(price);

    return 0;
}*/
