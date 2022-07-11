#include <iostream>
#include <thread>

using namespace std;

class Timer
{
public:

    Timer();
    Timer(uint32_t hous,uint32_t min,uint32_t seconds,uint32_t mills);
    ~Timer(){}
    void start();
    void restart();
    void stop();
    void setHous(uint32_t hous);
    void setMinutes(uint32_t min);;
    void setSeconds(uint32_t sec);
    void setMilleseconds(uint32_t mills);

    uint32_t getHous();
    uint32_t getMinutes();
    uint32_t getSeconds();
    uint32_t getMilleseconds();
private:
    uint32_t m_hous, m_minutes, m_seconds, m_milleseconds;
    bool m_isEnabled;
    void working();

};
Timer::Timer()
{
    m_hous=m_minutes=m_seconds=m_milleseconds=0;
    m_isEnabled=false;

}
Timer::Timer(uint32_t hous,uint32_t min,uint32_t seconds,uint32_t mills)
{
    m_hous=hous;
    m_minutes=min;
    m_seconds=seconds;
    m_milleseconds=mills;
    m_isEnabled=false;
}

void Timer::start()
{
    m_isEnabled=true;

    thread t1([this]()
    {
        this->working();

    }
    );
    cout<<"------------"<<endl;

    t1.detach();
    cout<<"++++++++++++++"<<endl;
}
void Timer::restart()
{
    m_hous=m_minutes=m_seconds=m_milleseconds=0;
    m_isEnabled=true;
}
void Timer::stop()
{
    m_isEnabled=false;
}

void Timer::working()
{
   while(m_isEnabled)
   {

       this_thread::sleep_for(5ms);
       m_milleseconds+=5;

       if(m_milleseconds >= 1000)
       {
           m_milleseconds=0;
           m_seconds++;
       }
       if(m_seconds >= 60)
       {
           m_seconds=0;
           m_minutes++;
       }

       if(m_minutes >= 60)
       {
           m_minutes=0;
           m_hous++;
       }
       cout<<m_hous<<":"<<m_minutes<<":"<<m_seconds<<":"<<m_milleseconds<<endl;
   }

}


void Timer::setHous(uint32_t hous)
{
    m_hous=hous;
}
void Timer::setMinutes(uint32_t min)
{
    m_minutes=min;
}
void Timer::setSeconds(uint32_t sec)
{
    m_seconds=sec;
}
void Timer::setMilleseconds(uint32_t mills)
{
    m_milleseconds=mills;
}

uint32_t Timer::getHous()
{
    return m_hous;
}
uint32_t Timer::getMinutes()
{
    return m_minutes;
}
uint32_t Timer::getSeconds()
{
    return m_seconds;
}
uint32_t Timer::getMilleseconds()
{
    return m_milleseconds;
}


static bool FuncThreadCont=true;
void func()
{
    cout<<"Funt thread is STARTED"<<endl;
    int32_t Timer=0;
    while(FuncThreadCont)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
        cout<<"Timer:"<<++Timer<<endl;
    }
    cout<<"Funt thread is close"<<endl;
}

int main(){
    cout<<"Programms is begin"<<endl;
    Timer timer;
    timer.start();


    for(int i=0;i<1000;++i)
    {
        this_thread::sleep_for(chrono::milliseconds(100));

    }
   /*
    thread FuncTread(func);

    cout<<"Hello, world!"<<endl;

    FuncTread.join();

    cout<<"Programms is End"<<endl;
*/
return  0;
}
