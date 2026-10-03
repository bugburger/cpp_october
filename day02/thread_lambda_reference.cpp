#include <iostream>
#include <thread>

int main() {
    int number = 10;

    std::thread t([&number]() {
        number += 10;

        std::cout << "thread number = "
                  << number
                  << std::endl;
    });

    t.join();

    std::cout << "main number = "
              << number
              << std::endl;

    return 0;
}
