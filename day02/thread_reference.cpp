#include <iostream>
#include <thread>

void worker(int& value) {
    value += 10;

    std::cout << "worker value = "
              << value
              << std::endl;
}

int main() {
    int number = 10;

    std::thread t(worker, number);

    t.join();

    std::cout << "main number = "
              << number
              << std::endl;

    return 0;
}
