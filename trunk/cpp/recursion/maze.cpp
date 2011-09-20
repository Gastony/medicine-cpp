#include <iostream>
using namespace std;

void BuildMaze(char maze[8][8])
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if ((i != j) || (i == 0 && j == 0) || (i == 7 && j == 7))
            {
                maze[i][j] = ' ';
            }
            else
            {
                maze[i][j] = '*';
            }
        }
    }

    maze[2][1] = 'S';
    maze[6][7] = 'E';
}

void PrintMaze(const char maze[8][8])
{
    for (int i = 0; i < 8; ++i)
    {
        cout << "|";
        for (int j = 0; j < 8; ++j)
        {
            cout << maze[i][j] << "|";
        }
        cout << endl;
    }
}

void setPath(char maze[8][8], int x, int y)
{
    maze[x][y] = 'P';
}

bool ExploreMaze(char maze[8][8], int x, int y)
{
    if (x < 0 || x > 7 || y < 0 || y > 7)
    {
        return false;
    }

    if (maze[x][y] == '*') return false;

    if (maze[x][y] == 'E') return true;

    maze[x][y] = '*';
    
    if (ExploreMaze(maze, x+1, y)) { setPath(maze, x, y); return true; }
    if (ExploreMaze(maze, x, y+1)) { setPath(maze, x, y); return true; }
    if (ExploreMaze(maze, x-1, y)) { setPath(maze, x, y); return true; }
    if (ExploreMaze(maze, x, y-1)) { setPath(maze, x, y); return true; }

    maze[x][y] = ' ';
    return false;
}

bool SolveMaze(char maze[8][8])
{
    int x = 0, y = 0;
    bool found = false;
    for (x = 0; x < 8; ++x)
    {
        for (y = 0; y < 8; ++y)
        {
            if (maze[x][y] == 'S')
            {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    cout << "S located at " << x << "|" << y << endl;
    
    if (x == 8 && y == 8)
    {
        return false;
    }

    bool ret = ExploreMaze(maze, x, y);
    maze[x][y] = 'S';
    return ret;
}

int main()
{
    char maze[8][8];
    BuildMaze(maze);
    PrintMaze(maze);

    if (SolveMaze(maze))
    {
        cout << "maze is solvable\n";
        PrintMaze(maze);
    }
    else
    {
        cout << "maze is not solvable\n";
    }
    
    return 0;
}
