#include "LcdDisplay.h"
#include "SoundAlarm.h"
#include "MotionDetector.h"
#include "CompositeMotionDetector.h"

LcdDisplay lcdDisplay;
SoundAlarm soundAlarm;

MotionDetector motionDetectors{ MotionDetector(13, 1) };
CompositeMotionDetector compositeMotionDetector(&soundAlarm, &lcdDisplay, &motionDetectors, 1);

void setup()
{
    Serial.begin(9600);
    lcdDisplay.initialize();
    lcdDisplay.ready();
    soundAlarm.initialize();
    compositeMotionDetector.initialize();
}

void loop()
{
    compositeMotionDetector.detect();
}
