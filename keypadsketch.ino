const int switchPin1 = 2;  // switch connected to pin 2
const int switchPin2 = 3;  // switch connected to pin 3
const int debounceDelay = 3;  // debounce delay time in milliseconds
bool switchState1 = HIGH;  // current state of switch 1
bool switchState2 = HIGH;  // current state of switch 2
bool lastSwitchState1 = HIGH;  // previous state of switch 1
bool lastSwitchState2 = HIGH;  // previous state of switch 2
unsigned long lastDebounceTime1 = 0;  // last time switch 1 was pressed
unsigned long lastDebounceTime2 = 0;  // last time switch 2 was pressed

void setup() {
  Serial.begin(9600);  // initialize serial communication
  pinMode(switchPin1, INPUT_PULLUP);  // set switch 1 pin as input with pull-up resistor
  pinMode(switchPin2, INPUT_PULLUP);  // set switch 2 pin as input with pull-up resistor
}

void loop() {
  // read the state of the switches
  switchState1 = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);

  // check if switch 1 is pressed and debounce
  if (switchState1 != lastSwitchState1 && millis() - lastDebounceTime1 > debounceDelay) {
    if (switchState1 == LOW) {
      Serial.print("press1\n");  // send "press1" and new line character on switch 1 press
    } else {
      Serial.print("release1\n");  // send "release1" and new line character on switch 1 release
    }
    lastDebounceTime1 = millis();
  }

  // check if switch 2 is pressed and debounce
  if (switchState2 != lastSwitchState2 && millis() - lastDebounceTime2 > debounceDelay) {
    if (switchState2 == LOW) {
      Serial.print("press2\n");  // send "press2" and new line character on switch 2 press
    } else {
      Serial.print("release2\n");  // send "release2" and new line character on switch 2 release
    }
    lastDebounceTime2 = millis();
  }

  // update last switch states
  lastSwitchState1 = switchState1;
  lastSwitchState2 = switchState2;
}