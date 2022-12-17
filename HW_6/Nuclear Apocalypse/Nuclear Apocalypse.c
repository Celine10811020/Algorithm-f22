#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

short nodeShelter[14];
short nodeLocation[10000];
short nodeLabel[10000];
int nodeDose[10000];
short graph[10000][8000];
short graphDose[10000][10000];

int main()
{
    int i, temp;
    int node, edge, shelter;
    int one, two, dose;
    int now;
    int min, index;
    int tempDose, tempNext;

    index = 0;
    while(scanf("%d", &node) != EOF)
    {
        for(i=0; i<node; i++)
        {
          	nodeLabel[i] = 0;
            nodeDose[i] = 2147483647;
        }

        for(i=0; i<node; i++)
        {
            graph[i][0] = 1;
        }

        scanf("%d", &edge);
        scanf("%d", &shelter);

        for(i=0; i<node; i++)
        {
            scanf("%d", &nodeLocation[i]);
        }

        for(i=0; i<edge; i++)
        {
            scanf("%d", &one);
            scanf("%d", &two);
            scanf("%d", &dose);

            temp = graph[one][0];
            graph[one][temp] = two;
            graph[one][0]++;

            temp = graph[two][0];
            graph[two][temp] = one;
            graph[two][0]++;

            graphDose[one][two] = dose;
            graphDose[two][one] = dose;
        }

        for(i=0; i<shelter; i++)
        {
            scanf("%d", &temp);
            nodeShelter[i] = temp;
            nodeLabel[temp] = 2;
        }

        scanf("%d", &now);

        nodeLabel[now] = 1;
        nodeDose[now] = nodeLocation[now];
        while(1)
        {
            temp = graph[now][0];

            //更新node資訊
            for(i=1; i<temp; i++)
            {
                tempNext = graph[now][i];

                if(nodeLabel[tempNext] != 1)
                {
                    tempDose = nodeDose[now] + graphDose[now][tempNext] + nodeLocation[tempNext];

                    if(tempDose < nodeDose[tempNext])
                    {
                        nodeDose[tempNext] = tempDose;
                    }
                }
            }

            min = 2147483647;
            for(i=0; i<node; i++)
            {
                if(nodeLabel[i] != 1)
                {
                    if(nodeDose[i] < min)
                    {
                        min = nodeDose[i];
                        now = i;
                    }
                }
            }

            if(min == 2147483647)
            {
                break;
            }

            if(nodeLabel[now] == 2)
            {
                break;
            }

            nodeLabel[now] = 1;
        }

        if(min == 2147483647)
        {
          	printf("-1\n");
        }else
        {
          	printf("%d\n", nodeDose[now]);
        }
    }

    return 0;
}
