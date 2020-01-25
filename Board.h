#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#ifndef CBProject1_BOARD_H
#define CBProject1_BOARD_H

class Board{
private:
int length;
int width;
int pieceTotal;
int blackScore = 0;
int whiteScore = 0;

vector<vector<int>> grid;

public:
Board(int length, int width, int pieceTotal){
    this->pieceTotal = pieceTotal;
    this->length = length;
    this->width = width;
    buildGrid();
}

void buildGrid(){
    vector<int> tempPieces;
    for (int i = 0; i < length; ++i){
        grid.push_back(tempPieces);
        for (int j = 0; j < width; ++j){
            grid[i].push_back(0);
        }
    }

    for (int i = 0; i < length/2-1; ++i){
        for (int j = 0; j < width; ++j){
            if (((i+1) % 2) != ((j+1) % 2)){
                grid[i][j] = -1;
            }
        }
    }
    for (int i = length/2+1; i < length; ++i){
        for (int j = 0; j < width; ++j){
            if (((i+1) % 2) != ((j+1) % 2)){
                grid[i][j] = 1;
            }
        }
    }
}

void printBoard(){
    for (int i = 0; i < length; ++i){
        for (int j = 0; j < width; ++j){
            
            if (grid[i][j] != 0){
                if (grid[i][j] == -1){
                    cout << "W ";
                }
                else if (grid[i][j] == 1){
                    cout << "B ";
                }
            }else{
                if (((i+1) % 2) == ((j+1) % 2)){
                    cout << "- ";
                }else{
                    cout << "- ";
                }
            }
            
        }
        cout << endl;
    } 
}

bool movePiece(int row, int column, int moveRow, int moveColumn, string player){
    bool hasMoved = false;
    bool isBlackPiece = checkForPiece(moveRow, moveColumn, "black's");
    bool isWhitePiece = checkForPiece(moveRow, moveColumn, "white's");
    bool isEmptyTile = !checkForPiece(moveRow, moveColumn, "white's") && !checkForPiece(moveRow, moveColumn, "black's");
    bool isValid;

    if (player == "black's"){
        isValid = ((row - moveRow == 1) && (abs(column - moveColumn) == 1));
    }
    if (player == "white's"){
        isValid = ((moveRow - row == 1) && (abs(column - moveColumn) == 1));
    }

    int input;
    vector<vector<int>> oldGrid = grid;
    if (isEmptyTile && isValid){
        oldGrid[moveRow][moveColumn] = oldGrid[row][column];
        oldGrid[row][column] = 0;
        grid = oldGrid;
        hasMoved = true;
    }
    else if (moveRow == -1 || moveColumn == -1){
        hasMoved = true;
    }
    return hasMoved;

}

bool checkForPiece(int pieceRow, int pieceColumn, string player){
    bool found = false;
    if (pieceRow > -1 && pieceColumn > -1 && pieceRow <= length && pieceColumn <= width){
        if (player == "white's"){
            if (grid[pieceRow][pieceColumn] == -1){
                found = true;
            }
        }
        if (player == "black's"){
            if (grid[pieceRow][pieceColumn] == 1){
                found = true;
            }
        }
    }else if (pieceRow != -1 && pieceColumn != -1){
        cout << "Your input was outside the range of the board, please try again" << endl;
    }
    return found;
}

int getBlackScore(){
    return blackScore;
}

int getWhiteScore(){
    return whiteScore;
}

};

#endif //CBProject1_BOARD_H