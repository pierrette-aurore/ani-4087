 #include <iostream>
#include <string>
#include <vector>

static bool signeDeNom(char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    if (c >= '0' && c <= '9') {
        return true;
    }
    return c == '_';
}

static bool signeDeMot(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return signeDeNom(c);
}

static bool estCommentaire(const std::string& ligne) {
    std::size_t debut = 0;
    while (debut < ligne.size() && (ligne[debut] == ' ' || ligne[debut] == '\t')) {
        ++debut;
    }
    return ligne.compare(debut, 2, "//") == 0;
}

static void chercherVariables(const std::string& l, std::vector<std::string>& variables) {
    for (std::size_t i = 0; i + 3 <= l.size(); ++i) {
        if (l.compare(i, 3, "NK_") != 0) {
            continue;
        }
        if (i > 0 && signeDeMot(l[i - 1])) {
            continue;
        }
        std::size_t j = i + 3;
        while (j < l.size() && signeDeNom(l[j])) {
            ++j;
        }
        if (j == i + 3) {
            continue;
        }
        if (j >= l.size() || l[j] != '=') {
            continue;
        }
        const std::string nom = l.substr(i, j - i);
        bool deja = false;
        for (const std::string& v : variables) {
            if (v == nom) {
                deja = true;
            }
        }
        if (!deja) {
            variables.push_back(nom);
        }
        i = j;
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    std::string reste;
    std::getline(std::cin, reste);

    std::vector<std::string> lignes;
    for (int i = 0; i < n; ++i) {
        std::string l;
        std::getline(std::cin, l);
        if (!l.empty() && l.back() == '\r') {
            l.pop_back();
        }
        lignes.push_back(l);
    }

    int entete = 0;
    std::vector<std::string> variables;
    for (const std::string& l : lignes) {
        if (!estCommentaire(l)) {
            break;
        }
        ++entete;
        chercherVariables(l, variables);
    }

    const int ignorees = n - entete;
    int part = 0;
    if (n > 0) {
        part = (100 * entete) / n;
    }

    std::cout << "ENTETE " << entete << "\n";
    std::cout << "IGNOREES " << ignorees << "\n";
    if (variables.empty()) {
        std::cout << "VARIABLE AUCUNE\n";
    }
    for (const std::string& v : variables) {
        std::cout << "VARIABLE " << v << "\n";
    }
    std::cout << "PART " << part << "\n";
    return 0;
}

