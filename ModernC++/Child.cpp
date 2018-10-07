//
// Created by Shweta Neema on 28/07/2018.
//
#include "Child.h"
#include "Mother.h"
Child::Child(const string & name): name(name){
    std::cout<<"Hey Iam Child\n";
}
void Child::addMother(shared_ptr<Mother> & mother)
{
    this->mother = mother;
}
void Child::tellMotherName()
{
    shared_ptr mom = mother.lock();
    if(mom)
        cout<<"Mother name is :"<<mom->getName();
    else
        cout<<"Mother not available\n";
}

const string &Child::getName() const {
    return name;
}