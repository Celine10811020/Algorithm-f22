//TLE的PAC

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int one, int two);

short graph[10000][10000];
short graphEdge[10000][10000];
bool nodeLabel[10000];
int nodeDistance[10000];
int result[1000];

int main()
{
    int i, j, temp;
    int one, two, cost;
    int node, edge;
    int now, next, mininum;
    int special;
    int ans;
    int goOn, index;

    index = 0;
    while(scanf("%d", &node) != EOF)
    {
        ans = 0;
        for(i=0; i<node; i++)
        {
            for(j=0; j<node; j++)
            {
                graph[i][j] = -1;
            }

            nodeLabel[i] = 0;
            nodeDistance[i] = 2147483647;
            graphEdge[i][0] = 1;
        }

        scanf("%d", &edge);

        for(i=0; i<edge; i++)
        {
            scanf("%d", &one);
            scanf("%d", &two);
            scanf("%d", &cost);

            if(graph[one][two] != -1)
            {
                temp = graph[one][two];

                if(cost < temp)
                {
                    graph[one][two] = cost;
                    graph[two][one] = cost;
                }
            }else
            {
                temp = graphEdge[one][0];
                graphEdge[one][temp] = two;
                graphEdge[one][0]++;

                temp = graphEdge[two][0];
                graphEdge[two][temp] = one;
                graphEdge[two][0]++;

                graph[one][two] = cost;
                graph[two][one] = cost;
            }
        }
//printf("70\n");
        scanf("%d", &special);

        goOn = 1;
        now = special;
        nodeLabel[now] = 1;
        nodeDistance[now] = 0;
        while(goOn)
        {
            goOn = 0;
//printf("80\n");
            temp = graphEdge[now][0];

            for(i=1; i<temp; i++)
            {
                next = graphEdge[now][i];

                if(nodeLabel[next]==0)
                {
                    one = nodeDistance[now] + graph[now][next];
                    two = nodeDistance[next];

                    nodeDistance[next] = min(one, two);
                }
            }

            /*if(goOn == 0)
            {
                break;
            }*/
//printf("100\n");
            mininum = 2147483647;
            for(i=0; i<node; i++)
            {
                if(nodeLabel[i] == 0)
                {
                    if(nodeDistance[i] < mininum)
                    {
                        goOn = 1;
                        now = i;
                        mininum = nodeDistance[i];
                    }
                }
            }

            nodeLabel[now] = 1;
        }

        for(i=0; i<node; i++)
        {
            if(nodeDistance[i] == 2147483647)
            {
                ans--;
            }else
            {
                ans = ans + nodeDistance[i];
            }
        }

        //printf("%d\n", ans);

        result[index] = ans;
        index++;
    }

    for(i=0; i<index; i++)
    {
        printf("%d", result[i]);

        if(i < index-1)
        {
            printf("\n");
        }
    }

    return 0;
}

int min(int one, int two)
{
    if(one < two)
    {
        return one;
    }else
    {
        return two;
    }
}