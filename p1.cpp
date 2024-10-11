// C++ code
//
int YELLOW_LED = 5;
int GREEN_LED = 4;
int BLUE_LED = 3;
int RED_LED = 2;
int BUTTON = 6;

int CURRENT_LED = 5;
void setup()
{
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  int button_pressed = digitalRead(BUTTON);

  if (button_pressed) {
    CURRENT_LED = (CURRENT_LED - 2 - 1 + 4) % 4 + 2;
  } else {
    CURRENT_LED = (CURRENT_LED - 2 + 1) % 4 + 2;
  }

  digitalWrite(CURRENT_LED, HIGH);
  delay(1000);  // Wait for 1000 millisecond(s)
  digitalWrite(CURRENT_LED, LOW);
}
