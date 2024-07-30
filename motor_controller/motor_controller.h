#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <stdint.h>


int8_t AverageThreeBytes(int8_t a, int8_t b, int8_t c);

// Inputs
    // Position that the move starts from;
    // Position that the move ends at;
    // Current position as reported by the encoder;
    // Maximum speed that the load may reach during the move;
    // Maximum acceleration/deceleration of the load.
uint16_t getVelocityForMotor(uint16_t start, uint16_t end, uint8_t current, uint8_t maxSpeed, uint8_t maxAccel);

#endif /* MOTOR_CONTROLLER_H */
