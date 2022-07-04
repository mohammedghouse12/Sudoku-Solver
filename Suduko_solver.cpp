#include <bits/stdc++.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>
using namespace std;

class Board
{
private:
    char board[9][9], ansboard[9][9];
    bool row_wise[9][10], col_wise[9][10];

public:
    Board()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = ' ';
                row_wise[i][j] = col_wise[i][j] = 0;
            }
        }
        for (int i = 0; i < 9; i++)
            row_wise[i][9] = col_wise[i][9] = 0;
    }
    void invalid()
    {
        cout << "Invalid board" << endl;
    }
    void getInput()
    {
        string str;
        for (int i = 0; i < 9; i++)
        {
            getline(cin, str);
            if (str.size() != 9)
            {
                cout << i << endl;
                invalid();
                return;
            }
            for (int j = 0; j < 9; j++)
                board[i][j] = str[j];
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == ' ')
                    continue;
                int val = board[i][j] - '0';
                if (val <= 0 || val > 9 || row_wise[i][val] == 1 || col_wise[j][val] == 1)
                {
                    invalid();
                    return;
                }
                row_wise[i][val] = 1;
                col_wise[j][val] = 1;
            }
        }
        cout << "\nInput taken successfully\n"
             << endl;
    }
    void printBoard()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    void printansBoard()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << ansboard[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    void solve(int i, int j)
    {
        if (j == 9)
            j = 0, i++;
        if (i == 9)
        {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    ansboard[i][j] = board[i][j];
            return;
        }
        if (board[i][j] >= '1' && board[i][j] <= '9')
        {
            solve(i, j + 1);
            return;
        }
        assert(board[i][j] == ' ');
        for (int val = 1; val <= 9; val++)
        {
            if (row_wise[i][val] == 0 && col_wise[j][val] == 0)
            {
                board[i][j] = val + '0';
                row_wise[i][val] = col_wise[j][val] = 1;
                solve(i, j + 1);
                board[i][j] = ' ';
                row_wise[i][val] = col_wise[j][val] = 0;
            }
        }
    }
};

int main()
{
    Board board;
    cout << "Enter Nine strings to denote Nine rows and give space in a string to denote void cell.\n";
    board.getInput();
    board.solve(0, 0);
    cout << "Given Board\n";
    board.printBoard();
    sleep(3);
    cout << "\nAnswer Board\n";
    board.printansBoard();
    sleep(120);
}
/*
9  5   6
  6 4  82
7  28 3
4821   56
 17 59 3
39562
 7   56 8
  976   3
2 43   79
*/