# Exercice 5 - Le define absent

## Consigne
Ecrivez un petit en-tete a vous qui declare une classe complete si un define est pose, et une coquille vide sinon. Compilez un programme qui l'emploie, avec puis sans le define. Rendez les deux messages et dites lequel des deux vous auriez su diagnostiquer sans cet exercice.

## Mise en place
La classe choisie est `Chrono` (fichier [include/Chrono.hpp](include/Chrono.hpp)) : complete si `AVEC_CHRONO` est defini (methodes `demarrer()` et `afficherDuree()`), reduite a une coquille vide sinon. Le fichier [src/main.cpp](src/main.cpp) appelle les deux methodes.

### Avec le define (`defines(["AVEC_CHRONO"])` present dans [chantier.jenga](chantier.jenga))
```text
[jenga] compilation : src/main.cpp
[jenga] edition de liens : CabineTest.exe
[jenga] construction terminee en 0,76 s
```
Aucune erreur : le programme s'execute et affiche les deux messages de `Chrono`.

### Sans le define (ligne `defines([...])` commentee)
```text
error C2039: 'demarrer' : n'est pas membre de 'Chrono'
error C2039: 'afficherDuree' : n'est pas membre de 'Chrono'
[jenga] echec de la construction (CabineTest)
```

## Lequel j'aurais su diagnostiquer sans l'exercice
Le message obtenu **sans** le define (`n'est pas membre de 'Chrono'`) est direct et assez explicite : il pointe vers les deux methodes precises et le nom de la classe, meme sans connaitre le mecanisme des `#ifdef`. J'aurais probablement fini par comprendre qu'il manque quelque chose a la classe.

Le cas **avec** le define, lui, ne produit pas de message d'erreur du tout puisque tout compile : c'est justement le piege. Sans avoir fait cet exercice, j'aurais pu croire que la coquille vide et la classe complete etaient interchangeables, et ne jamais remarquer qu'un define silencieux change completement le contenu d'une classe declaree dans un simple `.hpp`.
