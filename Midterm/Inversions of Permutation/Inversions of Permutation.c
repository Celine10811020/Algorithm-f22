#include <stdio.h>

void inverse(int head, int tail);
void merge(int head, int mid, int tail);

int data[500000];
int arr[500000];
long ans;

int main()
{
  int i, num;
  
  while(scanf("%d", &num) != EOF)
  {
    ans = 0;
    
    for(i=0; i<num; i++)
    {
      scanf("%d", &data[i]);
    }
    
    inverse(0, num-1);
    
    printf("%ld\n", ans);
  }
  
  return 0;
}

void merge(int head, int mid, int tail)
{
  int index = head;
  int indexLeft = head;
  int indexRight = mid + 1;
  
  while(indexLeft<=mid && indexRight<=tail)
  {
    if(data[indexLeft] <= data[indexRight])
    {
      arr[index] = data[indexLeft];
      index++;
      indexLeft++;
    }else
    {
      arr[index] = data[indexRight];
      index++;
      indexRight++;
      
      ans = ans + mid - indexLeft + 1;
    }
  }
  
  while(indexLeft <= mid)
  {
    arr[index] = data[indexLeft];
    index++;
    indexLeft++;
  }
  
  while(indexRight <= tail)
  {
    arr[index] = data[indexRight];
    index++;
    indexRight++;
  }
  
  index--;
  
  while(index >= head)
  {
    data[index] = arr[index];
    index--;
  }
}

void inverse(int head, int tail)
{
  int mid;
  
  if(head < tail)
  {
    mid = (head+tail) / 2;
    
    inverse(head, mid);
    inverse(mid+1, tail);
    
    merge(head, mid, tail);
  }
}