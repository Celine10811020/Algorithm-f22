#include <stdio.h>
#include <stdlib.h>

int month[20000];

int main()
{
    int i, temp, one, two;
    int num, currentMax, generalMax;

    scanf("%d", &num);

    for(i=0; i<num; i++)
    {
        scanf("%d", &month[i]);
    }

    //earned
    currentMax = 0;
    generalMax = 0;
    for(i=0; i<num; i++)
    {
        temp = currentMax + month[i];

        if(temp > month[i])
        {
            currentMax = temp;
        }else
        {
            currentMax = month[i];
        }

        if(currentMax > generalMax)
        {
            generalMax = currentMax;
        }
    }
    one = generalMax;

    //lost
    for(i=0; i<num; i++)
    {
        month[i] = month[i] * -1;
    }
    currentMax = 0;
    generalMax = 0;
    for(i=0; i<num; i++)
    {
        temp = currentMax + month[i];

        if(temp > month[i])
        {
            currentMax = temp;
        }else
        {
            currentMax = month[i];
        }

        if(currentMax > generalMax)
        {
            generalMax = currentMax;
        }
    }
    two = generalMax;

    if(abs(one) > abs(two))
    {
        printf("%d", abs(one));
    }else
    {
        printf("%d", abs(two));
    }

    return 0;
}
