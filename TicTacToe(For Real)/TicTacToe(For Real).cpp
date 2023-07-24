// Imports
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include<cstdlib>
#include <numeric>
#include <vector>
#include <random>
#include <array>

/* srand, rand */

using namespace std;

//Gameboard
char gameboard[3][3] = { {'1','2','3'} , {'4','5','6'}, {'7','8','9'} };

void printBoard() {

    // print a 3x3 with nums 1-9
    for (int i = 0; i < 3; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {

            cout << gameboard[i][j] << " ";
        }
    }
}
vector<int> UnavailableNUM;

int tie = 1; 

void chooseReplace(int choice) {

    // check choice exist
    bool exist = (find(begin(UnavailableNUM), end(UnavailableNUM), choice) != end(UnavailableNUM));

    // if it exists in the vector 
    while (exist) {
        cout << "Pick another SPOT" << endl;
        cin >> choice;
        exist = (find(begin(UnavailableNUM), end(UnavailableNUM), choice) != end(UnavailableNUM));
        
    }
    // if it is an available number
    UnavailableNUM.push_back(choice);
    tie++; 
    const int col = choice / 3;
    const int row = choice % 3 - 1;

    gameboard[col][row] = 'X';

};





void CPUchoices() {
    // ------------------------------- TODO ------------------------------------//
    //create a vector eith the numbers 1-10 that is shuffled up (Fisher–Yates ALG)//
    //THE CPU chooses a random number
    // if the number is part of the UNAV vector
    // push it out of the vector "A" and keep cycling untill one is found
    // else keep the number, convert it, and then add it to UNAV by pushing it

    int opt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    srand(time(NULL));

    for (int i = 8; i > 0; i--) {
        int randomIndex = rand() % (i + 1);
        int temp = opt[i];
        opt[i] = opt[randomIndex];
        opt[randomIndex] = temp;
    }

    int idx = 0;
    int current = opt[idx];
    // check current number exist
    bool exist = (find(begin(UnavailableNUM), end(UnavailableNUM), current) != end(UnavailableNUM));

    while (exist) {
        idx++;
        current = opt[idx];
        exist = (find(begin(UnavailableNUM), end(UnavailableNUM), current) != end(UnavailableNUM));
       
    }
    tie++;
    UnavailableNUM.push_back(current);
    const int col = current / 3;
    const int row = current % 3 - 1;

    gameboard[col][row] = 'O';

      
}

bool isWin;
bool CPUWIN;

bool checkWinner() {
    // check horizontal Player

    //--------------------------------------------------------------------------------------------------------//

    if (gameboard[0][0] == gameboard[0][1] && gameboard[0][1] == gameboard[0][2] && gameboard[0][0] == 'X') {
        isWin = true;
    }
    else if (gameboard[1][0] == gameboard[1][1] && gameboard[1][1] == gameboard[1][2] && gameboard[1][0] == 'X') {
        isWin = true;
    }
    else if (gameboard[2][0] == gameboard[2][1] && gameboard[2][1] == gameboard[2][2] && gameboard[2][0] == 'X') {
        isWin = true;
    }

    //--------------------------------------------------------------------------------------------------------//

    // check vertical Player
    if (gameboard[0][0] == gameboard[1][0] && gameboard[1][0] == gameboard[2][0] && gameboard[0][0] == 'X') {
        isWin = true;
    }
    if (gameboard[0][1] == gameboard[1][1] && gameboard[1][1] == gameboard[2][1] && gameboard[0][1] == 'X') {
        isWin = true;
    }

    if (gameboard[0][2] == gameboard[1][2] && gameboard[1][2] == gameboard[2][2] && gameboard[0][2] == 'X') {
        isWin = true;
    }

    //--------------------------------------------------------------------------------------------------------//

    // check diagonal Player 

    if (gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2] && gameboard[0][0] == 'X') {
        isWin = true;
    }
    if (gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0] && gameboard[0][2] == 'X') {
        isWin = true;
    }
    //--------------------------------------------------------------------------------------------------------//
    

    // check horizontal CPU

    //--------------------------------------------------------------------------------------------------------//


    if (gameboard[0][0] == gameboard[0][1] && gameboard[0][1] == gameboard[0][2] && gameboard[0][0] == 'O') {
        CPUWIN = true;
    }
    else if (gameboard[1][0] == gameboard[1][1] && gameboard[1][1] == gameboard[1][2] && gameboard[1][0] == 'O') {
        CPUWIN = true;
    }
    else if (gameboard[2][0] == gameboard[2][1] && gameboard[2][1] == gameboard[2][2] && gameboard[2][0] == 'O') {
        CPUWIN = true;
    }

    //--------------------------------------------------------------------------------------------------------//


    // check vertical CPU

    //--------------------------------------------------------------------------------------------------------//

    if (gameboard[0][0] == gameboard[1][0] && gameboard[1][0] == gameboard[2][0] && gameboard[0][0] == 'O') {
        CPUWIN = true;
    }
    if (gameboard[0][1] == gameboard[1][1] && gameboard[1][1] == gameboard[2][1] && gameboard[0][1] == 'O') {
        CPUWIN = true;
    }

    if (gameboard[0][2] == gameboard[1][2] && gameboard[1][2] == gameboard[2][2] && gameboard[0][2] == 'O') {
        CPUWIN = true;
    }

    //--------------------------------------------------------------------------------------------------------//


    // check diagonal CPU

    //--------------------------------------------------------------------------------------------------------//


    if (gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2] && gameboard[0][0] == 'O') {
        CPUWIN = true;
    }
    if (gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0] && gameboard[0][2] == 'O') {
        CPUWIN = true;
    }

    //--------------------------------------------------------------------------------------------------------//



    // to check for tie keep track of amount of moves if it is 9 then ummm its a tie
    return false;
}


int main()
{

    //initlized as false
    isWin = false;

    // while the winner is not decided keep playing

    // print board

    printBoard();
    // take UIS
    while (true) {

        int choice; cin >> choice;
        chooseReplace(choice);
        cout << "\nYour Turn:\n";
        printBoard();
        cout << "\nCPU's Turn:\n";
        CPUchoices();
        printBoard();
        checkWinner();

        // CPU WIN
        if (isWin == true) {
            cout << "You Won";
            break;
        }
        // CPU WIN
        if (CPUWIN == true) {
            cout << "CPU wins";
            break;
        }
        // choose spot
        if (tie == 10) {
            cout << "There is a tie";
        }
    }

    return 0;
}
