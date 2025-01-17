/*
 * Programa para simular el comportamiento de las puertas lógicas de 
 * una practica (practica 7).
 * El script activa una salida luminosa (LED o Lampara) en función de 
 * tres entradas de interruptores, de manera que cumplan con la función 
 * digital a seguir:
 *   f = not a * b * not c + not a * b* c + a * not b * c + a * b * c =
 *     = not a * b + a * c
 *
 * Entradas: pines 10, 9, 8 (digitales)
 * Salidas: pin 11 (digital)
 *
 * Autor: Mauro Fernandez
 * Fecha: Enero 2025
*/

#define A 10
#define B 9
#define C 8
#define LAMP 11

bool a = 0;
bool b = 0;
bool c = 0;

void setup(){
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(LAMP, OUTPUT);
}

void loop() {
  a = digitalRead(A);
  b = digitalRead(B);
  c = digitalRead(C);
  // condicion = not a * b * not c + not a * b* c + a * not b * c + a * b * c =
  //   = not a * b + a * c
  //bool condicion = !a && b && !c || !a && b && c || a && !b && c || a && b && c;
  //bool condicion = !a && b || a && c;
  bool condicion1 = !a && b && !c;
  bool condicion2 = !a && b && c;
  bool condicion3 = a && !b && c;
  bool condicion4 = a && b && c;
  bool condicion = condicion1 || condicion2 || condicion3 || condicion4;
  if(condicion1) {
    digitalWrite(LAMP, HIGH);
  }
  else if(condicion2) {
    digitalWrite(LAMP, HIGH);
  }
  else if(condicion3) {
    digitalWrite(LAMP, HIGH);
  }
  else if(condicion4) {
    digitalWrite(LAMP, HIGH);
  }
  else {
   digitalWrite(LAMP, LOW); 
  }
}  
  
