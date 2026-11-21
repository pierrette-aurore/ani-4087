#include <iostream>
#include <string>
#include <vector>

int main() {
    int total = 0;
    std::cin >> total;

    int justes = 0;
    int fautives = 0;

    for (int t = 1; t <= total; ++t) {
        int n = 0;
        std::cin >> n;
        std::vector<std::string> appels(n);
        for (auto& a : appels) std::cin >> a;

        // Chaque image repart de zéro
        bool attendu = false;
        bool commence = false;
        bool fini = false;
        bool vues = false;
        bool pris[2] = {false, false};

        int place = 0;
        std::string code;

        for (int i = 0; i < n && place == 0; ++i) {
            const std::string& a = appels[i];
            std::string faute;

            if (fini) {
                faute = "APRES_END";
            } else if (a == "WAIT") {
                if (commence) faute = "WAIT_APRES_BEGIN";
                else attendu = true;
            } else if (a == "BEGIN") {
                if (commence) faute = "DOUBLE_BEGIN";
                else if (!attendu) faute = "BEGIN_SANS_WAIT";
                else commence = true;
            } else if (a == "VUES") {
                if (!attendu) faute = "VUES_SANS_WAIT";
                else vues = true;
            } else if (a == "PREND_G" || a == "PREND_D") {
                const int e = (a == "PREND_G") ? 0 : 1;
                if (!commence) faute = "PREND_SANS_BEGIN";
                else if (!vues) faute = "PREND_SANS_VUES";
                else if (pris[e]) faute = "DOUBLE_PREND";
                else pris[e] = true;
            } else if (a == "LACHE_G" || a == "LACHE_D") {
                const int e = (a == "LACHE_G") ? 0 : 1;
                if (!pris[e]) faute = "LACHE_SANS_PREND";
                else pris[e] = false;
            } else if (a == "END") {
                if (!commence) faute = "END_SANS_BEGIN";
                else if (pris[0] || pris[1]) faute = "END_IMAGE_PRISE";
                else fini = true;
            }

            if (!faute.empty()) {
                place = i + 1;
                code = faute;
            }
        }

        // Aucune faute mais pas de END : fin oubliée à la place n + 1
        if (place == 0 && !fini) {
            place = n + 1;
            code = "SANS_END";
        }

        if (place == 0) {
            std::cout << t << " OK\n";
            ++justes;
        } else {
            std::cout << t << " FAUTE " << place << " " << code << "\n";
            ++fautives;
        }
    }

    std::cout << "JUSTES " << justes << "\n";
    std::cout << "FAUTIVES " << fautives << "\n";
    return 0;
}
