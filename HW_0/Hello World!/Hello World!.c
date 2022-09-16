#include <stdio.h>

int main()
{
    int input = 0;

    scanf("%d", &input);

    if(input == 1)
    {
        printf("Hello world!");
    }else if(input == 2)
    {
        printf("Hello world!Hello world!");
    }
    return 0;
}


/*
Hello World!

Description
The classic task to start a programming course.


Input
There will be an integerNon a single line of input, with the value either1or2.


Output
Output NN times of "Hello world!".


Sample Input 1
1

Sample Output 1
Hello world!

Sample Input 2
2

Sample Output 2
Hello world!Hello world!
*/
