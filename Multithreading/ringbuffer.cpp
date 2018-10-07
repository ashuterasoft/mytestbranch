#include<iostream>
#include<condition_variable>
#include<mutex>
#include<chrono>
#include<thread>

using namespace std;

mutex print;
template<typename T>
class RingBuffer
{
	private:
	int front,rear,size,capacity;
	T * data ;
	condition_variable not_empty;
	condition_variable not_full;
	mutex mu;

	public:
	RingBuffer():front(0),rear(0),data(0),size(0),capacity(0){};
	RingBuffer(int capacity):front(0),rear(0),size(0),capacity(capacity)
	{
		data = new T [capacity];

	}
	~RingBuffer()
	{
		delete [] data;
	}
	RingBuffer(const RingBuffer & rhs) =delete;
	RingBuffer& operator=(const RingBuffer & rhs) = delete;

	T pop();
	void push( const T & value);
};
template<typename T>
T RingBuffer<T>::pop()
{
	unique_lock<mutex> ul(mu);
	while(size ==0)
		not_empty.wait(ul);
	T result = data[front];
	front = (front+1)%capacity;
	--size;
	not_full.notify_all();
	return result;
}
template<typename T>
void RingBuffer<T>::push(const T & value)
{
	unique_lock<mutex> ul(mu);
	while(size == capacity)
		not_full.wait(ul);
	data[rear]= value;
	rear = (rear+1)%capacity;
	++size;
	not_empty.notify_one();
}
template<typename T>
void producer(int id ,RingBuffer<T> & buffer)
{
	
	for(int i=1;i< 100;i++)
	{
		buffer.push(i);
		unique_lock<mutex> p(print);
		cout<<"Producer id :" <<id<<" " <<i<<endl;
		p.unlock();
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}
template<typename T>
void consumer(int id ,RingBuffer<T> & buffer)
{
	while(true)	
	{
		T result = buffer.pop();
		unique_lock<mutex> p(print);
		cout<<"Consumer id:"<<id<<" "<<result<<endl;
		p.unlock();
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}
int main()
{
	RingBuffer<int> buffer(50);
	thread c1(consumer<int>, 0, std::ref(buffer));
    	thread c2(consumer<int>, 1, std::ref(buffer));
    	thread c3(consumer<int>, 2, std::ref(buffer));
    	thread p1(producer<int>, 0, std::ref(buffer));
    	thread p2(producer<int>, 1, std::ref(buffer));

    	c1.join();
    	c2.join();
    	c3.join();
    	p1.join();
    	p2.join();

}		
