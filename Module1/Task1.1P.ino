// C++ code

constexpr unsigned char SIGNAL_PIN = 12;
constexpr unsigned short MAX_PROXIMITY = 336;

void HandleProximity(unsigned long distance)
{
  if (distance <= MAX_PROXIMITY)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print(distance);
    Serial.println(" cm");
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // References: https://docs.arduino.cc/built-in-examples/sensors/Ping
  delay(10); // Delay a little bit to improve simulation performance

  pinMode(SIGNAL_PIN, OUTPUT);
  digitalWrite(SIGNAL_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(SIGNAL_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(SIGNAL_PIN, LOW);
  pinMode(SIGNAL_PIN, INPUT);
  
  unsigned long durationUs = pulseIn(SIGNAL_PIN, HIGH);
  
  // Speed of sound = 343 m/s == 34,300 cm/s
  // 34,300 / 1*10^-6 = 0.0343 cm/us
  // 1 / 0.0343 = 29.1 us/cm
  unsigned long distanceCm = (durationUs / 2) / 29;
  
  HandleProximity(distanceCm);
  delay(100);
}
