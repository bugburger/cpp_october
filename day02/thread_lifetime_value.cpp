#include <iostream>
#include <thread>
#include <chrono>

void startWorker() {
    int number = 10;

    std::thread t([number]() {
        std::this_thread::sleep_for(
            std::chrono::seconds(1)
        );

        std::cout << "number = "
                  << number
                  << std::endl;
    });

    t.detach();
}

int main() {
    startWorker();

    std::this_thread::sleep_for(
        std::chrono::seconds(2)
    );

    return 0;
}
