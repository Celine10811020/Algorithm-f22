#include <stdio.h>
#include <stdlib.h>

int fighting(int start, int end);
int min(int one, int two);

int enemy[25001];
int memLevel[250001] = {};

int main()
{
    int i;
    int level, ans;

    scanf("%d", &level);

    for(i=1; i<=level; i++)
    {
        scanf("%d", &enemy[i]);
    }

    ans = fighting(0, level);

    printf("%d", ans);

    return 0;
}

int fighting(int start, int end)
{
    int one, two, three;

    if(memLevel[start] != 0)
    {
        return memLevel[start];
    }else if(start < end-1)
    {

        one = enemy[start] + fighting(start+1, end);
        two = enemy[start] + fighting(start+2, end);

        three = min(one, two);

        memLevel[start] = three;

        return three;

    }else if(start == end || start == end-1)
    {
        return enemy[start];

    }else
    {
        return 10000;
    }
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
