#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, temp;
  int num;
  int *arr;
  
  arr=(int*)malloc(sizeof(int)*num);
  
  for (i=1; i<num; i++)
  {
    temp = arr[i];
    j = i - 1;
    while(temp>arr[j] && j>=0)
    {
      arr[j+1] = arr[j];
      j--;
    }
     arr[j+1] = temp;
  }
  
  return 0;
}
