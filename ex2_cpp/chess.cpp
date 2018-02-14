#include <iostream>
#include <map>
#include "Board.h"
#define POS_ZERO_IN_LINE 0
#define POS_ONE_IN_LINE 1
#define POS_TWO_IN_LINE 2
#define POS_THREE_IN_LINE 3
#define ASCII_CODE 48
#define BIG_CASTLING "o-o-o"
#define SMALL_CASTLING "o-o"
#define PRINT_CHECK "\33[37;41mCheck!\33[0m"
#define PRINT_ILLEGAL_MOVE "\33[37;41millegal move\33[0m"
#define PRINT_WON " won!"
using std::string;
using std::cin;
using std::cout;

/**
 * Gets input from user and translate to coordinate in the matrix representing the board.
 * @param user name of user.
 * @param line input from user.
 * @param player 0 for white player and 1 for black player.
 * @param wasCheck flag representing if there is check in game.
 * @param castleFlag flag representing if player make castling.
 * @param x1 col number in board where piece we want to move located.
 * @param y1 row number in board where piece we want to move located.
 * @param x2 col number in board where we wish to move the piece.
 * @param y2 row number in board where we wish to move the piece.
 * @param board 2D array that represent board in the game.
 */
void moveInput(string &user, string &line, int &player, bool &wasCheck, bool &castleFlag,
               int &x1, int &y1, int &x2, int &y2, Board &board)
{
    std::map<char, int> toNum =
    {
        { 'A', 0 },
        { 'B', 1 },
        { 'C', 2 },
        { 'D', 3 },
        { 'E', 4 },
        { 'F', 5 },
        { 'G', 6 },
        { 'H', 7 }
    };
    cout << user << ": Please enter your move:" << std::endl;
    cin >> line;
    if (line == BIG_CASTLING || line == SMALL_CASTLING)  // trying for making castling
    {
        if (!wasCheck)
        {
            castleFlag = line == BIG_CASTLING ? board.bigCastling(player) : board.smallCastling(player);
        }
        else
        {
            castleFlag = false;
        }
    }
    else
    {
        // translate input to coordinate in matrix
        x1 = toNum[line[POS_ZERO_IN_LINE]];
        y1 = BOARD_SIZE - (line[POS_ONE_IN_LINE] - ASCII_CODE);
        x2 =  toNum[line[POS_TWO_IN_LINE]];
        y2 = BOARD_SIZE - (line[POS_THREE_IN_LINE] - ASCII_CODE);
    }
}

/**
 * Runs the game. First we print the welcoming message to screen and getting the names of the
 * players. The game run until there is a check mate, and every round we print the board to screen.
 * @param board 2D array that represent board in the game.
 */
void runGame(Board &board)
{
    string white, black, user, line;
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0, player = BLACK_PLAYER;
    bool castleFlag = false, wasCheck = false;
    cout << "Enter white player name:" << std::endl;
    cin >> white;
    cout << "Enter black player name:" << std::endl;
    cin >> black;
    user = black;
    while (!board.isCheckMate(player)) // run until check mate
    {
        user = (user == white) ? black : white;
        player = BLACK_PLAYER - player; // flip between players
        board.printBoard();
        if(board.getIsCheck())
        {
            cout << PRINT_CHECK << std::endl;
            wasCheck = true;
            board.setIsCheck(false);
        }
        else
        {
            wasCheck = false;
        }
        moveInput(user, line, player, wasCheck, castleFlag, x1, y1, x2, y2, board);
        while ((line[POS_ZERO_IN_LINE] != 'o' and !board.legalMove(x1, y1, x2, y2, player)) or
               (line[POS_ZERO_IN_LINE] == 'o' and !castleFlag))
        {
            cout << PRINT_ILLEGAL_MOVE << std::endl;
            board.printBoard();
            moveInput(user, line, player, wasCheck, castleFlag, x1, y1, x2, y2, board);
        }
    }
    board.printBoard();
    cout << user << PRINT_WON << std::endl;
}

/**
 * Main function of program
 * @return 0 in success
 */
int main()
{

    Board board;
    runGame(board);
    return EXIT_SUCCESS;
}
