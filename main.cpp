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

int main()
try {

}
catch (std::exception& e) {
	std::cerr << "exceptison: " << e.what() << std::endl;
}
catch (...) {
	std::cerr << "unknown exception\n";
}