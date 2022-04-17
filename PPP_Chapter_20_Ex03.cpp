//	PPP_Chapter_20
// 
//	Exercise solutions from the book:
//	************************************************************************************
//	* Programming Principles and Practice Using C++, Second Edition, Bjarne Stroustrup *
//	************************************************************************************
//
//  3. Look at the palindrome examples (§18.7); redo the Jack-and-Jill example
//  from §20.1.2 using that variety of techniques.

//#include "std_lib_facilities.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <list>
#include <array>


double* get_from_jack(int* count)
{
    std::string iname{"jack_data.txt"};
    std::ifstream ist{iname.c_str()};
    if(!ist) std::cerr<<"can't open input file "<<iname<<'\n';

    std::vector<double> v;
    double d{};
    while(ist>>d) v.push_back(d);

    *count= v.size();
    double* data = new double[*count];
    for(int i =0; i<v.size();++i)
        data[i]=v[i];

    return data;
}

std::vector<double>* get_from_jill()
{
    std::string iname{"jill_data.txt"};
    std::ifstream ist{iname.c_str()};
    if(!ist) std::cerr<<"can't open input file "<<iname<<'\n';

    std::vector<double>* v = new std::vector<double>;
    double d{};
    while(ist>>d) (*v).push_back(d);

    return v;
}

// Return a pointer to the element in the array a[] that has the highest value
double* high_array(double a[], int n)
{
	if(n==0) return 0;
	double* highest = &a[0];
	for(int i = 0; i<n;++i){
		if (a[i]>*highest) highest=&a[i];
	}
	return highest;
}

// Return a pointer to the element in the vector v that has the highest value
double* high_vector( std::vector<double>& v)
{
	if(v.size()==0) return 0;
	double* highest = &v[0];
	for(int i = 0; i<v.size();++i){
		if (v[i]>*highest) highest=&v[i];
	}
	return highest;
}

// Return a pointer to the element in [first,last) that has the highest value
double* high_pointer( double* first, double* last)
{
	if(first==last)return 0;

	double h = -1;
    double* high;
    for(double* p = first; p!=last; ++p)
        if (h<*p) { high = p; h = *p; }
    return high;
}

int main()
try {

    int count{0};
    double* jack_data=get_from_jack(&count);

    double* jack_high = high_array(jack_data, count);
    std::cout<<"Jack's max using high_array(): "<<*jack_high<<'\n';

    jack_high = high_pointer(&jack_data[0], &jack_data[count]);
    std::cout<<"Jack's max using high_pointer(): "<<*jack_high<<'\n';

    std::vector<double>* jill_data;
    jill_data=get_from_jill();

    double* jill_high = high_vector(*jill_data);
    std::vector<double> v_jill = *jill_data;
    std::cout<<"Jill's max using high_vector(): "<<*jill_high<<'\n';

    jill_high = high_pointer(&v_jill[0], &v_jill[v_jill.size()]);
    std::cout<<"Jill's max using high_pointer(): "<<*jill_high<<'\n';

    delete[] jack_data;
    delete jill_data;
}
catch (std::exception& e) {
	std::cerr << "exceptison: " << e.what() << std::endl;
}
catch (...) {
	std::cerr << "unknown exception\n";
}