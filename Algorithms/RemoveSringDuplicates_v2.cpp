// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
int main()
{
    string s="AAABBBCCCCCCD";
   
    int j=0;
    for (int i =1; i<s.size();++i)
    {
        //cout<<s[i]<<":"<<s[i+1]<<"\n";
        if(s[i]!=s[j])
        { 
            cout<<s[i-1]<<":"<<s[i]<<":j-"<<j<<"\n";
            s[++j] = s[i];
        }
    }
    s.resize(j+1);
    
    std::cout<<"New string is :"<<s;
    
    
    
}
