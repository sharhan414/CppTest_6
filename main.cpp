#include <iostream>
#include <thread>

using namespace std;
static bool FuncThreadCont=true;
void func(){
    int32_t Timer=0;
    while(FuncThreadCont){
        this_thread::sleep_for(chrono::milliseconds(100));
cout<<"Timer:"<<++Timer<<endl;
    }

}

int main(){
cout<<"Programms is begin"<<endl;

thread FuncTread(func);

cout<<"Hello, world!"<<endl;

FuncTread.join();
cout<<"Programms is End"<<endl;

return  0;
}
