#include <iostream>
#include <thread>
#include <functional>

void worker(int& value) {
    value += 10;

    std::cout << "worker value = "
              << value
              << std::endl;
}

int main() {
    int number = 10;

    std::cout << "before thread, number = "
              << number
              << std::endl;

    std::thread t(worker, std::ref(number));

    t.join();

    std::cout << "after thread, number = "
              << number
              << std::endl;

    return 0;
}
