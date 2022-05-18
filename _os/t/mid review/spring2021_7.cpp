#include <iostream>
#include <mutex>

int main()
{
    std::mutex m;
    m.lock();
    printf("lianqi\n");
    m.unlock();
    return 0;
}