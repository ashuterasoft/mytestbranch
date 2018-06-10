#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int binary_search( int a [] , int size,int elem)
 {
	 int low = 0;
	 int high = size -1;
	 while(low<high)
	 {
		int mid = low+ (high-low)/2;
		if( a[mid] == elem)
			return mid+1;
		else if( a[mid] < elem)
			high = mid -1;
		
		else
			low = mid+1;
	 }	
	 return -1;
 
 }
 class bomb
 {
	 private:
	 int x;
	 public:
	 bomb():x(0){cout<<"default ctor\n";}
	 ~bomb(){cout<<"in dtor\n"; throw "hello";}
	 void * operator new(size_t n) throw()
	 {
		 cout<<"operator new\n";
		 return malloc(n);
	 }
	 void operator delete(void  * p) throw()
	 {
		 cout<<"operator delete\n";
		 if(p)
		  free(p);
	 }
};
 void f()
 {
	 bomb mybomb;
	 bomb *pbomb = new bomb();
	 try
	 {
		 delete pbomb;
	 }
	 catch(...)
	 {
		 cout<<"Exception 1 caught\n";
		 
	 }
	 throw "no bomb";
}
	
int main()
{
	int *i = new int(10);
	cout<<*i<<endl;

	try
	{
		f();
	}
	catch(...)
	{
		cout<<"Exception 2 caught:"<<endl;
	}

	int num = 12345;
	int res =0;
	while(num)
	{
		res = res * 10 + num%10;
		num = num/10;
		
	}
 //cout<<res;
 
 int a [] = {5,8,9,10,12};
 int size = sizeof(a)/sizeof(a[0]);
 
 int elem = 9;
 
 cout<<binary_search(a,size,elem);
 return 0;
}
