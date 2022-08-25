#include <head.h>
#include <Arduino.h>
#include <Servo.h>

/*
The head's movements are defined as follows:
Also to note: up, down, left, and right are relative to the robot

Neck Rotation: This is the larger rod that rotates the neck and head assembly around the wheel
Neck Tilt: This is the smaller rod that changes the angle of the neck and head assembly

Head Rotation: This is the rotation of the cone head in the z-axis. Positive is right, negative is left
Head Nod: This is the angle of the head up-to-down. Positive is looking up, negative is looking down
Head Tilt: This is the angle of the head side-to-side. Positive is right, negative is left
*/

//*variables for the different rotations of the head and neck assembly----------------------------
int neckRotationAngle;
int neckTiltAngle;
int headRotationAngle;
int headNodAngle;
int headTiltAngle;

//*Servo pin definitions-------------------------------------------------------------------------
int neckRotationPin = 5;
int neckTiltPin = 4;

//*Servo object definitions----------------------------------------------------------------------
Servo neckRotationServo;
Servo neckTiltServo;

//*Servo min and max definitions----------------------------------------------------------------

//*Communication class for communicating with the head Arduino
Communication comm;

Head::Head(void) {}

/** constrainAngle(int angle, int minMax)
 * @param angle the angle that has to be constrained
 * @param minMax the min/max value to constrain the angle around. It is assumed the minimum is negative maximum
 * @return the constrained angle
 */
int constrainAngle(int angle, int minMax)
{
    if (angle > minMax)
    {
        angle = minMax;
    }
    else if (angle < (-1 * minMax))
    {
        angle = (-1 * minMax);
    }
    return angle;
}

void Head::headSetup()
{
    neckRotationServo.attach(neckRotationPin);
    neckTiltServo.attach(neckTiltPin);
}

/** setNeckRotation(int angle)
 * This sets the neck rotation angle in degrees.
 * This is the rotation of the entire head and neck assembly relative to the main body
 * 0 degrees is straight up, positive is forward and negative is backward
 * Max angle is +/- 25 degrees
 * The angle is stored in the class variable so it can be retrieved later
 */
void Head::setNeckRotation(int angle)
{
    angle = constrainAngle(angle, 25); // Constraining the angles to the min and max

    // Now we're actually setting/sending the angle
    neckRotationAngle = angle;
    int servoAngle = map(angle, -25, 25, 0, 180);
    neckRotationServo.write(servoAngle);
    //setNeckTilt(neckTiltAngle); // since the neck tilt angle is defined relative to the rotation bar, it needs to be updated
    // whenever the rotation bar is moved
}

/** setNeckTilt(int angle)
 * This sets the neck tilt angle in degrees.
 * This is the tilt of the entire head and neck assembly relative to the rotation bar
 * 0 degrees is perpendicular to the rotation bar, positive is tilting the head down and negative is tilting the head up
 * Max angle is +/- 25 degrees
 * The angle is stored in the class variable so it can be retrieved later
 */
void Head::setNeckTilt(int angle)
{
    angle = constrainAngle(angle, 25); // Constraining the angles to the min and max

    // Now we're actually setting/sending the angle
    neckTiltAngle = angle;
    int servoAngle = map(angle, -25, 25, 0, 180);
    neckTiltServo.write(servoAngle); // Set the servo to the angle with the microseconds value
}

// HEAD COMMUNICATION---------------------------

/** setHeadRotation(int angle)
 * This sets the head rotation angle in degrees.
 * This is the rotation of the entire head
 * 0 degrees is forward, positive is right and negative is left
 * Max angle is +/- 90 degrees
 * The angle is stored in the class variable so it can be retrieved later
 */
void Head::setHeadRotation(int angle)
{
    angle = constrainAngle(angle, 90); // Constraining the angles to the min and max

    // Now we're actually setting/sending the angle
    headRotationAngle = angle;
    comm.sendHeadRotation(angle);
}

/** setHeadNod(int angle)
 * This sets the head nod angle in degrees.
 * This is the "nodding" motion of the entire head
 * 0 degrees is level (relative to the neck base), positive is up and negative is down
 * Max angle is +/- 30 degrees
 * The angle is stored in the class variable so it can be retrieved later
 */
void Head::setHeadNod(int angle)
{
    angle = constrainAngle(angle, 30); // Constraining the angles to the min and max

    //Since the Head "Nod" is done by changing the angle of the fourbar, which is inside the body, we won't actually send a command.
    //We'll just set the servo here.

    // Now we're actually setting/sending the angle
    //Set the servo to the right angle
}

/** setHeadTilt(float angle)
 * This sets the head tilt angle in degrees.
 * This is the side-to-side leaning motion of the entire head
 * 0 degrees is level (relative to the neck base), positive is leaning to the right and negative is leaning to the left
 * Max angle is +/- 30 degrees
 * The angle is stored in the class variable so it can be retrieved later
 */
void Head::setHeadTilt(int angle)
{
    angle = constrainAngle(angle, 30); // Constraining the angles to the min and max

    // Now we're actually setting/sending the angle
    headTiltAngle = angle;
    comm.sendHeadTilt(angle);
}
