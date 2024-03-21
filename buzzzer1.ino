const int trigPin = 9;  // Trigger pin of the ultrasonic sensor (connect to Arduino pin 9)
const int echoPin = 10; // Echo pin of the ultrasonic sensor (connect to Arduino pin 10)
const int buzz=13;

void setup() {
  Serial.begin(9600); // Initialize serial communication for displaying distance
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzz, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop() {
  long duration;
  int distance;

  // Generate a pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the time it takes for the echo to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters (you can change to inches if needed)
  distance = duration / 58.2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Wait for a while before taking another reading
  if(distance<15){
    tone(buzz, 1000); // Send 1KHz sound signal... 
    delay(1000); // ...for 1 sec 
    noTone(buzz); // Stop sound... 
    delay(1000); // ...for 1sec
}




}

    


  


