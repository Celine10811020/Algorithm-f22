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
            for(i=1; i<4; i++)
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

    for(i=home; i<=end && end-i+1 >= 4-diJiCeng; i++)
    {
        arr[diJiCeng] = stone[i];
        paiLeiZuHe(stone, arr, i+1, end, diJiCeng+1, sum, ans, compare);
    }
}

int comparison(int *compare, int times)
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




/*
Description

Once upon a time, the brilliant archaeologist Andy and his team went on a treasure hunt to the Cajaboole Islands. After months of hunting, the team finally got to the location that was marked a red X on the map. Instead of discovering a treasure chest, an ancient stele came into sight. There was a poem carved into it which says,
Find four stones,
among those buried in the bones.
Sum up the weights,
matching T with no clone,
the path to the treasure will be shown.
Simply put, if you can find four stones that weigh T in total, you are granted access to the treasure. Now you have k stones, which weights w1, w2, ... , wk, respectively. As a smart programmer, can you help the team find out the total number of unique combinations of stones that match the statement? If there is no possible combination, outputFeiDooDoo_Zuo_Wei_Men.
Note that the two combinations are consider different if and only if there exists at least one element with different weights. For example (0, 1, -1, 3) and (1, 3, 0, -1) are consider the same combination.


Input
The first line contains two integers N, T, where N is the total number of stones Andy's team have and T is the target that you are going to make.
The next line contains N integers w1, w2, ... , wk, indicating the weight of each stone.

Constraints:
4≤n≤300
-10^9≤T≤10^9
-10^9≤wi≤10^9

Output
Please print the total number of the possible combinations, if there is no possible combination then print FeiDooDoo_Zuo_Wei_Men as shown in the description.

Sample Input 1
6 0
0 1 -1 0 -2 2

Sample Output 1
3
*/
