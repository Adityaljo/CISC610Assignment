// Assignment2B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<list>
#include<vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>

using namespace std;
class myStcack {
    list<char> _val;
public:
    void push(char c) {
        _val.push_back(c);
    }
    void pop() {
        _val.pop_back();
    }
    char top() {
        return _val.back();
    }
};

bool isPalindrome(string candidate) {
    int size = candidate.size();
    myStcack firstHalf;
    int i = 0;
    for (; i < size / 2; i++)
        firstHalf.push(candidate[i]);
    if (size % 2)
        i++;
    for (; i < size; i++) {
        if (tolower(candidate[i]) != tolower(firstHalf.top()))
            return false;
        firstHalf.pop();
    }
    return true;
}
int main()
{
    std::fstream fin;
    fin.open("palindrome.txt", std::ios::in);
    std::string line, word, temp;
    vector<string> data;
    while (fin >> temp) {
        // used for breaking words
        std::stringstream s(temp);
        char delim = ',';
        getline(s, word, delim);
        data.push_back(word);//populate data from file
        while (getline(s, word, delim))
            data.push_back(word);
    }
    for (auto candidate : data) {
        if (isPalindrome(candidate))
            cout << candidate << "\tis palindrome\n";
        else
            cout << candidate << "\tis not a palindrome\n";
    }
}
