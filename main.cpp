#include <iostream>

#include "canvas.h"
#include "Figura.h"

int main() {
  Canvas canvas;
  canvas.add(Rectangulo(10, 20));
  canvas.add(Circulo(100, 200));
  canvas.dibujar();

  return 0;
}
