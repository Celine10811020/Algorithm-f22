now = 0;
label = 1;
nodeLabel[now] = 1;
start = 0;
end = 0;
while(1)
{
  for(j=0; j<node; j++)
  {
    if(graph[now][j] > -1)
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

  now = nodeNext[start];
  start++;
}

if(label < node)
{
  printf("graph is disconnected\n");
}
