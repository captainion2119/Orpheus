const int trigPin = 8; // Ultrasonic sensor trigger pin
const int echoPin = 9; // Ultrasonic sensor echo pin
const int minDistance = 10; // Minimum distance for MIDI note range
const int maxDistance = 46; // Maximum distance for MIDI note range
const int distanceBetweenNotes = 3; // Distance between each MIDI note

int sampleRate = 17;
int sample = 0;
 
int velocity = 100;
int noteON = 144;
int noteOFF = 128;
int dnot = 0;
 
int distance;
 
void setup() {
  // Set trigger and echo pins as outputs and inputs, respectively
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(115200); // Start MIDI communication
}
 
void loop() {
  

  for(int i = 0; i < sampleRate; i++ ) {
    // Send a trigger pulse to the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Measure the duration of the echo pulse
    long duration = pulseIn(echoPin, HIGH);
    //if(duration==0) return;
 
    // Calculate the distance based on the duration of the echo pulse
    distance = duration / 2 / 29.1;

    distance = constrain(distance, minDistance, maxDistance);
 
    // Constrain the distance to the valid range

    sample += distance;
    delay(20);


  }

  int sampleAvg = sample / sampleRate;

  Serial.print("Avg dist: ");
  Serial.println(sampleAvg);
 
  sample = 0;
  // Map the distance to a specific MIDI note
  int note = 60 + (sampleAvg - minDistance) / distanceBetweenNotes;
 
  Serial.print("Note id: ");
  Serial.println(note);
  Serial.print("\n");

  delay(1);
}