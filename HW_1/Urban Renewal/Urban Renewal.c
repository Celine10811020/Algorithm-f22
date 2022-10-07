#include <stdio.h>
#include <stdlib.h>

int main()
{
    long i, j, temp=0;
    long building, brick, sum=0;
    long *cal;

    scanf("%ld", &building);
    scanf("%ld", &brick);

    cal = (long*)malloc(sizeof(long)*brick);
    cal[0] = '\0';

    for(i=0; i<brick; i++)
    {
        cal[i] = 1;
    }

    sum = brick;
    j = brick - 1;

    while(sum < building)
    {
        temp = sum - cal[j] + cal[j]*2;
        if(temp <= building)
        {
            sum = sum - cal[j] + cal[j]*2;
            cal[j] = cal[j] * 2;
        }else
        {
            j--;
            if(j<0)
            {
                break;
            }
        }
    }

    if(sum == building)
    {
        printf("YES\n");
        for(i=0; i<brick; i++)
        {
            printf("%ld ", cal[i]);
        }
    }else
    {
        printf("NO");
    }

    return 0;
}
