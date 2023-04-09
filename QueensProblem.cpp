// QueensProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void DrawBoard(int size,bool**);
bool CheckMove(bool**, int,int, int);
bool PlaceQueen(bool**, int, int);


int main()
{
    int size = 5;
    bool** queens = new bool*[size];
    for (int i = 0; i < size; i++) {
        queens[i] = new bool[size];
    }

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            queens[row][col] = false;
        DrawBoard(size, queens);

    PlaceQueen(queens, size, 0);


    for (int i = 0; i < size; i++) {
        delete[] queens[i];
    }
    delete[] queens;

    return 0;
}

bool PlaceQueen(bool** queens, int size, int col) {
    if (col == size) {
        return true;
    }

    for (int row = 0; row < size; row++) {
        if (CheckMove(queens, size, row, col)) {
            cout << "Okay Placement " << row << " " << col << endl;
            queens[row][col] = true;

            DrawBoard(size, queens);
            if (PlaceQueen(queens, size, col + 1)) 
                return true;
            
            queens[row][col] = false;
        }
    }
    return false;
}

void DrawBoard(int size, bool** queens) {
    //top row
    cout << "+";
    for (int col = 0; col < size; col++) {
        cout << "--+";
    }
    cout << endl;

    for (int row = 0;row < size; row++) {
        cout << "|";
        for (int col = 0; col < size; col++) {
            if (queens[row][col]) {
                cout << "QQ|";
            }
            else {
                cout << "  |";
            }
            
        }
        cout << endl;
        cout << "+";
        for (int col = 0; col < size; col++) {
            cout << "--+";
        }
        cout << endl;
    }

}

bool CheckMove(bool** queens, int size, int row, int col) {

    for (int i = 0; i < size; i++) {
        if (queens[i][col] || queens[row][i] ) {
            return false;
        }
    }

    for (int i = col, j = row; (i >=0 && j>=0); i--,j--) {
        if (queens[j][i]) {
            return false;
        }
    }

    for (int i = col, j = row; (i >= 0 && j < size); i--, j++) {
        if (queens[j][i]) {
            return false;
        }
    }

    return true;

}