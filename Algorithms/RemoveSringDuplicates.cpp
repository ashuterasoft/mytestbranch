//Remove duplicate chars from string stl way
#include <iostream>
#include <algorithm>
#include <string>

 
int main()
{
    std::string s = "geeksforgeeks";
    int array [256] = {0};
    
    for(std::string::iterator i = s.begin();i!=s.end();)
    {
        int pos = *i;
       
        if(!array[pos])
        {
            array[pos] =1;
            ++i;
        }
        else
        {
            i = s.erase(i);
        }
    }
    std::cout << s << '\n';
 

}
