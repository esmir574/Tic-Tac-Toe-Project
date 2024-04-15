#include <iostream>
using namespace std;

void showItems(char items[3][3]){
    for (int r =  0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            cout << items[r][c] << '|';
        }
        cout << endl;
    }
}

bool getWinnerPlayer(char items[3][3], char player){
    for (int r = 0; r < 3; r++){
        if ((items[r][0] == player &&
             items[r][1] == player &&
             items[r][2] == player) ||
            (items[0][r] == player &&
             items[1][r] == player &&
             items[2][r] == player))
        {
            return true;
        }
    }

    if ((items[0][0] == player &&
         items[1][1] == player &&
         items[2][2] == player) ||
        (items[0][2] == player &&
         items[1][1] == player &&
         items[2][0] == player))
    {
        return true;
    }

    return false;
}

bool availableSpaces(char items[3][3]){
    for (int r =  0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            if (items[r][c] == ' '){
                return true;
            }
        }
    }

    return false;
}

int main()
{
    char gameItems[3][3] = {{' ',' ', ' '}, {' ',' ', ' '}, {' ',' ', ' '}};
    char player = 'X';
    int r, c;

    bool gameOver = false;

    while (!gameOver)
    {
        showItems(gameItems);

        cout << "Player " << player << ", enter row and column (0-2):";
        cin >> r >> c;

        if((r >= 0 && r < 3) &&  (c >=0 && c < 3)) {


            if (gameItems[r][c] == ' ') {
                gameItems[r][c] = player;
                gameOver = getWinnerPlayer(gameItems, player);

                if (gameOver) {
                    showItems(gameItems);
                    cout << "Player " << player << " wins!" << endl;
                } else if (!availableSpaces(gameItems)) {
                    showItems(gameItems);
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                }

                if (player == 'X') {
                    player = '0';
                } else {
                    player = 'X';
                }
            } else {
                cout << "That spot is already taken. Try again." << endl;
            }
        }else{
            cout << "The value is out of range. Try again." << endl;
        }
    }

    return 0;
}