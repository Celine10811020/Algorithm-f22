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
Description
Postfix notation is a mathematical notation in which operators follow their operands. It does not need any parentheses to indicate the order of operations when evaluating the values of the expression. It is found that using postfix notation may lead to faster calculations and can save more memory compared to other mathematical notations during evaluation.
Now, given a postfix expression, please write a program to calculate the value of it. Since the answer might be very large, please output the answer modulo 10^9 + 7.


Input
Each input will contain one mathematical expression presented in the postfix notation. Each integer in the expression would be a 32-bit integer, while operators OO will be one of \{+,*\}{+,∗}. Two consecutive operands or operators will be seprated by a single space.

Constraints:
1 <= X <= 2^31 - 1
O∈{+, ∗}

Output
Output an integer, the result of the expression.


Sample Input 1
3 8 + 5 6 + *

Sample Output 1
121

Sample Input 2
2147483647 2147483647 *

Sample Output 2
850618742
*/


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