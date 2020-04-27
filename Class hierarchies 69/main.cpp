#include <iostream>
#include <math.h>
#include
using namespace std;

class Shape{
 public:
     virtual Point center() const = 0; // Pure virtual
     virtual void move(Point to) = 0;

     virtual void draw() const = 0;
     virtual void rotate(int angle) = 0;

     virtual ~Shape() {} // Destructor
};

/**< To define a particular shape, we must say that it is a Shape and specify its particular properties (including its virtual function) */
class Circle : public Shape {
public:
    Circle(Point p, int rr); // Constructor

    Point center() const {return x;}
    void move(Point to) {x = to;}

    void draw() const; // Specify function do not modify that object for which they are called.
    void rotate(int) {} // nice simple algorithm

private:
    Point x; // center
    int r;  // Radius
};

class Smiley : public Circle {

public:
    Smiley(Point p, int r) : Circle(p, r), mouth(nullptr) {}

    ~Smiley()
    {
        delete mouth;
        for(auto p: eyes) delete p;
    }

    void move(Point to);
    void draw() const;
    void rotate(int);

    void add_eye(Shape* s) {eyes.push_back(s);}

    void set_mouth(Shape* s);
    virtual void wink(int i); // wink eye number i

private:
    vector<Shape> eyes; // Ussual two eyes

    Shape* mouth;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
