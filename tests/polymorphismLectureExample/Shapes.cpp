// This programm demonstarates the work of virtual members.
// You can play with removing the key word "virtual" to see the difference in running the program.
// You can read more in http://www.cplusplus.com/doc/tutorial/polymorphism/
#include <iostream>
using namespace std;

class Polygon { // Calculator
  protected:
    int width, height; // battleparticipant 1 & 2
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area ()
      { return 0; }
};

class Rectangle: public Polygon { // Round 1
  public:
    int area ()
      { return width * height; }
};

class Triangle: public Polygon { // Round 2
  public:
    int area ()
      { return (width * height / 2); }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  Polygon * ppoly3 = &poly;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);
  
  cout << "by pointer" << '\n';
  cout << ppoly1->area() << '\n';
  cout << ppoly2->area() << '\n';
  cout << ppoly3->area() << '\n';
  
  cout << "by object" << '\n';
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
  cout << poly.area() << '\n';
  
  return 0;
}