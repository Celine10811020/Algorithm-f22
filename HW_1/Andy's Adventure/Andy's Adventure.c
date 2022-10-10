//TLE的PAC

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int head, int tail);
void merge(int head, int mid, int tail);
void paiLeiZuHe(int home, int diJiCeng);
int comparison();

int arr[7] = {};
int compare[400000] = {};
int stone[300] = {};

int main()
{
    int i, temp = 0;

    scanf("%d", &arr[6]);
    scanf("%d", &arr[5]);

    //stone = (int*)malloc(sizeof(int)*num);
    for(i=0; i<arr[6]; i++)
    {
        scanf("%d", &stone[i]);
    }

  	arr[6]--;
    mergeSort(0, arr[6]);
    paiLeiZuHe(0, 0);

    if(arr[4] == 0)
    {
        printf("FeiDooDoo_Zuo_Wei_Men");
    }else
    {
        printf("%d", arr[4]);
    }
    
    //free(stone);
    return 0;
}


/*
stone[] = 原本完整陣列
arr[0~3] = nC4後的陣列
arr[4] = 一共有幾組答案了
arr[5] = 希望加總的最終數字
arr[6] = 陣列結束位置
compare[] = 將答案存到另一個二維陣列中
*/
//排列組合（陣列起始位置，排到第幾層(有幾個)）
void paiLeiZuHe(int home, int diJiCeng)
{
    int i, temp, tmp=0;
    int summation = 0;

    if (diJiCeng == 4)
    {
        tmp = arr[4];
        for(i=0; i<4; i++)
        {
            summation = summation + arr[i];
        }
        if(arr[5] == summation)
        {
            for(i=0; i<4; i++)
            {
                compare[tmp*4 + i + 1] = arr[i];
            }
            compare[0] = tmp;
            temp = comparison();
            if(temp == 0)
            {
                arr[4] = arr[4] + 1;
            }
        }
        return;
    }

    //遞迴
    for(i=home; i<=arr[6] && arr[6]-i+1 >= 4-diJiCeng; i++)
    {
        arr[diJiCeng] = stone[i];
        paiLeiZuHe(i+1, diJiCeng+1);
    }
}

//compare[0] = 目前有幾組為重複答案;
//有重複：1、沒有重複：0
int comparison() //檢查找出來的組合是否有重複
{
    int i, j, temp;

    if(compare[0] == 0)
    {
        return 0;
    }
  
    for(j=compare[0]-1; j>=0; j--)
      {
          temp = 0;
          for(i=1; i<5; i++)
          {
              //二維陣列其實算是一維陣列，第二行、第三行... 是直接接在第一行後面
              if(compare[compare[0]*4 + i] == compare[j*4 + i])
              {
                	
                  temp++;
              }
          }
          if(temp == 4)
          {
              return 1;
          }
      }
  return 0;
}

int leftSub[151];
int rightSub[151];
void merge(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = stone[head + leftIndex];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = stone[mid + 1 + rightIndex];
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
            stone[writePointer] = leftSub[leftIndex++];
        }else
        {
            stone[writePointer] = rightSub[rightIndex++];
        }
    }

    //free(leftSub);
    //free(rightSub);
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
