#include <iostream>

void leak_memory() {
    // int* ptr = new int[100];
    // ptr[0] = 42;
    // std::cout << "Leaked memory with value: " << ptr[0] << std::endl;
}

int main() {
    leak_memory();
    return 0;
}
