#include <iostream>
#include "Array.hpp"

#define MAX_VAL 25

void    leaks(void)
{
    system("leaks -q Array");
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 15;
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "---------NUMBERS---------" << std::endl;
    std::cout << numbers << std::endl;
    std::cout << "---------MIRROR---------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << mirror[i] << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        std::cout << "---------TMP---------" << std::endl;
        std::cout << tmp << std::endl;
        Array<int> test(tmp);
        std::cout << "---------TEST---------" << std::endl;
        std::cout << test << std::endl;
    }
    std::cout << "---------COMPARE ARRAYS---------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return (1);
        }
    }
    std::cout << "---------CONTENT IS THE SAME!---------" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "---------NUMBERS---------" << std::endl;
    std::cout << numbers << std::endl;
    delete [] mirror;
    atexit(&leaks);
    return 0;
}