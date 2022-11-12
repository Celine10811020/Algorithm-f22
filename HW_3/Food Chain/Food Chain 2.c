//用遞迴寫了，還是TLE的PAC @@

#include <stdio.h>
#include <stdlib.h>

int buildTree(int inStart, int inEnd, int postStart, int postEnd);

int speices[2000001];
int postOrder[2000000];
int inOrder[2000000];
int tree[2000001][3] = {};
/*
tree[i][0] = parent;
tree[i][1] = left;
tree[i][2] = right;
*/

int main()
{
    int i, temp;
    int num;
    int predator, foodOne, foodTwo, ans;

    scanf("%d", &num);
    for(i=1; i<=num; i++)
    {
        scanf("%d", &speices[i]);
    }
    for(i=0; i<num; i++)
    {
        scanf("%d", &inOrder[i]);
    }
    for(i=0; i<num; i++)
    {
        scanf("%d", &postOrder[i]);
    }

    buildTree(0, num-1, 0, num-1);

    ans = 0;
    for(i=1; i<=num; i++)
    {
        predator = speices[i];

        if(tree[i][1] != 0)
        {
            temp = tree[i][1];
            foodOne = speices[temp];

            if(foodOne > predator)
            {
                ans++;
            }
        }
        if(tree[i][2] != 0)
        {
            temp = tree[i][2];
            foodTwo = speices[temp];

            if(foodTwo > predator)
            {
                ans++;
            }
        }
    }

    printf("%d", ans);

    return 0;
}

int buildTree(int inStart, int inEnd, int postStart, int postEnd)
{
    int length = inEnd - inStart + 1;

    if(length == 1)
    {
        return postOrder[postStart];
    }else if(length < 1)
    {
        return 0;
    }

    int root = postOrder[postEnd];

    int i;
    for(i=inStart; i<=inEnd; i++)
    {
        if(inOrder[i] == root)
        {
            break;
        }
    }
    int lenA = i - inStart;

    tree[root][1] = buildTree(inStart, inStart+lenA-1, postStart, postStart+lenA-1);
    tree[root][2] = buildTree(inStart+lenA+1, inEnd, postStart+lenA, postEnd-1);

    return root;
}
