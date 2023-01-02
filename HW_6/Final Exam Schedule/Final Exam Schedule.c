//TLE的PAC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int bfs(int node, int nodeS, int nodeT);

int nodeLabel[2003];
int nodeNext[2003];
int graph[2003][2003];
int flow[2003][2003];
int nodePath[2003]; //index: nodeNow, value: nodePrevious
int nodeTimeSlot[1003];
int result[100000];

int main()
{
    int i, j, k, m, temp;
    int numTimeSlot, numStudent, capacity, numCombination;
    int indexStudent, timeSlot;
    int node, nodeS, nodeT, nodePrevious;
    int increment;
    int goOn, max, index;

  	index = 0;
    node = 2002;
    while(scanf("%d", &numTimeSlot) != EOF)
    {
        for(i=0; i<node; i++)
        {
            for(j=0; j<node; j++)
            {
                graph[i][j] = 0;
            }
        }

        scanf("%d", &numStudent);
        scanf("%d", &capacity);
        scanf("%d", &numCombination);

        //flow from nodeS to nodeT
        node = numStudent + numTimeSlot + 2;
        nodeS = numStudent + numTimeSlot;
        nodeT = numStudent + numTimeSlot + 1;

        for(i=0; i<numStudent; i++)
        {
            scanf("%d", &indexStudent);
            scanf("%d", &numTimeSlot);

            for(j=0; j<numTimeSlot; j++)
            {
                scanf("%d", &timeSlot);

                timeSlot = timeSlot + numStudent;

                graph[indexStudent][timeSlot] = 1;
            }

            graph[nodeS][indexStudent] = 1;
        }

        numTimeSlot = 0;
        for(i=0; i<numCombination; i++)
        {
            for(j=0; j<numTimeSlot; j++)
            {
                temp = nodeTimeSlot[j];

                graph[temp][nodeT] = 0;
            }

            scanf("%d", &numTimeSlot);

            for(j=0; j<numTimeSlot; j++)
            {
                scanf("%d", &timeSlot);

                timeSlot = timeSlot + numStudent;

                nodeTimeSlot[j] = timeSlot;

                graph[timeSlot][nodeT] = capacity;
            }

            //ford fulkerson
            for(k=0; k<node; k++)
            {
                for(m=0; m<node; m++)
                {
                    flow[k][m] = 0;
                }
            }

            //find path by bfs
            max = 0;
            goOn = bfs(node, nodeS, nodeT);
            while(goOn)
            {
                increment = 2147483647;
                for(k=node-1; nodePath[k]>=0; k=nodePath[k])
                {
                    nodePrevious = nodePath[k];

                    temp = graph[nodePrevious][k] - flow[nodePrevious][k];

                    if(temp < increment)
                    {
                        increment = temp;
                    }
                }

                for(k=node-1; nodePath[k]>=0; k=nodePath[k])
                {
                    nodePrevious = nodePath[k];

                    flow[nodePrevious][k] = flow[nodePrevious][k] + increment;
                    flow[k][nodePrevious] = flow[k][nodePrevious] - increment;
                }

                //Adding the path flows
                max = max + increment;
                goOn = bfs(node, nodeS, nodeT);
            }

            //printf("Max Flow: %d\n", numStudent - max);
            result[index] = numStudent - max;
            index++;
        }
    }

  	for(i=0; i<index; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}

int bfs(int node, int nodeS, int nodeT)
{
    int i, j;
    int now;
    int start = 0;
    int end = 0;

    //reset nodeLabel
    for(i=0; i<node; i++)
    {
        nodeLabel[i] = 0;
    }

    now = nodeS;
    nodeLabel[now] = 1;
    nodePath[now] = -1;
    while(1)
    {
        for(j=0; j<node; j++)
        {
            if((graph[now][j]-flow[now][j]) > 0)
            {
                if(nodeLabel[j] == 0)
                {
                    nodeLabel[j] = 1;
                    nodeNext[end] = j;
                    nodePath[j] = now;
                    end++;
                }
            }
        }

        if(start == end)
        {
            break;
        }

        now = nodeNext[start];
        start++;
    }

    if(nodeLabel[nodeT] == 1)
    {
        return 1;
    }else
    {
        return 0;
    }
}
