// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
int main()
{
    std::cout << "Hello, Wandbox!" << std::endl;
    string str = "{[()))";
    stack<char> st;
    int i=0;
    while(str[i])
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
            st.push(str[i]);
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
                char br = st.top();
                if( str[i] == '}' && br == '{')
                    st.pop();
                else if(str[i] == ']'&& br == '[')
                    st.pop();
                else if(str[i] == ')' && br == '(')
                    st.pop();
                else
                {
                    cout<<"breaking loop\n";
                    break;
                }
        }
        else
        {
            cout<<"Invalid character found\n";
            break;
        }
        i++;
   }
   if(st.empty())
    cout<<"balanced";
    else
    cout<<"unbalanced";
        
}

// GCC reference:
//   https://gcc.gnu.org/

// C++ language references:
//   https://msdn.microsoft.com/library/3bstk3k5.aspx
//   http://www.cplusplus.com/
//   https://isocpp.org/
//   http://www.open-std.org/jtc1/sc22/wg21/

// Boost libraries references:
//   http://www.boost.org/doc/

