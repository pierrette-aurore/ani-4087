#include <iostream>

int main()
{
#if defined(_WIN32)
    std::cout << "Plateforme detectee au run : Windows" << std::endl;
#elif defined(__linux__)
    std::cout << "Plateforme detectee au run : Linux" << std::endl;
#else
    std::cout << "Plateforme detectee au run : inconnue" << std::endl;
#endif
    return 0;
}
