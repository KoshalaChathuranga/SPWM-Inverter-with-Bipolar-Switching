//Define my output pins
const int IN1 = 5;
const int IN2 = 6;
// delays of the pulse signal in Microseconds.
const int delays[] = {480, 620, 330, 730, 210, 830, 140, 880, 100, 910, 80, 900, 130, 840, 190, 760, 290, 660, 400, 540, 520, 420, 640, 310, 750, 210, 820, 140, 870, 120, 860, 160, 800, 250, 700, 360, 580, 460};

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(delays) / sizeof(delays[0]); i += 2) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delayMicroseconds(delays[i]);

    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
    delayMicroseconds(delays[i + 1]);
  }
}
