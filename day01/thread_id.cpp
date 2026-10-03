#include <iostream>
#include <thread>

void worker() {
    std::cout << "worker thread id = "
              << std::this_thread::get_id()
              << std::endl;
}

int main() {
    std::cout << "main thread id = "
              << std::this_thread::get_id()
              << std::endl;

    std::thread t(worker);

    std::cout << "t thread id = "
              << t.get_id()
              << std::endl;

    t.join();

    return 0;
}
