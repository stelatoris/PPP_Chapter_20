// Chapter 20, Try This 3: write a function void copy(int* f1, int* e1, int* f2)
// that copies the elements of an array of ints defined by [f1:e1) into another
// [f2:f2+(e1-f1)) using only iterator operations (no subscripting)

//#include "std_lib_facilities.h"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

template<typename Elem>
struct Link {
    Link* prev;
    Link* succ;
    Elem val;
};

template<typename Elem>
class list {
    Link<Elem>* first;
    Link<Elem>* last;   // one beyond the last link
public:
    class iterator;

    iterator begin();
    iterator end();

    iterator insert(iterator p, const Elem& v);
    iterator erase(iterator p);

    void push_back(const Elem& v);
    void push_front(const Elem& v);
    void pop_front();           // remove first element
    void pop_back();            // remove last element

    Elem& front();          // the first element
    Elem& back();           // the last element

};

template<typename Elem>
class list<Elem>::iterator {
    Link<Elem>* curr;
public:
    iterator(Link<Elem>* p) :curr{p} {}

    iterator& operator++() {curr=curr->succ; return *this;} // forward
    iterator& operator--() {curr=curr->prev; return *this;} // backward
    Elem& operator*() {return curr->val;}       // get value - dereference

    bool operator==(const iterator& b) const {return curr==b.curr;}
    bool operator!=(const iterator& b) const {return curr!=b.curr;}
};

using Line = std::vector<char>;     // a line is a vector of characters

struct Document {
    list<Line> line;
    Document() {line.push_back(Line{});}

    Text_iterator begin()           // first character of first line
        { return Text_iterator(line.begin(), (*line.begin()).begin());}
    Text_iterator end()             // one beyond the last character of the last line
    {
        auto last=line.end();
        --last;     // we know that the document is not empty
        return Text_iterator(last, (*last).end());
    }
};

std::istream& operator>>(std::istream& is, Document& d)
{
    for(char ch; is.get(ch);){
        d.line.back().push_back(ch);    // add the character
        if(ch=='\n')
        d.line.push_back(Line{});       // add another line
    }
    if(d.line.back().size()) d.line.push_back(Line{});  //add final empty line
    return is;
}

class Text_iterator{

    list<Line>::iterator ln;
    Line::iterator pos;
public:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
    :ln{ll}, pos{pp} {}

    char& operator*() {return *pos;}
    Text_iterator& operator++();

    bool operator==(const Text_iterator& other) const
    { return ln==other.ln && pos==other.pos;}
    bool operator!=(const Text_iterator& other) const
    { return !(*this==other);}
};

Text_iterator& Text_iterator::operator++()
{
    ++pos;
    if(pos==(*ln).end()) {      //
        ++ln;
        pos=(*ln).begin();
    }
    return *this;
}

int main()
try {

    
    
}
catch (std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
	std::cerr << "unknown exception\n";
}