#include<iostream>





using namespace std;

template<typename T>
class vector
{
	private:
	T * data;
	int size;
	int capacity;
	T * iterator;


	public:
	vector():size(0):capacity(0){};
	vector(int capacity) :capacity(capacity);
	void push_back(const T & value);
	void reserve(unsigned int , bool copy);
	T& front()
	{
		if(data)
		 return data[0];
		
	}
	T& back()
	{
		if(data)
		 data[size -1];
	}

	vector(const vector & rhs);
	const vector & operator=(const vector & rhs);


};

template<typename T>
vector<T>::reserve(unsigned int size , bool copy )
{
	T * newArray;
	
	newArray =  new T[n];
	

	if(copy)
	for(int i =0;i< size ; i++)
		newArray[i] = data[i];

	if(data)
	 delete [] data;

	data = newArray;
	capacity = n;
}
	

