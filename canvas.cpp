//
// Created by rudri on 4/8/2025.
//

#include <fstream>
#include <sstream>
#include <vector>
#include "canvas.h"

#include <iostream>
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

///----------------

Canvas2::Canvas2(const Canvas2 &other) {
  figuras.reserve(other.figuras.size());
  for (int i = 0; i < other.figuras.size(); i++) {
    figuras.emplace_back(other.figuras[i]->clone());
  }
}

Canvas2::Canvas2(Canvas2 &&other) noexcept {
  std::swap(figuras, other.figuras);
}

Canvas2 & Canvas2::operator=(const Canvas2 &other) {
  // Verificar que other nose si mismo
  if (this == &other) return *this;

  // Copia profunda
  figuras.reserve(other.figuras.size());
  for (int i = 0; i < other.figuras.size(); i++) {
    figuras.emplace_back(other.figuras[i]->clone());
  }
  return *this;
}

Canvas2 & Canvas2::operator=(Canvas2 &&other) noexcept {
  // Verificar que other nose si mismo
  if (this == &other) return *this;
  figuras = std::move(other.figuras);
  return *this;
}

void Canvas2::add(const Figura &figura) {
  figuras.emplace_back(figura.clone());
}

void Canvas2::dibujar() const {
  for (const auto& item: figuras) {
    item->dibujar();
  }
}

void Canvas2::load_canvas(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    std::cout << "Can't open file " << file_name << std::endl;
    return;
  }

  std::vector<std::string> v1;
  std::string line;
  while (std::getline(file, line)) {
    v1.push_back(line);
  }

  for (const auto& item: v1) {
    std::string stype;
    std::string pos;
    std::stringstream ss(item);

    std::getline(ss, stype, ',');
    char type = stype[0];
    std::getline(ss, pos, ',');
    int pos_x = std::stoi(pos);
    std::getline(ss, pos);
    int pos_y = std::stoi(pos);

    switch (std::tolower(type)) {
      case 'c':
        add(Circulo(pos_x, pos_y));
        break;
      case 'r':
        add(Rectangulo(pos_x, pos_y));
        break;
      default:
        break;
    }
  }
}
