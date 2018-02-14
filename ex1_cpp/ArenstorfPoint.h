//
// Created by nadav vitri on 20/12/2017.
//

#ifndef EX1_CPP_ARENSTORFPOINT_H
#define EX1_CPP_ARENSTORFPOINT_H

#include <iosfwd>
#include <ostream>
#include <iomanip>
#include <iostream>

/**
 * Class that represent point with position and velocity in x and y axis.
 */
class ArenstorfPoint
{
public:
    /**
     *A constructor.
     * Point contain of position and velocity in axis x and y.
     * @param x position in axis x
     * @param y position in axis y
     * @param vx velocity in axis x
     * @param vy velocity in axis y
     */
    ArenstorfPoint(long double x, long double y, long double vx, long double vy);

    /**
	* Access method for the x value.
	* @return The x value
    */
    long double getX()const;

    /**
	* Access method for the y value.
	* @return The y value
    */
    long double getY() const;

    /**
	* Access method for the vx value.
	* @return The vx value
    */
    long double getVX() const;

    /**
	* Access method for the vy value.
	* @return The vy value
    */
    long double getVY() const;

    /**
     * Setter for new x position.
     * @param xNewPos new x position.
     */
    void setX(long double xNewPos);

    /**
     * Setter for new y position.
     * @param yNewPos new y position.
     */
    void setY(long double yNewPos);

    /**
     * Setter for new x velocity.
     * @param xNewVel new x velocity.
     */
    void setVX(long double xNewVel);

    /**
     * Setter for new y velocity.
     * @param yNewVel y velocity.
     */
    void setVY(long double yNewVel);

    /**
     * writes to the os a string representation of the point in the format x, y, vx, vy
     */
    friend void operator<<(std::ostream& os, const ArenstorfPoint& a);

private:

    long double _x; /**< the x coordinate */

    long double _y; /**< the y coordinate */

    long double _vx; /**< the velocity of x coordinate */

    long double _vy; /**< the velocity of y coordinate */

};

#endif //EX1_CPP_ARENSTORFPOINT_H
