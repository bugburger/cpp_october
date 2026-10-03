#include <iostream>
#include <thread>

int main() {
    int a = 10;
    int b = 20;

    std::thread t([&]() {
        a += 100;
        b += 100;

        std::cout << "thread a = "
                  << a
                  << std::endl;

        std::cout << "thread b = "
                  << b
                  << std::endl;
    });

    t.join();

    std::cout << "main a = "
              << a
              << std::endl;

    std::cout << "main b = "
              << b
              << std::endl;

    return 0;
}
