#include <unity.h>
#include <math.h>
#include <motor_controller.h>

void test_getVelocityForMotor_should_ReturnZeroIfOutOfRange(void)
{
    TEST_ASSERT_EQUAL_UINT16(0, getVelocityForMotor(100, 200, 99, 50, 10));  // Below start range
    TEST_ASSERT_EQUAL_UINT16(0, getVelocityForMotor(100, 200, 201, 50, 10)); // Above end range
}

void test_getVelocityForMotor_should_CalculateAccelerationPhase(void)
{
    // Test within acceleration phase
    uint16_t maxSpeed = 50;
    uint16_t maxAccel = 10;
    uint16_t encoderStart = 100;
    uint16_t encoderEnd = 200;
    uint16_t decelDist = (maxSpeed * maxSpeed) / (2 * maxAccel);

    uint16_t encoderCurrent = encoderStart + decelDist / 2;
    uint16_t expectedVelocity = (uint16_t)sqrt(2.0F * maxAccel * (encoderCurrent - encoderStart));
    TEST_ASSERT_EQUAL_UINT16(expectedVelocity, getVelocityForMotor(encoderStart, encoderEnd, encoderCurrent, maxSpeed, maxAccel));
}

void test_getVelocityForMotor_should_CalculateConstantVelocityPhase(void)
{
    // Test within constant velocity phase
    uint16_t maxSpeed = 50;
    uint16_t maxAccel = 10;
    uint16_t encoderStart = 100;
    uint16_t encoderEnd = 200;
    uint16_t decelDist = (maxSpeed * maxSpeed) / (2 * maxAccel);

    uint16_t encoderCurrent = encoderStart + decelDist + 1;
    TEST_ASSERT_EQUAL_UINT16(maxSpeed, getVelocityForMotor(encoderStart, encoderEnd, encoderCurrent, maxSpeed, maxAccel));

    encoderCurrent = encoderEnd - decelDist - 1;
    TEST_ASSERT_EQUAL_UINT16(maxSpeed, getVelocityForMotor(encoderStart, encoderEnd, encoderCurrent, maxSpeed, maxAccel));
}

void test_getVelocityForMotor_should_CalculateDecelerationPhase(void)
{
    // Test within deceleration phase
    uint16_t maxSpeed = 50;
    uint16_t maxAccel = 10;
    uint16_t encoderStart = 100;
    uint16_t encoderEnd = 200;
    uint16_t decelDist = (maxSpeed * maxSpeed) / (2 * maxAccel);

    uint16_t encoderCurrent = encoderEnd - decelDist / 2;
    uint16_t distanceRemaining = encoderEnd - encoderCurrent;
    uint16_t expectedVelocity = (uint16_t)sqrt(2.0F * maxAccel * distanceRemaining);
    TEST_ASSERT_EQUAL_UINT16(expectedVelocity, getVelocityForMotor(encoderStart, encoderEnd, encoderCurrent, maxSpeed, maxAccel));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_getVelocityForMotor_should_ReturnZeroIfOutOfRange);
    RUN_TEST(test_getVelocityForMotor_should_CalculateAccelerationPhase);
    RUN_TEST(test_getVelocityForMotor_should_CalculateConstantVelocityPhase);
    RUN_TEST(test_getVelocityForMotor_should_CalculateDecelerationPhase);


    return UNITY_END();
}
