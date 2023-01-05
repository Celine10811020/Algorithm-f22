#include <stdio.h>
#include <stdlib.h>

void merge(int head, int mid, int tail);
void mergeSort(int head, int tail);

int graph[500][500];
int nodeOne[124750];
int nodeTwo[124750];
int nodeCost[124750];
int nodeLabel[500];
int nodeNext[500];

int main()
{
    int i, j;
    int one, two, cost;
    int node, edge, label;
    int now, start, end;
    int special;
    int ans;

    while(scanf("%d", &node) != EOF)
    {
        ans = 0;
        for(i=0; i<node; i++)
        {
            for(j=0; j<node; j++)
            {
                graph[i][j] = 0;
            }

            nodeLabel[i] = 0;
        }

        scanf("%d", &edge);

        for(i=0; i<edge; i++)
        {
            scanf("%d", &one);
            scanf("%d", &two);
            scanf("%d", &cost);

            nodeOne[i] = one;
            nodeTwo[i] = two;
            nodeCost[i] = cost;

            graph[one][two] = 1;
            graph[two][one] = 1;
        }

        scanf("%d", &special);

        start = 0;
        end = 0;
        label = 1;
        now = 0;
        nodeLabel[now] = 1;
        while(1)
        {
            for(i=0; i<node; i++)
            {
                if(graph[now][i]==1 && nodeLabel[i]==0)
                {
                    nodeLabel[i] = 1;
                    nodeNext[end] = i;
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

        if(label < node)
        {
            printf("-1\n");
            continue;
        }

        for(i=0; i<node; i++)
        {
            nodeLabel[i] = i;
        }

        mergeSort(0, edge-1);

        for(i=0; i<edge; i++)
        {
            one = nodeOne[i];
            two = nodeTwo[i];

            if(nodeLabel[one] != nodeLabel[two])
            {
                label = nodeLabel[one];

                for(j=0; j<node; j++)
                {
                    if(nodeLabel[j] == label)
                    {
                        nodeLabel[j] = nodeLabel[two];
                    }
                }

                ans = ans + nodeCost[i];
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

void merge(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - mid;
    int *leftSubOne = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSubOne = (int*)malloc(sizeof(int)*(lenB+1));
    int *leftSubTwo = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSubTwo = (int*)malloc(sizeof(int)*(lenB+1));
    int *leftSubCost = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSubCost = (int*)malloc(sizeof(int)*(lenB+1));

    int leftIndex, rightIndex, writePointer;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSubOne[leftIndex] = nodeOne[leftIndex + head];
        leftSubTwo[leftIndex] = nodeTwo[leftIndex + head];
        leftSubCost[leftIndex] = nodeCost[leftIndex + head];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSubOne[rightIndex] = nodeOne[rightIndex + mid + 1];
        rightSubTwo[rightIndex] = nodeTwo[rightIndex + mid + 1];
        rightSubCost[rightIndex] = nodeCost[rightIndex + mid + 1];
    }

    leftSubCost[lenA] = 2147483647;
    rightSubCost[lenB] = 2147483647;

    leftIndex = 0;
    rightIndex = 0;

    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if(leftSubCost[leftIndex] <= rightSubCost[rightIndex])
        {
            nodeOne[writePointer] = leftSubOne[leftIndex];
            nodeTwo[writePointer] = leftSubTwo[leftIndex];
            nodeCost[writePointer] = leftSubCost[leftIndex];
            leftIndex++;
        }else
        {
            nodeOne[writePointer] = rightSubOne[rightIndex];
            nodeTwo[writePointer] = rightSubTwo[rightIndex];
            nodeCost[writePointer] = rightSubCost[rightIndex];
            rightIndex++;
        }
    }

    free(leftSubOne);
    free(rightSubOne);
    free(leftSubTwo);
    free(rightSubTwo);
    free(leftSubCost);
    free(rightSubCost);
}

void mergeSort(int head, int tail)
{
    int mid;

    if(head < tail)
    {
        mid = (head+tail) / 2;

        mergeSort(head, mid);
        mergeSort(mid+1, tail);

        merge(head, mid, tail);
    }
}