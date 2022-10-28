#include <stdio.h>

int flower[20000];
int display[20000];

int main()
{
    int i, j;
    int num, ans;

    scanf("%d", &num);

    for(i=0; i<num; i++)
    {
        scanf("%d", &flower[i]);
    }

    display[0] = flower[0];
    for(i=1; i<num; i++)
    {
        display[i] = 10001;
    }

    ans=1;
    for(i=1; i<num; i++)
    {
        j=0;
        while(flower[i]>display[j])
        {
            j++;
        }

        if(display[j] == 10001)
        {
            ans++;
        }
        display[j] = flower[i];
    }

    printf("%d", ans);

    return 0;
}
