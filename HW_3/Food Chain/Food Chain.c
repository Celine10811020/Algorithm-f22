//TLE的PAC
//如果建構二元數是用遞迴，應該可以AC

#include <stdio.h>

int buildTree(int start, int end);

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
    int i, j, k, m, temp, left, right, self;
    int num , findRight, findLeft;
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

    j=num;
    findRight = 0;
    for(j=num-1; j>=0; j--)
    {
        self = postOrder[j];
        right = postOrder[j-1];

        for(i=0; i<num; i++)
        {
            if(inOrder[i] == self)
            {
                for(k=i+1; k<num; k++)
                {
                    if(inOrder[k] == right)
                    {
                        findRight = 1;
                        break;
                    }
                }
                break;
            }
        }

        if(findRight == 1)
        {
            tree[self][2] = right;
            tree[right][0] = self;
            findRight = 0;
        }
    }

    j=num;
    findLeft = 0;
    for(j=0; j<num; j++)
    {
        left = inOrder[j];
        while(left==postOrder[num-1] || tree[left][0]!=0)
        {
            j++;
            left = inOrder[j];
        }

        for(m=1; m<num-j; m++)
        {
            left = inOrder[j];
            self = inOrder[j+m];

            for(i=0; i<num; i++)
            {
                if(postOrder[i] == left)
                {
                    for(k=i+1; k<num; k++)
                    {
                        if(postOrder[k] == self)
                        {
                            findLeft = 1;
                            break;
                        }
                    }
                    break;
                }
            }

            if(findLeft == 1)
            {
                tree[self][1] = left;
                tree[left][0] = self;
                findLeft = 0;
                break;
            }
        }
    }

    /*for(i=1; i<=num; i++)
    {
        printf("%d: %d %d %d\n", i, tree[i][0], tree[i][1], tree[i][2]);
    }*/

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
