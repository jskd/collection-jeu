#ifndef POS2D_H
#define POS2D_H

class Pos2D {

  public:
    Pos2D(int x, int y);
    virtual ~Pos2D();

    int x() const;
    int y() const;

    void x(int x);
    void y(int y);

  private:
    int _x;
    int _y;

};

Pos2D operator+(Pos2D const pA, Pos2D const pB);
Pos2D operator-(Pos2D const pA, Pos2D const pB);
Pos2D operator*(Pos2D const pos, int factor);
Pos2D operator*(int factor, Pos2D const pos);
bool operator==(Pos2D const pA, Pos2D const pB);


namespace Direction
{
  const Pos2D one_up(0,-1);
  const Pos2D one_down(0,1);
  const Pos2D one_left(-1,0);
  const Pos2D one_right(1,0);
}

#endif
