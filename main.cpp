#include <iostream>
#include <memory>
#include "canvas.h"
#include "Figura.h"

void ejemplo_1() {
  Canvas canvas;
  canvas.add(Rectangulo(10, 20));
  canvas.add(Circulo(100, 200));
  canvas.dibujar();
}

int main() {

  /*
   * 2 CATEGORIAS y 3 TIPOS DE DATOS
   *
   * CATEGORIA #1 - Punteros Unicos
   *  - unique_ptr
   *
   * CATEGORIA #2 - Punteros Compartidos
   *  - shared_ptr  --> Principal
   *  - weak_ptr    --> Es un puntero observador del puntero shared
   */

  // Definicion de un puntero
  int* ptr = nullptr;   // Regular
  std::unique_ptr<int> u_ptr;
  std::shared_ptr<int> s_ptr;
  std::weak_ptr<int> w_ptr;

  // Asignar memoria
  ptr = new int(10);
  u_ptr = std::make_unique<int>(10);
  s_ptr = std::make_shared<int>(20);
  w_ptr = s_ptr;

  auto s2_ptr = s_ptr;
  auto u2_ptr = std::move(u_ptr);

  delete ptr;
  return 0;
}
