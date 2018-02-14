//
// Created by nadav vitri on 20/12/2017.
//

#include "Arenstorf.h"

const long double ALPHA = 0.012299L;
const long double BETA = 1 - ALPHA;

/**
 * compute the trajectory points and write it to the output stream
 * @param init Arenstorf point
 * @param n number of steps
 * @param m number of steps to save
 * @param dt time / n
 * @param out outputFile to write the results of points to it
 * @return 0 on success, -1 on an error
 */
int Arenstorf::computeArenstorf(const ArenstorfPoint &init, unsigned int n, unsigned int m,
                                long double dt, std::ostream &out)
{
    long double d1, d2, a_x, a_y;
    // init temp point for updating every step of calculating the Arenstorf Orbit
    ArenstorfPoint tempPoint (init.getX(), init.getY(), init.getVX(), init.getVY());
    long step = n / m;
    for (int i = 0; i <= (n - step); i++)
    {
        d1 = calculateD1(tempPoint.getX(), tempPoint.getY());
        d2 = calculateD2(tempPoint.getX(), tempPoint.getY());
        a_x = calculateVx(tempPoint.getX(), tempPoint.getVY(), d1, d2);
        a_y = calculateVy(tempPoint.getY(), tempPoint.getVX(), d1, d2);
        tempPoint.setX(tempPoint.getX() + tempPoint.getVX() * dt);
        tempPoint.setY(tempPoint.getY() + tempPoint.getVY() * dt);
        tempPoint.setVX(tempPoint.getVX() + a_x * dt);
        tempPoint.setVY(tempPoint.getVY() + a_y * dt);
        if ((i % step == 0) && i != (n - step))
        {
            out << tempPoint;
            out << ", ";
        }
    }
    out << tempPoint;
    out << "\n";
    return 0;
}

/**
 * calculate the D1 of the Arenstorf formula.
 * @param xCurPos - the current body position in axle x.
 * @param yCurPos - the current body position in axle y.
 * @return D1 according to Arenstorf formula.
 */
long double Arenstorf::calculateD1(long double xCurPos, long double yCurPos)
{

    long double d1 = powl(xCurPos + ALPHA, 2) + powl(yCurPos, 2);
    return powl(d1, 1.5);
}

/**
 * Calculate the D2 of the Arenstorf formula.
 * @param xCurPos - the current body position in axle x.
 * @param yCurPos - the current body position in axle y.
 * @return D2 according to Arenstorf formula.
 */
long double Arenstorf::calculateD2(long double xCurPos, long double yCurPos)
{
    long double d2 = powl(xCurPos - BETA, 2) + powl(yCurPos, 2);
    return powl(d2, 1.5);
}

/**
 * Calculate the velocity in a specific point x.
 * @param xCurPos - the current body position in axle x.
 * @param yCurVelocity - the current body velocity in axle y.
 * @param d1 - D1 according to Arenstorf formula.
 * @param d2 - D2 according to Arenstorf formula.
 * @return the velocity according to Arenstorf formula.
 */
long double
Arenstorf::calculateVx(long double xCurPos, long double yCurVelocity, long double d1,
                       long double d2)
{
    long double xVelocity = (xCurPos + 2 * (yCurVelocity) - BETA * ((xCurPos + ALPHA) / d1) -
                             (ALPHA) * ((xCurPos - BETA) / d2));
    return xVelocity;
}

/**
 * Calculate the velocity in a specific point y.
 * @param yCurPos - the current body position in axle y.
 * @param xCurVelocity - the current body velocity in axle x.
 * @param d1 - D1 according to Arenstorf formula.
 * @param d2 - D2 according to Arenstorf formula.
 * @return the velocity according to Arenstorf formula.
 */
long double
Arenstorf::calculateVy(long double yCurPos, long double xCurVelocity, long double d1,
                       long double d2)
{
    long double yVelocity = (yCurPos - 2 * (xCurVelocity) - BETA * (yCurPos / d1)
                             - ALPHA * (yCurPos / d2));
    return yVelocity;
}