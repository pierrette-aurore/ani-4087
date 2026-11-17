
#include <iostream>
#include <string>

int main() {
    int k, n;
    std::cin >> k >> n;

    bool ouverte = false;
    int idx[2] = {0, 0};
    bool emp[2] = {false, false};
    int journal = 0;
    int avert = 0;
    int silencieux = 0;

    for (int i = 1; i <= n; ++i) {
        std::string cmd;
        std::cin >> cmd;
        std::cout << i << " " << cmd << " ";

        if (cmd == "wait" || cmd == "begin") {
            if (ouverte) {
                std::cout << "REFUSE\n";
                ++journal;
            } else {
                std::cout << "OK\n";
                if (cmd == "begin") ouverte = true;
            }
        } else if (cmd == "acquire") {
            std::string o;
            std::cin >> o;
            const int e = (o == "G") ? 0 : 1;
            if (emp[e]) {
                std::cout << "REFUSE\n";
                ++silencieux;
            } else {
                std::cout << "OK " << idx[e] << "\n";
                emp[e] = true;
            }
        } else if (cmd == "release") {
            std::string o;
            std::cin >> o;
            const int e = (o == "G") ? 0 : 1;
            if (!emp[e]) {
                std::cout << "REFUSE\n";
                ++silencieux;
            } else {
                std::cout << "OK\n";
                emp[e] = false;
                idx[e] = (idx[e] + 1) % k;
            }
        } else {
            std::string a;
            std::cin >> a;
            const bool proj = (a != "-");
            int g = 0;
            int d = 0;
            if (proj) {
                std::string b;
                std::cin >> b;
                g = std::stoi(a);
                d = std::stoi(b);
            }

            if (!ouverte) {
                std::cout << "REFUSE AUCUNE\n";
                ++journal;
            } else {
                ouverte = false;  // la trame se ferme dans tous les cas
                if (proj && g && emp[0]) {
                    std::cout << "REFUSE ACQUISE G\n";
                    ++journal;
                } else if (proj && d && emp[1]) {
                    std::cout << "REFUSE ACQUISE D\n";
                    ++journal;
                } else {
                    std::cout << "OK";
                    if (proj) {
                        if (!g) {
                            std::cout << " AVERT G";
                            ++avert;
                        }
                        if (!d) {
                            std::cout << (g ? " AVERT D" : " D");
                            ++avert;
                        }
                    }
                    std::cout << "\n";
                }
            }
        }
    }

    std::cout << "JOURNAL " << journal << "\n";
    std::cout << "AVERTISSEMENTS " << avert << "\n";
    std::cout << "SILENCIEUX " << silencieux << "\n";
    return 0;
}
// resultats
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
