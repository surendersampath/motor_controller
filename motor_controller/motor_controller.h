#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <stdint.h>

/**
 * @brief  Calculate the velocity for the motor based on the provided parameters.
 * 
 * @param  encoderStart   The position that the move starts from (in encoder counts).
 * @param  encoderEnd     The position that the move ends at (in encoder counts).
 * @param  encoderCurrent The current position as reported by the encoder (in encoder counts).
 * @param  maxSpeed       The maximum speed that the load may reach during the move (in counts per time unit).
 * @param  maxAccel       The maximum acceleration/deceleration of the load (in counts per time unit squared).
 * 
 * @return uint16_t       The calculated velocity for the motor (in counts per time unit).
 *
 * @note   This function assumes that the start, end, and current positions are within a valid range and that maxSpeed and maxAccel are within appropriate limits.
 */
uint16_t getVelocityForMotor(uint16_t encoderStart, uint16_t encoderEnd, uint16_t encoderCurrent, 
                             uint8_t maxSpeed, uint8_t maxAccel);

#endif /* MOTOR_CONTROLLER_H */
