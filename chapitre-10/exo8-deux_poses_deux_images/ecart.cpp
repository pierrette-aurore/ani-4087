
#include <cmath>
#include <iostream>

// Distance arrondie à l'entier le plus proche, en calcul entier
static long long racineArrondie(long long d) {
    long long r = static_cast<long long>(std::sqrt(static_cast<double>(d)));
    while (r * r > d) --r;
    while ((r + 1) * (r + 1) <= d) ++r;
    return (d - r * r > r) ? r + 1 : r;
}

int main() {
    int n = 0;
    long long d = 0;
    std::cin >> n >> d;

    long long sommePos = 0;
    long long sommeAng = 0;

    for (int t = 1; t <= n; ++t) {
        long long x1, z1, a1, x2, z2, a2;
        std::cin >> x1 >> z1 >> a1 >> x2 >> z2 >> a2;

        const long long dx = x2 - x1;
        const long long dz = z2 - z1;
        const long long p = racineArrondie(dx * dx + dz * dz);
        long long a = a2 - a1;
        if (a < 0) a = -a;

        std::cout << t << " POSITION " << p << " ANGLE " << a << "\n";
        sommePos += p;
        sommeAng += a;
    }

    if (n == 0 || d == 0) {
        std::cout << "AUCUNE\n";
        return 0;
    }

    std::cout << "MOYENNE POSITION " << sommePos / n << "\n";
    std::cout << "MOYENNE ANGLE " << sommeAng / n << "\n";
    std::cout << "VITESSE " << sommeAng / (n * d) << "\n";
    return 0;
}
