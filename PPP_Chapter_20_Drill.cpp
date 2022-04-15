//	PPP_Chapter_20
// 
//	Exercise solutions from the book:
//	************************************************************************************
//	* Programming Principles and Practice Using C++, Second Edition, Bjarne Stroustrup *
//	************************************************************************************
//
//  Drill
//  1. Define an array of ints with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
//  2. Define a vector<int> with those ten elements.
//  3. Define a list<int> with those ten elements.
//  4. Define a second array, vector, and list, each initialized as a copy of the first
//  array, vector, and list, respectively.
//  5. Increase the value of each element in the array by 2; increase the value of
//  each element in the vector by 3; increase the value of each element in the
//  list by 5.
//  6. Write a simple copy() operation,
//
//      template<typename Iter1, typename Iter2>
//          // requires Input_iterator<Iter1>() && Output_iterator<Iter2>() 
//      Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);
//
//  that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the standard library copy function. 
//  Note that if f1==e1 the sequence is empty, so that there is nothing to copy.
//  7. Use your copy() to copy the array into the vector and to copy the list into the array.
//  8. Use the standard library find() to see if the vector contains the value 3 and print out its 
//  position if it does; use find() to see if the list contains the value 27 and print out its position if it does. 
//  The “position” of the first element is 0, the position of the second element is 1, etc. 
//  Note that if find() returns the end of the sequence, the value wasn’t found.

//#include "std_lib_facilities.h"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <array>

//Drill 6
template<typename Iter1, typename Iter2>
        //equires Input_iterator<Iter1>() && Output_iterator<Iter2>() 
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while(f1!=e1){
        *f2=*f1;
        ++f1;
        ++f2;
    }
    return f2;
}

template<typename Iter>
void print_vector(Iter f, Iter e, const std::string& label)
{
	std::cout<<label<<": { ";
    while(f!=e) {
        std::cout<<*f<<' ';
        ++f;
    }
    std::cout<<"}\n";
}

template <typename Iter>
void my_find(Iter f, Iter e, int val)
{
    std::vector<int>::iterator p = std::find(f, e, val);
    if(p!=e) {
        std::cout<<"The value "<<*p<<" was found in location: ";
        std::cout<<p-f<<'\n';
    }
    else std::cout<<"The value "<<val<<" was not found!\n";
}

int main()
try {

   const int sz{10};
   // Drill 1
   std::array<int, sz> arr1;
   for(int i{};i<sz;++i) arr1[i]=i;
   std::cout<<"Drill 1:-\n";
   print_vector(arr1.begin(), arr1.end(), "arr1");
   //Drill 2
   std::vector<int> v1;
   for(int i{}; i<sz;++i) v1.push_back(i);
   std::cout<<"Drill 2:-\n";
   print_vector(v1.begin(), v1.end(), "v1");

   //Drill 3
   std::list<int> l1;
   for(int i{}; i<sz;++i) l1.push_back(i);
   std::cout<<"Drill 3:-\n";
   print_vector(l1.begin(), l1.end(), "l1");

   //Drill 4
   std::cout<<"Drill 4:-\n";
   std::array<int, sz> arr2{arr1};
   print_vector(arr2.begin(), arr2.end(), "arr2");

   std::vector<int> v2{v1};
   print_vector(v2.begin(), v2.end(), "v2");

   std::list<int> l2{l1};
   print_vector(l2.begin(), l2.end(), "l2");

   //Drill 5
   std::cout<<"Drill 5:-\n";
    for(std::array<int,sz>::iterator p = arr2.begin(); p!=arr2.end(); ++p)
        *p+=2;
   print_vector(arr2.begin(), arr2.end(), "arr2+2");

   for(std::vector<int>::iterator p = v2.begin(); p!=v2.end(); ++p)
        *p+=3;
   print_vector(v2.begin(), v2.end(), "v2+2");

   for(std::list<int>::iterator p = l2.begin(); p!=l2.end(); ++p)
        *p+=5;
   print_vector(l2.begin(), l2.end(), "l2+2");

   //Drills 7
   std::vector<int>::iterator vp = my_copy(arr2.begin(),arr2.end(),v2.begin());
    print_vector(v2.begin(), v2.end(), "v2 copy from arr2");
    std::array<int, sz>::iterator arr_p = my_copy(l2.begin(),l2.end(),arr2.begin());
    print_vector(arr2.begin(), arr2.end(), "arr2 copy from l2");

    //Drill 8
    my_find(v2.begin(), v2.end(), 25);
    

}
catch (std::exception& e) {
	std::cerr << "exceptison: " << e.what() << std::endl;
}
catch (...) {
	std::cerr << "unknown exception\n";
}