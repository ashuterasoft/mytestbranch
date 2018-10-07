//
// Created by Shweta Neema on 28/07/2018.
//

#ifndef MODERNC_MOTHER_H
#define MODERNC_MOTHER_H
#include<iostream>
#include<memory>
#include<string>
#include "Child.h"
using namespace std;
class Mother
{
public:
    Mother(const string & name);
    void addChild(shared_ptr<Child> & child);
    void tellChildName();
    const string &getName() const ;
    ~Mother(){ std::cout<<"\nMother out of country now\n";}

private:
    shared_ptr<Child> child;
    string name;

};
#endif //MODERNC_MOTHER_H
