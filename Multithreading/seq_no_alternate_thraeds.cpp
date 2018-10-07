#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

using namespace std;
 
std::condition_variable cv1;
std::condition_variable cv2;
std::mutex cv_m; 
                 
int i = 0;
int turn = 1;
 
void wait1()
{
    while(i<19)
    {
    std::unique_lock<std::mutex> lk(cv_m);
    cv2.wait(lk,[]{return turn%2 == 1;} );
    turn++;
    cout<<"Thread1:"<<++i<<std::endl;
    
    cv1.notify_one();
  }
}
void wait2()
{
    while(i<19)
   {
    std::unique_lock<std::mutex> lk(cv_m);
    cv1.wait(lk,[] { return turn%2 == 0;});
    turn++;
    cout<<"Thread2:"<<++i<<std::endl;
    cv2.notify_one();
   }
}
void waiting(int tid,int num)
{
    while(turn<22)
   {
    std::unique_lock<std::mutex> lk(cv_m);
    cv1.wait(lk,[&] { return turn%num == tid;});
    cout<<"Thread"<<tid<<":"<<turn++<<std::endl;
    cv1.notify_one();
   }
}

int main()
{
    std::thread t1(waiting,1,3); 
    thread t2(waiting,2,3);
    thread t3(waiting,0,3);
    t1.join(); 
    t2.join(); 
    t3.join(); 
}
