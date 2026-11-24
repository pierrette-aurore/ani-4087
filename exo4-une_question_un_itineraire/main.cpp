#include <iostream>
#include <string>

int main() {
    int k = 0;
    if (!(std::cin >> k)) {
        return 0;
    }

    // Consommer le reste de la ligne contenant K
    std::string ligne_vide;
    std::getline(std::cin, ligne_vide);

    for (int i = 1; i <= k; ++i) {
        std::string chemin_registre;
        std::getline(std::cin, chemin_registre);

        // Nettoyage éventuel d'un retour chariot Windows (\r)
        if (!chemin_registre.empty() && chemin_registre.back() == '\r') {
            chemin_registre.pop_back();
        }

        int l = 0;
        std::cin >> l;
        std::getline(std::cin, ligne_vide);

        // Lecture obligatoire des L lignes du manifeste pour ne pas décaler le flux
        std::string texte_manifeste;
        for (int j = 0; j < l; ++j) {
            std::string ligne;
            std::getline(std::cin, ligne);
            if (!ligne.empty() && ligne.back() == '\r') {
                ligne.pop_back();
            }
            texte_manifeste += ligne + '\n';
        }

        // Cas 1 : Aucun runtime actif
        if (chemin_registre == "-") {
            std::cout << i << " REGISTRE AUCUN\n";
            continue;
        }

        std::cout << i << " MANIFESTE " << chemin_registre << '\n';

        // Règle 1 : Manifeste illisible
        if (l == -1) {
            std::cout << i << " ECHEC ILLISIBLE\n";
            continue;
        }

        // Règle 2 : Recherche de "library_path" (14 caractères)
        const std::string cle = "\"library_path\"";
        std::size_t pos_cle = texte_manifeste.find(cle);
        if (pos_cle == std::string::npos) {
            std::cout << i << " ECHEC CLE\n";
            continue;
        }

        // Règle 3 : Recherche du premier ':' après les 14 signes
        std::size_t pos_deux_points = texte_manifeste.find(':', pos_cle + cle.size());
        if (pos_deux_points == std::string::npos) {
            std::cout << i << " ECHEC DEUX_POINTS\n";
            continue;
        }

        // Règle 4 : Recherche des deux guillemets
        std::size_t pos_g1 = texte_manifeste.find('"', pos_deux_points + 1);
        if (pos_g1 == std::string::npos) {
            std::cout << i << " ECHEC GUILLEMET\n";
            continue;
        }

        std::size_t pos_g2 = texte_manifeste.find('"', pos_g1 + 1);
        if (pos_g2 == std::string::npos) {
            std::cout << i << " ECHEC GUILLEMET\n";
            continue;
        }

        // Règle 5 : Extraction et nettoyage des doubles antislashs
        std::string valeur;
        for (std::size_t idx = pos_g1 + 1; idx < pos_g2; ++idx) {
            if (texte_manifeste[idx] == '\\' && (idx + 1 < pos_g2) && texte_manifeste[idx + 1] == '\\') {
                valeur += '\\';
                ++idx; // Saute le second antislash
            } else {
                valeur += texte_manifeste[idx];
            }
        }

        // Règle 6 : Valeur vide
        if (valeur.empty()) {
            std::cout << i << " ECHEC VIDE\n";
            continue;
        }

        std::cout << i << " VALEUR " << valeur << '\n';

        // Règles 7 & 8 : Détermination chemin absolu ou relatif
        bool est_absolu = false;
        if (valeur.size() >= 2 && valeur[1] == ':') {
            est_absolu = true;
        } else if (valeur[0] == '\\' || valeur[0] == '/') {
            est_absolu = true;
        }

        if (est_absolu) {
            std::cout << i << " ABSOLU\n";
            std::cout << i << " CHARGE " << valeur << '\n';
        } else {
            std::cout << i << " RELATIF\n";
            std::size_t dernier_sep = chemin_registre.find_last_of("\\/");
            std::string dossier = chemin_registre.substr(0, dernier_sep + 1);
            std::cout << i << " CHARGE " << dossier << valeur << '\n';
        }
    }

    return 0;
}
