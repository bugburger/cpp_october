#include <iostream>
#include <thread>

int main() {
    int a = 10;
    int b = 20;

    std::thread t([=]() {
        std::cout << "a = "
                  << a
                  << std::endl;

        std::cout << "b = "
                  << b
                  << std::endl;
    });

    t.join();

    return 0;
}
