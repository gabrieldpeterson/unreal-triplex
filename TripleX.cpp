#include <iostream>

int main()
{
    std::cout << "\nYou are a secret agent breaking into a secure server room\n";
    std::cout << "You need to enter the correct codes to continue\n";

    int CodeA = 4;
    int CodeB = 7;
    int CodeC = 8;

    int Sum = CodeA + CodeB + CodeC;
    int Product = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are three numbers in the code" << std::endl;
    std::cout << "+ The codes add up to: " << Sum << std::endl;
    std::cout << "+ The codes multiply to give: " << Product << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    std::cout << "You guessed: " << GuessA;

    return 0;
}