#include <Servo.h>

Servo servoBase;
Servo servoGarra;

char comando;

int posBase = 90;
int posGarra = 90;

void setup() {

  Serial.begin(9600);

  servoBase.attach(9);
  servoGarra.attach(10);

  pinMode(3, OUTPUT);

  servoBase.write(posBase);
  servoGarra.write(posGarra);

  Serial.println("=== BRACO ROBOTICO ESPACIAL ===");
  Serial.println("U = Up");
  Serial.println("D = Down");
  Serial.println("O = Open");
  Serial.println("C = Close");
}

void loop() {

  if (Serial.available()) {

    comando = Serial.read();

    // SUBIR
    if (comando == 'U' || comando == 'u') {

      posBase += 15;

      if (posBase > 180)
        posBase = 180;

      servoBase.write(posBase);

      Serial.println("Braco subindo");
    }

    // DESCER
    if (comando == 'D' || comando == 'd') {

      posBase -= 15;

      if (posBase < 0)
        posBase = 0;

      servoBase.write(posBase);

      Serial.println("Braco descendo");
    }

    // ABRIR GARRA
    if (comando == 'O' || comando == 'o') {

      posGarra = 20;

      servoGarra.write(posGarra);

      digitalWrite(3, LOW);

      Serial.println("Garra aberta");
    }

    // FECHAR GARRA
    if (comando == 'C' || comando == 'c') {

      posGarra = 90;

      servoGarra.write(posGarra);

      digitalWrite(3, HIGH);

      Serial.println("Amostra capturada");
    }
  }
}