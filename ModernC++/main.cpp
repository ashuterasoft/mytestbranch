#include <iostream>
#include <memory>
#include "Mother.h"
#include "Child.h"
using namespace std;

class test
{
    public:
    void serialize()
    {
        cout<<"Say serialize\n";
    }
};

class test1
{
    public:
    void to_string()
    {
        cout<<"Say string\n";
    }
};
class test3
{
public:
    void to_string1()
    {
        cout<<"Say string\n";
    }
};

template <typename T>
auto func( T t )->decltype(t.serialize())
{
    t.serialize();
};
template <typename T>
auto func( T t )->decltype(t.to_string())
{
    t.to_string();
};
void func( ... )
{
    cout<<"Ordinary\n";
};

int main() {
    //std::cout << "Hello, World!" << std::endl;
    //Node node;
    //node.implementation();
    func(test{});
    func(test1{});
    func(5);
    func(test3{});

    auto child = make_shared<Child>("Reyaan");
    {
        auto mother = make_shared<Mother>("Shweta");
        mother->addChild(child);
        mother->tellChildName();
        std::cout<<"\n";
        child->addMother(mother);
        std::cout<<child->getName()<<" ";
        child->tellMotherName();

    }
    child->tellMotherName();
    cout<<"child"<<child->getName();

    return 0;
}