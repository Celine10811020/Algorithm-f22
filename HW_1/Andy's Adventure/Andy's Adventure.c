//TLE的PAC

#include <stdio.h>
#include <stdlib.h>

void paiLeiZuHe(int *stone, int *arr, int home, int end, int diJiCeng, int sum, int *ans, int *compare);
int comparison(int *compare, int times);

int main()
{
    int i, temp = 0;
    int num, sum = 0;
    int ans[1], arr[4];
    int compare[400000] = {};
    int *stone;

    scanf("%d", &num);
    scanf("%d", &sum);

    stone = (int*)malloc(sizeof(int)*num);
    for(i=0; i<num; i++)
    {
        scanf("%d", &temp);
        stone[i] = temp;
    }

    ans[0] = 0;
    paiLeiZuHe(stone, arr, 0, num-1, 0, sum, ans, compare);

    if(ans[0] == 0)
    {
        printf("FeiDooDoo_Zuo_Wei_Men");
    }else
    {
        printf("%d", ans[0]);
    }

    free(stone);

    return 0;
}

//排列組合（原本完整陣列，nC4後的陣列，陣列起始位置，陣列結束位置，排到第幾層(有幾個)，希望加總的最終數字，一共有幾組答案了，將答案存到另一個二維陣列中）
void paiLeiZuHe(int *stone, int *arr, int home, int end, int diJiCeng, int sum, int *ans, int *compare)
{
    int i, j, tmp, key=0;
    int temp[4];
    int summation = 0;

    if (diJiCeng == 4)
    {
        tmp = ans[0];
        for(i=0; i<4; i++)
        {
            summation = summation + arr[i];
        }
        if(sum == summation)
        {
            for(i=0; i<4; i++)
            {
                temp[i] = arr[i];
            }
            for(i=1; i<4; i++) //insertion sort
            {
                key = temp[i];
                j = i - 1;
                while(key < temp[j] && j >= 0)
                {
                    temp[j+1] = temp[j];
                    j--;
                }
                temp[j+1] = key;
            }
            for(i=0; i<4; i++)
            {
                compare[tmp*4 + i] = temp[i];
            }
            tmp = comparison(compare, tmp);
            if(tmp == 0)
            {
                ans[0] = ans[0] + 1;
            }
        }
        return;
    }

    //遞迴
    for(i=home; i<=end && end-i+1 >= 4-diJiCeng; i++)
    {
        arr[diJiCeng] = stone[i];
        paiLeiZuHe(stone, arr, i+1, end, diJiCeng+1, sum, ans, compare);
    }
}

int comparison(int *compare, int times) //檢查找出來的組合是否有重複
{
    int i, j, temp;

    if(times == 0)
    {
        return 0;
    }

    for(j=0; j<times; j++)
    {
        temp = 0;
        for(i=0; i<4; i++)
        {
            //二維陣列其實算是一維陣列，第二行、第三行... 是直接接在第一行後面
            if(compare[times*4 + i] == compare[j*4 + i])
            {
                temp++;
            }
        }
        if(temp == 4)
        {
            return 1;
        }
    }

    return 0;
}
