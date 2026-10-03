#include <iostream>
#include <thread>

void worker() {
    std::cout << "worker is running" << std::endl;
}

int main() {
    std::thread t(worker);

    std::cout << "before join, joinable = "
              << t.joinable()
              << std::endl;

    t.join();

    std::cout << "after join, joinable = "
              << t.joinable()
              << std::endl;

    return 0;
}
