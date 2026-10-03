#include <iostream>
#include <thread>

void worker() {
    std::cout << "worker thread is running" << std::endl;
}

int main() {
    std::cout << "main thread starts" << std::endl;

    std::thread t(worker);

    std::cout << "before join: "
              << t.joinable()
              << std::endl;

    t.join();

    std::cout << "after join: "
              << t.joinable()
              << std::endl;

    std::cout << "main thread ends" << std::endl;

    return 0;
}
