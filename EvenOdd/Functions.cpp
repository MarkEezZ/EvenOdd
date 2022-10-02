#include "Functions.h"

using namespace std;

void wait(double seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}


void Rules() {

    cout << "Welcome to the game \"Even & Odd\"!" << endl;
    wait(1);

    cout << "Let's get acquainted with the rules of the game: " << endl << endl;
    wait(2);

    cout << "The \"Even & Odd\" game is intellectual game for two players. " << endl;
    cout << "All you need to do is set 0 or 1 in empty cells on the field" << endl;
    wait(5);

    cout << "When game field will be filled, program will say a name of winner. " << endl << endl;
    wait(5);

    cout << "If amount of even sums bigger than odd, even player won." << endl;
    wait(5);
    cout << "If amount of odd sums bigger than even, odd player won." << endl;
    wait(5);
    cout << "If amount of even sums equal to odd, it's draw." << endl << endl;
    wait(5);

    cout << "Good luck!" << endl << endl << endl;
}


void askRules() {

    cout << "Hello!" << endl << endl;
    cout << "Whould you like to educate rules of the game?" << endl;
    cout << "1. Yes" << endl << "2. No" << endl << endl;

    int checkRules = 0;

    while (checkRules != 1 && checkRules != 2) {
        cout << "Please, select 1 or 2 >> ";
        cin >> checkRules;
        cout << endl;
    }

    if (checkRules == 1) {
        Rules();
    }
}


void fieldOutput(int** gameField, int fieldSize) {

    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if (gameField[i][j] == 4) {
                cout << "-" << "\t";
            }
            else {
                cout << gameField[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}


void memoryCleaning(int** gameField, int fieldSize) {

    for (int i = 0; i < fieldSize; i++) {
        delete[] gameField[i];
    }
    delete[] gameField;

}


int declarationFunc(int** gameField, int fieldSize, int x, int y) {

    int emptyCells = fieldSize * fieldSize;

    while (emptyCells != 0) {

        cout << "Enter the coordinates of the field you want to put the value on: " << endl;
        cin >> x;
        cin >> y;
        cout << endl;

        if (gameField[x - 1][y - 1] == 4) {
            while (gameField[x - 1][y - 1] != 0 && gameField[x - 1][y - 1] != 1) {
                cout << "Enter 0 or 1 >> ";
                cin >> gameField[x - 1][y - 1];
                cout << endl;
            }
        }
        else {
            while (gameField[x - 1][y - 1] != 4) {
                cout << "This field is taken or undefined. Try again" << endl;
                cout << "Enter the coordinates of the field you want to put the value on : " << endl;
                cin >> x;
                cin >> y;
                cout << endl;

                if (gameField[x - 1][y - 1] == 4) {
                    while (gameField[x - 1][y - 1] != 0 && gameField[x - 1][y - 1] != 1) {
                        cout << "Enter 0 or 1 >> ";
                        cin >> gameField[x - 1][y - 1];
                        cout << endl;
                    }
                    break;
                }
            }
        }

        for (int i = 0; i < fieldSize; i++) {
            for (int j = 0; j < fieldSize; j++) {
                if (gameField[i][j] == 4) {
                    cout << "-" << "\t";
                }
                else {
                    cout << gameField[i][j] << "\t";
                }
            }
            cout << endl;
        }

        cout << endl;

        emptyCells--;
    }

    return 0;
}


int calculationFunc(int** gameField, int fieldSize) {

    int even = 0;
    int odd = 0;

    int sumCols;
    int sumRows;
    int sumDiagonal;

    ///////////////////////////////// Rows

    for (int i = 0; i < fieldSize; i++) {

        sumRows = 0;

        for (int j = 0; j < fieldSize; j++) {
            sumRows += gameField[i][j];
        }

        if (sumRows % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }

    ///////////////////////////////// Columns

    for (int i = 0; i < fieldSize; i++) {

        sumCols = 0;

        for (int j = 0; j < fieldSize; j++) {
            sumCols += gameField[j][i];
        }

        if (sumCols % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }

    ///////////////////////////////// Diagonal

    sumDiagonal = 0;

    for (int i = 0; i < fieldSize; i++) {
        sumDiagonal += gameField[i][i];
    }

    if (sumDiagonal % 2 == 0) {
        even++;
    }
    else {
        odd++;
    }

    sumDiagonal = 0;

    int j = fieldSize - 1;

    for (int i = 0; i < fieldSize; i++) {
        sumDiagonal += gameField[i][j];
        j = j - 1;
    }

    if (sumDiagonal % 2 == 0) {
        even++;
    }
    else {
        odd++;
    }

    if (even > odd) {
        cout << "Even player won!" << endl;
    }
    else if (even < odd) {
        cout << "Odd player won!" << endl;
    }
    else {
        cout << "Draw!" << endl;
    }

    return 0;
}