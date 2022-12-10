#include <stdio.h>
#include <stdlib.h>

void mergeSortCost(int head, int tail);
void mergeCost(int head, int mid, int tail);

int nodeOne[124750];
int nodeTwo[124750];
int nodeCost[124750];
int result[124750];
int nodeNext[500];
int nodeLabel[500];
int graph[500][500];

int main()
{
    int i, j, temp, tmp, ans, index, temptemp;
    int start, end;
    int node, edge, outpost;
    int one, two, cost;
    int nodeNow;
    int label;

    index = 0;
    while((scanf("%d", &node)) != EOF)
    {
        scanf("%d", &edge);
        scanf("%d", &outpost);

        //reset array
        for(i=0; i<node; i++)
        {
            for(j=0; j<node; j++)
            {
                graph[i][j] = -1;
            }
            nodeLabel[i] = 0;
            nodeNext[i] = 0;
        }
        for(i=0; i<edge; i++)
        {
            nodeOne[i] = 0;
            nodeTwo[i] = 0;
            nodeCost[i] = 0;
        }

        for(i=0; i<edge; i++)
        {
            scanf("%d", &one);
            scanf("%d", &two);
            scanf("%d", &cost);

            graph[one][two] = cost;
            graph[two][one] = cost;

            nodeOne[i] = one;
            nodeTwo[i] = two;
            nodeCost[i] = cost;
        }

        //test for the connected component with outpost
        nodeNow = 0;
        label = 1;
        nodeLabel[nodeNow] = 1;
        start = 0;
        end = 0;
        while(1)
        {
            for(j=0; j<node; j++)
            {
                if(graph[nodeNow][j] > -1)
                {
                    if(nodeLabel[j] == 0)
                    {
                        nodeLabel[j] = 1;
                        nodeNext[end] = j;
                        end++;
                        label++;
                    }
                }
            }

            if(start == end)
            {
                break;
            }

            nodeNow = nodeNext[start];
            start++;
        }

        temp = label;
        label = 600;
        for(i=0; i<outpost; i++)
        {
            scanf("%d", &tmp);
            nodeLabel[tmp] = label;
            label++;
        }

        if(temp < node) //graph is disconnected
        {
            result[index] = -1;
            index++;
            continue;
        }

        //test for the connected component without outpost
        if(outpost < node)
        {
            nodeNow = 0;
            while(nodeLabel[nodeNow] >= 600 && nodeNow<node)
            {
                nodeNow++;
            }

            label = 1;
            nodeLabel[nodeNow] = 2;
            start = 0;
            end = 0;
            while(1)
            {
                for(j=0; j<node; j++)
                {
                    if(graph[nodeNow][j] > -1)
                    {
                        if(nodeLabel[j] == 1)
                        {
                            nodeLabel[j] = 2;
                            nodeNext[end] = j;
                            end++;
                            label++;
                        }
                    }
                }

                if(start == end)
                {
                    break;
                }

                nodeNow = nodeNext[start];
                start++;
            }
        }

        if(label < node-outpost)
        {
            result[index] = -1;
            index++;
            continue;
        }

        //put each node into different set
        label = 0;
        for(i=0; i<node; i++)
        {
            if(nodeLabel[i] == 2)
            {
                nodeLabel[i] = label;
                label++;
            }
        }

        //MST by Kruskal
        mergeSortCost(0, edge-1);

        //build the MST without outpost
        ans = 0;
        label = 2;
        for(i=0; i<edge; i++)
        {
            one = nodeOne[i];
            two = nodeTwo[i];

            if(nodeLabel[one]>=600 || nodeLabel[two]>=600) //remove outpost
            {
                continue;
            }else //land connected without outpost
            {
                if(nodeLabel[one] != nodeLabel[two])
                {
                    ans = ans + nodeCost[i];
                    temp = nodeLabel[one];

                    for(j=0; j<node; j++)
                    {
                        if(nodeLabel[two]==nodeLabel[j] && j!=two)
                        {
                            nodeLabel[j] = temp;
                        }
                    }

                    nodeLabel[two] = temp;
                }
            }
        }

        //build the MST with outpost
        for(i=0; i<edge; i++)
        {
            one = nodeOne[i];
            two = nodeTwo[i];

            if(nodeLabel[one] != nodeLabel[two])
            {
                ans = ans + nodeCost[i];
                temp = nodeLabel[one];

                for(j=0; j<node; j++)
                {
                    if(nodeLabel[two]==nodeLabel[j] && j!=two)
                    {
                        nodeLabel[j] = temp;
                    }
                }
                nodeLabel[two] = temp;
            }
        }

        result[index] = ans;
        index++;
    }

    for(i=0; i<index; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}

void mergeCost(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;
    int *leftSubOne = (int*)malloc(sizeof(int)*(lenA+1));
    int *leftSubTwo = (int*)malloc(sizeof(int)*(lenA+1));
    int *leftSubCost = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSubOne = (int*)malloc(sizeof(int)*(lenB+1));
    int *rightSubTwo = (int*)malloc(sizeof(int)*(lenB+1));
    int *rightSubCost = (int*)malloc(sizeof(int)*(lenB+1));

    int leftIndexCost = 0;
    int rightIndexCost = 0;

    for(leftIndexCost=0; leftIndexCost<lenA; leftIndexCost++)
    {
        leftSubOne[leftIndexCost] = nodeOne[head + leftIndexCost];
        leftSubTwo[leftIndexCost] = nodeTwo[head + leftIndexCost];
        leftSubCost[leftIndexCost] = nodeCost[head + leftIndexCost];
    }

    for(rightIndexCost=0; rightIndexCost<lenB; rightIndexCost++)
    {
        rightSubOne[rightIndexCost] = nodeOne[mid + 1 + rightIndexCost];
        rightSubTwo[rightIndexCost] = nodeTwo[mid + 1 + rightIndexCost];
        rightSubCost[rightIndexCost] = nodeCost[mid + 1 + rightIndexCost];
    }

    leftSubCost[lenA] = 2147483647;
    rightSubCost[lenB] = 2147483647;

    leftIndexCost = 0;
    rightIndexCost = 0;

    int writePointer=0;
    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if (leftSubCost[leftIndexCost] <= rightSubCost[rightIndexCost])
        {
            nodeOne[writePointer] = leftSubOne[leftIndexCost];
            nodeTwo[writePointer] = leftSubTwo[leftIndexCost];
            nodeCost[writePointer] = leftSubCost[leftIndexCost++];
        }else
        {
            nodeOne[writePointer] = rightSubOne[rightIndexCost];
            nodeTwo[writePointer] = rightSubTwo[rightIndexCost];
            nodeCost[writePointer] = rightSubCost[rightIndexCost++];
        }
    }

    free(leftSubOne);
    free(leftSubTwo);
    free(leftSubCost);
    free(rightSubOne);
    free(rightSubTwo);
    free(rightSubCost);
}

void mergeSortCost(int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        mergeSortCost(head, mid);
        mergeSortCost(mid+1, tail);
        mergeCost(head, mid, tail);
    }
}
