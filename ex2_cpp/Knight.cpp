#include "Knight.h"

/**
 * Check if the wanted moving is match the rules of knight.
 * @param x new x position.
 * @param y new y position.
 * @return true if move match the rules of piece, else false
 */
bool Knight::move(int x, int y) const
{
    bool flag = (((this->getX() == x + 1 or this->getX() == x - 1) and
            (this->getY() == y + 2 or this->getY() == y - 2)) or
           ((this->getY() == y + 1 or this->getY() == y - 1) and
            (this->getX() == x + 2 or this->getX() == x - 2)));
    return flag;
}
