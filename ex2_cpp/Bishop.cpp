#include "Bishop.h"

/**
 * Check if the wanted moving is match the rules of bishop.
 * @param x new x position.
 * @param y new y position.
 * @return true if move match the rules of piece, else false
 */
bool Bishop::move(int x, int y) const
{
    return (abs(this->getX() - x) - abs(this->getY() - y) == 0) and this->getX() != x;
}
