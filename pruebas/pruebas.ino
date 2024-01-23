#include <Servo.h>

Servo baseServo;    // Servo para la base
Servo hombroServo;  // Servo para el hombro
Servo codoServo;    // Servo para el codo
Servo garraServo;   // Servo para la garra

char command;

void setup() {
  Serial.begin(9600);      //Set the baud rate to your Bluetooth module.
  baseServo.attach(11);    // Conecta el servo de la base al pin 11
  hombroServo.attach(10);  // Conecta el servo del hombro al pin 10
  codoServo.attach(9);     // Conecta el servo del codo al pin 9
  garraServo.attach(6);    // Conecta el servo de la garra al pin 6
  codoServo.write(90);
  baseServo.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    //Change pin mode only if new command is different from previous.
    //Serial.println(command);
    switch (command) {
      case 'F':  // Mover el codo hacia adelante
        garraForward();
        break;
      case 'B':  // Mover el codo hacia atrás
        codoBackward();
        break;
      case 'L':
        garraBackward();
      case 'R':
      codoForward();
    }
  }
}

void codoForward() {
  codoServo.write(codoServo.read() + 1);  // Ajusta la posición del servo del codo hacia adelante
}

void codoBackward() {
  codoServo.write(codoServo.read() - 1);  // Ajusta la posición del servo del codo hacia atrás
}

void garraForward() {
  garraServo.write(garraServo.read() + 1);  // Ajusta la posición del servo de la base hacia la derecha
}

void garraBackward() {
  garraServo.write(garraServo.read() - 1);  // Ajusta la posición del servo de la base hacia la izquierda
}
