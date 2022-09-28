#include <stdio.h>
#include <stdlib.h> //包含malloc函數
#include <memory.h> //包含memset函數

int main()
{
    //輸入資料
    int i, j, range, people = 0;
    long long temp_i = 0;
    float temp_f = 0;
    float min = 1;
    long long *income, *income_people;
    float  *tax, *result;

    scanf("%d", &range);

    income = (long long*)malloc(sizeof(long long)*range); //動態陣列
    tax = (float*)malloc(sizeof(float)*range);
    memset(income, 0, range); //初始化陣列，都設為0
    memset(tax, 0, range);

    for(i=0; i<range; i++)
    {
        scanf("%lld", & temp_i);
        *(income+i) = (long long)(temp_i);
        scanf("%f", &temp_f);
        *(tax+i) = (float)(temp_f);
    }
    if(income[0] == 0) //第一個range可能是0
    {
        income[0] = 1;
    }

    scanf("%d", &people);

    income_people = (long long*)malloc(sizeof(long long)*people);
    memset(income_people, 0, people);


    for(i=0; i<people; i++)
    {
        scanf("%lld", &temp_i);
        *(income_people+i) = (long long)(temp_i);
    }

    //正式開始
    result = (float*)malloc(sizeof(float)*people);
    memset(result, 0, people);


    for(i=0; i<people; i++)
    {
        if(income_people[i] < income [0]) //個人所得小於第一個range的範圍
        {
            result[i] = 0;
        }
        for(j=range-1; j>=0; j--)
        {
            if(income_people[i] >= income[j])
            {
                if(j == 0) //第一個range可能不是從1開始
                {
                    temp_f = income_people[i] * tax[j];
                    result[i] = result[i] + temp_f;
                }else
                {
                    temp_i = income_people[i] - income[j] + 1;
                    temp_f = temp_i * tax[j];
                    result[i] = result[i] + temp_f;
                    income_people[i] = income[j] - 1;
                }
            }
        }
    }

    for(i=0; i<people; i++)
    {
        temp_i = result[i];

        temp_f = result[i] - temp_i;
        if(temp_f < min && temp_f != 0)
        {
            min = temp_f;
        }
    }





    if(min < 0.1)
    {
        for(i=0; i<people; i++)
        {
            printf("%.2f\n", result[i]);
        }
    }else if(min < 0.01)
    {
        for(i=0; i<people; i++)
        {
            printf("%.3f\n", result[i]);
        }
    }else if(min < 0.001)
    {
        for(i=0; i<people; i++)
        {
            printf("%.4f\n", result[i]);
        }
    }else if(min < 0.0001)
    {
        for(i=0; i<people; i++)
        {
            printf("%.5f\n", result[i]);
        }
    }else if(min < 0.000001)
    {
        for(i=0; i<people; i++)
        {
            printf("%.6f\n", result[i]);
        }
    }else
    {
        for(i=0; i<people; i++)
        {
            printf("%.1f\n", result[i]);
        }
    }



    //free the memory
    free(income);
    free(income_people);
    free(tax);
    free(result);


    return 0;
}
