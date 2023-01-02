//ford fulkerson
for(i=0; i<node; i++)
{
  for(j=0; j<node; j++)
  {
    flow[i][j] = 0;
  }
}

//find path by bfs
max = 0;
goOn = bfs(node, nodeS, nodeT);
while(goOn)
{
  increment = 2147483647;

  for(i=node-1; nodePath[i]>=0; i=nodePath[i])
  {
    nodePrevious = nodePath[i];

    temp = graph[nodePrevious][i] - flow[nodePrevious][i];

    if(temp < increment)
    {
      increment = temp;
    }
  }

  for(i=node-1; nodePath[i]>=0; i=nodePath[i])
  {
    nodePrevious = nodePath[i];

    flow[nodePrevious][i] = flow[nodePrevious][i] + increment;
    flow[i][nodePrevious] = flow[i][nodePrevious] - increment;
  }

  //Adding the path flows
  max = max + increment;
  goOn = bfs(node, nodeS, nodeT);
}

int bfs(int node, int nodeS, int nodeT)
{
  int i;
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
    for(i=0; i<node; i++)
    {
      if((graph[now][i]-flow[now][i]) > 0)
      {
        if(nodeLabel[i] == 0)
        {
          nodeLabel[i] = 1;
          nodeNext[end] = i;
          nodePath[i] = now;
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
