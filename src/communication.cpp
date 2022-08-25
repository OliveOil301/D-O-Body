#include <Arduino.h>
#include <communication.h>

/** Communication class
 * ! Communication Guide-------
 *
 * ?----Part 1 of Commands:----
 * All commands are started with a 2 character designation
 * | start  |   full name   | explanation
 * |--------|---------------|-------------
 * |   HR   | Head Rotation | Specifies the angle of the head "rotation" in degrees. Positive is right, negative is left.
 * |   HT   | Head Tilt     | Specifies the angle of the head "tilt" in degrees. Positive is right, negative is down.
 * |   SD   | Sound         | Asks the head to play a sound with the specified name
 * |   RQ   | Request       | Requests some data from the head. This could be the battery level or something else
 *
 * ?----Part 2 of Commands:----
 * After the 2 letter designation is the value of the command. Since commands are separated by "\n", there isn't a limit to the length of the value.
 * There hasn't been testing to find a length limit but command values should be less than 10 characters to be safe. truncate values that aren't integers and limit strings
 * Examples:
 * "HR15" - asks the head rotation to go to + 15 degrees
 * "SDno thanks" - asks the head to play the sound file titled "no thanks"
 * "SD12" - asks the head to play the sound file titled "12"
 *
 * ?----Part 3 of Commands:----
 * When sending a command, always use Serial1.println() instead of Serial1.print() to ensure the return character is sent last
 *
 * ?----Command Usage Examples:----
 * Serial1.println("SD14");
 * Serial1.println("HR-15");
 * Serial1.println("HT-3");
 * Serial1.println("SDhello there");
 * Serial1.println("RQBattery");
 *
 */

Communication::Communication(void)
{
    // put your setup code here, to run once:
    Serial1.begin(9600); // Sets up on serial1 (pins 18 & 19 on MEGA) at 9600 bps. //? consider upping the speed if 9600 is too slow for the communication between boards
}

void Communication::sendHeadRotation(int angle)
{
    String message = "HR" + String(angle);
    Serial1.println(message);
}

void Communication::sendHeadTilt(int angle)
{
    String message = "HT" + String(angle);
    Serial1.println(message);
}

void Communication::sendSound(String soundTitle)
{
    String message = "SD" + soundTitle;
    Serial1.println(message);
}

void Communication::requestBatteryLevel()
{
    String message = "RQBattery";
    Serial1.println(message);
}