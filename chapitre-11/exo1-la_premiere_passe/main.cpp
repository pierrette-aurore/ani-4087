#include <string>
#include <vector>

// Vrai si c'est une majuscule, un chiffre ou _
static bool signeDeNom(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}

// Vrai si c'est une lettre, un chiffre ou _
static bool signeDeMot(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9') || c == '_';
}

int main() {
    int n = 0;
    std::cin >> n;
    std::string reste;
    std::getline(std::cin, reste);  // fin de la ligne contenant N

    std::vector<std::string> lignes;
    for (int i = 0; i < n; ++i) {
        std::string l;
        std::getline(std::cin, l);
        if (!l.empty() && l.back() == '\r') l.pop_back();
        lignes.push_back(l);
    }

    // L'en-tête : les lignes du haut qui commencent par //
    int entete = 0;
    std::vector<std::string> variables;

    for (const std::string& l : lignes) {
        std::size_t debut = 0;
        while (debut < l.size() && (l[debut] == ' ' || l[debut] == '\t')) ++debut;
        if (l.compare(debut, 2, "//") != 0) break;
        ++entete;

        // Chercher les variables NK_xxx= dans cette ligne
        for (std::size_t i = 0; i + 3 <= l.size(); ++i) {
            if (l.compare(i, 3, "NK_") != 0) continue;
            if (i > 0 && signeDeMot(l[i - 1])) continue;

            std::size_t j = i + 3;
            while (j < l.size() && signeDeNom(l[j])) ++j;
            if (j == i + 3) continue;                 // au moins un signe
            if (j >= l.size() || l[j] != '=') continue;  // suivi tout de suite d'un =

            const std::string nom = l.substr(i, j - i);
            bool deja = false;
            for (const std::string& v : variables) {
                if (v == nom) { deja = true; break; }
            }
            if (!deja) variables.push_back(nom);
            i = j;
        }
    }

    const int ignorees = n - entete;
    const int part = (n == 0) ? 0 : (100 * entete) / n;

    std::cout << "ENTETE " << entete << "\n";
    std::cout << "IGNOREES " << ignorees << "\n";
    if (variables.empty()) {
        std::cout << "VARIABLE AUCUNE\n";
    } else {
        for (const std::string& v : variables) {
            std::cout << "VARIABLE " << v << "\n";
        }
    }
    std::cout << "PART " << part << "\n";
    return 0;
}

