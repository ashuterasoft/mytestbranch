//
// Created by Shweta Neema on 28/07/2018.
//

#ifndef MODERNC_CHILD_H
#define MODERNC_CHILD_H
#include<iostream>
#include<memory>
#include<string>
using namespace std;
class Mother;
class Child
{
public:
    Child(const string & name);
    ~Child(){ std::cout<<"\nChild out of country now";}
    void addMother(shared_ptr<Mother> & mother);
    void tellMotherName();

    const string &getName() const;

private:
    weak_ptr<Mother> mother;
    std::string name ;
};
#endif //MODERNC_CHILD_H
