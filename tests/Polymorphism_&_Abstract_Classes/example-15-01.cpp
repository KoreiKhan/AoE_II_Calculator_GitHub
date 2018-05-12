#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
   virtual int area () = 0; // Abstract classes part (not instantiated)
      
};

class Rectangle: public Polygon {
  public:
    int area () // Polymorphism part 1
      { return width * height; }
};

class Triangle: public Polygon {
  public:
    int area ()
      { return (width * height / 2); }
};

int main () {
  Rectangle rect;
  Polygon * ppoly1 = &rect;
  ppoly1->set_values (4,5);
  cout << "Rectangle Area: " << ppoly1->area() << '\n';
  cout << "Rectangle Area: " << rect.area() << '\n'; // Polymorphism part 2

  Triangle trgl;
  Polygon * ppoly2 = &trgl;
  ppoly2->set_values (4,5);
  cout << "Triangle Area: " << ppoly2->area() << '\n';
  cout << "Triangle Area: " << trgl.area() << '\n';

  // You may play with this part uncommenting it. What do you expect to happen?
  //Polygon poly;
  //Polygon * ppoly3 = &poly;
  //ppoly3->set_values (4,5);
  //cout << "Polygon Area: " << ppoly3->area() << '\n';

  return 0;
}