#include "../01-Rational/rational.hpp"

namespace DS
{

class Rational_array
{


public:
    explicit Rational_array();
    explicit Rational_array(int s);
    Rational_array(const Rational_array &other);
    Rational_array& operator=(const Rational_array &other);
    ~Rational_array();

    int get_size() const;
    Rational get_element(int index) const;
    void set_element(int index, Rational value);
    void print() const;

 
    
 private:
    int size;
    Rational *data;

};

}
