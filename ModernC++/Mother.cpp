//
// Created by Shweta Neema on 28/07/2018.
//
#include "Mother.h"
Mother::Mother(const string & name): name(name){
    std::cout<<"Hey Iam Mother\n";
}
void Mother::addChild(shared_ptr<Child> & child)
{
    this->child = child;
}
void Mother::tellChildName()
{
    cout<<"Child name is :"<<child->getName();
}

const string &Mother::getName() const {
    return name;
}