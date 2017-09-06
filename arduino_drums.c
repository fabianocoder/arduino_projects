
const int buttonPin = 0;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState0;             // the current reading from the input pin
int buttonState2;             // the current reading from the input pin
int buttonState3;             // the current reading from the input pin
int buttonState4;             // the current reading from the input pin
int buttonState5;             // the current reading from the input pin
int buttonState6;             // the current reading from the input pin
int lastButtonState0 = LOW;   // the previous reading from the input pin
int lastButtonState2 = LOW;   // the previous reading from the input pin
int lastButtonState3 = LOW;   // the previous reading from the input pin
int lastButtonState4 = LOW;   // the previous reading from the input pin
int lastButtonState5 = LOW;   // the previous reading from the input pin
int lastButtonState6 = LOW;   // the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime0 = 0;  // the last time the output pin waswas toggled
unsigned long lastDebounceTime2 = 0;  // the last time the output pin waswas toggled
unsigned long lastDebounceTime3 = 0;  // the last time the output pin waswas toggled
unsigned long lastDebounceTime4 = 0;  // the last time the output pin waswas toggled
unsigned long lastDebounceTime5 = 0;  // the last time the output pin waswas toggled
unsigned long lastDebounceTime6 = 0;  // the last time the output pin waswas toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(0, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(0, ledState);
  digitalWrite(2, ledState);
  digitalWrite(3, ledState);
  digitalWrite(4, ledState);
  digitalWrite(5, ledState);
  digitalWrite(6, ledState);
  Serial.begin(115200); 
}
unsigned char status;
#define  midichannel  0;    
void loop() {
  int reading0 = digitalRead(0);
  if (reading0 != lastButtonState0) {
    lastDebounceTime0 = millis();
  }
  if ((millis() - lastDebounceTime0) > debounceDelay) {
    if (reading0 != buttonState0) {
      buttonState0 = reading0;
      if (buttonState0 != HIGH) {
        MIDI_TX(144,40,17);
      }
    }
  }
  lastButtonState0 = reading0;

  int reading2 = digitalRead(2);
  if (reading2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay) {
    if (reading2 != buttonState2) {
      buttonState2 = reading2;
      if (buttonState2 != HIGH) {
       MIDI_TX(144,36,17);
       
      }
    }
  }
  lastButtonState2 = reading2;

  int reading3 = digitalRead(3);
  if (reading3 != lastButtonState3) {
    lastDebounceTime3 = millis();
  }

  if ((millis() - lastDebounceTime3) > debounceDelay) {
    if (reading3 != buttonState3) {
      buttonState3 = reading3;
      if (buttonState3 != HIGH) {
        MIDI_TX(144,50,17);
       
      }
    }
  }
  lastButtonState3 = reading3;

  int reading4 = digitalRead(4);
  if (reading4 != lastButtonState4) {
    lastDebounceTime4 = millis();
  }

  if ((millis() - lastDebounceTime4) > debounceDelay) {
    if (reading4 != buttonState4) {
      buttonState4 = reading4;
      if (buttonState4 != HIGH) {
        MIDI_TX(144,51,17);
       
      }
    }
  }
  lastButtonState4 = reading4;

  int reading5 = digitalRead(5);
  if (reading5 != lastButtonState5) {
    lastDebounceTime5 = millis();
  }

  if ((millis() - lastDebounceTime5) > debounceDelay) {
    if (reading5 != buttonState5) {
      buttonState5 = reading5;
      if (buttonState5 != HIGH) {
        MIDI_TX(144,51,17);
       
      }
    }
  }
  lastButtonState5 = reading5;

  int reading6 = digitalRead(6);
  if (reading6 != lastButtonState6) {
    lastDebounceTime6 = millis();
  }

  if ((millis() - lastDebounceTime6) > debounceDelay) {
    if (reading6 != buttonState6) {
      buttonState6 = reading6;
      if (buttonState6 != HIGH) {
        MIDI_TX(144,53,17);
       
      }
    }
  }
  lastButtonState6 = reading6;
}

void MIDI_TX(unsigned char MESSAGE, unsigned char PITCH, unsigned char VELOCITY) 
{
  status = MESSAGE + midichannel;
  Serial.write(status);
  Serial.write(PITCH);
  Serial.write(100);
}
