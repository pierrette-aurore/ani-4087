#include <iostream>
#include <string>

using namespace std;

static bool lireLigne(string &s) {
    if (!getline(cin, s)) {
        s.clear();
        return false;
    }
    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }
    return true;
}

int main() {
    string ligne;
    lireLigne(ligne);
    int k = stoi(ligne);

    for (int i = 1; i <= k; ++i) {
        string reg;
        lireLigne(reg);
        lireLigne(ligne);
        int l = stoi(ligne);

        string texte;
        for (int j = 0; j < l; ++j) {
            lireLigne(ligne);
            texte += ligne;
            texte += '\n';
        }

        const string pre = to_string(i) + " ";

        if (reg == "-") {
            cout << pre << "REGISTRE AUCUN\n";
            continue;
        }

        cout << pre << "MANIFESTE " << reg << "\n";

        if (l == -1) {
            cout << pre << "ECHEC ILLISIBLE\n";
            continue;
        }

        const string cle = "\"library_path\"";
        size_t pos = texte.find(cle);
        if (pos == string::npos) {
            cout << pre << "ECHEC CLE\n";
            continue;
        }

        size_t deuxPoints = texte.find(':', pos + cle.size());
        if (deuxPoints == string::npos) {
            cout << pre << "ECHEC DEUX_POINTS\n";
            continue;
        }

        size_t q1 = texte.find('"', deuxPoints);
        size_t q2 = (q1 == string::npos) ? string::npos : texte.find('"', q1 + 1);
        if (q1 == string::npos || q2 == string::npos) {
            cout << pre << "ECHEC GUILLEMET\n";
            continue;
        }

        string v;
        for (size_t p = q1 + 1; p < q2; ++p) {
            if (texte[p] == '\\' && p + 1 < q2 && texte[p + 1] == '\\') {
                continue;
            }
            v += texte[p];
        }

        if (v.empty()) {
            cout << pre << "ECHEC VIDE\n";
            continue;
        }

        cout << pre << "VALEUR " << v << "\n";

        bool absolu = (v.size() >= 2 && v[1] == ':') || v[0] == '\\' || v[0] == '/';
        if (absolu) {
            cout << pre << "ABSOLU\n";
            cout << pre << "CHARGE " << v << "\n";
        } else {
            cout << pre << "RELATIF\n";
            size_t sep = reg.find_last_of("\\/");
            string dossier = (sep == string::npos) ? "" : reg.substr(0, sep + 1);
            cout << pre << "CHARGE " << dossier << v << "\n";
        }
    }

    return 0;
}
