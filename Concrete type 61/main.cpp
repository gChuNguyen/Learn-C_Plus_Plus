#include <iostream>

using namespace std;


class complex
{
    double re, im; //representation two doubles
public:
    complex(double r, double i) : re{r}, im{i}{} // Construct complex from two scalars
    complex(double r) : re{r}, im{0}{} // Construct complex from one scalars
    complex() : re{0}, im{0}{} //default complex 0

    double real() const {return re;}
    void real(double d){re = d;}
    double imag() const {return im;}
    void imag(double d){im = d;}

    complex& operator+=(complex z)
    {
        re+= z.re;
        im+= z.im;

        cout << "add z: " << &z << endl;
        cout << "add this: " << this << endl;

        return *this;

    } // defined out-of-class somewhere,
                                                                        // and return the result
    complex& operator-=(complex z) {re-= z.re; im-= z.im; return *this;}

    complex& operator*=(complex);   // defined out-of-class somewhere
    complex& operator/=(complex);   // defined out-of-class somewhere
};

class Vector{

    double *elements;
    int sn;

public:
    Vector(std::initializer_list<double> lst)
    {
        elements = new double[lst.size()];

        sn = lst.size();

        copy(lst.begin(), lst.end(), elements);

        lst.
    }

    void push_back(double d)
    {

    }

    read(istream& is)
    {
        Vector v;

        for(double d; is >> d;)
        {
            v.push_back(d)
        }
    }
};

V

int main()
{
    cout << "Hello world!" << endl;

    complex v1{4, 5};
    complex v2(3, 6);

    cout << "add v2: " << &v2 << endl;
    v2 += v1; // operator+=(v1)

    cout << v2.real() << "\t" << v2.imag() << endl;

    return 0;
}
