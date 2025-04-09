//
// Created by rudri on 4/8/2025.
//

#include "canvas.h"

#include <vector>

Canvas::Canvas(const Canvas &other) {
  sz = other.sz;
  figuras = new Figura*[sz];
  if (other.figuras == nullptr) return;
  for (int i = 0; i < sz; i++) {
    figuras[i] = other.figuras[i]->clone();
  }
}

Canvas::Canvas(Canvas &&other) noexcept {
  std::swap(sz, other.sz);
  std::swap(figuras, other.figuras);
}

Canvas & Canvas::operator=(const Canvas &other) {
  // Verificar que other nose si mismo
  if (this == &other) return *this;

  // Eliminar los datos anteriores
  for (int i = 0; i < sz; i++) {
    delete figuras[i];
  }
  delete [] figuras;

  // Verificar si other.figura es nulo
  if (other.figuras == nullptr) {
    figuras = nullptr;
    sz = 0;
    return *this;
  }

  // Copia profunda
  sz = other.sz;
  figuras = new Figura*[sz];
  for (int i = 0; i < sz; i++) {
    figuras[i] = other.figuras[i]->clone();
  }

  return *this;
}

Canvas & Canvas::operator=(Canvas &&other) noexcept {
  // Verificar que other nose si mismo
  if (this == &other) return *this;

  // Eliminar los datos anteriores
  for (int i = 0; i < sz; i++) {
    delete figuras[i];
  }
  delete [] figuras;
  if (other.figuras == nullptr) {
    figuras = nullptr;
    sz = 0;
    return *this;
  }

  sz = other.sz;
  figuras = other.figuras;

  // Anular la clase other
  other.figuras = nullptr;
  other.sz = 0;

  return *this;
}

Canvas::~Canvas() {
  for (int i = 0; i < sz; i++) {
    delete figuras[i];
  }
  delete [] figuras;
}

void Canvas::add(const Figura &figura) {
  const auto temp = new Figura*[sz+1];
  for (int i = 0; i < sz; i++) {
    temp[i] = figuras[i];
  }
  temp[sz] = figura.clone();
  delete [] figuras;
  figuras = temp;
  sz++;
}

void Canvas::dibujar() const {
  for (int i = 0; i < sz; i++) {
    figuras[i]->dibujar();
  }
}
