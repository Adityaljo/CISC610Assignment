// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include<vector>
using namespace std;

class myList {
    vector<list<int>> _values;
    int _currindx = 0, _size = 0;
public:
    myList() {}
    myList(list<int> myVal) { _values.push_back(myVal); _size++;}
    void undo();
    void redo();
    void funcdo();
};

ostream& operator<<(ostream& os, list<int>val)
{
    for (auto v : val)
        os << v << "\t";
    os << endl;
    return os;
}

void myList::redo() {
    if (_currindx < _size)
        _currindx++;
    cout << _values[_currindx];
}

void myList::undo() {
    if (_currindx > 0)
        _currindx--;
    cout << _values[_currindx];
}

void myList::funcdo() {
    //Step0: Create a list with given Values
    cout << "Step0: Create a list with given Values" << endl;
    _values.clear();
    list<int> values{ 5,3,2,1,4,8};
    _values.push_back(values); 
    cout << _values[_currindx];
    //Step1: Sort the list
    cout << "Step1: Sort the list" << endl;
    _values.push_back(_values[_currindx]);
    _size++; _currindx++;
    _values.back().sort();
    cout << _values[_currindx];
    //Step2: reverse the list
    cout << "Step2: reverse the list" << endl;
    _values.push_back(_values[_currindx]);
    _size++; _currindx++;
    _values.back().reverse();
    cout << _values[_currindx];
    //Step3: Add 9 to end of the list
    cout << "Step3: Add 9 to end of the list" << endl;
    while ((_size-1) > _currindx) {
        _values.pop_back();
        _size--;
    }
    _values.push_back(_values[_currindx]);
    _size++; _currindx++;
    _values.back().push_back(9);
    cout << _values[_currindx];
    //Undo to step 1
    cout << "Undo to step 1" << endl;
    undo();
    undo();
    //Step4: Add 9 at the end
    cout << "Step4: Add 9 at the end" << endl;
    while ((_size-1) > _currindx){
        _values.pop_back();
        _size--;
    }
    _values.push_back(_values[_currindx]);
    _size++; _currindx++;
    _values[_currindx].push_back(9);
    cout << _values[_currindx];
    //undo to original
    cout << "Undo to step 0" << endl;
    undo();
    undo();
    //redo to latest
    cout << "redo to latest" << endl;
    redo();
    redo();
}

int main()
{
    std::cout << "Hello World!\n";
    
    list<int> values{};
    myList myval(values);
    myval.funcdo();
    
}
