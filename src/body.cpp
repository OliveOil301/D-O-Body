#include <Arduino.h>
#include <Servo.h>
#include <body.h>

//*variables for the different rotations in the body for retrieval----------------------------
int lateralWeightAngle;

//*Servo pin definitions-------------------------------------------------------------------------
int lateralWeightPin = 6; // TODO: pick real pins
int driveMotorPin = 12;

//*Servo object definitions----------------------------------------------------------------------
Servo lateralWeightServo;

Head head;

Body::Body(void) {}

void Body::bodySetup()
{
    lateralWeightServo.attach(lateralWeightPin);
    head.headSetup();
}

/** setNeckAngles(int rotation, int tilt)
 * @param rotation: 0 degrees is straight up, positive is forward and negative is backward. Max angle is +/- 25 degrees
 * @param tilt: 0 degrees is perpendicular to the rotation bar, positive is tilting the head down and negative is tilting the head up. Max angle is +/- 25 degrees
 * This sets the neck rotation and tilt angle in degrees.
 * This is the rotation of the entire head and neck assembly relative to the main body and the tilt relative to the rotation bar
 */
void Body::setNeckAngles(int rotation, int tilt)
{
    head.setNeckRotation(rotation);
    head.setNeckTilt(tilt);
}

/** setHeadAngles(int rotation, int tilt, int nod)
 * @param rotation: 0 degrees is straight up, positive is forward and negative is backward. Max angle is +/- 25 degrees
 * @param tilt: 0 degrees is perpendicular to the rotation bar, positive is tilting the head down and negative is tilting the head up. Max angle is +/- 25 degrees
 * @param nod: 0 degrees is perpendicular to the rotation bar, positive is tilting the head down and negative is tilting the head up. Max angle is +/- 25 degrees
 * This sets the head rotation, tilt, and nod angle in degrees.
 */
void Body::setHeadAngles(int rotation, int tilt, int nod)
{
    head.setHeadRotation(rotation);
    head.setHeadTilt(tilt);
    head.setHeadNod(tilt);
}

/** setLateralWeightAngle(int angle)
 * @param angle: 0 degrees is in the middle, positive is right and negative is left. Max angle is +/- 25 degrees
 * TODO: find the real min and max angle
 * This sets the position of the lateral stabilization weight
 */
void Body::setLateralWeightAngle(int angle)
{
    if (angle > 25)
    {
        angle = 25;
    }
    else if (angle < -25)
    {
        angle = -25;
    }
    // Now we're actually setting/sending the angle
    lateralWeightAngle = angle;
    int servoAngle = map(angle, -25, 25, 5, 3); // TODO: make sure this map has the correct min and max vales for the servo
    lateralWeightServo.write(servoAngle);
}

void Body::balanceAtLateralAngle(int angle)
{
    float angleFromIMU = 12; // TODO replace with I2C comm to IMU
    float angleDiff = angle - angleFromIMU;
    // float angleOut =
}