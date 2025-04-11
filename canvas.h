//
// Created by rudri on 4/8/2025.
//

#ifndef CANVA_H
#define CANVA_H
#include <vector>
#include <memory>
#include <string>
#include "figura.h"

class Canvas {
  Figura** figuras = nullptr;
  int sz = 0;
public:
  Canvas() = default;
  Canvas(const Canvas& other);
  Canvas(Canvas&& other) noexcept;
  Canvas& operator=(const Canvas& other); // assignment copy
  Canvas& operator=(Canvas&& other) noexcept; // assignment move
  ~Canvas();
  void add(const Figura& figura);  // Agregar figuras
  void dibujar() const;                  // Dibujar las figuras
};


class Canvas2 {
  std::vector<std::unique_ptr<Figura>> figuras;
public:
  Canvas2() = default;
  Canvas2(const Canvas2& other);
  Canvas2(Canvas2&& other) noexcept;
  Canvas2& operator=(const Canvas2& other); // assignment copy
  Canvas2& operator=(Canvas2&& other) noexcept; // assignment move
  void add(const Figura& figura);  // Agregar figuras
  void dibujar() const;                  // Dibujar las figuras
  void load_canvas(const std::string& file_name);
};

#endif //CANVA_H
