#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);   
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player;
    char computer;
    bool running = true;

    std::cout << "\n==============Welcome to Tic Tac Toe!==============\n\n";
    std::cout << "You are to pick whether you want to be 'X' or 'O'.\n";
    std::cout << "The player to go first will be picked randomly.\n";
    std::cout << "Now, enjoy the game!\n\n";
    std::cout << "===================================================\n\n";
    std::cout << "Would you like to be 'X' or 'O'?: ";
    std::cin >> player;

    // handle user input
    player = toupper(player);
    if (player == 'X') {
        computer = 'O';
    } else if (player == 'O') {
        computer = 'X';
    } else {
        std::cout << "Invalid input. Please restart and pick between 'X or 'O'. \n";
        exit(0);
    }


    drawBoard(spaces);

    // Randomise who starts placing.
    srand(time(0));
    int whoGoesFirst = rand() % 2;
    
    // begin game
    if (whoGoesFirst == 0) {

        std::cout << "You goes first.\n";

        while (running) {
            playerMove(spaces, player);

            if (checkWinner(spaces, player, computer)) {
                running = false;
                break;
            } else if (checkTie(spaces)) {
                running = false;
                break;
            }

            drawBoard(spaces);

            std::cout << "Opponent's move... \n";

            computerMove(spaces, computer);

            if (checkWinner(spaces, player, computer)) {
                running = false;
                break;
            } else if (checkTie(spaces)) {
                running = false;
                break;
            }

            drawBoard(spaces);
        }
    } else {
        std::cout << "Opponent goes first.\n";
        while (running) {

            std::cout << "Opponent's move... \n";

            computerMove(spaces, computer);
            
            if (checkWinner(spaces, player, computer)) {
                running = false;
                drawBoard(spaces);
                break;
            } else if (checkTie(spaces)) {
                running = false;
                drawBoard(spaces);
                break;
            }

            drawBoard(spaces);

            playerMove(spaces, player);

            if (checkWinner(spaces, player, computer)) {
                running = false;
                drawBoard(spaces);
                break;
            } else if (checkTie(spaces)) {
                running = false;
                drawBoard(spaces);
                break;
            }

            drawBoard(spaces);
        }
    }

    return 0;
}

// draws the 9 celled grid for the game
void drawBoard(char *spaces) {
    std::cout << "\n    1    |2    |3    " << '\n';
    std::cout << "      " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "    _____|_____|_____" << '\n';
    std::cout << "    4    |5    |6    " << '\n';
    std::cout << "      " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "    _____|_____|_____" << '\n';
    std::cout << "    7    |8    |9    " << '\n';
    std::cout << "      " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "         |     |     " << '\n' << '\n';

}

// moves the player to the desired spot the user has entered
void playerMove(char *spaces, char player) {
    int number;
    do {
        std::cout << "\nEnter a spot to place a marker (1-9): ";
        std::cin >> number;

        // check user input
        if (number != 1 && number != 2 && number != 3 
            && number != 4 && number != 5 && number != 6 
            && number != 7 && number != 8 && number != 9) {

            std::cout << "\nInvalid input, please enter a number between 1-9.\n";

        } else {

            number--;
            //check whether cell is occupied
            if (spaces[number] == ' ') {
                spaces[number] = player;
                break;
            } else {
                std::cout << "\nCell already occupied. \n";
            }
        }
    } while (!number > 0 || !number < 8);
}

// Place the computer randomly onto a spot in the grid (Will try to make it have
// an optimised strategy later. Or randomise optimised or random strategy)
void computerMove(char *spaces, char computer) {
    int number;
    srand(time(0));
    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
    std::cout << "\nOpponent places on " << number << '\n';
}

// check if either the player or the computer has won. 
bool checkWinner(char *spaces, char player, char computer) {

    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
        drawBoard(spaces);
        spaces[0] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    } else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
        drawBoard(spaces);
        spaces[3] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    } else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        drawBoard(spaces);
        spaces[6] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    } else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        drawBoard(spaces);
        spaces[0] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    } else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
        drawBoard(spaces);
        spaces[1] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    } else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
        drawBoard(spaces);
        spaces[2] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    } else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        drawBoard(spaces);
        spaces[0] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    } else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
        drawBoard(spaces);
        spaces[2] == player ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
    } else {
        return false;
    }
    std::cout << "\n===================================================\n";
    return true;
}

// checking if tied
bool checkTie(char *spaces) {

    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }

    std::cout << "Tied! \n";

    return true;
}
