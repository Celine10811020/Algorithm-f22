#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countArea(int one, int two, int recursive);
void labelArea(int one, int two, int recursive);

int land[7000][7000];
short landOne[800000];
short landTwo[800000];
int ans;
int range;
int pointStart;
int pointEnd;

int main()
{
    int i, j, k, m;
    int temp, max, one, two;
    int num;
    int possible, landmark;
    int center, leftTop;

    scanf("%d", &num);

    for(i=0; i<num; i++)
    {
        scanf("%d", &range);
        scanf("%d", &possible);

      	if(range == 0)
        {
          printf("0\n");
          continue;
        }

        landmark = getchar();

        for(j=0; j<range; j++)
        {
            for(k=0; k<=range; k++)
            {
                landmark = getchar();

                if(landmark == 94)
                {
                    land[j][k] = 0;
                }else if(landmark == 95)
                {
                    land[j][k] = 1;
                }
            }
        }

        for(j=0; j<range; j++)
        {
            for(k=0; k<range; k++)
            {
                if(land[j][k] == 1)
                {
                    ans = 3;
                    pointStart = 0;
                    pointEnd = 0;
                    land[j][k] = 2;
                    countArea(j, k, 0);

                    while(pointStart < pointEnd)
                    {
                        one = landOne[pointStart];
                        two = landTwo[pointStart];

                        countArea(one, two, 0);

                        pointStart++;
                    }

                    pointStart = 0;
                    pointEnd = 0;
                    land[j][k] = ans;
                    labelArea(j, k, 0);

                    while(pointStart < pointEnd)
                    {
                        one = landOne[pointStart];
                        two = landTwo[pointStart];

                        labelArea(one, two, 0);

                        pointStart++;
                    }
                }
            }
        }

        center = range / 2;
        leftTop = center - possible;
        possible = possible*2 + 1;

        max = 0;
        for(j=0; j<possible; j++)
        {
            for(k=0; k<possible; k++)
            {
                temp = land[leftTop+j][leftTop+k];

                if(temp > max)
                {
                    max = temp;
                }
            }
        }

        if(max == 0)
        {
            printf("0\n");
        }else
        {
            printf("%d\n", max-2);
        }
    }

    return 0;
}

void countArea(int one, int two, int recursive)
{
    if(recursive > 100000) //recursive ¤Ó¦h·|¥X¨Æ
    {
        landOne[pointEnd] = one;
        landTwo[pointEnd] = two;
        pointEnd++;
        return;
    }

    if(one-1 >= 0)
    {
        if(land[one-1][two] == 1)
        {
            ans++;
            land[one-1][two] = 2;
            countArea(one-1, two, recursive+1);
        }
    }

    if(two-1 >= 0)
    {
        if(land[one][two-1] == 1)
        {
            ans++;
            land[one][two-1] = 2;
            countArea(one, two-1, recursive+1);
        }
    }

    if(two+1 < range)
    {
        if(land[one][two+1]==1)
        {
            ans++;
            land[one][two+1] = 2;
            countArea(one, two+1, recursive+1);
        }
    }

    if(one+1 < range)
    {
        if(land[one+1][two]==1)
        {
            ans++;
            land[one+1][two] = 2;
            countArea(one+1, two, recursive+1);
        }
    }
}

void labelArea(int one, int two, int recursive)
{
    if(recursive > 100000) //recursive ¤Ó¦h·|¥X¨Æ
    {
        landOne[pointEnd] = one;
        landTwo[pointEnd] = two;
        pointEnd++;
        return;
    }


    if(one-1 >= 0)
    {
        if(land[one-1][two] == 2)
        {
            land[one-1][two] = ans;
            labelArea(one-1, two, recursive+1);
        }
    }

    if(two-1 >= 0)
    {
        if(land[one][two-1] == 2)
        {
            land[one][two-1] = ans;
            labelArea(one, two-1, recursive+1);
        }
    }

    if(two+1<range)
    {
        if(land[one][two+1]==2)
        {
            land[one][two+1] = ans;
            labelArea(one, two+1, recursive+1);
        }
    }

    if(one+1<range)
    {
        if(land[one+1][two]==2)
        {
            land[one+1][two] = ans;
            labelArea(one+1, two, recursive+1);
        }
    }
}
