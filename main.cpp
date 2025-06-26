#include <iostream>
#include <vector>

std::vector<int*> leaks;

void leak_memory() {
    for (int i = 0; i < 1000; i++) {
        int* ptr = new int[100];
        ptr[0] = 42;
        leaks.push_back(ptr);
    }
}

int main() {
    leak_memory();
    return 0;
}
