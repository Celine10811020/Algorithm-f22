//®t¤@µ§WAªºPAC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char nameOne[300]; //200~300
char nameTwo[300];
char nodeName[500][300];
bool nodeLabel[500];
short nodeNext[500];
short nodeDepth[500];
short graph[500][500];
int result[1000];

int main()
{
    int i, j, k, temp;
    int node, edge;
    int one, two;
    int now, start, end, neighbor;
    int label, depth;
    int compare, length, max, index;

    index = 0;
    while(scanf("%d", &edge) != EOF)
    {
       	for(i=0; i<500; i++)
        {
            for(j=1; j<300; j++)
            {
                nodeName[i][j] = '\0';
            }
            graph[i][0] = 1;
            nodeLabel[i] = 0;
        }
        node = 0;

        for(i=0; i<edge; i++)
        {
            for(j=0; j<300; j++)
            {
                nameOne[j] = '\0';
                nameTwo[j] = '\0';
            }

            scanf("%s", nameOne);
            scanf("%s", nameTwo);

            //assign a node for nameOne
            for(j=0; j<node; j++)
            {
                compare = strcmp(nodeName[j], nameOne);

                if(compare == 0)
                {
                    break;
                }
            }

            if(j == node)
            {
				strcpy(nodeName[node], nameOne);
                node++;
            }
            one = j;

            //assign a node for nameTwo
            for(j=0; j<node; j++)
            {
                compare = strcmp(nodeName[j], nameTwo);

                if(compare == 0)
                {
                    break;
                }
            }

            if(j == node)
            {
				strcpy(nodeName[node], nameTwo);
                node++;
            }
            two = j;

            //build the graph
            temp = graph[one][0];
            graph[one][temp] = two;
            graph[one][0]++;

            temp = graph[two][0];
            graph[two][temp] = one;
            graph[two][0]++;
        }

        //test for the connection
        now = 0;
        label = 1;
        nodeLabel[now] = 1;
        nodeDepth[now] = 0;
        start = 0;
        end = 0;
        while(1)
        {
            temp = graph[now][0];

            for(j=1; j<temp; j++)
            {
                neighbor = graph[now][j];

                if(nodeLabel[neighbor] == 0)
                {
                    nodeLabel[neighbor] = 1;
                    nodeNext[end] = neighbor;
                    nodeDepth[neighbor] = nodeDepth[now] + 1;

                    end++;
                    label++;
                }
            }

            if(start == end)
            {
                break;
            }

            now = nodeNext[start];
            start++;
        }

        if(label < node) //graph is disconnected
        {
            printf("-1\n");
            result[index] = -1;
            index++;
            continue;
        }

        //now = nodeNext[end-1];
        //max = nodeDepth[now];
      	max = 0;
      	for(i=0; i<node; i++)
        {
          if(nodeDepth[i] > max)
          {
            max = nodeDepth[i];
          }
        }

        //find the longest depth
        for(i=1; i<node; i++)
        {
            //reset label
            for(j=0; j<node; j++)
            {
                nodeLabel[j] = 0;
            }

            now = i;
            nodeLabel[now] = 1;
            nodeDepth[now] = 0;
            start = 0;
            end = 0;
            while(1)
            {
                temp = graph[now][0];

                for(j=1; j<temp; j++)
                {
                    neighbor = graph[now][j];

                    if(nodeLabel[neighbor] != 1)
                    {
                        nodeLabel[neighbor] = 1;
                        nodeNext[end] = neighbor;
                        nodeDepth[neighbor] = nodeDepth[now] + 1;

                        end++;
                    }
                }

                if(start == end)
                {
                    break;
                }

                now = nodeNext[start];
                start++;
            }


          for(k=0; k<node; k++)
          {
            if(nodeDepth[k] > max)
            {
              max = nodeDepth[k];
            }
          }
        }

        printf("%d\n", max);
        result[index] = max;
        index++;
    }

    return 0;
}
