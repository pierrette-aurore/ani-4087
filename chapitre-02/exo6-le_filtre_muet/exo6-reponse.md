# Exercice 6 - Le filtre muet

## Consigne
Ecrivez un filtre dont la condition est fausse sur votre machine, avec une definition a l'interieur, et prouvez qu'elle n'est pas appliquee. Puis rendez la condition vraie et prouvez qu'elle l'est. Ne comptez pas sur `jenga info` : sa sortie est identique que la condition soit vraie ou fausse.

## Le filtre choisi
Ma machine hote est Windows, j'ai donc pose un filtre `system:Linux` qui pose le define `PLATEFORME_LINUX` (fichier [chantier.jenga](chantier.jenga)). Sur Windows, ce filtre doit rester silencieux. Le programme [main.cpp](main.cpp) affiche lui-meme s'il a recu le define ou non.

## Preuve que `jenga info` ne dit rien
```text
jenga info
```
donne exactement la meme sortie que le filtre `system:Linux` soit present ou absent dans le fichier : aucune mention des defines actifs, aucune trace du filtre. C'est bien le premier constat demande par l'enonce : `jenga info` est aveugle a ce genre de condition.

## Etape 1 - condition fausse (build natif Windows)
```text
jenga build --config Debug
```
```text
Filtre inactif : le define PLATEFORME_LINUX est absent.
```
Le filtre `system:Linux` ne s'est pas declenche : conforme a l'attente, puisque je construis pour Windows.

## Etape 2 - condition rendue vraie (build croise pour Linux)
```text
jenga build --config Debug --platform linux-x86_64
```
```text
Filtre actif : compile pour Linux.
```
En demandant explicitement la plateforme Linux, le filtre `system:Linux` s'active cette fois et le define `PLATEFORME_LINUX` est bien pose : le programme l'affiche lui-meme, ce que `jenga info` n'aurait jamais montre.

## Conclusion
`jenga info` reste identique quelle que soit l'activation reelle d'un filtre : seul le programme, en affichant sa propre configuration au moment de l'execution, permet de verifier concretement qu'un define conditionnel a bien ete pose ou non.
