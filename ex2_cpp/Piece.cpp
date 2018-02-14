#include "Piece.h"

/**
* Access method for the xPos.
* @return The xPos value
*/
int Piece::getX() const
{
    return _x;
}

/**
* Access method for the yPos.
* @return The yPos value
*/
int Piece::getY() const
{
    return _y;
}

/**
* Access method for the player.
* @return The player value (0 if white, 1 if black)
*/
int Piece::getPlayer() const
{
    return this->_player;
}

/**
* Access method for the unicode.
* @return The unicode value
*/
const string Piece::getUnicode() const
{
    return _unicode;
}

/**
* Access method for the type.
* @return The unicode value
*/
const string Piece::getType() const
{
    return _pieceType;
}

/**
 * Check if the wanted moving is match the rules of the specific piece.
 * @param x new x position.
 * @param y new y position.
 * @return true if move match the rules of piece, else false
 */
bool Piece::move(int /* x */, int /* y */) const
{
    return false;
}

/**
 * Setter for new x and y positions.
 * @param x new x position.
 * @param y new y position.
 */
void Piece::setCoordinates(int x, int y)
{
    _x = x;
    _y = y;
}

/**
 * Check if piece moved before.
 * @return true if the piece moved already, else false
 */
bool Piece::movedBefore() const
{
    return 0;
}

/**
 * Setter the flag to true if piece moved.
 */
void Piece::setMoved()
{

}

