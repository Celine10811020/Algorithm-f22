#include <stdio.h>
#include <stdlib.h>

void findLand(int i, int j);

char graph[300][300];
int zhi, heng;

int main()
{
//printf("11\n");
    int i, j, temp;
    int ans;
    int goOn;

    scanf("%d", &zhi);
    scanf("%d", &heng);
//printf("18\n");
    for(i=0; i<zhi; i++)
    {
//printf("21\n");
        scanf("%c", &temp);

        for(j=0; j<heng; j++)
        {
//printf("24\n");
            scanf("%c", &graph[i][j]);
//printf("26\n");
        }
        //scanf("%c", &temp);
    }

    /*printf("graph\n");
    for(i=0; i<zhi; i++)
    {
        for(j=0; j<heng; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

  	ans = 0;
    goOn = 1;
    while(goOn)
    {
        goOn = 0;

        for(i=0; i<zhi; i++)
        {
            for(j=0; j<heng; j++)
            {
                if(graph[i][j] == 49)
                {
                    //printf("land: (%d, %d)\n", i, j);

                    findLand(i, j);

                    ans++;
                    goOn = 1;
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}

void findLand(int i, int j)
{
    graph[i][j] = 50;

    if(i-1 >= 0)
    {
        if(graph[i-1][j] == 49)
        {
            findLand(i-1, j);
        }
    }

    if(j-1 >= 0)
    {
        if(graph[i][j-1] == 49)
        {
			findLand(i, j-1);
        }
    }

    if(i+1 < zhi)
    {
        if(graph[i+1][j] == 49)
        {
            findLand(i+1, j);
        }
    }

    if(j+1 < heng)
    {
        if(graph[i][j+1] == 49)
        {
            findLand(i, j+1);
        }
    }
}