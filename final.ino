#include <MIDI.h> // required MIDI library to interface

const int trigPin = 8; // set trigger pin (yellow) -> 8
const int echoPin = 9; // set echo pin (orange) -> 9

const int minDist = 10; // min distance for sensor = 10
const int maxDist = 46; // max distnace for sensor = 46

const int distbwnotes = 3; // distance between each note
const int smplrt = 17;

int dist;
int smpls;

MIDI_CREATE_DEFAULT_INSTANCE();


void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    Serial.begin(9600);
    Serial1.begin(115200);

    MIDI.begin();
}

void loop() {
    //Ultrasonic sensor reading
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Measuring the distance of echo
    long duration = pulseIn(echoPin, HIGH);

    dist = duration / 2 / 29.1;
    dist = constrain(dist, minDist, maxDist);

    Serial1.println(dist);
    Serial1.println('\t');

    for(int k = 0; k = smplrt; k++) {
        smpls += dist;
        delayMicroseconds(20);
    }

    int smplsAvg = smpls / smplrt;
    delayMicroseconds(20);

    Serial.println(smplsAvg);
    Serial.println('\t');

    delay(20);

}


// https://violinspiration.com/violin-finger-positions/#how-many-notes-are-on-the-violin
