//
// Created by nadav vitri on 20/12/2017.
//

#ifndef EX1_CPP_ARENSTORF_H
#define EX1_CPP_ARENSTORF_H

#include <iosfwd>
#include <cmath>
#include <iomanip>
#include "ArenstorfPoint.h"

/**
 * Class that get point and steps and dt and calculate the Arenstorf Orbits.
 */
class Arenstorf
{
public:
    /**
     * compute the trajectory points and write it to the output stream
     * @param init Arenstorf point
     * @param n number of steps
     * @param m number of steps to save
     * @param dt time / n
     * @param out outputFile to write the results of points to it
     * @return 0 on success, -1 on an error
     */
    static int computeArenstorf(const ArenstorfPoint& init, unsigned int n, unsigned int m,
                                long double dt, std::ostream& out);
    /**
     * calculate the D1 of the Arenstorf formula.
     * @param xCurPos - the current body position in axle x.
     * @param yCurPos - the current body position in axle y.
     * @return D1 according to Arenstorf formula.
     */
    static long double calculateD1(long double xCurPos, long double yCurPos);

    /**
     * Calculate the D2 of the Arenstorf formula.
     * @param xCurPos - the current body position in axle x.
     * @param yCurPos - the current body position in axle y.
     * @return D2 according to Arenstorf formula.
     */
    static long double calculateD2(long double xCurPos, long double yCurPos);

    /**
     * Calculate the velocity in a specific point x.
     * @param xCurPos - the current body position in axle x.
     * @param yCurVelocity - the current body velocity in axle y.
     * @param d1 - D1 according to Arenstorf formula.
     * @param d2 - D2 according to Arenstorf formula.
     * @return the velocity according to Arenstorf formula.
     */
    static long double calculateVx(long double xCurPos, long double yCurVelocity, long double d1,
                                   long double d2);

    /**
     * Calculate the velocity in a specific point y.
     * @param yCurPos - the current body position in axle y.
     * @param xCurVelocity - the current body velocity in axle x.
     * @param d1 - D1 according to Arenstorf formula.
     * @param d2 - D2 according to Arenstorf formula.
     * @return the velocity according to Arenstorf formula.
     */
    static long double calculateVy(long double yCurPos, long double xCurVelocity, long double d1,
                                   long double d2);
};

#endif //EX1_CPP_ARENSTORF_H
