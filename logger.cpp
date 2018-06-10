#include<fstream>
#include<mutex>
#include<thread>
#include<condition_variable>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<chrono>
#include<sstream>

using namespace std;

class Logger
{
	private:
		mutex qm;
		mutex fm;
		condition_variable empty;
		queue<string> mq;
		vector<thread> vt;
		ofstream file;
		static Logger * logger;
		Logger(int num_threads,const string & filename);
		Logger(const Logger & rhs);
		Logger & operator=(const Logger & rhs);
	
	public:
		~Logger();
		void log(const string & msg);
		void worker(int num);
		static Logger * getInstance();
		static void initialize(int num_threads, const string & filename);

};
Logger * Logger::logger = nullptr;
void Logger::worker(int num)
{
	 cout<<"starting thread:"<<this_thread::get_id()<<"\n";
	while(true)
	{
		unique_lock<mutex> lg(qm);
		while(mq.empty())
			empty.wait(lg);
		string msg = mq.front();
		mq.pop();
		lg.unlock();
		lock_guard<mutex> ll(fm);
		file<<msg<<" threadid:" <<num<<"\n";
		cout<<msg<<"\n";
		file.flush();
	}
}
Logger::Logger(int num_threads,const string & filename)
{
	if(!filename.empty())
	{
		file.open(filename);
	}
	for(int i= 0;i<num_threads;++i)
		vt.push_back(thread(&Logger::worker,this,i));
}
Logger::~Logger()
{
	for(auto & th :vt)
		th.join();
	file.close();
}
void Logger::log(const string & msg)
{
	unique_lock<mutex> lm (qm);
	mq.push(msg);
	lm.unlock();
	empty.notify_all();
}
Logger * Logger::getInstance()
{
	if(!logger)
	{
	   cout<<"Initialize logger first\n";
	}
	return logger;
}
void Logger::initialize(int num_threads ,const string & filename)
{
	if(!logger)
	{
		logger = new Logger(num_threads,filename);
		return ;
	}
	cout<<"Logger already initialized\n";
}
void producer(int i,Logger * logger)
{
	cout<<"Producer:"<<i<<"started\n";
	for(int j=0;j<100;j++)
	{
		stringstream ss;
		ss<<"message producer:"<<i<<"I am :"<<j;
		logger->log(ss.str());
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}
		
	
int main()
{
	Logger::initialize(5,"log.txt");
	Logger * lg  = Logger::getInstance();
	thread th(producer,1,lg);
	thread th1(producer,2,lg);
	

	th.join();
	th1.join();
	
	return 0;
}
