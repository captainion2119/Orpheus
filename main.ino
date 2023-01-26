#include <MIDI.h> // Include the MIDI library
const int trigPin = 8; // Ultrasonic sensor trigger pin
const int echoPin = 9; // Ultrasonic sensor echo pin
const int minDistance = 10; // Minimum distance for MIDI note range
const int maxDistance = 46; // Maximum distance for MIDI note range
const int distanceBetweenNotes = 3; // Distance between each MIDI note
int distance;
MIDI_CREATE_DEFAULT_INSTANCE(); // Create a default MIDI instance

void setup() {
  // Set trigger and echo pins as outputs and inputs, respectively
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  MIDI.begin(); // Start MIDI communication
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
  distance = duration / 2 / 29.1;

  // Constrain the distance to the valid range
  distance = constrain(distance, minDistance, maxDistance);

  // Map the distance to a specific MIDI note
  int note = 60 + (distance - minDistance) / distanceBetweenNotes;

  // Send the MIDI note on message with the mapped note number and velocity of 100
  MIDI.sendNoteOn(note, 100, 1);
  
  // delay before next reading
  delay(100);
}