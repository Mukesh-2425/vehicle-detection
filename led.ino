#define trigPin 9
#define echoPin 8

// Define LED pins
#define redLED 10
#define yellowLED 11
#define greenLED 12

// Define thresholds
#define closeThreshold 20    // Close proximity (in cm)
#define mediumThreshold 50   // Medium proximity (in cm).
#define farThreshold 100     // Far proximity (in cm)

void setup() {
  // Configure pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Initialize serial monitor
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  float distance = (duration * 0.034) / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Determine proximity level and activate LEDs
  if (distance > 0 && distance <= closeThreshold) {
    // Close proximity: Turn on Red LED
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  } else if (distance > closeThreshold && distance <= mediumThreshold) {
    // Medium proximity: Turn on Yellow LED
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
  } else if (distance > mediumThreshold && distance <= farThreshold) {
    // Far proximity: Turn on Green LED
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
  } else {
    // No object detected: Turn off all LEDs
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }

  // Small delay for stability
  delay(100);
}
