#include "Pos2D.h"

Pos2D::Pos2D(int x, int y)
  : _x(x) , _y(y)
{
}

Pos2D::~Pos2D()
{
}

int Pos2D::x() const
{
  return _x;
}

int Pos2D::y() const
{
  return _y;
}

void Pos2D::y(int y)
{
  _y= y;
}

void Pos2D::x(int x)
{
  _x= x;
}

Pos2D operator+(Pos2D const pA, Pos2D const pB)
{
  return Pos2D(pA.x()+pB.x(), pA.y()+pB.y());
}

Pos2D operator-(Pos2D const pA, Pos2D const pB)
{
  return Pos2D(pA.x()-pB.x(), pA.y()-pB.y());
}

Pos2D operator*(Pos2D const pos, int factor)
{
  return Pos2D(pos.x() * factor, pos.y() * factor);
}

Pos2D operator*(int factor, Pos2D const pos)
{
  return pos * factor;
}

bool operator==(Pos2D const pA, Pos2D const pB)
{
  return pA.x() == pB.x() && pA.y() == pB.y();
}

