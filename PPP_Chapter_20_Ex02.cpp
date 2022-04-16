//	PPP_Chapter_20
// 
//	Exercise solutions from the book:
//	************************************************************************************
//	* Programming Principles and Practice Using C++, Second Edition, Bjarne Stroustrup *
//	************************************************************************************
//
//  2. Get the Jack-and-Jill example from §20.1.2 to work. Use input from a
//  couple of small files to test it.

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

// Return a pointer to the element in [first,last) that has the highest value
double* high(double* first, double* last)
{
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
    std::cout<<"Data from Jack: { ";
    for(int i=0; i<count;++i)
        std::cout<<jack_data[i]<<' ';
    std::cout<<"}\n";

    std::vector<double>* v_Jill=get_from_jill();
    std::cout<<"Data from Jill: { ";
    for(int i=0; i<(*v_Jill).size();++i)
        std::cout<<(*v_Jill)[i]<<' ';
    std::cout<<"}\n";

    double* jack_high=high(jack_data, jack_data+count);
    std::cout<<"Jack's max: "<<*jack_high<<'\n';

    std::vector<double>& v= *v_Jill;
    double* jill_high=high(&v[0], &v[0]+v.size());
    std::cout<<"Jill's max: "<<*jill_high<<'\n';

    delete[] jack_data;
    delete v_Jill;
}
catch (std::exception& e) {
	std::cerr << "exceptison: " << e.what() << std::endl;
}
catch (...) {
	std::cerr << "unknown exception\n";
}