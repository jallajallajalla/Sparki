#include <Sparki.h> // include the sparki library

float capHeight = 5;
float width = 5; 

void setup() {
  // put your setup code here, to run once:

  m();

  space(1.2);

  i();

  space(1.2);

  n();

  space(1.2);

  n();

  space(1);

  a();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void m() {
  //M
  sparki.moveForward(capHeight);
  sparki.moveLeft(tan(capHeight/(width/2)));
  sparki.moveBackward(sqrt(sq(width/2)+sq(capHeight)));
  sparki.moveRight(2*tan(capHeight/(width/2)));
  sparki.moveForward(sqrt(sq(width/2)+sq(capHeight)));
  sparki.moveLeft(tan(capHeight/(width/2)));
  sparki.moveBackward(capHeight);
}

void space(float n) {
  //Space
  sparki.moveRight(90);
  sparki.moveForward(n);
  sparki.moveLeft(90);
}

void i() {
  //I
  sparki.moveForward(5);
  sparki.moveBackward(5);
}

void n() {
  //N
  sparki.moveForward(5);
  sparki.moveLeft(38.7);
  sparki.moveBackward(6.4);
  sparki.moveRight(38.7);
  sparki.moveForward(5);
  sparki.moveBackward(5);
}

void a() {
  //A
  sparki.moveRight(22.5);
  sparki.moveForward(5.6);
  sparki.moveLeft(45);
  sparki.moveBackward(5.6);
  sparki.moveForward(2.8);
  sparki.moveLeft(67.5);
  sparki.moveForward(2.5);
  sparki.moveBackward(2.5);
}



