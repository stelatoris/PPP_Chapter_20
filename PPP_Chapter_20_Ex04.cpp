//	PPP_Chapter_20
// 
//	Exercise solutions from the book:
//	************************************************************************************
//	* Programming Principles and Practice Using C++, Second Edition, Bjarne Stroustrup *
//	************************************************************************************
//
//  4. Find and fix the errors in the Jack-and-Jill example from §20.3.1 by using
//  STL techniques throughout.

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

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
    if(first==last) std::cerr<<"Container empty!\n";
    Iterator high = first;
    for(Iterator p = first; p!=last; ++p) {
        if(*high<*p) high = p;
    }
    return high;
}

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count); 
    std::vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data,jack_data+jack_count); 
    std::vector<double>& v = *jill_data;
    double* jill_high = high(&v[0],&v[0]+v.size());
    std::cout << "Jill's high " << *jill_high << "; Jack's high " << *jack_high; 

    delete[] jack_data;
    delete jill_data;
}

int main()
try {

    fct();
}
catch (std::exception& e) {
	std::cerr << "exceptison: " << e.what() << std::endl;
}
catch (...) {
	std::cerr << "unknown exception\n";
}