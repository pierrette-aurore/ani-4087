# Exercice 2 - Lire avant de construire

## Consigne
Lancez `jenga info` sur votre projet et lisez sa sortie en entier. Rendez-la, et dites ce qu'elle vous apprend que le fichier de projet ne disait pas explicitement.

## Commande lancee
```text
jenga info
```

## Sortie retranscrite
```text
Workspace        : chantier
Fichier source   : chantier.jenga
Configurations   : Debug, Release
Platform (hote)  : Windows
Target OSes      : Windows, Linux, Android
Architectures    : x86_64, arm64

Toolchains detectees :
  - msvc        (msvc, Windows, x86_64)
  - clang-cl    (clang, Windows, x86_64)
  - mingw       (gcc, Windows, x86_64)

Projets :
  - CabineTest  [ConsoleApp]  (pas de suite de tests, pas de projet externe)

Daemon Jenga : arrete
```

## Ce que ca m'apprend
Le fichier `chantier.jenga` ne dit explicitement que le nom du workspace, les configurations, les OS et architectures vises et le contenu du projet `CabineTest`. `jenga info` ajoute des choses qui ne sont ecrites nulle part dans mon fichier :

* la liste des **toolchains reellement presentes** sur ma machine (`msvc`, `clang-cl`, `mingw`) : je n'en ai choisi aucune explicitement, Jenga les a detectees ;
* la **plateforme hote** (Windows), qui depend de la machine et non du fichier de projet ;
* le fait que `CabineTest` est bien classe comme `ConsoleApp` et qu'il n'est ni une suite de tests ni un projet externe ;
* l'etat du **daemon Jenga**, une information purement liee a l'environnement d'execution.

Autrement dit, `jenga info` ne reformule pas le fichier de projet : il le complete avec ce que Jenga observe de l'environnement dans lequel il tourne.
