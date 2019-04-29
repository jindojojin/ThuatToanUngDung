#include <iostream>
#include <thread>
using namespace std;
void threadFunc()
{
	cout << "Welcome to Multithreading" << endl;

}
int main()
{
//truyền 1 function tới thread
    thread funcTest1(threadFunc);
}