#include <iostream>

int main() {
    long long w;
    int total;
    std::cin >> w >> total;

    int fausses = 0;
    long long pireCasque = 0;
    long long pireSimu = 0;

    for (int t = 1; t <= total; ++t) {
        long long p, s, a;
        char m;
        std::cin >> p >> s >> a >> m;

        const long long rendu = w * p;
        const long long soumise = (m == 'R') ? w * p : w * s;
        const long long casque = soumise - rendu;
        const long long simu = w * a - w * p;

        std::cout << t << " CASQUE " << casque << " SIMULATEUR " << simu << "\n";

        if (casque != 0) ++fausses;
        const long long ac = casque < 0 ? -casque : casque;
        const long long as = simu < 0 ? -simu : simu;
        if (ac > pireCasque) pireCasque = ac;
        if (as > pireSimu) pireSimu = as;
    }

    std::cout << "FAUSSES " << fausses << "\n";
    std::cout << "PIRE CASQUE " << pireCasque << "\n";
    std::cout << "PIRE SIMULATEUR " << pireSimu << "\n";
    return 0;
}
// resultat
//1 wait OK
//2 begin OK
//3 acquire OK 0
//4 release OK
//5 acquire OK 0
//6 release OK
//7 end OK
//8 wait OK
//9 begin OK
//10 acquire OK 1
//11 release OK
//12 end OK AVERT D
//JOURNAL 0
//AVERTISSEMENTS 1
//SILENCIEUX 0

