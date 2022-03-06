#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//////////////////////////////////////////////////////


int X = 12, Y = 14;
bool energizer = 0;
bool updown = 0;
int countjump=0;
bool gospace=0;
int count_hurdle=0;
int score=0;

char maze[20][94] = {
    {"#############################################################################################"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#                                                                                           #"},
    {"#############################################################################################"}
};

///////////////////////////////////////////////////

void display()
{
    for (int x = 0; x < 20; x++)
    {
        for (int m = 0; m < 94; m++)
        {
            cout << maze[x][m];
        }
        cout << endl;
    }
}
int hurdles_size()
{
    srand(time(0));
    int result = 3 + (rand() % 3);
    return result;
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void gameover()
{
    system("cls");
    cout<<"Your score : "<<score<<endl;
    system("pause");
    exit(0);
}

void moveup()
{
    // if (maze[X-1][Y] == '.')
    // {
    //     score++;
    // }
    // if (maze[X-1][Y] == '*')
    // {
    //     score=score+10;
    //     checkpoint();
    // }
    if(maze[X-1][Y] == '#')
    {
        countjump = 0;
        updown = 0;
    }
    if (energizer && (maze[X - 1][Y] == 'G' || maze[X - 1][Y] == '^'))
    {
        gotoxy(Y, X - 1);
        cout << 'P';
        maze[X - 1][Y] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
    }
    // if(!energizer &&maze[X - 1][Y] == 'G')
    // {gameover();}
    // if(!energizer &&maze[X - 1][Y] == '^')
    // {healthover();}
    if (maze[X - 1][Y] == ' ' || maze[X - 1][Y] == '.' || maze[X - 1][Y] == 'O' || maze[X - 1][Y] == 'P' || maze[X - 1][Y] == '*')
    {
        // if (maze[X - 1][Y] == 'O')
        // {
        //     energizer = 1;
        //     energycount=0;
        // }
        gotoxy(Y, X - 1);
        cout << 'P';
        maze[X - 1][Y] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
        X--;
    }
}
void movedown()
{
    // if (maze[X+1][Y] == '.')
    // {
    //     score++;
    // }
    // if (maze[X+1][Y] == '*')
    // {
    //     score=score+10;
    //     checkpoint();
    // }
    if (energizer && (maze[X + 1][Y] == 'G' || maze[X + 1][Y] == '^'))
    {
        gotoxy(Y, X + 1);
        cout << 'P';
        maze[X + 1][Y] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
    }
    // if(!energizer && maze[X+1][Y] == 'G' )
    // {
    //     gameover();
    // }
    // if(!energizer &&  maze[X+1][Y] == '^')
    // {
    //     healthover();
    // }
    if (maze[X + 1][Y] == ' ' || maze[X + 1][Y] == '.' || maze[X + 1][Y] == 'O' || maze[X + 1][Y] == 'P' || maze[X + 1][Y] == '*')
    {
        // if(maze[X+1][Y] == 'O')
        //     {energizer=1;
        //     energycount=0;}
        gotoxy(Y, X + 1);
        cout << 'P';
        maze[X + 1][Y] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
        X++;
    }
}
void moveright()
{
    // if (maze[X][Y+1] == '.')
    // {
    //     score++;
    // }
    // if (maze[X][Y+1] == '*')
    // {
    //     score=score+10;
    //     checkpoint();
    // }
    if (energizer && (maze[X][Y + 1] == 'G' || maze[X][Y + 1] == '^'))
    {
        gotoxy(Y + 1, X);
        cout << 'P';
        maze[X][Y + 1] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
    }
    // if(!energizer &&maze[X][Y+1]  == 'G')
    // {
    //     gameover();
    // }
    // if(!energizer && maze[X][Y+1]  == '^')
    // {
    //     healthover();
    // }
    if (maze[X][Y + 1] == ' ' || maze[X][Y + 1] == '.' || maze[X][Y + 1] == 'O' || maze[X][Y + 1] == 'P' || maze[X][Y + 1] == '*')
    {
        // if (maze[X][Y + 1] == 'O')
        // {
        //     energizer = 1;
        //     energycount = 0;
        // }
        gotoxy(Y + 1, X);
        cout << 'P';
        maze[X][Y + 1] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
        Y++;
    }
}
void moveleft()
{
    // if (maze[X][Y - 1] == '.')
    // {
    //     score++;
    // }
    // if (maze[X][Y - 1] == '*')
    // {
    //     score=score+10;
    //     checkpoint();
    // }
    if (energizer && (maze[X][Y - 1] == 'G' || maze[X][Y - 1] == '^'))
    {
        gotoxy(Y - 1, X);
        cout << 'P';
        maze[X][Y - 1] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
    }
    // if(!energizer &&maze[X][Y - 1] == 'G')
    // {
    //     gameover();
    // }
    // if(!energizer &&  maze[X][Y - 1] == '^')
    // {
    //     healthover();
    // }
    if (maze[X][Y - 1] == ' ' || maze[X][Y - 1] == '.' || maze[X][Y - 1] == 'O' || maze[X][Y - 1] == 'P' || maze[X][Y - 1] == '*')
    {
        // if (maze[X][Y - 1] == 'O')
        // {
        //     energizer = 1;
        //     energycount = 0;
        // }
        gotoxy(Y - 1, X);
        cout << 'P';
        maze[X][Y - 1] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
        Y--;
    }
}
void checkGame()
{
    if(maze[X][Y] == '$')
    {
        gameover();
    }
}

void create_hurdles()
{
    count_hurdle++;
    if(count_hurdle==20)
    {
        int size=hurdles_size();
        for(int x=19;x>19-size+1;x--)
        {
            maze[x][89]='$';
            gotoxy(89,x);
            cout<<'$';
        }
        for(int x=19;x>19-size;x--)
        {
            maze[x][90]='$';
            gotoxy(90,x);
            cout<<'$';
        }
        for(int x=19;x>19-size+1;x--)
        {
            maze[x][91]='$';
            gotoxy(91,x);
            cout<<'$';
        }
        count_hurdle=0;
    }
}
void move_hurdles()
{
    for(int x=0;x<19;x++)
    {
        for(int m=0;m<93;m++)
        {
            if(maze[x][m]=='$')
            {
                if(maze[x][12]=='$')
                {
                    score++;
                }
                maze[x][m] = ' ';
                gotoxy(m, x);
                cout << ' ';
                if (m != 1)
                {
                    maze[x][m - 1] = '$';
                    gotoxy(m - 1, x);
                    cout << '$';
                }
            }
        }
    }
}

void setcursor(bool visible, DWORD size)
{
    if (size == 0)
        size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}


main()
{
    setcursor(0,0); 
    system("cls");
    display();
    while (1)
    {
        Sleep(40);
        create_hurdles();
        move_hurdles();
        gotoxy(79,3);
        cout<<"Score : "<<score;
        score++;
        if (maze[X + 1][Y] == '#')
        {
            if (GetAsyncKeyState(VK_SPACE))
            {
                updown = 1;
            }
        }
        if(updown)
        {
            countjump++;
            if (countjump <= 5)
            {
                moveup();
            }
            else
            {
                countjump = 0;
                updown = 0;
            }
        }
        if (updown == 0)
        {
            if (maze[X + 1][Y] != '#')
            {
                movedown();
            }
        }
        checkGame();
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
    }
}