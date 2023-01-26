/*
  Trigger - yellow
  Echo - Orange
*/

#include<MIDI.h>

const int trigPin = 8; // Ultrasonic sensor trigger pin
const int echoPin = 9; // Ultrasonic sensor echo pin
const int minDistance = 10; // Minimum distance for MIDI note range
const int maxDistance = 30; // Maximum distance for MIDI note range

int velocity = 100;
int noteON = 144;
int noteOFF = 128;

int dis;

void setup() {
  // Set trigger and echo pins as outputs and inputs, respectively
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Start serial communication for debugging
  Serial.begin(115200);
}

void loop() {
  // Send a trigger pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the duration of the echo pulse
  dis = (duration / 2) / 29.1;

  // Map the distance to a MIDI note number

  // OLD CODE HERE
  int note = map(dis, minDistance, maxDistance, 60, 95);

  // Clamp the MIDI note number to the valid range
  note = constrain(note, 60, 95);

  // Send the MIDI note number to the serial port
  Serial.println(note);
  MIDImessage(noteON, note, velocity);
  delay(10); 
  MIDImessage(noteOFF, note, velocity);
  delay(10);
  
  /*
  if(dis <= 10 && dis > 13){
    MIDImessage(noteON, 60, velocity);
    delay(10);
    MIDImessage(noteOFF, 60, velocity);
  }
  else if(dis <= 13 && dis > 16){
    MIDImessage(noteON, 61, velocity);
    delay(10);
    MIDImessage(noteOFF, 61, velocity);
  }
  else if(dis <= 16 && dis > 19){
    MIDImessage(noteON, 62, velocity);
    delay(10);
    MIDImessage(noteOFF, 62, velocity);
  }
  else if(dis <= 19 && dis > 22){
    MIDImessage(noteON, 63, velocity);
    delay(10);
    MIDImessage(noteOFF, 63, velocity);
  }
  else if(dis <= 22 && dis > 25){
    MIDImessage(noteON, 64, velocity);
    delay(10);
    MIDImessage(noteOFF, 64, velocity);
  }
  else if(dis <= 25 && dis > 28){
    MIDImessage(noteON, 65, velocity);
    delay(10);
    MIDImessage(noteOFF, 65, velocity);
  }
  else if(dis <= 28 && dis > 31){
    MIDImessage(noteON, 66, velocity);
    delay(10);
    MIDImessage(noteOFF, 66, velocity);
  }
  else if(dis <= 31 && dis > 34){
    MIDImessage(noteON, 67, velocity);
    delay(10);
    MIDImessage(noteOFF, 67, velocity);
  }
  else if(dis <= 34 && dis > 37){
    MIDImessage(noteON, 68, velocity);
    delay(10);
    MIDImessage(noteOFF, 68, velocity);
  }
  else if(dis <= 37 && dis > 40){
    MIDImessage(noteON, 69, velocity);
    delay(10);
    MIDImessage(noteOFF, 69, velocity);
  }
  else if(dis <= 40 && dis > 43){
    MIDImessage(noteON, 70, velocity);
    delay(10);
    MIDImessage(noteOFF, 70, velocity);
  }
  else if(dis <= 43 && dis > 46){
    MIDImessage(noteON, 71, velocity);
    delay(10);
    MIDImessage(noteOFF, 71, velocity);
  }

  delay(10);
  */
  // You can use the note variable to send MIDI note on and off message to your MIDI device.
  
  // delay before next reading
}

void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
  Serial.write(command);
  Serial.write(MIDInote);
  Serial.write(MIDIvelocity);

}
