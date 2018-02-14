#include <iostream>
#include <algorithm>
#include <vector>
#include "Board.h"

/**
 * Constructor
 * Init 2D array that represent board in the game. Every square hold piece in the game or
 * nullptr if square is empty.
 */
Board::Board()
{
    _board = new Piece **[BOARD_SIZE];
    for (int j = 0; j < BOARD_SIZE; ++j)
    {
        _board[j] = new Piece *[BOARD_SIZE];
        for (int i = 0; i < BOARD_SIZE; ++i)
        {
            _board[j][i] = nullptr;
        }
    }
    int row = 1;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        this->_board[row + 5][i] = new Pawn(i, row + 5, WHITE_PLAYER); // init white pawns
        this->_board[row][i] = new Pawn(i, row, BLACK_PLAYER); // init black pawns
    }
    // init black pieces
    // Rooks
    this->_board[LINE_ZERO][COLUMN_ZERO] = new Rook(COLUMN_ZERO, LINE_ZERO, BLACK_PLAYER);
    this->_board[LINE_ZERO][COLUMN_SEVEN] = new Rook(COLUMN_SEVEN, LINE_ZERO, BLACK_PLAYER);
    // Knights
    this->_board[LINE_ZERO][COLUMN_ONE] = new Knight(COLUMN_ONE, LINE_ZERO, BLACK_PLAYER);
    this->_board[LINE_ZERO][COLUMN_SIX] = new Knight(COLUMN_SIX, LINE_ZERO, BLACK_PLAYER);
    // Bishops
    this->_board[LINE_ZERO][COLUMN_TWO] = new Bishop(COLUMN_TWO, LINE_ZERO, BLACK_PLAYER);
    this->_board[LINE_ZERO][COLUMN_FIVE] = new Bishop(COLUMN_FIVE, LINE_ZERO, BLACK_PLAYER);
    // Queen
    this->_board[LINE_ZERO][COLUMN_THREE] = new Queen(COLUMN_THREE, LINE_ZERO, BLACK_PLAYER);
    // King
    this->_board[LINE_ZERO][COLUMN_FOUR] = new King(COLUMN_FOUR, LINE_ZERO, BLACK_PLAYER);
    // init white pieces
    // Rooks
    this->_board[LINE_SEVEN][COLUMN_ZERO] = new Rook(COLUMN_ZERO, LINE_SEVEN, WHITE_PLAYER);
    this->_board[LINE_SEVEN][COLUMN_SEVEN] = new Rook(COLUMN_SEVEN, LINE_SEVEN, WHITE_PLAYER);
    // Knights
    this->_board[LINE_SEVEN][COLUMN_ONE] = new Knight(COLUMN_ONE, LINE_SEVEN, WHITE_PLAYER);
    this->_board[LINE_SEVEN][COLUMN_SIX] = new Knight(COLUMN_SIX, LINE_SEVEN, WHITE_PLAYER);
    // Bishops
    this->_board[LINE_SEVEN][COLUMN_TWO] = new Bishop(COLUMN_TWO, LINE_SEVEN, WHITE_PLAYER);
    this->_board[LINE_SEVEN][COLUMN_FIVE] = new Bishop(COLUMN_FIVE, LINE_SEVEN, WHITE_PLAYER);
    // Queen
    this->_board[LINE_SEVEN][COLUMN_THREE] = new Queen(COLUMN_THREE, LINE_SEVEN, WHITE_PLAYER);
    // King
    this->_board[LINE_SEVEN][COLUMN_FOUR] = new King(COLUMN_FOUR, LINE_SEVEN, WHITE_PLAYER);
    this->_whiteKing = this->_board[LINE_SEVEN][COLUMN_FOUR]; // pointer to white king
    this->_blackKing = this->_board[LINE_ZERO][COLUMN_FOUR];  // pointer to black king
}

/**
 * Destructor
 * Delete every square in the 2D table, then the rows and then the Board.
 */
Board::~Board()
{
    for (int j = 0; j < BOARD_SIZE; ++j)
    {
        for (int i = 0; i < BOARD_SIZE; ++i)
        {
            delete _board[j][i];
        }
        delete[] _board[j];
    }
    delete[] _board;
}


/**
 * Print board (like format asked in the pdf of the ex2)
 */
