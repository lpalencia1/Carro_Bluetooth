#include <SoftwareSerial.h>
SoftwareSerial BT(4, 2);  // RX, TX recorder que se cruzan

// Motor 1
int ENA = 5;
int IN1 = 6;
int IN2 = 7;
// Motor 2
int ENB = 10;
int IN3 = 8;
int IN4 = 9;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (BT.available()) {
    char dato = BT.read();
    switch (dato) {
      case 'A':
        Atras();
        break;
      case 'B':
        Adelante();
        break;
      case 'C':
        Derecha();
        break;
      case 'D':
        Izquierda();
        break;
      case 'E': 
        Parar();
        break;
    }
  }
}

void Atras() {
  //Dirección motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);  //Velocidad motor A
  //Dirección motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);  //Velocidad motor B
}

void Derecha() {
  //Dirección motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);  //Velocidad motor A
  //Dirección motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);  //Velocidad motor A
}

void Izquierda() {
  //Dirección motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);  //Velocidad motor A
  //Dirección motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);  //Velocidad motor A
}

void Adelante() {
  //Dirección motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);  //Velocidad motor A
  //Dirección motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);  //Velocidad motor B
}

void Parar() {
  //Dirección motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);  //Velocidad motor A
  //Dirección motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);  //Velocidad motor A
}