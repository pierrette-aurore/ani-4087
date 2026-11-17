
#include <iostream>
#include <string>

int main() {
    std::string politique;
    int total;
    std::cin >> politique >> total;

    std::string mot;
    if (total > 0) std::cin >> mot;
    const int taille = static_cast<int>(mot.size());
    const bool toujours = (politique == "TOUJOURS");

    bool ouverte = false;
    int rendues = 0;
    int perdues = 0;
    int erreurs = 0;
    int premier = 0;

    for (int t = 1; t <= total; ++t) {
        const bool signe = (t - 1 < taille) && (mot[t - 1] == '1');
        bool rendre = false;

        const char* w;
        if (ouverte) {
            w = "REFUSE";
            ++erreurs;
            if (premier == 0) premier = t;
        } else {
            w = "OK";
            rendre = signe;
        }

        const char* b;
        if (ouverte) {
            b = "REFUSE";
            ++erreurs;
        } else {
            b = "OK";
            ouverte = true;
        }

        if (rendre) ++rendues;
        else if (signe) ++perdues;

        const char* e;
        if (toujours || rendre) {
            if (ouverte) {
                e = "OK";
                ouverte = false;
            } else {
                e = "REFUSE";
                ++erreurs;
            }
        } else {
            e = "-";
        }

        std::cout << t << " " << w << " " << b << " "
                  << (rendre ? "OUI" : "NON") << " " << e << "\n";
    }

    std::cout << "RENDUES " << rendues << "\n";
    std::cout << "PERDUES " << perdues << "\n";
    std::cout << "ERREURS " << erreurs << "\n";
    if (premier == 0) std::cout << "PREMIER REFUS AUCUN\n";
    else std::cout << "PREMIER REFUS " << premier << "\n";
    return 0;
}

//Resultat
//1 OK OK OUI OK
//2 OK OK OUI OK
//3 OK OK NON -
//4 REFUSE REFUSE NON -
// REFUSE REFUSE NON -
//RENDUES 2
//PERDUES 2
//ERREURS 6
//PREMIER REFUS 4
