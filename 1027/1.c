#include <stdio.h>

int maze[9][9];

typedef struct Set
{
    int row;
    int col;
} Set;

Set move[8];

void setMove()
{
    move[0].row = -1;
    move[0].col = 0;

    move[1].row = -1;
    move[1].col = 1;

    move[2].row = 0;
    move[2].col = 1;

    move[3].row = 1;
    move[3].col = 1;

    move[4].row = 1;
    move[4].col = 0;

    move[5].row = 1;
    move[5].col = -1;

    move[6].row = 0;
    move[6].col = -1;

    move[7].row = -1;
    move[7].col = -1;
}

typedef struct element
{
    int row;
    int col;
    int dir;
} element;

element pos;
element mark;

int findWays()
{
    int flag = 1;
    for (int i = mark.dir; i < 8; i++)
    {
        if (maze[pos.row + move[i].row][pos.col + move[i].col] == 0)
        {
            flag = 0;
            return i;
        }
    }
    if (flag)
    {
        return -1;
    }
}

int main()
{
    setMove();
    int r, c;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%1d", &maze[i][j]);
        }
    }
    pos.row = 1;
    pos.col = 1;
    pos.dir = 0;
    while (pos.row != r - 2 || pos.col != c - 2)
    {
        int ways = findWays();
        if (ways >= 0)
        {
            mark.row = pos.row;
            mark.col = pos.col;
            mark.dir = 0;
            maze[pos.row][pos.col] = 1;
            printf("R%d C%d D%d\n", pos.row, pos.col, ways);
            pos.row += move[ways].row;
            pos.col += move[ways].col;
            pos.dir = ways;
        }
        else
        {
            maze[mark.row][mark.col] = 0;
            maze[pos.row][pos.col] = 1;
            pos.col = mark.col;
            pos.row = mark.row;
        }
    }
    printf("R%d C%d D*\n", pos.row, pos.col);
}
