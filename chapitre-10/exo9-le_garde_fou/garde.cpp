
#include <iostream>
#include <string>

// Fausse session : drapeau "trame ouverte" et compteurs
class Session {
public:
    bool ouverte = false;
    int debuts = 0;
    int fins = 0;
    int refus = 0;

    bool Wait() {
        if (ouverte) { ++refus; return false; }
        return true;
    }
    bool Begin() {
        if (ouverte) { ++refus; return false; }
        ouverte = true;
        ++debuts;
        return true;
    }
    bool End() {
        if (!ouverte) { ++refus; return false; }
        ouverte = false;
        ++fins;
        return true;
    }
};

// Garde : termine la trame dans son destructeur, ne se copie pas
class GardeTrame {
public:
    explicit GardeTrame(Session& s) : session_(s) {}
    ~GardeTrame() { session_.End(); }
    GardeTrame(const GardeTrame&) = delete;
    GardeTrame& operator=(const GardeTrame&) = delete;

private:
    Session& session_;
};

// Sans état de Wait, N et C deviennent V
static char effectif(char c, bool attenteOk) {
    if (!attenteOk && (c == 'N' || c == 'C')) return 'V';
    return c;
}

static void boucleSans(Session& s, const std::string& mot, int& images) {
    for (char c : mot) {
        const bool w = s.Wait();
        s.Begin();
        const char e = effectif(c, w);
        if (e == 'C') continue;   // saute End
        if (e == 'R') return;     // saute End
        if (e == 'N') ++images;
        s.End();                  // End écrit en bas du corps
    }
}

static void boucleAvec(Session& s, const std::string& mot, int& images) {
    for (char c : mot) {
        const bool w = s.Wait();
        s.Begin();
        GardeTrame garde(s);      // End appelé par le destructeur
        const char e = effectif(c, w);
        if (e == 'C') continue;
        if (e == 'R') return;
        if (e == 'N') ++images;
    }
}

static void afficher(const char* nom, const Session& s, int images) {
    std::cout << nom << " DEBUTS " << s.debuts << " FINS " << s.fins
              << " REFUS " << s.refus << " IMAGES " << images
              << " OUVERTE " << (s.ouverte ? "OUI" : "NON") << "\n";
}

int main() {
    int total = 0;
    std::cin >> total;
    std::string mot;
    if (total > 0) std::cin >> mot;

    Session sans;
    int imagesSans = 0;
    boucleSans(sans, mot, imagesSans);
    afficher("SANS", sans, imagesSans);

    Session avec;
    int imagesAvec = 0;
    boucleAvec(avec, mot, imagesAvec);
    afficher("AVEC", avec, imagesAvec);
    return 0;
}
