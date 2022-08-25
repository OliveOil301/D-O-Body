#include <Arduino.h>
#include <body.h>
#include <Servo.h>

Body body;

int lateralWeightTest[8] = {0, 15, 25, 15, 0, -15, -25, -15};
int neckRotationTest[8] = {0, 15, 25, 15, 0, -15, -25, -15};
int neckTiltTest[8] = {0, 15, 25, 15, 0, -15, -25, -15};

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  body.bodySetup();
}

void loop()
{
  //*Testing the lateral weight servo--------
  // for (int i = 0; i < 8; i++)
  // {
  //   Serial.println("We are setting the angle now");
  //   body.setLateralWeightAngle(lateralWeightTest[i]);
  //   delay(1000);
  // }
  // TODO: Check the min anx max values. Going to have to change them from 0 and 180 to something smaller in the code so this will give us the values

  // TODO: Next Tests--------------------------------------------------------------
  //  //*Testing the Neck Rotation servo--------
  //  for(int i = 0; i < 8; i++){
  //    body.head.setNeckRotation(neckRotationTest[i]);
  //    delay(1000);
  //    Serial.println("We are setting the angle now");
  //  }
  // TODO: Check the min anx max values. Going to have to change them from 0 and 180 to something smaller

  //*Testing the Neck Tilt servo--------
  // for(int i = 0; i < 8; i++){
  //   body.head.setNeckTilt(neckTiltTest[i]);
  //   delay(1000);
  //   Serial.println("We are setting the angle now");
  // }
  // //TODO: Check the min anx max values. Going to have to change them from 0 and 180 to something smaller
}