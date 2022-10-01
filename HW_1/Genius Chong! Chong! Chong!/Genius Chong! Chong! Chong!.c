#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    long i=0, j=0, k=0, l=0, q=0, m=0, row=0, temp=0, tmp=0, num=0;
    char Arr[1] = {0};
    char groupNum[4] = {0};
    char rank[4][4] = {0};
    char **name = NULL;
    long **score = NULL;
    long *group = NULL;


    scanf("%ld", &row);

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
    for(i=0; i<row; i++)
    {
        for(j=0; j<20; j++)
        {
            name[i][j] = 0;
        }
    }

    score = (long**)malloc(sizeof(long*)*row); //row*4
    for(i=0; i<row; i++)
    {
        score[i] = (long*)malloc(sizeof(long)*4);
    }
    for(i=0; i<row; i++)
    {
        for(j=0; j<4; j++)
        {
            score[i][j] = 0;
        }
    }

    //輸入資料
    for(i=0; i<row; i++)
    {
        scanf("%s", name[i]);
        for(j=0; j<4; j++)
        {
            scanf("%ld", &temp);
            score[i][j] = temp;
        }
    }

    //分組
    group = (long*)malloc(sizeof(long)*row);
    for(i=0; i<row; i++)
    {
        temp=0, tmp=0;
        group[i]=0;
        for(j=0; j<4; j++)
        {
            if(temp < score[i][j])
            {
                temp = score[i][j];
                group[i] = tmp;

            }
            tmp++;
        }
        tmp = group[i];
        groupNum[tmp]++;
    }

    temp=0;
    for(j=0; j<4; j++) //按組別排好
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
                        Arr[0] = name[temp][k];
                        name[temp][k] = name[i][k];
                        name[i][k] = Arr[0];
                    }
                    tmp = group[temp];
                    group[temp] = group[i];
                    group[i] = tmp;
                }
                temp++;
            }
        }
    }
    free(group);

    for(j=0; j<4; j++) //第幾組
    {
        if(j!=0)
        {
            num = num + groupNum[j-1];
        }
        //printf("\tdi %ld zu,\tgong %d ren\n", j, groupNum[j]);
        if(groupNum[j]>1)
        {
            for(l=0; l<groupNum[j]-1; l++) //在第幾組中計算
            {
                //printf("\t\tsname[%ld](%s) < name[%ld](%s)\n", l+num+1, name[l+num+1], l+num, name[l+num+1]);
                tmp = strcmp(name[l+num+1], name[l+num]);
                //if(tmp<0)
                //{
                //printf("rank[%ld][%ld]=%d\n", j, m, rank[j][m]);
                for(q=l; q>=0; q--)
                {
                    //printf("q=%ld\tnum=%ld\n", q, num);
                    if(tmp<0)
                    {
                        for(k=0; k<4; k++)
                        {
                            tmp = score[q+num+1][k];
                            score[q+num+1][k] = score[q+num][k];
                            score[q+num][k] = tmp;
                        }
                        for(k=0; k<20; k++)
                        {
                            Arr[0] = name[q+num+1][k];
                            name[q+num+1][k] = name[q+num][k];
                            name[q+num][k] = Arr[0];
                        }

                        /*tmp = group[q+num];
                        group[q+num] = group[q+num-1];
                        group[q+num+1] = tmp;*/

                        /*for(int t=0; t<row; t++)
                        {
                            printf("%s\t\t", name[t]);
                            for(int r=0; r<4; r++)
                            {
                                printf("%ld\t", score[t][r]);
                            }
                            printf("\n");
                        }*/
                    }
                }
                //}
            }
            i++;
        }
        i++;
    }

    for(m=3; m>=0; m--)//第幾次
    {
        i=0;
        num=0;
        //printf("di %ld pai\n", m);
        for(j=0; j<4; j++) //第幾組
        {
            if(j>0)
            {
                num = num + groupNum[j-1];
            }
            //printf("\tdi %ld zu,\tgong %d ren\n", j, groupNum[j]);
            if(groupNum[j]>1)
            {
                for(l=0; l<groupNum[j]-1; l++) //在第幾組中計算
                {
                    temp = rank[j][m];
                    //printf("\t\tscore[%ld][%ld](%ld) < score[%ld][%ld](%ld)\n", l+num, temp, score[l+num][temp], l+num+1, temp, score[l+num+1][temp]);
                    //if(score[l+num][temp] < score[l+num+1][temp])
                    //{
                    //printf("rank[%ld][%ld]=%d\n", j, m, rank[j][m]);
                    for(q=l; q>=0; q--)
                    {
                        //printf("q=%ld\tnum=%ld\n", q, num);
                        if(score[q+num][temp] < score[q+num+1][temp])
                        {
                            for(k=0; k<4; k++)
                            {
                                tmp = score[q+num+1][k];
                                score[q+num+1][k] = score[q+num][k];
                                score[q+num][k] = tmp;
                            }
                            for(k=0; k<20; k++)
                            {
                                Arr[0] = name[q+num+1][k];
                                name[q+num+1][k] = name[q+num][k];
                                name[q+num][k] = Arr[0];
                            }

                            /*tmp = group[q+num];
                            group[q+num] = group[q+num-1];
                            group[q+num+1] = tmp;*/

                            /*for(int t=0; t<row; t++)
                            {
                                printf("%s\t\t", name[t]);
                                for(int r=0; r<4; r++)
                                {
                                printf("%ld\t", score[t][r]);
                            }
                            printf("\n");
                            }*/
                        }
                    }
                    //}
                }
                i++;
            }
            i++;
        }
    }

    /*printf("output\n");
    for(i=0; i<row; i++)
    {
        printf("%s\t\t", name[i]);
        for(j=0; j<4; j++)
        {
            printf("%ld\t", score[i][j]);
        }
        printf("\n");
    }*/

    //printf("%ld\n", row);
    //temp = 0;

    /*if(row == 0)
    {
        printf("Group A: No Audience\nGroup B: No Audience\nGroup C: No Audience\nGroup D: No Audience");
        //temp = 3;
    }else
    {

        //temp = 0;
    }*/

    printf("Group A:");
    if(groupNum[0] == 0)
    {
        printf(" No Audience");
    }
    temp = 0;
    for(j=0; j<4; j++)
    {
        //printf("j=%ld\n", j);
        if(j>0)
        {
            temp = temp + groupNum[j-1];
        }

        for(k=0; k<groupNum[j]; k++)
        {
            //printf("temp=%ld\tk=%ld\n", temp, k);
            //printf("name[%ld]=%s\n", temp+k, name[temp+k]);
            printf("\n%s", name[temp+k]);
        }


        if(j == 0)
        {
            printf("\nGroup B:");
            //temp = 1;
        }else if(j == 1)
        {
            printf("\nGroup C:");
            //temp = 2;
        }else if(j == 2)
        {
            printf("\nGroup D:");
            //temp = 3;
        }
        //temp++;

        if(groupNum[j+1] == 0 && j<3)
        {
            printf(" No Audience");
        }
    }



        /*if(group[i] == temp)
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
        }*/
        //system("pause");

    /*if(temp<3)
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
    }*/



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





    return 0;
}

































/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

    printf("\nfen hao zu\n");
    for(i=0; i<row; i++)
    {
        printf("%s\t\t", name[i]);
        for(j=0; j<4; j++)
        {
            printf("%d\t", score[i][j]);
        }
        printf("group:%d\n", group[i]);
    }

    temp=0;
    for(j=0; j<4; j++) //按組別排好
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

    printf("\nfen zu pai hao\n");
    for(i=0; i<row; i++)
    {
        printf("%s\t\t", name[i]);
        for(j=0; j<4; j++)
        {
            printf("%d\t", score[i][j]);
        }
        printf("group:%d\n", group[i]);
    }

    for(i=0; i<row; i++)
    {
        printf("%s\n", name[i]);
    }


    while(goOn == 0)
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

    while(goOn == 1)
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

    while(goOn == 0)
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

    while(goOn == 1)
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

    while(goOn == 0)
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
                                temp = strcmp(name[i], name[i-1]);
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


    printf("\nquan bu pai hao\n");
    for(i=0; i<row; i++)
    {
        printf("%s\t\t", name[i]);
        for(j=0; j<4; j++)
        {
            printf("%d\t", score[i][j]);
        }
        printf("group:%d\n", group[i]);
    }



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
}*/
