#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
void runGame();

int main()
{
    runGame();
}

//---------------------------------------------------//
//---------------| initialize the board  |-----------//
//---------------------------------------------------//
void initializeGameBoard(string gameBoard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; j++)
        {
            gameBoard[i][j] = " ";
        }
    }
} // end of initializing the game board

//---------------------------------------------------//
//----------| print the current board  |-------------//
//---------------------------------------------------//
void printCurrentBoard(string gameBoard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (j != 2)
            {
                cout << gameBoard[i][j] << " | ";
            }
            else
            {
                cout << gameBoard[i][j] << " ";
            }
        }
        if (i < 2)
        {
            cout << "\n- - - - -\n";
        }
    }

    cout << endl;
} // end print current board

//---------------------------------------------------//
//---| return 'true' if cell is already occupied  |--//
//---------------------------------------------------//
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS])
{
    // returns true if the position is not empty
    return gameBoard[row][col] != " ";
} // end cellAlreadyOccupied

//---------------------------------------------------//
//--------| get user input and place symbol  |-------//
//---------------------------------------------------//
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS])
{
    int row = -1;
    int col = -1;

    bool keepAsking = true;
    while (keepAsking)
    {
        // Keep asking until you get a valid answer
        cout << "\nPlease enter row index, THEN column index for position -> [0, 1, or 2] \n";
        cout << "Enter row index number: ";
        cin >> row;

        cout << "Enter column index number: ";
        cin >> col;

        if (row >= 0 && col >= 0 && row <= 2 && col <= 2)
        {
            if (!cellAlreadyOccupied(row, col, gameBoard))
            {
                keepAsking = false;
            }
            else
            {
                cout << "That cell is already occupied!" << endl;
            }
        }
    } // end while

    if (xTurn)
    {
        gameBoard[row][col] = "X";
    }
    else
    {
        gameBoard[row][col] = "O";
    }
} // end getUserInput

//---------------------------------------------------//
//-------------| test if board is full  |------------//
//---------------------------------------------------//
bool isBoardFull(string gameBoard[ROWS][COLS])
{
    int countFill = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (gameBoard[i][j] != " ")
            {
                countFill++;
            }
        }
    }

    return countFill == 9;
}

//---------------------------------------------------//
//-----------| test if we have a winner  |-----------//
//---------------------------------------------------//
string getWinner(string gameBoard[ROWS][COLS])
{
    // check rows
    for (int i = 0; i < ROWS; ++i)
    {
        if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
        {
            return gameBoard[i][0]; // Horizontal match!
        }
    }

    // check columns
    for (int i = 0; i < COLS; i++)
    {
        if (gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
        {
            return gameBoard[0][i]; // Horizontal match!
        }
    }

    // check diagonals --> 'manuallly'
    if (gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
    {
        return gameBoard[0][0]; // Diagonal match
    }

    // check reverse diagonals --> 'manuallly'
    if (gameBoard[2][0] != " " && gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2])
    {
        return gameBoard[2][0]; // Diagonal match
    }

    return ""; // return empty string if no winner yet!
}

//---------------------------------------------------//
//-----------| the game loop - run game  |-----------//
//---------------------------------------------------//
void runGame()
{
    string winner = "";
    bool xTurn = true;
    int theRow = 0;
    int theCol = 0;

    string gameBoard[ROWS][COLS];

    initializeGameBoard(gameBoard);

    cout << "\n";
    printCurrentBoard(gameBoard);

    while (winner == "")
    {
        if (xTurn)
        {
            cout << "\nIt is X's turn" << endl;
        }
        else
        {
            cout << "\nIt's O's turn" << endl;
        }

        getUserInput(xTurn, gameBoard);

        cout << "\n";

        printCurrentBoard(gameBoard);

        winner = getWinner(gameBoard);

        xTurn = !xTurn;

        if (winner == "" && isBoardFull(gameBoard))
        {
            winner = "C"; // Draw... no winner!
        }
    } // end while

    cout << "\n\n";

    if (winner == "C")
    {
        cout << "It was a Cat's game... No Winner!" << endl;
    }
    else
    {
        cout << "The winner is: " << winner << endl;
    }
    cout << endl;
}