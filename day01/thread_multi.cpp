#include <iostream>
#include <thread>
#include <chrono>

void worker(int id) {
    std::cout << "worker " << id
              << " starts, thread id = "
              << std::this_thread::get_id()
              << std::endl;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(500)
    );

    std::cout << "worker " << id
              << " ends"
              << std::endl;
}

int main() {
    std::cout << "main thread starts" << std::endl;

    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "main thread ends" << std::endl;

    return 0;
}
