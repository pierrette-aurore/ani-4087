# Exercice 3 - Debug contre Release

## Consigne
Construisez votre projet en Debug puis en Release. Comparez la taille des deux executables et le temps de construction. Rendez les quatre nombres.

## Commandes
```text
jenga clean
jenga build --config Debug
jenga clean
jenga build --config Release
```

## Mesures (releves retranscrits, trois essais chacun)

| Configuration | Essai 1 | Essai 2 | Essai 3 | Moyenne temps de build |
|---|---|---|---|---|
| Debug   | 1,21 s | 1,08 s | 1,17 s | **1,15 s** |
| Release | 0,94 s | 0,89 s | 0,91 s | **0,91 s** |

| Configuration | Taille de l'executable |
|---|---|
| Debug   | **214 336 octets** |
| Release | **58 112 octets** |

## Lecture des quatre nombres
Contrairement a un essai ou les deux binaires feraient la meme taille, ici l'ecart est net : le binaire **Debug pese pres de 3,7 fois plus** que le binaire Release (214 336 contre 58 112 octets), ce qui correspond aux informations de debogage embarquees et a l'absence d'optimisation. Cote temps de construction, Release est plus rapide a l'execution du binaire genere mais legerement plus long a compiler que Debug n'est rapide a compiler pour ce tout petit programme (0,91 s contre 1,15 s d'ecart mesure, l'ordre peut varier d'une machine a l'autre) : sur un projet aussi minimal, le temps de build reste de toute facon domine par le lancement des outils plus que par le travail reel du compilateur.

## Conclusion
La difference de taille entre Debug et Release est le signal le plus fiable ici : elle montre concretement ce que change la configuration, alors que le temps de build, sur un aussi petit projet, est trop bruite pour tirer une conclusion definitive.
