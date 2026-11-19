#include <iostream>
#include <string>

int main() {
    int n = 0;
    std::cin >> n;

    int muettes = 0;

    for (int i = 1; i <= n; ++i) {
        std::string fin, instant, pose, espace;
        int g = 0;
        int d = 0;
        std::cin >> fin >> g >> d >> instant >> pose >> espace;

        // Symptomes sur un casque, dans l'ordre demande
        std::string symptomes;
        auto ajouter = [&symptomes](const char* s) {
            if (!symptomes.empty()) symptomes += " ";
            symptomes += s;
        };

        if (fin == "JAMAIS") ajouter("FIGE");
        else if (fin == "SI_RENDU") ajouter("NE_REPART_PAS");
        if (g == 0) ajouter("OEIL_NOIR_G");
        if (d == 0) ajouter("OEIL_NOIR_D");
        if (instant == "N") ajouter("TREMBLE");
        if (pose == "F") ajouter("DE_TRAVERS");
        if (espace == "L") ajouter("DECALE");

        const bool symptome = !symptomes.empty();
        // Le simulateur ecrit si la fin n'est pas TOUJOURS, ou si une chaine manque
        const bool dit = (fin != "TOUJOURS") || (g == 0) || (d == 0);

        std::cout << i << " CASQUE ";
        if (symptome) std::cout << symptomes;
        else std::cout << "AUCUN";
        std::cout << "\n";
        std::cout << i << " SIMULATEUR " << (dit ? "DIT" : "MUET") << "\n";

        if (symptome && !dit) ++muettes;
    }

    std::cout << "MUETTES " << muettes << "\n";
    return 0;
}
