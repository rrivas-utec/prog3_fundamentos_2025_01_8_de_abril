//
// Created by rudri on 4/8/2025.
//

#ifndef FIGURA_H
#define FIGURA_H

// Crear la clase base
class Figura {
protected:
  int x = 0;  // Inicialización in-class
  int y = 0;
public:
  Figura() = default;
  Figura(int x, int y);
  virtual ~Figura() = default;
  int getX() const;
  int getY() const;
  virtual void dibujar() = 0;
  virtual Figura* clone() const = 0;
};

class Rectangulo : public Figura {
public:
  Rectangulo(int x, int y);
  ~Rectangulo() override = default;
  void dibujar() override;
  Figura* clone() const override;
};

class Circulo : public Figura {
public:
  Circulo(int x, int y);
  ~Circulo() override = default;
  Figura* clone() const override;
  void dibujar() override;
};



#endif //FIGURA_H
