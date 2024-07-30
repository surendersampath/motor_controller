#include "motor_controller.h"
#include <math.h>

int8_t AverageThreeBytes(int8_t a, int8_t b, int8_t c)
{
    return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
}

uint16_t getVelocityForMotor(uint16_t startDist, uint16_t endDist, uint8_t currentDist, uint8_t maxSpeed, uint8_t maxAccel)
{
    // The velocity that the motor should be set to.
    uint16_t CalculatedVelocity = 0;


    // Distance at which the motor should start decelerating.
    uint16_t decelDist = (maxSpeed * maxSpeed) / (2 * maxAccel);

    if ( currentDist < startDist || currentDist > endDist )
    {
        // The motor is not in the correct position.
        CalculatedVelocity = 0;
    }

    //Determine the Phase of the motion.

    /* Phase 1: Acceleration */
    if ( currentDist <= startDist + decelDist )
    {   
        // Applying kinematic eqn. ( v^2 = u^2 + 2as ) 
        uint16_t distanceTravelled = currentDist - startDist;
        CalculatedVelocity = (uint16_t)sqrt(2 * maxAccel * distanceTravelled);
    }

    /* Phase 2: Constant Velocity */
    else if ( currentDist <= endDist - decelDist )
    {
        CalculatedVelocity = maxSpeed;
    }

    /* Phase 3: Deceleration */
    else if ( currentDist > decelDist )
    {
        // Applying kinematic eqn. ( v^2 = u^2 + 2as ) 
        uint16_t distanceRemaining = endDist - currentDist;
        CalculatedVelocity = (uint16_t)sqrt(2 * maxAccel * distanceRemaining);
    }
    
    return CalculatedVelocity;
}