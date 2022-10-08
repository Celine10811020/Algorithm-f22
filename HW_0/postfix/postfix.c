#include <stdio.h>
#include <stdlib.h> //提供atoi函數

int main()
{
    int i;
    long long temp = 0;
    long long num[100];
    char input[100];

    while(scanf("%s", input) != EOF)
    {
        if(input[0] == '*')
        {
            temp = (num[i-2] * num[i-1]);
            num[i-2] = temp % 1000000007;
            i--;
        }else if(input[0] == '+')
        {
            temp = (num[i-2] + num[i-1]);
            num[i-2] = temp % 1000000007;
            i--;
        }else
        {
            temp = atoi(input); //atoi函數：把字串換成數字
            num[i] = temp % 1000000007;
            i++;
        }
    }

    printf("%lld", num[0]);

    return 0;
}

/*
Addition :
(A+B)%mod = (A%mod + B%mod)%mod

Subtraction :
(A-B)%mod = (A%mod + (-B)%mod)%mod

Multiplication :
(A*B)%mod = (A%mod * B%mod)%mod

Division :
(A/B)%mod = (A%mod * inv(B)%mod + mod)%mod, where inv(B) is inverse of B.
Now, how to calculate inv(B)%mod.
inv(B)%mod=B^-1 % mod=B^(mod-2)%mod, only if B and mod are COPRIME.
If mod is prime(like, 10^9+7), then above formula will work.(Why ?)
So, (A/B)%mod = (A*B^(mod-2))%mod, if B and mod are COPRIME.

Power :
(A^B)%mod=(A^(B%(mod-1)))%mod
*/
