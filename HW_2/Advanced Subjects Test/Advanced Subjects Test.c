#include <stdio.h>

int main()
{
    int i, j, num, one, two, three, four, five, temp, total;
    int score[501] = {};

    for(i=0; i<501; i++)
    {
        score[i] = 0;
    }

    scanf("%d", &num);

    for(i=0; i<num; i++)
    {
        scanf("%d", &one);
        scanf("%d", &two);
        scanf("%d", &three);
        scanf("%d", &four);
        scanf("%d", &five);
        total = one + two + three + four + five;
        score[total]++;
    }

    for(i=500; i>=0; i--)
    {
        temp = score[i];
        for(j=0; j<temp; j++)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}