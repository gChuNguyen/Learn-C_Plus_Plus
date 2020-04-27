#include <iostream>

using namespace std;

class Vector{
public:
    Vector(int s)
    {
        cout << "Declare object v with " << s << endl;

        if(s < 0) throw std::length_error{""};

        elements = new double[s];

        sn = s;

    } // Constructor function

    double& operator[](int i)
    {
        if(i < 0 || size() <= i)
        {
            // out_of_range exception:
            throw out_of_range{"Vector::operator[]"};
        }

        return elements[i];
    } // Element access subscripting

    int size() {return sn;}

private:
    int sn; // Size of elements

    double *elements; // Pointer contain sn elements
};

void exceptions(Vector& v)
{
    try // exceptions here are handled by the handler define below
    {
        v[v.size()] = 7; //try to access beyond the end of v
    }

    catch(out_of_range) // oops: out of range error
    {
        // handle range error
        cout << "Handle range error" << endl;
    }
}

void invariants(void)
{
    try
    {
        Vector v(-3);
    }

    catch(std::length_error)
    {
        cout << "Length Error\n";
    }

    catch(std::bad_alloc)
    {
        cout << "Allocate memory failed!\n";
    }
}

int main()
{
    cout << "Hello world!" << endl;

    Vector v(6);


    // Assign value
    for(int i = 0; i < v.size(); i++)
    {
 //       v[i] = i + 10;

        cout << v[i] << endl;
    }

    exceptions(v);

    invariants();

    return 0;
}
