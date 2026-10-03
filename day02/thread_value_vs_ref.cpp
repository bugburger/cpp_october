#include <iostream>
#include <thread>
#include <functional>

void changeByValue(int value) {
    value += 10;

    std::cout << "changeByValue: "
              << value
              << std::endl;
}

void changeByReference(int& value) {
    value += 10;

    std::cout << "changeByReference: "
              << value
              << std::endl;
}

int main() {
    int a = 10;
    int b = 10;

    std::thread t1(changeByValue, a);
    std::thread t2(changeByReference, std::ref(b));

    t1.join();
    t2.join();

    std::cout << "main a = "
              << a
              << std::endl;

    std::cout << "main b = "
              << b
              << std::endl;

    return 0;
}
