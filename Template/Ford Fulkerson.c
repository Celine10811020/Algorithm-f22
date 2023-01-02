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
