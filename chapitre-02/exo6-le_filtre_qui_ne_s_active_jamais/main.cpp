#include <iostream>

int main()
{
#ifdef PLATEFORME_LINUX
    std::cout << "Filtre actif : compile pour Linux." << std::endl;
#else
    std::cout << "Filtre inactif : le define PLATEFORME_LINUX est absent." << std::endl;
#endif
    return 0;
}
