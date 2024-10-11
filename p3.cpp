#include <Keypad.h>

const byte rowsCount = 4;
const byte columsCount = 4;

char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};

const byte rowPins[rowsCount] = { 12, 11, 10, 9 };
const byte columnPins[columsCount] = { 8, 7, 6, 5 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);

String inputTime = "12";  
String nextTime = "";

int light_cycle_time = 17; 
int looping_timer = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);  
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (isDigit(key) && nextTime.length() < 2) {
        nextTime += key;
    }
    if (nextTime.length == 2) {
        inputTime = nextTime;
        nextTime = "";
    }
  }

  Serial.println(inputTime);
  int hour = inputTime.toInt();   
  if (hour >= 3 && hour < 16) {  
    if (looping_timer < 5) {
        digitalWrite(2, LOW);   
        digitalWrite(3, LOW);   
        digitalWrite(4, HIGH);  
    } else if (looping_timer >= 5 && looping_timer < 7) {
        digitalWrite(2, LOW);   
        digitalWrite(3, HIGH);  
        digitalWrite(4, LOW);   
    } else if (looping_timer >= 7) {
        digitalWrite(2, HIGH);  
        digitalWrite(3, LOW);   
        digitalWrite(4, LOW);   
    }
    delay(1000);  
    looping_timer++;
    looping_timer %= 17;  
  } else if (hour >= 16 && hour < 24) {  
    if (looping_timer < 10) {
        digitalWrite(2, LOW);   
        digitalWrite(3, LOW);   
        digitalWrite(4, HIGH);  
    } else if (looping_timer >= 10 && looping_timer < 14) {
        digitalWrite(2, LOW);   
        digitalWrite(3, HIGH);  
        digitalWrite(4, LOW);   
    } else if (looping_timer >= 14) {
        digitalWrite(2, HIGH);  
        digitalWrite(3, LOW);   
        digitalWrite(4, LOW);   
    }
    delay(1000);  
    looping_timer++;
    looping_timer %= 34;  
  } else {  
    digitalWrite(2, LOW);   
    digitalWrite(4, LOW);   

    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(3, LOW);
    delay(500);
  }
}
