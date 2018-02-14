#include "King.h"

/**
 * Check if the wanted moving is match the rules of king.
 * @param x new x position.
 * @param y new y position.
 * @return true if move match the rules of piece, else false
 */
bool King::move(int x, int y) const
{
    return ((x == getX() + 1 or x == getX() - 1) and y == getY()) or
            ((y == getY() + 1 or y == getY() - 1)  and x == getX()) or
            ((abs(this->getX() - x) - abs(this->getY() - y) == 0) and (abs(this->getX() - x) == 1));
}

/**
 * Setter the flag to true if king moved.
 */
void King::setMoved()
{
    _moved = true;
}

/**
 * Check if king moved before.
 * @return true if the piece moved already, else false
 */
bool King::movedBefore() const
{
    return _moved;
}
