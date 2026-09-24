# Exercice 1 - Le local minimal Bonjour

## Consigne
Ecrivez le fichier de projet de votre salle et faites-le construire. Le programme n'a rien a faire : une fonction main qui rend zero suffit. Rendez le fichier et la sortie de `jenga build`.

## Ce que j'ai monte
Plutot que d'appeler le workspace "salle", je l'ai appele **chantier**, et le projet a l'interieur **CabineTest** : c'est le nom que je garde pour tout le chapitre, une petite cabine de test qui ne fait rien d'autre que prouver que la chaine de construction fonctionne.

Le fichier de projet est [chantier.jenga](chantier.jenga), le programme est [main.cpp](main.cpp) : une fonction `main` reduite a un `return 0;`, sans meme inclure `<iostream>` puisqu'il n'y a rien a afficher.

## Commande lancee
```text
jenga build --config Debug
```

## Sortie obtenue (retranscrite, pas de capture d'ecran)
```text
[jenga] resolution du workspace "chantier"...
[jenga] toolchain selectionnee : msvc (auto-detection)
[jenga] generation des projets pour CabineTest (Debug|x86_64)...
[jenga] compilation : src/main.cpp
[jenga] edition de liens : CabineTest.exe
[jenga] construction terminee en 0,81 s
[jenga] binaire : Build/Bin/Debug-Windows/CabineTest/CabineTest.exe
```

## Constat
La construction reussit du premier coup : un fichier `.cpp` et un fichier de projet suffisent, `jenga` genere lui-meme l'arborescence `Build/Bin/...`. Le programme ne fait rien d'autre que renvoyer zero, ce qui est deja le critere de reussite demande par l'enonce.
