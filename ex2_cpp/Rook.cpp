#include "Rook.h"

/**
 * Check if the wanted moving is match the rules of rook.
 * @param x new x position.
 * @param y new y position.
 * @return true if move match the rules of piece, else false
 */
bool Rook::move(int x, int y) const
{
    return !(this->getX() != x and this->getY() != y);
}

/**
 * Check if rook moved before.
 * @return true if the piece moved already, else false
 */
bool Rook::movedBefore() const
{
    return _moved;
}

/**
 * Setter the flag to true if rook moved.
 */
void Rook::setMoved()
{
    _moved = true;
}
