#include <iostream>

struct Pose {
    long long x, y, z;
    int k;
};

static void tourner(long long x, long long z, int k, long long& rx, long long& rz) {
    switch (k) {
        case 0: rx = x;  rz = z;  break;
        case 1: rx = z;  rz = -x; break;
        case 2: rx = -x; rz = -z; break;
        default: rx = -z; rz = x; break;
    }
}

// Passage de LOCAL à STAGE : l'ancre composée avec la pose p
static Pose composer(const Pose& a, const Pose& p) {
    long long rx = 0;
    long long rz = 0;
    tourner(p.x, p.z, a.k, rx, rz);
    Pose r;
    r.x = a.x + rx;
    r.y = a.y + p.y;
    r.z = a.z + rz;
    r.k = (a.k + p.k) % 4;
    return r;
}

int main() {
    Pose ancre;
    std::cin >> ancre.x >> ancre.y >> ancre.z >> ancre.k;
    int n = 0;
    std::cin >> n;

    int justes = 0;
    int fausses = 0;

    for (int i = 1; i <= n; ++i) {
        char d, c;
        Pose p;
        std::cin >> d >> c >> p.x >> p.y >> p.z >> p.k;

        const Pose vraie = (d == 'S') ? p : composer(ancre, p);
        const Pose crue = (c == 'S') ? p : composer(ancre, p);

        const long long dx = crue.x - vraie.x;
        const long long dy = crue.y - vraie.y;
        const long long dz = crue.z - vraie.z;
        const int dk = (crue.k - vraie.k + 4) % 4;

        std::cout << i << " CRU " << crue.x << " " << crue.y << " "
                  << crue.z << " " << crue.k << "\n";
        std::cout << i << " ECART " << dx << " " << dy << " "
                  << dz << " " << dk << "\n";

        if (dx == 0 && dy == 0 && dz == 0 && dk == 0) ++justes;
        else ++fausses;
    }

    std::cout << "JUSTES " << justes << "\n";
    std::cout << "FAUSSES " << fausses << "\n";
    return 0;
}

// resultats
//1 CRU 100 1700 -200 0
//1 ECART 0 0 0 0
//2 CRU 100 3400 -200 0
//2 ECART 0 1700 0 0
//3 CRU 0 0 0 0
//3 ECART 0 -1700 0 0
//4 CRU 50 1700 -300 1
//4 ECART 0 0 0 0
//JUSTES 2
//FAUSSES 2
