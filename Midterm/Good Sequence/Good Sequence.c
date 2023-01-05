#include <cstdio>
#include <algorithm>

long goodSequence(long left, long right);
long min(long one, long two);

long sequence[2000000];
long arr[2000000];

int main()
{
  long i, num, ans;
  
  scanf("%ld", &num);
  
  for(i=0; i<num; i++)
  {
    scanf("%ld", &sequence[i]);
  }
  
  if(num <= 3)
  {
    ans = 0;
  }else
  {
    ans = goodSequence(0, num-1);
  }
  
  printf("%ld", ans);
  
  return 0;
}

long goodSequence(long left, long right)
{
  long i, j, temp, one, two;
  long length = right - left + 1;
  long mid = (left+right) / 2;
  
  if(length > 4)
  {
    one = goodSequence(mid+1, right);
    
    j = 0;
    for(i=left; i<=mid; i++)
    {
      arr[j] = sequence[i];
      j++;
    }
    
    temp = j / 2;
    
    std::nth_element(arr, arr+temp, arr+j);
    
    for(i=0; i<j; i++)
    {
      one = one + abs(arr[i] - arr[temp]);
    }
    
    two = goodSequence(left, mid);
    
    j = 0;
    for(i=mid+1; i<=right; i++)
    {
      arr[j] = sequence[i];
      j++;
    }
    
    temp = j / 2;
    
    std::nth_element(arr, arr+temp, arr+j);
    
    for(i=0; i<j; i++)
    {
      two = two + abs(arr[i] - arr[temp]);
    }
    
    return min(one, two);
  }else if(length == 4)
  {
    one = abs(sequence[left] - sequence[left+1]);
    
    two = abs(sequence[right] - sequence[right-1]);
    
    return min(one, two);
  }else
  {
    return 0;
  }
}

long min(long one, long two)
{
  if(one < two)
  {
    return one;
  }else
  {
    return two;
  }
}