#include <iostream>
using namespace std;

int main()
{
    char array[256];
    cout << "what is this?\n";
    cin >> array;
    cout << "it is " << array << "\n";
    
    printf("it is 李碧滢\n");
    //为打出中文: g++ -fexec-charset=GBk 3.cpp
}