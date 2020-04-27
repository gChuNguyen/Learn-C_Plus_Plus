#include <iostream>
#include <list>

using namespace std;

/**<
class Vector
{
    double* elements;

    int sz;

public:
    Vector(std::initializer_list<double> lst) // initialize with a list
    {
        elements = new double[lst.size()];
        sz = lst.size();

        copy(lst.begin(),lst.end(),elements); // copy from lst into elem
    }

    double& operator[](int s){return elements[s];}

    int size() const {return sz;}
};

*/

class Container {
public:
    virtual double& operator[](int) = 0; // pure virtual function
    virtual int size() const = 0;        // constant member function
    virtual ~Container() {};
};


void use(Container& c)
{
    const int sz = c.size();

    for(int i = 0; i != sz; i++)
    {
        cout << c[i] << '\n';
    }
}

class List_container : public Container {

    list<double> ld; // list of double

public:
    List_container( ) {} // empty list
    List_container(initializer_list<double> il) : ld{il} {}
    ~List_container(){}

    double& operator[](int i) {

        for(auto& x: ld)
        {
            if(i == 0) return x;

            --i;
        }

        throw out_of_range("List Container");
    }

    int size() const {return ld.size();}
};

int main()
{
    cout << "Hello world!" << endl;

    List_container lc = {1, 2, 3, 4, 5, 6, 7};

    use(lc);

    return 0;
}
