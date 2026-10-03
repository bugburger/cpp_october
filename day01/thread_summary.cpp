#include <iostream>
#include <thread>
#include <chrono>

void worker(int id, int seconds) {
    std::cout << "worker " << id
              << " starts, thread id = "
              << std::this_thread::get_id()
              << std::endl;

    std::this_thread::sleep_for(
        std::chrono::seconds(seconds)
    );

    std::cout << "worker " << id
              << " ends"
              << std::endl;
}

int main() {
    std::cout << "main thread id = "
              << std::this_thread::get_id()
              << std::endl;

    std::thread t1(worker, 1, 3);
    std::thread t2(worker, 2, 1);
    std::thread t3(worker, 3, 2);

    std::cout << "t1 joinable = "
              << t1.joinable()
              << std::endl;

    std::cout << "t2 joinable = "
              << t2.joinable()
              << std::endl;

    std::cout << "t3 joinable = "
              << t3.joinable()
              << std::endl;

    t1.join();
    t2.join();
    t3.join();

    std::cout << "after join:" << std::endl;

    std::cout << "t1 joinable = "
              << t1.joinable()
              << std::endl;

    std::cout << "t2 joinable = "
              << t2.joinable()
              << std::endl;

    std::cout << "t3 joinable = "
              << t3.joinable()
              << std::endl;

    std::cout << "main thread ends"
              << std::endl;

    return 0;
}
