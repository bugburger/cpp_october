#include <iostream>
#include <thread>
#include <chrono>

void worker() {
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "worker thread finished" << std::endl;
}

int main() {
    std::cout << "main thread starts" << std::endl;

    std::thread t(worker);

    t.detach();

    std::cout << "after detach, joinable = "
              << t.joinable()
              << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "main thread ends" << std::endl;

    return 0;
}
