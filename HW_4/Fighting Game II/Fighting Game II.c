#include <stdio.h>

int main()
{
    int i, ans, temp;
    int gongJiGuan, xianZaiZaiDiJiGuan, zueiHouKeYiDaoDiJiGuan;
    int level[2][25001];

    scanf("%d", &gongJiGuan);

    for(i=1; i<=gongJiGuan; i++)
    {
        scanf("%d", &level[0][i]);
        level[1][i] = i + level[0][i];
    }

    xianZaiZaiDiJiGuan = 1;
    zueiHouKeYiDaoDiJiGuan = level[1][1];
    ans = 1;
    while(xianZaiZaiDiJiGuan < gongJiGuan)
    {
        temp = zueiHouKeYiDaoDiJiGuan;
        for(i=xianZaiZaiDiJiGuan+1; i<=zueiHouKeYiDaoDiJiGuan; i++)
        {
            if(temp < level[1][i])
            {
                temp = level[1][i];
                xianZaiZaiDiJiGuan = i;
            }

            if(temp >= gongJiGuan)
            {
                xianZaiZaiDiJiGuan = temp;
                break;
            }
        }

        zueiHouKeYiDaoDiJiGuan = temp;

        ans++;
    }

    printf("%d", ans);

    return 0;
}
