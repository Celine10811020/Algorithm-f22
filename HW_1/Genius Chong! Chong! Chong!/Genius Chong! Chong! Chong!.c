//TLE的PAC

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //提供strcmp函數


int main()
{
    long long i=0, j=0, k=0, row=0, temp=0, tmp=0, goOn=0;
    char tempArr[1]= {};
    char rank[4][4] = {};
    char **name = NULL;
    long long **score = NULL;
    long long *group = NULL;

    scanf("%d", &row);

    for(i=0; i<4; i++)
    {
        scanf("%s", rank[i]);
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            switch(rank[i][j])
            {
                case 'H':
                    rank[i][j] = 0;
                    break;
                case 'W':
                    rank[i][j] = 1;
                    break;
                case 'I':
                    rank[i][j] = 2;
                    break;
                case 'E':
                    rank[i][j] = 3;
                    break;
            }
        }
    }

    //動態二維陣列
    name = (char**)malloc(sizeof(char*)*row); //row*20
    for(i=0; i<row; i++)
    {
        name[i] = (char*)malloc(sizeof(char)*20);
    }

    score = (long long**)malloc(sizeof(long long*)*row); //row*4
    for(i=0; i<row; i++)
    {
        score[i] = (long long*)malloc(sizeof(long long)*4);
    }

    //輸入資料
    for(i=0; i<row; i++)
    {
        scanf("%s", name[i]);
        for(j=0; j<4; j++)
        {
            scanf("%lld", &temp);
            score[i][j] = temp;
        }
    }

    //分組
    group = (long long*)malloc(sizeof(long long)*row);
    for(i=0; i<row; i++)
    {
        temp=0, tmp=0;
        for(j=0; j<4; j++)
        {
            if(temp < score[i][j])
            {
                temp = score[i][j];
                group[i] = tmp;
            }
            tmp++;
        }
    }

    /*printf("\nfen hao zu\n");
    for(i=0; i<row; i++)
    {
        printf("%s\t\t", name[i]);
        for(j=0; j<4; j++)
        {
            printf("%d\t", score[i][j]);
        }
        printf("group:%d\n", group[i]);
    }*/

    temp=0;
    for(j=0; j<4; j++) //先按組別排好
    {
        for(i=0; i<row; i++)
        {
            if(group[i] == rank[j][0])
            {
                if(temp<i)
                {
                    for(k=0; k<4; k++)
                    {
                        tmp = score[temp][k];
                        score[temp][k] = score[i][k];
                        score[i][k] = tmp;
                    }
                    for(k=0; k<20; k++)
                    {
                        tempArr[0] = name[temp][k];
                        name[temp][k] = name[i][k];
                        name[i][k] = tempArr[0];
                    }
                    tmp = group[temp];
                    group[temp] = group[i];
                    group[i] = tmp;
                }
                temp++;
            }
        }
    }

    /*printf("\nfen zu pai hao\n");
    for(i=0; i<row; i++)
    {
        printf("%s\t\t", name[i]);
        for(j=0; j<4; j++)
        {
            printf("%d\t", score[i][j]);
        }
        printf("group:%d\n", group[i]);
    }*/

    /*for(i=0; i<row; i++)
    {
        printf("%s\n", name[i]);
    }*/


    while(goOn == 0) //再按各組數字排序，第一次
    {
        goOn = 1;
        //printf("\npai di yi ge:\n");
        for(i=row-1; i>0; i--)
        {
            //printf("group[%d](%d) == group[%d](%d)\n", i, group[i], i-1, group[i-1]);
            if(group[i] == group[i-1])
            {
                //printf("TRUE\n");
                temp = group[i];
                temp = rank[temp][0];
                //printf("\tscore[%d][%d](%d) > score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                if(score[i][temp]>score[i-1][temp])
                {
                    //printf("TRUE\n");
                    for(k=0; k<4; k++)
                    {
                        tmp = score[i-1][k];
                        score[i-1][k] = score[i][k];
                        score[i][k] = tmp;
                    }
                    for(k=0; k<20; k++)
                    {
                        tempArr[0] = name[i-1][k];
                        name[i-1][k] = name[i][k];
                        name[i][k] = tempArr[0];
                    }
                    tmp = group[i];
                    group[i] = group[i-1];
                    group[i-1] = tmp;
                    goOn = 0;
                }
            }
        }
    }

    while(goOn == 1) //若前一個比較的數字相同，再比較之後的數字，第二次
    {
        goOn = 0;
        //printf("\npai di er ge:\n");
        for(i=row-1; i>0; i--)
        {
            //printf("group[%d](%d) == group[%d](%d)\n", i, group[i], i-1, group[i-1]);
            if(group[i] == group[i-1])
            {
                //printf("TRUE\n");
                temp = group[i];
                temp = rank[temp][0];
                //printf("\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                if(score[i][temp] == score[i-1][temp])
                {
                    //printf("TRUE\n");
                    temp = group[i];
                    temp = rank[temp][1];
                    //printf("\t\tscore[%d][%d](%d) > score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                    if(score[i][temp] > score[i-1][temp])
                    {
                        //printf("TRUE\n");
                        for(k=0; k<4; k++)
                        {
                            tmp = score[i-1][k];
                            score[i-1][k] = score[i][k];
                            score[i][k] = tmp;
                        }
                        for(k=0; k<20; k++)
                        {
                            tempArr[0] = name[i-1][k];
                            name[i-1][k] = name[i][k];
                            name[i][k] = tempArr[0];
                        }
                        tmp = group[i];
                        group[i] = group[i-1];
                        group[i-1] = tmp;
                        goOn = 1;
                    }
                }
            }
        }
    }

    while(goOn == 0) //若前一個比較的數字相同，再比較之後的數字，第三次
    {
        goOn = 1;
        //printf("\npai di san ge:\n");
        for(i=row-1; i>0; i--)
        {
            //printf("group[%d](%d) == group[%d](%d)\n", i, group[i], i-1, group[i-1]);
            if(group[i] == group[i-1])
            {
                //printf("TRUE\n");
                temp = group[i];
                temp = rank[temp][0];
                //printf("\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                if(score[i][temp] == score[i-1][temp])
                {
                    //printf("TRUE\n");
                    temp = group[i];
                    temp = rank[temp][1];
                    //printf("\t\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                    if(score[i][temp] == score[i-1][temp])
                    {
                        //printf("TRUE\n");
                        temp = group[i];
                        temp = rank[temp][2];
                        //printf("\t\t\t\tscore[%d][%d](%d) > score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                        if(score[i][temp] > score[i-1][temp])
                        {
                            //printf("TRUE\n");
                            for(k=0; k<4; k++)
                            {
                                tmp = score[i-1][k];
                                score[i-1][k] = score[i][k];
                                score[i][k] = tmp;
                            }
                            for(k=0; k<20; k++)
                            {
                                tempArr[0] = name[i-1][k];
                                name[i-1][k] = name[i][k];
                                name[i][k] = tempArr[0];
                            }
                            tmp = group[i];
                            group[i] = group[i-1];
                            group[i-1] = tmp;
                            goOn = 0;
                        }
                    }
                }
            }
        }
    }

    while(goOn == 1) //若前一個比較的數字相同，再比較之後的數字，第四次
    {
        goOn = 0;
        //printf("\npai di si ge:\n");
        for(i=row-1; i>0; i--)
        {
            //printf("group[%d](%d) == group[%d](%d)\n", i, group[i], i-1, group[i-1]);
            if(group[i] == group[i-1])
            {
                //printf("TRUE\n");
                temp = group[i];
                temp = rank[temp][0];
                //printf("\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                if(score[i][temp] == score[i-1][temp])
                {
                    //printf("TRUE\n");
                    temp = group[i];
                    temp = rank[temp][1];
                    //printf("\t\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                    if(score[i][temp] == score[i-1][temp])
                    {
                        //printf("TRUE\n");
                        temp = group[i];
                        temp = rank[temp][2];
                        //printf("\t\t\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                        if(score[i][temp] == score[i-1][temp])
                        {
                            //printf("TRUE\n");
                            temp = group[i];
                            temp = rank[temp][3];
                            //printf("\t\t\t\tscore[%d][%d](%d) > score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                            if(score[i][temp] > score[i-1][temp])
                            {
                                //printf("TRUE\n");
                                for(k=0; k<4; k++)
                                {
                                    tmp = score[i-1][k];
                                    score[i-1][k] = score[i][k];
                                    score[i][k] = tmp;
                                }
                                for(k=0; k<20; k++)
                                {
                                    tempArr[0] = name[i-1][k];
                                    name[i-1][k] = name[i][k];
                                    name[i][k] = tempArr[0];
                                }
                                tmp = group[i];
                                group[i] = group[i-1];
                                group[i-1] = tmp;
                                goOn = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    while(goOn == 0) //若前一個比較的數字相同，再比較之後的數字，第四次
    {
        goOn = 1;
        //printf("\nbi ming zi:\n");
        for(i=row-1; i>0; i--)
        {
            //printf("group[%d](%d) == group[%d](%d)\n", i, group[i], i-1, group[i-1]);
            if(group[i] == group[i-1])
            {
                //printf("TRUE\n");
                temp = group[i];
                temp = rank[temp][0];
                //printf("\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                if(score[i][temp] == score[i-1][temp])
                {
                    //printf("TRUE\n");
                    temp = group[i];
                    temp = rank[temp][1];
                    //printf("\t\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                    if(score[i][temp] == score[i-1][temp])
                    {
                        //printf("TRUE\n");
                        temp = group[i];
                        temp = rank[temp][2];
                        //printf("\t\t\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                        if(score[i][temp] == score[i-1][temp])
                        {
                            //printf("TRUE\n");
                            temp = group[i];
                            temp = rank[temp][3];
                            //printf("\t\t\t\tscore[%d][%d](%d) == score[%d][%d](%d)\n", i, temp, score[i][temp], i-1, temp, score[i-1][temp]);
                            if(score[i][temp] == score[i-1][temp])
                            {
                                //printf("TRUE\n");
                                temp = strcmp(name[i], name[i-1]); //strcmp: 比較兩組字串的大小
                                //printf("\t\t\t\t\t%s < %s", name[i], name[i-1]);
                                if(temp<0)
                                {
                                    //printf("TRUE\n");
                                    for(k=0; k<4; k++)
                                    {
                                        tmp = score[i-1][k];
                                        score[i-1][k] = score[i][k];
                                        score[i][k] = tmp;
                                    }
                                    for(k=0; k<20; k++)
                                    {
                                        tempArr[0] = name[i-1][k];
                                        name[i-1][k] = name[i][k];
                                        name[i][k] = tempArr[0];
                                    }
                                    tmp = group[i];
                                    group[i] = group[i-1];
                                    group[i-1] = tmp;
                                    goOn = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    /*printf("\nquan bu pai hao\n");
    for(i=0; i<row; i++)
    {
        printf("%s\t\t", name[i]);
        for(j=0; j<4; j++)
        {
            printf("%d\t", score[i][j]);
        }
        printf("group:%d\n", group[i]);
    }*/



    if(row == 0)
    {
        printf("Group A: No Audience\nGroup B: No Audience\nGroup C: No Audience\nGroup D: No Audience");
        temp = 3;
    }else
    {
        printf("Group A:");
        temp = 0;
    }
    for(i=0; i<row; i++)
    {
        if(group[i] == temp)
        {
            printf("\n%s", name[i]);
        }else
        {
            printf(" No Audience");
            i--;
        }
        if(group[i+1] >= temp + 1 && i+1<row)
        {
            temp++;

            if(temp == 1)
            {
                printf("\nGroup B:");
            }else if(temp == 2)
            {
                printf("\nGroup C:");
            }else if(temp == 3)
            {
                printf("\nGroup D:");
            }
        }
        //system("pause");
    }
    if(temp<3)
    {
        temp++;
        printf("\n");
        if(temp == 1)
        {
            printf("Group B: No Audience\nGroup C: No Audience\nGroup D: No Audience");
        }else if(temp == 2)
        {
            printf("Group C: No Audience\nGroup D: No Audience");
        }else if(temp == 3)
        {
            printf("Group D: No Audience");
        }
    }



    //釋放指標
    for(i=0; i<row; i++)
    {
        free(name[i]);
    }
    free(name);

    for(i=0; i<row; i++)
    {
        free(score[i]);
    }
    free(score);

    free(group);


    return 0;
}
