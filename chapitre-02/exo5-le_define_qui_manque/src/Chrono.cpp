#include "Chrono.hpp"

#ifdef AVEC_CHRONO

#include <iostream>

void Chrono::demarrer()
{
    std::cout << "Chrono demarre." << std::endl;
}

void Chrono::afficherDuree()
{
    std::cout << "Duree ecoulee : (mesure non branchee dans cet exercice)." << std::endl;
}

#endif
