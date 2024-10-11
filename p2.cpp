// C++ code
//

int light_cycle_time = 17;
int looping_timer = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  if (looping_timer < 5) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  } else if (looping_timer >= 5 and looping_timer < 7) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (looping_timer >= 7) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW); 
  }
  delay(1000);
  looping_timer++;
  looping_timer %= light_cycle_time;
}