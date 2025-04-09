//
// Created by rudri on 4/8/2025.
//

#ifndef CANVA_H
#define CANVA_H
#include <vector>
#include <memory>
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


// class Canvas2 {
//   std::vector<Figura*> figuras;
// public:
//   Canvas() = default;
//   Canvas(const Canvas& other);
//   Canvas(Canvas&& other) noexcept;
//   Canvas& operator=(const Canvas& other); // assignment copy
//   Canvas& operator=(Canvas&& other) noexcept; // assignment move
//   ~Canvas();
//   void add(const Figura& figura);  // Agregar figuras
//   void dibujar() const;                  // Dibujar las figuras
// };

#endif //CANVA_H
