//
// Created by nadav vitri on 20/12/2017.
//

#include "ArenstorfPoint.h"

/**
 *A constructor.
 * Point contain of position and velocity in axis x and y.
 * @param x position in axis x
 * @param y position in axis y
 * @param vx velocity in axis x
 * @param vy velocity in axis y
 */
ArenstorfPoint::ArenstorfPoint(long double x, long double y, long double vx, long double vy)
{
    _x = x;
    _y = y;
    _vx = vx;
    _vy = vy;
}

/**
* Access method for the x value.
* @return The x value
*/
long double ArenstorfPoint::getX()const
{
    return _x;
}

/**
* Access method for the y value.
* @return The y value
*/
long double ArenstorfPoint::getY()const
{
    return _y;
}

/**
* Access method for the vx value.
* @return The vx value
*/
long double ArenstorfPoint::getVX()const
{
    return _vx;
}

/**
* Access method for the vy value.
* @return The vy value
*/
long double ArenstorfPoint::getVY()const
{
    return _vy;
}

/**
 * Setter for new x position.
 * @param xNewPos new x position.
 */
void ArenstorfPoint::setX(long double xNewPos)
{
    _x = xNewPos;
}

/**
 * Setter for new y position.
 * @param yNewPos new y position.
 */
void ArenstorfPoint::setY(long double yNewPos)
{
    _y = yNewPos;
}

/**
 * Setter for new x velocity.
 * @param xNewVel new x velocity.
 */
void ArenstorfPoint::setVX(long double xNewVel)
{
    _vx = xNewVel;
}

/**
 * Setter for new y velocity.
 * @param yNewVel y velocity.
 */
void ArenstorfPoint::setVY(long double yNewVel)
{
    _vy = yNewVel;
}

/**
 * writes to the os a string representation of the point in the format x, y, vx, vy
 */
void operator<<(std::ostream& os, const ArenstorfPoint& a)
{
    os << std::setprecision(3) << std::scientific << a.getX() << ", "
       << std::setprecision(3) << std::scientific << a.getY();
}
