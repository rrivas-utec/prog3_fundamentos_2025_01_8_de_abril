//
// Created by rudri on 4/8/2025.
//

#include "figura.h"

#include <iostream>
#include <ostream>

Figura::Figura(int x, int y): x(x), y(y) {
}

int Figura::getX() const {
  return x;
}

int Figura::getY() const {
  return y;
}

Rectangulo::Rectangulo(int x, int y): Figura(x, y) {
}

void Rectangulo::dibujar() {
  std::cout << "Rectangulo::dibujar: " << x << " " << y << std::endl;
}

Figura * Rectangulo::clone() const {
  return new Rectangulo(*this);
}

Circulo::Circulo(int x, int y): Figura(x, y) {
}

Figura * Circulo::clone() const {
  return new Circulo(*this);
}

void Circulo::dibujar() {
  std::cout << "Circulo::dibujar: " << x << " " << y << std::endl;
}