void Board::printBoard() const
{
    string square, text;
    auto print = [](const char& n) { cout << n; };
    std::vector<char> rowChar{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    cout << "  ";
    for_each (rowChar.begin(), rowChar.end(), print);
    cout << std::endl << std::endl;

    for (int row = LINE_ZERO; row < BOARD_SIZE; ++row)
    {
        cout << abs(row - 8) << " ";
        for (int col = COLUMN_ZERO; col < BOARD_SIZE; ++col)
        {
            cout << _printSquare(row, col);
        }
        cout << " " << abs(row - 8) ;
        cout << std::endl;
    }
    cout << std::endl << "  ";
    for_each (rowChar.begin(), rowChar.end(), print);
    cout << std::endl << std::endl;
}

/**
 * Print square following the format given in pdf.
 * @param row number in board.
 * @param col number in board.
 * @return code string the print of her will be shown on screen
 */
const string Board::_printSquare(int row, int col) const
{
    string background, piece = " ", text = "0";
    background = (row + col) % 2 == 0 ? "46" : "42";
    if (this->_board[row][col] != nullptr)
    {
        text = this->_board[row][col]->getPlayer() == WHITE_PLAYER ? "37" : "30";
        piece = this->_board[row][col]->getUnicode();
    }
    return "\33[" + text + ";" + background + "m" + piece + "\33[0m";
}

/**
 * Check if moving the piece in [x1,y1] to [x2,y2] is inside the board bounds.
 * @param x1 col number in board where piece we want to move located.
 * @param y1 row number in board where piece we want to move located.
 * @param x2 col number in board where we wish to move the piece.
 * @param y2 row number in board where we wish to move the piece.
 * @return true if it's legal (in board bounds), else false
 */
bool Board::_checkBounds(int x1, int y1, int x2, int y2)
{
    return !(x1 >= BOARD_SIZE or x2 >= BOARD_SIZE or y1 >= BOARD_SIZE or y2 >= BOARD_SIZE or
            x1 < COLUMN_ZERO or x2 < COLUMN_ZERO or y1 < LINE_ZERO or y2 < LINE_ZERO or
            (x1 == x2 and y1 == y2));
}

/**
 * Check if the wanted move for piece in x1,y1 to x2,y2 is legal.
 * @param x1 col number in board where piece we want to move located.
 * @param y1 row number in board where piece we want to move located.
 * @param x2 col number in board where we wish to move the piece.
 * @param y2 row number in board where we wish to move the piece.
 * @param player represent to who player the piece belong (0 if white, 1 if to the black).
 * @return true if the move is legal, else false
 */
bool Board::legalMove(int x1, int y1, int x2, int y2, int player)
{
    if (!_isLegalPath(x1, y1, x2, y2, player))
    {
        return false;
    }
    Piece *promoted = nullptr, *prevPromoted = nullptr;
    Piece *temp = this->_board[y2][x2];
    Piece *king = this->_whiteKing;
    this->_board[y2][x2] = this->_board[y1][x1]; // update board with the move
    this->_board[y2][x2]->setCoordinates(x2, y2);
    this->_board[y1][x1] = nullptr; // "remove" the the previous place of the piece
    // promote of pawn
    if (this->_board[y2][x2]->getType() == "Pawn" and (y2 == LINE_SEVEN or y2 == LINE_ZERO))
    {
        prevPromoted = this->_board[y2][x2];
        promoted = new Queen (this->_board[y2][x2]-> getX(), this->_board[y2][x2]-> getY(),
                                     this->_board[y2][x2]-> getPlayer());
        this->_board[y2][x2] = promoted;
    }
    if (player == BLACK_PLAYER) // check if the player king is threaten because of the given move
    {
        king = this->_blackKing;
    }
    if (_isPieceThreaten(king, player))
    {
        if (promoted != nullptr)
        {
            this->_board[y1][x1] = prevPromoted;
            this->_board[y1][x1]->setCoordinates(x1, y1);
            this->_board[y2][x2] = temp;
//            delete prevPromoted;
            delete promoted;
            delete temp;
        }
        else
        {
            this->_board[y1][x1] = this->_board[y2][x2]; // illegal move, replace to the original
            this->_board[y2][x2] = temp;
            this->_board[y1][x1]->setCoordinates(x1, y1);
            delete temp;
        }
        return false;
    }
    this->_board[y2][x2]->setMoved();
    if (player == BLACK_PLAYER)
    {
        king = this->_whiteKing;
    }
    else
    {
        king = this->_blackKing;
    }
    // check if the player check opponent
    this->_isCheck = _isPieceThreaten(king, king->getPlayer());
    delete temp;
    if (promoted != nullptr)
    {
        delete prevPromoted;
    }
    return true;
}

/**
 * Check (if piece can moves in rows) if there is another piece in the way to the new x2,y2
 * location in the board, if so we can't moving there.
 * @param x1 col number in board where piece we want to move located.
 * @param y1 row number in board where piece we want to move located.
 * @param x2 col number in board where we wish to move the piece.
 * @return true if the move is legal, else false
 */
bool Board::_checkRow(int x1, int y1, int x2) const
{
    int start = x1 + 1, end = x2;
    if (x2 < x1)
    {
        start = x2 + 1;
        end = x1;
    }
    for (int col = start; col < end; ++col)
    {
        if (this->_board[y1][col] != nullptr) // if there is piece on way
        {
            return false;
        }
    }
    return true;
}

/**
 * Check (if piece can moves in columns) if there is another piece in the way to the new x2,y2
 * location in the board, if so we can't moving there.
 * @param x1 col number in board where piece we want to move located.
 * @param y1 row number in board where piece we want to move located.
 * @param y2 row number in board where we wish to move the piece.
 * @return true if the move is legal, else false
 */
bool Board::_checkCol(int x1, int y1, int y2) const
{
    int start = y1 + 1, end = y2;
    if (y2 < y1)
    {
        start = y2 + 1;
        end = y1;
    }
    for (int row = start; row < end; ++row)
    {
        if (this->_board[row][x1] != nullptr)  // if there is piece on way
        {
            return false;
        }
    }
    return true;
}

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
bool Board::_backDiagonal(int x1, int y1, int x2, int y2) const
{
    int start = y1 - 1, col = x1 - 1, end = y2;
    if (x2 > x1)
    {
        start = y2 - 1;
        col = x2 - 1;
        end = y1;
    }
    for (int row = start; row > end; --row)
    {
        if (this->_board[row][col] != nullptr)  // if there is piece on way
        {
            return false;
        }
        --col;
    }
    return true;
}

/**
 * Check (for piece can moves in diagonals) if there is another piece in the way to the new
 * x2,y2 location in the board (by moving like "/").
 * @param x1 col number in board where piece we want to move located.
 * @param y1 row number in board where piece we want to move located.
 * @param x2 col number in board where we wish to move the piece.
 * @param y2 row number in board where we wish to move the piece.
 * @return true if the move is legal, else false
 */
bool Board::_forwardDiagonal(int x1, int y1, int x2, int y2) const
{
    int start = y1 - 1, col = x1 + 1, end = y2;
    if (x2 < x1)
    {
        start = y2 - 1;
        col = x2 + 1;
        end = y1;
    }
    for (int row = start; row > end; --row)
    {
        if (this->_board[row][col] != nullptr)  // if there is piece on way
        {
            return false;
        }
        ++col;
    }
    return true;
}

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
bool Board::_checkDiagonal(int x1, int y1, int x2, int y2) const
{
    if ((x2 < x1 and y2 > y1) or (x2 > x1 and y2 < y1))
    {
        return _forwardDiagonal(x1, y1, x2, y2);
    }
    return _backDiagonal(x1, y1, x2, y2);
}

/**
 * Check if opponent threat the given piece
 * @param piece of player
 * @param player represent to who player the piece belong (0 if white, 1 if to the black).
 * @return
 */
bool Board::_isPieceThreaten(Piece *piece, int player)
{
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            if (this->_board[row][col] != nullptr and
                this->_board[row][col]->getPlayer() != player)
            {
                if (_isLegalPath(col, row, piece->getX(), piece->getY(),
                    this->_board[row][col]->getPlayer()))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
* Access method for isCheck flag.
* @return isCheck value (if there is check in board)
*/
bool Board::getIsCheck() const
{
    return _isCheck;
}

/**
 * Check if there is check mate on board.
 * @param player represent to who player the piece belong (0 if white, 1 if to the black).
 * @return true if there is check mate on board, else false
 */
bool Board::isCheckMate(int player)
{
    Piece *king;
    int x, y;
    if (player == BLACK_PLAYER) // check if player is threaten by trying moving piece
    {
        king = this->_whiteKing;
    }
    else
    {
        king = this->_blackKing;
    }
    x = king->getX();
    y = king->getY();
    // check all squares around the king for avoid check
    for (int col = king->getX() - 1; col <= king->getX() + 1; ++col)
    {
        for (int row = king->getY() + 1; row >= king->getY() - 1; --row)
        {
            if (_checkBounds(x, y, col, row) and this->_board[row][col] == nullptr)
            {
                this->_board[row][col] = king;
                king->setCoordinates(col, row);
                this->_board[y][x] = nullptr;
                // found place to run away from check
                if (!_isPieceThreaten(king, king->getPlayer()))
                {
                    this->_board[row][col] = nullptr;
                    king->setCoordinates(x, y);
                    this->_board[y][x] = king;
                    return false;
                }
                this->_board[row][col] = nullptr;
                king->setCoordinates(x, y);
                this->_board[y][x] = king;
            }
        }
    }
    return _isCheck;
}

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
bool Board::_isLegalPath(int x1, int y1, int x2, int y2, int player)
{
    // check if move is inside the bounds of the board and if there is a piece in x1,y1
    if (!_checkBounds(x1, y1, x2, y2) or this->_board[y1][x1] == nullptr)
    {
        return false;
    }
    // if move on another player piece
    if (this->_board[y2][x2] != nullptr and this->_board[y2][x2]->getPlayer() == player)
    {
        return false;
    }
    if (this->_board[y1][x1]->getPlayer() != player or !this->_board[y1][x1]->move(x2, y2))
    {
        return false;
    }
    if (this->_board[y1][x1]->getType() == "Pawn") // check if move match rules of Pawn
    {
        if (!_checkCol(x1, y1, y2) or (x1 == x2 and this->_board[y2][x2] != nullptr) or
            (x1 != x2 and (this->_board[y2][x2] == nullptr or
            this->_board[y2][x2]->getPlayer() == player)))
        {
            return false;
        }
    }
    if (this->_board[y1][x1]->getType() == "Rook") // check if move match rules of Rook
    {
        if (!_checkCol(x1, y1, y2) or !_checkRow(x1, y1, x2))
        {
            return false;
        }
    }
    if (this->_board[y1][x1]->getType() == "Bishop") // check if move match rules of Bishop
    {
        if (!_checkDiagonal(x1, y1, x2, y2))
        {
            return false;
        }
    }
    if (this->_board[y1][x1]->getType() == "Queen") // check if move match rules of Queen
    {
        if ((x1 == x2 and !(_checkCol(x1, y1, y2))) or
            (y1 == y2 and !(_checkRow(x1, y1, x2))) or
            (x1 != x2 and y1 != y2 and !(_checkDiagonal(x1, y1, x2, y2))))
        {
            return false;
        }
    }
    return true;
}

/**
 * Setter for isCheck flag.
 * @param flag true iff there is check on board
 */
void Board::setIsCheck(bool flag)
{
    _isCheck = flag;
}

/**
 * Check if player can do small castling, and if so do the castling and update the board.
 * @param player represent to who player the piece belong (0 if white, 1 if to the black).
 * @return true if player can do, else false
 */
bool Board::smallCastling(int player)
{
    int row = LINE_SEVEN;
    if (player == BLACK_PLAYER)
    {
        row = LINE_ZERO;
    }
    if (this->_board[row][COLUMN_SEVEN] == nullptr or this->_board[row][COLUMN_FOUR] == nullptr)
    {
        return false;
    }
    if (this->_board[row][COLUMN_SEVEN]->getType() == "Rook" and
        this->_board[row][COLUMN_FOUR]->getType() == "King")
    {
        if (!(this->_board[row][COLUMN_SEVEN]->movedBefore()) and
            !(this->_board[row][COLUMN_FOUR]->movedBefore())
            and (this->_board[row][COLUMN_FIVE] == nullptr) and
            (this->_board[row][COLUMN_SIX] == nullptr))
        {
            this->_board[row][COLUMN_FIVE] = this->_board[row][COLUMN_SEVEN]; // replace Rook place
            this->_board[row][COLUMN_FIVE]->setCoordinates(COLUMN_FIVE, row);
            this->_board[row][COLUMN_SEVEN] = nullptr; // put null in the original square of Rook
            this->_board[row][COLUMN_SIX] = this->_board[row][COLUMN_FOUR];  // king
            this->_board[row][COLUMN_SIX]->setCoordinates(COLUMN_SIX, row);
            this->_board[row][COLUMN_FOUR] = nullptr;
            // if king threaten by castling king
            if (!_isPieceThreaten(this->_board[row][COLUMN_SIX], player)
                and !_isPieceThreaten(this->_board[row][COLUMN_FIVE], player))
            {
                if (player == WHITE_PLAYER)
                {
                    this->_isCheck = _isPieceThreaten(this->_blackKing,
                    this->_blackKing->getPlayer());
                }
                else
                {
                    this->_isCheck = _isPieceThreaten(this->_whiteKing,
                    this->_blackKing->getPlayer());
                }
                return true;
            }
            this->_board[row][COLUMN_SEVEN] = this->_board[row][COLUMN_FIVE]; // rightRook
            this->_board[row][COLUMN_SEVEN]->setCoordinates(COLUMN_SEVEN, row);
            this->_board[row][COLUMN_FIVE] = nullptr;
            this->_board[row][COLUMN_FOUR] = this->_board[row][COLUMN_SIX];
            this->_board[row][COLUMN_FOUR]->setCoordinates(COLUMN_FOUR, row);
            this->_board[row][COLUMN_SIX] = nullptr;
        }
    }
    return false;
}

/**
 * Check if player can do big castling, and if so do the castling and update the board.
 * @param player represent to who player the piece belong (0 if white, 1 if to the black).
 * @return true if player can do, else false
 */
bool Board::bigCastling(int player)
{
    int row = LINE_SEVEN;
    if (player == BLACK_PLAYER)
    {
        row = LINE_ZERO;
    }
    if (this->_board[row][COLUMN_ZERO] == nullptr or this->_board[row][COLUMN_FOUR] == nullptr)
    {
        return false;
    }
    if (this->_board[row][COLUMN_ZERO]->getType() == "Rook" and
        this->_board[row][COLUMN_FOUR]->getType() == "King")
    {
        if (!(this->_board[row][COLUMN_ZERO]->movedBefore()) and
            !(this->_board[row][COLUMN_FOUR]->movedBefore())
            and (this->_board[row][COLUMN_ONE] == nullptr) and
            (this->_board[row][COLUMN_TWO] == nullptr)
            and (this->_board[row][COLUMN_THREE] == nullptr))
        {
            this->_board[row][COLUMN_THREE] = this->_board[row][COLUMN_ZERO]; // replace Rook place
            this->_board[row][COLUMN_THREE]->setCoordinates(COLUMN_THREE, row);
            this->_board[row][COLUMN_ZERO] = nullptr; // put null in the original square of Rook
            this->_board[row][COLUMN_TWO] = this->_board[row][COLUMN_FOUR];  // king
            this->_board[row][COLUMN_TWO]->setCoordinates(COLUMN_TWO, row);
            this->_board[row][COLUMN_FOUR] = nullptr;
            // if king threaten by castling king
            if (!_isPieceThreaten(this->_board[row][COLUMN_TWO], player)
                and !_isPieceThreaten(this->_board[row][COLUMN_THREE], player))
            {
                if (player == WHITE_PLAYER)
                {
                    this->_isCheck = _isPieceThreaten(this->_blackKing,
                    this->_blackKing->getPlayer());
                }
                else
                {
                    this->_isCheck = _isPieceThreaten(this->_whiteKing,
                    this->_blackKing->getPlayer());
                }
                return true;
            }
            this->_board[row][COLUMN_ZERO] = this->_board[row][COLUMN_THREE]; // leftRook
            this->_board[row][COLUMN_ZERO]->setCoordinates(COLUMN_ZERO, row);
            this->_board[row][COLUMN_THREE] = nullptr;
            this->_board[row][COLUMN_FOUR] = this->_board[row][COLUMN_TWO];
            this->_board[row][COLUMN_FOUR]->setCoordinates(COLUMN_FOUR, row);
            this->_board[row][COLUMN_TWO] = nullptr;
        }
    }
    return false;
}