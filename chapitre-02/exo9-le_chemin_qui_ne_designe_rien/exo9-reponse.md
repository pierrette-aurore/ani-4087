# Exercice 9 - Le chemin fantome

## Consigne
Ajoutez a `files` un motif qui ne correspond a aucun fichier, et a `includedirs` un dossier qui n'existe pas. Rendez ce que `jenga info` en dit, et ce que `jenga build` en dit. Comparez les deux : lequel vous aurait fait gagner du temps ?

## Modification
Dans [chantier.jenga](chantier.jenga), j'ai ajoute :
* `src/Outillage.cpp` dans `files`, un fichier que je n'ai jamais cree ;
* `vendor/introuvable` dans `includedirs`, un dossier qui n'existe pas dans mon arborescence.

## `jenga info`
```text
jenga info
```
```text
Projets :
  - CabineTest  [ConsoleApp]
    Files       : src/main.cpp, src/Outillage.cpp
    IncludeDirs : include, vendor/introuvable
```
`jenga info` **recopie tel quel** ce qui est ecrit dans le fichier de projet, sans verifier que les chemins existent reellement. Le fichier fantome et le dossier fantome apparaissent normalement dans le resume, sans aucun avertissement.

## `jenga build`
```text
jenga build --config Debug
```
```text
[jenga] avertissement : aucun fichier ne correspond a "src/Outillage.cpp"
[jenga] avertissement : le dossier d'inclusion "vendor/introuvable" n'existe pas, ignore
[jenga] compilation : src/main.cpp
[jenga] edition de liens : CabineTest.exe
[jenga] construction terminee (avec avertissements) en 0,83 s
```
Cette fois, Jenga signale les deux problemes explicitement, sous forme d'avertissements, avant de continuer avec ce qu'il a reussi a resoudre.

## Comparaison
`jenga info` ne verifie rien : il se contente d'afficher la configuration declaree, exacte ou non. C'est **`jenga build`** qui aurait fait gagner du temps ici, puisque c'est lui qui confronte le fichier de projet a l'etat reel du disque et signale immediatement les chemins invalides, plutot que de laisser l'erreur se decouvrir plus tard au hasard d'une recherche de fichier manquant.

## Conclusion
Un chemin errone dans `files` ou `includedirs` ne se voit pas dans un simple resume de configuration ; seule une tentative de construction reelle le revele.
