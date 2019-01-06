#include <iostream>
#include <cstdlib>
using namespace std;

void reverse(int s ,int e ,string & str)
{
    while(s<e)
    {
        swap(str[s++],str[e--]);
    }
}

int main()
{
   string s = "i am a big boy";
   //cout<<s.size();
   int start =0 ;
   for(int i=0 ; i< s.size();++i)
   {
        if(s[i] == ' ' || (i == (s.size()-1)))
        {
            if(s[i] == ' ')
            reverse(start,i-1,s);
            else
            reverse(start,i,s);
            start=i+1;
         }
   }
   reverse(0,s.size()-1,s);
      cout<<s;

            
        
            
}


