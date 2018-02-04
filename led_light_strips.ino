/**************************************************
* led_light_strips.ino
*
* refugees{code} Hackathon Programme
*
* code written by: Sadra, Farah, Siamak
*
* Connect the light color of an LED strip to the output of an Arduino. 
* Write a program that uses Ultra-sound Sensor.
***************************************************/
// defines pins numbers
const int trigPinR = 12;
const int echoPinR = 13;
const int ledR = 9;

const int trigPinG = 7;
const int echoPinG = 8;
const int ledG = 10;

const int trigPinB = 4;
const int echoPinB = 2;
const int ledB = 11; 

// defines variables
long durationR;
int distanceR;

long durationG;
int distanceG;

long durationB;
int distanceB;

void calcDistance(int distance, int led){
   if(distance > 25){
    analogWrite(led, 0);
    return;
  }
  int value = 255 - (distance * 10);
//  Serial.println(value);
  analogWrite(led, value);
}


void setup() {
  
pinMode(trigPinR, OUTPUT); 
pinMode(echoPinR, INPUT); 
pinMode(ledR, OUTPUT);
  
pinMode(trigPinG, OUTPUT);
pinMode(echoPinG, INPUT);
pinMode(ledG, OUTPUT); 
  
pinMode(trigPinB, OUTPUT); 
pinMode(echoPinB, INPUT); 
pinMode(ledB, OUTPUT); 

Serial.begin(9600);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPinR, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinR, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinR, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationR = pulseIn(echoPinR, HIGH);
// Calculating the distance
distanceR= durationR*0.034/2;

//delayMicroseconds(2);
digitalWrite(trigPinG, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinG, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinG, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationG = pulseIn(echoPinG, HIGH);
// Calculating the distance
distanceG= durationG*0.034/2;
//delayMicroseconds(2);
digitalWrite(trigPinB, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinB, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinB, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationB = pulseIn(echoPinB, HIGH);
// Calculating the distance
distanceB= durationB*0.034/2;
// Prints the distance on the Serial Monitor

calcDistance(distanceR, ledR);

calcDistance(distanceG, ledG);

calcDistance(distanceB, ledB);

delay(25);

//Serial.print("DistanceR: ");
//Serial.println(distanceR);
//Serial.print("DistanceG: ");
//Serial.println(distanceG);
//Serial.print("DistanceB: ");
//Serial.println(distanceB);
}
