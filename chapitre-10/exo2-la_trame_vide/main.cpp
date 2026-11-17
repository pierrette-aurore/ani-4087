#include <iostream>
#include <string>
 
 int main() {
     int n, total;
     std::cin >> n >> total;
 
     if (n < 1 || n > 4) {
         std::cout << "CHAINE REFUSEE\n"; 
       return 0;
     }
 
     std::string mot;
     if (total > 0) std::cin >> mot;
     const int taille = static_cast<int>(mot.size());
 
     int index = 0;
     int fins = 0;
     int rendues = 0;
     int sautees = 0;
 
         const bool rendre = (t - 1 < taille) && (mot[t - 1] == '1');
 
        if (rendre) {
             const int lacet = t - 1;
             std::cout << t << " OUI 1 " << lacet << " " << index << "\n";
             index = (index + 1) % n;
             ++rendues;
         } else {
             std::cout << t << " NON 0\n";
             ++sautees;
         ++fins;
     }
 
     std::cout << "FINS " << fins << "\n";
     std::cout << "RENDUES " << rendues << "\n";
     std::cout << "SAUTEES " << sautees << "\n";
     std::cout << "PROCHAINE " << index << "\n";
     return 0;

 }

//resultat
//1 OUI 1 0 0
//2 OUI 1 1 1
//3 NON 0
//4 NON 0
//5 OUI 1 4 2
//6 OUI 1 5 0
//FINS 6
//RENDUES 4
//SAUTEES 2
//PROCHAINE 1
