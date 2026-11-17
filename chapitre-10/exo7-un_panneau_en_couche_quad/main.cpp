#include <cmath>
#include <iostream>

static void tourner(long long x, long long z, int k, long long& rx, long long& rz) {
    switch (k) {
        case 0: rx = x;  rz = z;  break;
        case 1: rx = z;  rz = -x; break;
        case 2: rx = -x; rz = -z; break;
        default: rx = -z; rz = x; break;
    }
}

int main() {
    long long ax, ay, az;
    int ak;
    long long ex, ey, ez;
    int n = 0;
    std::cin >> ax >> ay >> az >> ak;
    std::cin >> ex >> ey >> ez;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        char e;
        long long x, y, z, w, h;
        int k;
        std::cin >> e >> x >> y >> z >> k >> w >> h;

        // Sans espace précisé (-) : LOCAL
        const bool stage = (e == 'S');

        long long cx = x;
        long long cy = y;
        long long cz = z;
        int ck = k;
        if (!stage) {
            long long rx = 0;
            long long rz = 0;
            tourner(x, z, ak, rx, rz);
            cx = ax + rx;
            cy = ay + y;
            cz = az + rz;
            ck = (ak + k) % 4;
        }

        std::cout << "PANNEAU " << i << " " << (stage ? "STAGE" : "LOCAL") << "\n";

        const long long coinX[4] = {-w / 2, w / 2, w / 2, -w / 2};
        const long long coinY[4] = {-h / 2, -h / 2, h / 2, h / 2};
        for (int j = 0; j < 4; ++j) {
            long long rx = 0;
            long long rz = 0;
            tourner(coinX[j], 0, ck, rx, rz);
            std::cout << cx + rx << " " << cy + coinY[j] << " " << cz + rz << "\n";
        }

        const long long dx = cx - ex;
        const long long dy = cy - ey;
        const long long dz = cz - ez;
        const double dist = std::sqrt(static_cast<double>(dx * dx + dy * dy + dz * dz));
        std::cout << "DISTANCE " << std::llround(dist) << "\n";
    }

    std::cout << "PANNEAUX " << n << "\n";
    return 0;
}

// resultat
//PANNEAU 1 STAGE
//-150 1500 -1500
//150 1500 -1500
//150 1700 -1500
//-150 1700 -1500
//DISTANCE 1503
//PANNEAU 2 LOCAL
//-150 3200 -1500
//150 3200 -1500
//150 3400 -1500
//-150 3400 -1500
//DISTANCE 2193
//PANNEAUX 2
