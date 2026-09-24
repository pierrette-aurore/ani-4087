# Exercice 8 - Un fichier, deux systemes

## Consigne
Ecrivez les filtres pour Windows et pour Linux dans votre projet, chacun avec ses bibliotheques. Faites verifier par un camarade sur l'autre systeme que le projet se construit chez lui sans modification. Si vous n'avez acces qu'a un systeme, ecrivez quand meme les deux et dites ce que vous n'avez pas pu verifier.

## Fichier de projet
Le fichier [chantier.jenga](chantier.jenga) declare deux filtres independants :
```python
with filter("system:Windows"):
    links(["kernel32", "user32", "winmm"])

with filter("system:Linux"):
    links(["pthread", "dl"])
```
Le programme [main.cpp](main.cpp) affiche lui-meme la plateforme detectee a l'execution, via `_WIN32` et `__linux__`.

## Ce que j'ai pu verifier
Sur ma machine (Windows), le build natif prend le filtre `system:Windows` :
```text
jenga build --config Debug
```
```text
Plateforme detectee au run : Windows
```

## Ce que je n'ai pas pu verifier
Je n'ai pas d'acces direct a une machine Linux, et je n'ai pas fait relire ce projet par un camarade sur Linux pour cet exercice. Je n'ai donc **pas verifie concretement** que le filtre `system:Linux` compile bien avec `pthread` et `dl` disponibles sur une vraie distribution : je me fie a la coherence du filtre (memes bibliotheques que celles habituellement necessaires pour le threading et le chargement dynamique sur Linux) plutot qu'a une construction reellement executee de ce cote.

## Conclusion
Le fichier de projet est ecrit pour les deux systemes sans qu'aucune modification ne soit necessaire pour passer de l'un a l'autre : c'est le principe demande par l'exercice. Seule la moitie Windows a ete reellement construite et verifiee ici ; la moitie Linux reste, pour l'instant, verifiee seulement sur le papier.
