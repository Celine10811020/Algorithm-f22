#include <stdio.h>
#include <stdlib.h>

void changeCoin(long coinNum, long change);
long min(long one, long two);

long coin[30];
long coinChange[100001];

int main()
{
    long i, j, temp;
    long coinNum, customerNum, sum, change, ans;
    long *customer, **customerCoin, *customerChange;

    scanf("%ld", &coinNum);
    for(i=0; i<coinNum; i++)
    {
        scanf("%ld", &coin[i]);
    }

    scanf("%ld", &customerNum);
    customer = (long*)malloc(sizeof(long)*customerNum);
    customerCoin = (long**)malloc(sizeof(long*)*customerNum);
    for(i=0; i<customerNum; i++)
    {
        customerCoin[i] = (long*)malloc(sizeof(long)*coinNum);
    }

    for(i=0; i<customerNum; i++)
    {
        scanf("%ld", &customer[i]);

        for(j=0; j<coinNum; j++)
        {
            scanf("%ld", &temp);
            customerCoin[i][j] = temp;
        }
    }

    customerChange = (long*)malloc(sizeof(long)*customerNum);

    temp = 0;
    for(i=0; i<customerNum; i++)
    {
        sum = 0;
        for(j=0; j<coinNum; j++)
        {
            sum = sum + coin[j]*customerCoin[i][j];
        }
        change = sum - customer[i];
        customerChange[i] = change;

        if(change > temp)
        {
            temp = change;
        }
    }

    changeCoin(coinNum, temp);

    for(i=0; i<customerNum; i++)
    {
        temp = customerChange[i];
        ans = coinChange[temp];

        if(ans == 2147483647)
        {
            sum = 0;
            for(j=0; j<coinNum; j++)
            {
                sum = sum + customerCoin[i][j];
            }
            ans = sum;
        }
        printf("%ld\n", ans);
    }

    return 0;
}


void changeCoin(long coinNum, long change)
{
    long i, j;
    long one;

    coinChange[0] = 0;

    for(i=1; i<=change; i++)
    {
        coinChange[i] = 2147483647;

        one = 2147483647;
        for(j=0; j<coinNum; j++)
        {
            if(i-coin[j] >= 0)
            {
                one = min(one, coinChange[i-coin[j]] + 1);
            }
        }
        coinChange[i] = one;
    }
}

long min(long one, long two)
{
    long temp = one;
    if(two < temp)
    {
        temp = two;
    }
    return temp;
}
