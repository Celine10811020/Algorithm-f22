#include <stdio.h>

int path(int row, int column);

int grid[1001][1001] = {};
int data[2];
/*
data[0] = row;
data[1] = column;
*/

int main()
{
    int ans;

    scanf("%d", &data[0]);
    scanf("%d", &data[1]);

    ans = path(1, 1);

    printf("%d", ans);

    return 0;
}

int path(int row, int column)
{
    int temp;

    if(grid[row][column] > 0)
    {
        return grid[row][column];

    }else if(row == data[0] && column == data[1])
    {
        grid[row][column] = 1;
        return 1;

    }else if(row == data[0])
    {
        temp = path(row, column+1);
        grid[row][column] = temp;
        return temp;

    }else if(column == data[1])
    {
        temp = path(row+1, column);
        grid[row][column] = temp;
        return temp;

    }else
    {
        temp = (path(row+1, column) + path(row, column+1)) % 100000007;
        grid[row][column] = temp;
        return temp;
    }
}
