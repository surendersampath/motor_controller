#include "motor_controller.h"
#include <math.h>


uint16_t getVelocityForMotor(uint16_t encoderStart, uint16_t encoderEnd, uint16_t encoderCurrent, 
                             uint8_t maxSpeed, uint8_t maxAccel)
{
    /* The velocity that the motor should be set to. */
    uint16_t CalculatedVelocity = 0U;

    /* Check if the motor is within the valid range */
    if ( encoderCurrent < encoderStart || encoderCurrent > encoderEnd )
    {
        // The motor is not in the correct position.
        // TODO : Add Error Log.
        return 0U;
    }

    /* Distance at which the motor should start decelerating. */
    uint16_t decelDist = (maxSpeed * maxSpeed) / (2 * maxAccel);

    /* Determine the Phase of the motion. */

    /* Phase 1: Acceleration */
    if ( encoderCurrent < encoderStart + decelDist )
    {   
        // Applying kinematic eqn. ( v^2 = u^2 + 2as ) 
        uint16_t distanceTravelled = encoderCurrent - encoderStart;
        CalculatedVelocity = (uint16_t)sqrt(2.0F * maxAccel * distanceTravelled);
    }

    /* Phase 2: Constant Velocity */
    else if ( encoderCurrent < encoderEnd - decelDist )
    {
        CalculatedVelocity = maxSpeed;
    }

    /* Phase 3: Deceleration */
    else
    {
        /*  Applying kinematic eqn. ( v^2 = u^2 + 2as ) */
        uint16_t distanceRemaining = encoderEnd - encoderCurrent;
        CalculatedVelocity = (uint16_t)sqrt(2.0F * maxAccel * distanceRemaining);
    }

    /* Ensure that the calculated velocity does not exceed the max speed. */
    if ( CalculatedVelocity > maxSpeed )
    {
        // TODO : Add Warning Log.
        CalculatedVelocity = maxSpeed;
    }

    /* Ensure that it does not acceerate beyond end stop distance. */
    if ( CalculatedVelocity > encoderEnd - encoderCurrent )
    {
        // TODO : Add Warning Log.
        CalculatedVelocity = encoderEnd - encoderCurrent;
    }

    /* Return the calculated velocity */
    return CalculatedVelocity;
}