// TIC-TAC-TOE 1.0

#include <iostream>

using namespace std;

int main()
{
    const int ROWS = 3;
    const int COLUMNS = 3;

    char board[ROWS][COLUMNS] = {
        {'X', 'O', 'X'},
        {'X', 'O', 'O'},
        {' ', 'X', 'O'}};

    // cout << board[0][0] << endl;
    // cout << board[1][2] << endl;
    cout << "Here's the tic-tac-toe board:\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\n'X' moves to the empty location.\n\n";
    board[2][0] = 'X';

    cout << "Now the tic-tac-toe board is:\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}