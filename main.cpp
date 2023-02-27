// Vitor Hugo Behlau Weber
// TicTacToe Game

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void menu();

void clearScreen(){
    system("CLS");
}

void fillBoard(char board[3][3]){
    int line, column;
    for(line = 0; line < 3; line++){
        for(column = 0; column < 3; column++){
            board[line][column] = '-';
        }
        cout << "\n";
    }
}

void printBoard(char board[3][3]){
    int line, column;
    for(line = 0; line < 3; line++){
        for(column = 0; column < 3; column++){
            cout << board[line][column];
        }
        cout << "\n";
    }
}

int checkBoard(char board[3][3]){
    int line, column;
        for(line = 0; line < 3; line++){
            if(board[line][0] == 'X' && board[line][0] == board[line][1] && board[line][1] == board[line][2]){
                return 1;
            }else if(board[line][0] == 'O' && board[line][0] == board[line][1] && board[line][1] == board[line][2]){
                return 2;
            }
        }

        for(column = 0; column < 3; column++){
            if(board[0][column] == 'X' && board[0][column] == board[1][column] && board[1][column] == board[2][column]){
                return 1;
            }else if(board[0][column] == 'O' && board[0][column] == board[1][column] && board[1][column] == board[2][column]){
                return 2;
            }
        }

        if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            if(board[0][0] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }

        if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            if(board[0][2] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }
    return 0;
}

void printInstructions(){
    cout << "\nPositions Map:\n";
    cout << "7 | 8 | 9\n4 | 5 | 6\n1 | 2 | 3";
}

void game(string playerOne, string playerTwo, int pointsPlayerOne, int pointsPlayerTwo){
    string currentPlayer;
    char board[3][3];
    int line, column, setLine, setColumn, setPosition;
    int gameStatus = 1;
    int playerTurn = 1;
    int round = 0;
    int option;
    bool choiceMarked;

    fillBoard(board);

    while(round < 9 && gameStatus == 1){
        clearScreen();
        cout << "\nRound: " << round << "\n";
        cout << "Score: " << playerOne << " " << pointsPlayerOne << " X " << pointsPlayerTwo << " " << playerTwo << "\n";

        printBoard(board);
        printInstructions();

        if(playerTurn == 1){
            currentPlayer = playerOne;
        }else{
            currentPlayer = playerTwo;
        }

        choiceMarked = false;
        int positions[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};

        while(choiceMarked == false){
            cout << "\n" << currentPlayer << ", choose one position number acoording to the map above: ";
            cin >> setPosition;

            setLine = positions[setPosition-1][0];
            setColumn = positions[setPosition-1][1];

            if(board[setLine][setColumn] == '-'){
                choiceMarked = true;
                if(playerTurn == 1){
                    board[setLine][setColumn] = 'X';
                    playerTurn = 2;
                }else{
                    board[setLine][setColumn] = 'O';
                    playerTurn = 1;
                }
            }
        }

        if(checkBoard(board) == 1){
            cout << "The X player won!\n";
            pointsPlayerOne++;
            gameStatus = 0;
        }else if(checkBoard(board) == 2){
            cout << "The O player won!\n";
            pointsPlayerTwo++;
            gameStatus = 0;
        }else{
            cout << "The game tied!\n";
        }
        round++;
    }
    printBoard(board);
    cout << "Game Over!\n";
    cout << "What do you want to do?\n";
    cout << "1 - Keep playing\n";
    cout << "2 - Menu\n";
    cout << "3 - Exit\n\n";
    cin >> option;
    if(option == 1){
        game(playerOne, playerTwo, pointsPlayerOne, pointsPlayerTwo);
    }else if(option == 2){
        menu();
    }else if(option == 3){
        cout << "I hope you had a great time!\n";
        cout << "Goodbye!\n";
    }
}

void menu(){
    int option = 0;
    string playerOne, playerTwo;

    while(option < 1 || option > 2){
        clearScreen();
        cout << "Welcome to the TicTacToe Game!\n";
        cout << "Type the number of the option that you want and click ENTER:\n\n";
        cout << "1 - Play\n";
        cout << "2 - Exit\n\n";
        cin >> option;

        switch(option){
            case 1:
                cout << "Game Started!\n";
                cout << "What is the name of the Player 1? ";
                cin >> playerOne;
                cout << "What is the name of the Player 2? ";
                cin >> playerTwo;
                game(playerOne, playerTwo, 0, 0);
                break;
            case 2:
                cout << "I hope you had a great time!\n";
                cout << "Goodbye!\n";
                break;
        }
    }
}

int main(){
    menu();
    return 0;
}
