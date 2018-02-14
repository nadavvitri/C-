#ifndef EX2_BOARD_H
#define EX2_BOARD_H
#define BOARD_SIZE 8
#define LINE_ZERO 0
#define LINE_SEVEN 7
#define COLUMN_ZERO 0
#define COLUMN_ONE 1
#define COLUMN_TWO 2
#define COLUMN_THREE 3
#define COLUMN_FOUR 4
#define COLUMN_FIVE 5
#define COLUMN_SIX 6
#define COLUMN_SEVEN 7
#include "Piece.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
using std::string;
using std::cin;
using std::cout;

/**
 * Class represent the board in chess game
 */
class Board
{
private:
    Piece*** _board;
    Piece *_whiteKing, *_blackKing;
    bool _isCheck = false;  // flag represent if there is check on board

    /**
     * Print square following the format given in pdf.
     * @param row number in board.
     * @param col number in board.
     * @return code string the print of her will be shown on screen
     */
    const string _printSquare(int row, int col) const;

    /**
     * Check if moving the piece in [x1,y1] to [x2,y2] is inside the board bounds.
     * @param x1 col number in board where piece we want to move located.
     * @param y1 row number in board where piece we want to move located.
     * @param x2 col number in board where we wish to move the piece.
     * @param y2 row number in board where we wish to move the piece.
     * @return true if it's legal (in board bounds), else false
     */
    bool _checkBounds(int x1, int y1, int x2, int y2);

    /**
     * Check if the wanted moves for piece in x1,y1 to x2,y2 is generally legal by checking the
     * boundaries of the move, if player piece is in x2,y2, if the piece in x1,y1 belong to the
     * player that want to move and if the move match the rules of the specific rules.
     * @param x1 col number in board where piece we want to move located.
     * @param y1 row number in board where piece we want to move located.
     * @param x2 col number in board where we wish to move the piece.
     * @param y2 row number in board where we wish to move the piece.
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return true if the move is legal, else false
     */
    bool _isLegalPath(int x1, int y1, int x2, int y2, int player);

    /**
     * Check (if piece can moves in rows) if there is another piece in the way to the new x2,y2
     * location in the board, if so we can't moving there.
     * @param x1 col number in board where piece we want to move located.
     * @param y1 row number in board where piece we want to move located.
     * @param x2 col number in board where we wish to move the piece.
     * @return true if the move is legal, else false
     */
    bool _checkRow(int x1, int y1, int x2) const;

    /**
     * Check (if piece can moves in columns) if there is another piece in the way to the new x2,y2
     * location in the board, if so we can't moving there.
     * @param x1 col number in board where piece we want to move located.
     * @param y1 row number in board where piece we want to move located.
     * @param y2 row number in board where we wish to move the piece.
     * @return true if the move is legal, else false
     */
    bool _checkCol(int x1, int y1, int y2) const;

    /**
     * Check (for piece can moves in diagonals) if there is another piece in the way to the new
     * x2,y2 location in the board - by sending to another function that check the way of move in
     * diagonal (forward or backward, e.g. "/" or "\" way) if so we can't moving there.
     * @param x1 col number in board where piece we want to move located.
     * @param y1 row number in board where piece we want to move located.
     * @param x2 col number in board where we wish to move the piece.
     * @param y2 row number in board where we wish to move the piece.
     * @return true if the move is legal, else false
     */
    bool _checkDiagonal(int x1, int y1, int x2, int y2) const;

    /**
     * Check (for piece can moves in diagonals) if there is another piece in the way to the new
     * x2,y2 location in the board (by moving like "\").
     * @param x1 col number in board where piece we want to move located.
     * @param y1 row number in board where piece we want to move located.
     * @param x2 col number in board where we wish to move the piece.
     * @param y2 row number in board where we wish to move the piece.
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return true if the move is legal, else false
     */
    bool _backDiagonal(int x1, int y1, int x2, int y2) const;

    /**
     * Check (for piece can moves in diagonals) if there is another piece in the way to the new
     * x2,y2 location in the board (by moving like "/").
     * @param x1 col number in board where piece we want to move located.
     * @param y1 row number in board where piece we want to move located.
     * @param x2 col number in board where we wish to move the piece.
     * @param y2 row number in board where we wish to move the piece.
     * @return true if the move is legal, else false
     */
    bool _forwardDiagonal(int x1, int y1, int x2, int y2) const;

    /**
     * Check if opponent threat the given piece
     * @param piece of player
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return
     */
    bool _isPieceThreaten(Piece *piece, int player);

public:
    /**
     * Constructor
     * Init 2D array that represent board in the game. Every square hold piece in the game or
     * nullptr if square is empty.
     */
    Board ();

    /**
     * Destructor
     * Delete every square in the 2D table, then the rows and then the Board.
     */
    ~Board();

    /**
     * Print board (like format asked in the pdf of the ex2)
     */
    void printBoard() const;

    /**
     * Check if the wanted move for piece in x1,y1 to x2,y2 is legal.
     * @param x1 col number in board where piece we want to move located.
     * @param y1 row number in board where piece we want to move located.
     * @param x2 col number in board where we wish to move the piece.
     * @param y2 row number in board where we wish to move the piece.
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return true if the move is legal, else false
     */
    bool legalMove(int x1, int y1, int x2, int y2, int player);

    /**
	* Access method for isCheck flag.
	* @return isCheck value (if there is check in board)
    */
    bool getIsCheck() const;

    /**
     * Setter for isCheck flag.
     * @param flag true iff there is check on board
     */
    void setIsCheck(bool flag);

    /**
     * Check if there is check mate on board.
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return true if there is check mate on board, else false
     */
    bool isCheckMate(int player);

    /**
     * Check if player can do small castling, and if so do the castling and update the board.
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return true if player can do, else false
     */
    bool smallCastling(int player);

    /**
     * Check if player can do big castling, and if so do the castling and update the board.
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return true if player can do, else false
     */
    bool bigCastling(int player);
};


#endif //EX2_BOARD_H
