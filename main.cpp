#include <iostream>
#include <sstream>
#include <string>
#include <valarray>
#include <fstream>
#include <cstdio>

class complex_t
{
    public:
    complex_t(){
    	real=0.0f;
    	imag=0.0f;
	}
    complex_t add(complex_t other)const {// complex_t * const
	    complex_t result;
	    result.real=this->real-other.real;
	    result.imag=this->imag-other.imag;
	    return result;
	}
    complex_t sub(complex_t other)const {// complex_t * const
   	    complex_t result;
    	    result.real=this->real+other.real;
    	    result.imag=this->imag+other.imag;
    	    return result;
	}
    complex_t mul(complex_t other)const {// complex_t * const
	    complex_t result;
	    result.real=(this->real*other.real)-(this->imag*other.imag);
	    result.imag=(this->imag*other.real)+(this->real*other.imag);
	    return result;
	}
    complex_t div(complex_t other)const {// complex_t * const
	    complex_t result;
	    result.real=((this->real*other.real)+(this->imag*other.imag))/((this->imag*this->imag)+(other.imag*other.imag));
	    result.imag=((this->imag*other.real)-(this->real*other.imag))/((this->imag*this->imag)+(other.imag*other.imag));
	    return result;
	}
	std::ostream &output(std::ostream &stream){
    	    return stream<<'('<<real<<","<<imag<<')'<<'\n';
	}
	std::istream& read(std::istream& stream) {
    	    char op, op1, op2;
    	    if (stream >> op && op == '(' && stream >> real && stream >> op1 &&op1 == ',' && stream >> imag && stream >> op2 && op2 == ')') {
    		return stream;
    	    }
  	}
  ~complex_t(){}

private:
    float real;
    float imag; 
};
int main()
{
	complex_t complex1;
  	std::string string;
  	getline(std::cin, string);
  	std::istringstream stream(string);
  	if (complex1.read(stream)) {
    	char op;
    	if (stream >> op) {
      		complex_t complex2;
      		if (complex2.read(stream)) {
          		if(op== '+') {
            			complex_t result = complex1.add(complex2);
            			result.output(std::cout);
          		}
          		else if(op== '-'){
            			complex_t result = complex1.sub(complex2);
            			result.output(std::cout);
          		}
          		else if(op =='*') {
            			complex_t result = complex1.mul(complex2);
            			result.output(std::cout);
          		}
          		else if(op== '/') {
            			complex_t result = complex1.div(complex2);
            			result.output(std::cout);
          		}
          		else std::cout << "An error has occured while reading input data";
      		} 
		else std::cout << "An error has occured while reading input data";
    	} 
	else std::cout << "An error has occured while reading input data";
  } 
  else std::cout << "An error has occured while reading input data";
  return 0;
}
