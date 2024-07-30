#include <stdio.h>
#include "motor_controller.h"

void simulateMotorMotion(uint16_t startDist, uint16_t endDist, uint8_t maxSpeed, uint8_t maxAccel)
{
    printf("Position\tVelocity\n");
    for (uint16_t currentDist = startDist; currentDist <= endDist; currentDist++)
    {
        uint16_t velocity = getVelocityForMotor(startDist, endDist, currentDist, maxSpeed, maxAccel);
        printf("%d\t\t%d\n", currentDist, velocity);
    }
}

int main()
{
    // Define parameters
    uint16_t startDist = 0;
    uint16_t endDist = 1000;
    uint8_t maxSpeed = 20;
    uint8_t maxAccel = 10;

    // Simulate motor motion from start to stop
    simulateMotorMotion(startDist, endDist, maxSpeed, maxAccel);

    return 0;
}