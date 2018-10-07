#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main()
{
	int array [256] = {0};
	for(int i=0 ;i<256;i++)
		cout<<array[i]<<" ";
	list<char> chars = { 'a','b','c','a','b','b'};
	int freq =0;
	char elem ;
	for(auto x: chars)
	{
		int value = x;
		array[value]++;
		if(freq< array[value] )
		{
			freq = array[value];
			elem = x;
		}
	}
	
	cout<<"The highest occuring char nearest to head is: "<<elem<<" with freq:"<<freq;
		
		
	
		
	

}
