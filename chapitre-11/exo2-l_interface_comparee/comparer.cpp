#include <iostream>
#include <set>
#include <string>
#include <vector>

static std::vector<std::string> lireListe() {
    int n = 0;
    std::cin >> n;
    std::vector<std::string> noms;
    for (int i = 0; i < n; ++i) {
        std::string nom;
        std::cin >> nom;
        noms.push_back(nom);
    }
    return noms;
}

int main() {
    const std::vector<std::string> a = lireListe();
    const std::vector<std::string> b = lireListe();
    const std::set<std::string> ensembleA(a.begin(), a.end());
    const std::set<std::string> ensembleB(b.begin(), b.end());

    int communs = 0;
    for (const std::string& nom : ensembleA) {
        if (ensembleB.count(nom) > 0) {
            ++communs;
        }
    }
    std::cout << "DEUX " << communs << "\n";

    int seuls = 0;
    for (const std::string& nom : a) {
        if (ensembleB.count(nom) == 0) {
            std::cout << "SEUL_A " << nom << "\n";
            ++seuls;
        }
    }
    for (const std::string& nom : b) {
        if (ensembleA.count(nom) == 0) {
            std::cout << "SEUL_B " << nom << "\n";
            ++seuls;
        }
    }

    std::set<std::string> reunion(ensembleA);
    reunion.insert(ensembleB.begin(), ensembleB.end());
    std::cout << "DIFFERENTES " << seuls << " SUR " << reunion.size() << "\n";
    return 0;
}
