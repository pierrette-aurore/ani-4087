#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using Inclusions = std::map<std::string, std::vector<std::string>>;

static bool finitParCpp(const std::string& nom) {
    if (nom.size() < 4) {
        return false;
    }
    return nom.compare(nom.size() - 4, 4, ".cpp") == 0;
}

// Parcours par niveaux : renvoie le chemin jusqu'au premier en-tete externe
// rencontre, ou une chaine vide si aucun n'est atteint.
static std::string chercher(const std::string& unite, const Inclusions& inclusions,
                            const std::set<std::string>& externes) {
    std::set<std::string> vus;
    std::map<std::string, std::string> parent;
    std::queue<std::string> file;
    vus.insert(unite);
    file.push(unite);

    while (!file.empty()) {
        const std::string courant = file.front();
        file.pop();
        const auto it = inclusions.find(courant);
        if (it == inclusions.end()) {
            continue;
        }
        for (const std::string& nom : it->second) {
            if (vus.count(nom) > 0) {
                continue;
            }
            vus.insert(nom);
            parent[nom] = courant;
            if (externes.count(nom) > 0) {
                std::string chemin = nom;
                std::string actuel = nom;
                while (actuel != unite) {
                    actuel = parent[actuel];
                    chemin = actuel + ">" + chemin;
                }
                return chemin;
            }
            file.push(nom);
        }
    }
    return "";
}

int main() {
    int e = 0;
    std::cin >> e;
    std::set<std::string> externes;
    for (int i = 0; i < e; ++i) {
        std::string nom;
        std::cin >> nom;
        externes.insert(nom);
    }

    int f = 0;
    std::cin >> f;
    Inclusions inclusions;
    std::vector<std::string> unites;
    for (int i = 0; i < f; ++i) {
        std::string nom;
        int k = 0;
        std::cin >> nom >> k;
        std::vector<std::string> liste;
        for (int j = 0; j < k; ++j) {
            std::string inclus;
            std::cin >> inclus;
            liste.push_back(inclus);
        }
        inclusions[nom] = liste;
        if (finitParCpp(nom)) {
            unites.push_back(nom);
        }
    }

    int touchees = 0;
    for (const std::string& unite : unites) {
        const std::string chemin = chercher(unite, inclusions, externes);
        if (chemin.empty()) {
            std::cout << unite << " NON\n";
        } else {
            std::cout << unite << " OUI " << chemin << "\n";
            ++touchees;
        }
    }
    std::cout << "TOUCHEES " << touchees << " SUR " << unites.size() << "\n";
    return 0;
}
