#include <iostream>
using namespace std;

bool gameover(char game[][3], int count)
{
    bool player1 = false, player2 = false;

    if (((game[0][0] == 'X') && (game[0][1] == 'X') && (game[0][2] == 'X')) || // 1st row
        ((game[0][0] == 'X') && (game[1][0] == 'X') && (game[2][0] == 'X')) || // 1st column
        ((game[0][0] == 'X') && (game[1][1] == 'X') && (game[2][2] == 'X')) || // left diagonal
        ((game[1][0] == 'X') && (game[1][1] == 'X') && (game[1][2] == 'X')) || // 2nd row
        ((game[2][0] == 'X') && (game[2][1] == 'X') && (game[2][2] == 'X')) || // 3rd row
        ((game[0][1] == 'X') && (game[1][1] == 'X') && (game[2][1] == 'X')) || // 2nd column
        ((game[0][2] == 'X') && (game[1][2] == 'X') && (game[2][2] == 'X')) || // 3rd column
        ((game[0][2] == 'X') && (game[1][1] == 'X') && (game[2][0] == 'X')))   // right diagonal
    {
        player1 = true;
    }
    else if (((game[0][0] == 'O') && (game[0][1] == 'O') && (game[0][2] == 'O')) ||
             ((game[0][0] == 'O') && (game[1][0] == 'O') && (game[2][0] == 'O')) ||
             ((game[0][0] == 'O') && (game[1][1] == 'O') && (game[2][2] == 'O')) ||
             ((game[1][0] == 'O') && (game[1][1] == 'O') && (game[1][2] == 'O')) ||
             ((game[2][0] == 'O') && (game[2][1] == 'O') && (game[2][2] == 'O')) ||
             ((game[0][1] == 'O') && (game[1][1] == 'O') && (game[2][1] == 'O')) ||
             ((game[0][2] == 'O') && (game[1][2] == 'O') && (game[2][2] == 'O')) ||
             ((game[0][2] == 'O') && (game[1][1] == 'O') && (game[2][0] == 'O')))
    {
        player2 = true;
    }
    if (count != 9 && player1 == false && player2 == false)
    {
        return true;
    }
    else
    {
        if (player1 == true)
        {
            cout << "\nPlayer 1 won";
        }
        else if (player2 == true)
        {
            cout << "\nPlayer 2 won";
        }
        else
        {
            cout << "\nGame draw";
        }
        return false;
    }
}
void displayBoard(char game[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 1 || j == 2)
            {
                cout << "\t"
                     << "|"
                     << "  " << game[i][j] << "  ";
            }
            else
            {
                cout << "\t"
                     << "   " << game[i][j] << "  ";
            }
        }
        cout << "\n";
        if (i == 0 || i == 1)
        {
            cout << "\t------------------------";
        }
        cout << "\n";
    }
}

void player_turn(char game[][3], int &count, bool flag)
{
    int row, column;
    if (count != 9 && flag == 0)
    {
        cout << "Player 1's [X] turn: \n";
        cout << "Where do you want to place a X ? \n";
        cout << "Enter row number: ";
        cin >> row;
        while (!(row >= 1) || !(row <= 3))
        {
            cout << "Wrong Input\n";
            cout << "Enter row again: ";
            cin >> row;
        }
        cout << "Enter column number: ";
        cin >> column;
        while (column < 1 || column > 3)
        {
            cout << "Wrong Input\n";
            cout << "Enter column again: ";
            cin >> column;
        }
        if ((game[row - 1][column - 1] != 'X') && (game[row - 1][column - 1] != 'O'))
        {
            game[row - 1][column - 1] = 'X';
            flag = 1;
            count++;
        }
        else
        {
            cout << "Place already occupied\n";
        }
    }
    if (count != 9 && flag == 1)
    {
        cout << "Player 2's [O] turn: \n";
        cout << "Where do you want to place a O ? \n";
        cout << "Enter row number: ";
        cin >> row;
        while (row < 1 || row > 3)
        {
            cout << "Wrong Input\n";
            cout << "Enter row again: ";
            cin >> row;
        }
        cout << "Enter column number: ";
        cin >> column;
        while (column < 1 || column > 3)
        {
            cout << "Wrong Input\n";
            cout << "Enter column again: ";
            cin >> column;
        }
        if ((game[row - 1][column - 1] != 'X') && (game[row - 1][column - 1] != 'O'))
        {
            game[row - 1][column - 1] = 'O';
            flag = 0;
            count++;
        }
        else
        {
            cout << "Place already occupied\n";
        }
    }
}

int main()
{
    char game[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int count = 0;
    bool flag = 0;
    cout << "\tTIC -- TAC -- TOE -- GAME\n";
    cout << "\tFor 2 Players\n";
    cout << "\tPlayer 1 [X]\t Player 2 [O]\n\n";

    displayBoard(game);
    while (gameover(game, count))
    {
        player_turn(game, count, flag);
        displayBoard(game);
    }

    return 0;
}