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


thread FuncTread(func);

cout<<"Hello, world!"<<endl;

FuncTread.join();

return  0;
}
