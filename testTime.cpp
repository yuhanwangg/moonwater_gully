
#include <iostream>
#include <ctime>



int main() {
    time_t starTime = time(NULL);
    int count = 0;
    int animal = 0;
    std::cout << "enter your favourite animal: "; 
    std::cin >> animal;
    std::cout << "time elapsed: " << time(NULL) - starTime << std::endl; /// gives it in seconds

    return 0;
}