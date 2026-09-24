# Exercice 13 - L'etat des toolchains

## Consigne
Lancez `jenga info -v` et rendez le tableau `Available Toolchains` en entier. Dites ce qui est present sur votre machine et ce qui manque.

## Commande
```text
jenga info -v
```

## Tableau retranscrit

| Name       | Family | Target OS | Arch          | Env       |
|------------|--------|-----------|---------------|-----------|
| msvc       | msvc   | Windows   | x86_64, arm64 | msvc      |
| clang-cl   | clang  | Windows   | x86_64        | msvc      |
| mingw      | gcc    | Windows   | x86_64        | mingw     |

## Ce qui est present sur ma machine
Trois toolchains sont detectees, toutes pour Windows : `msvc` (compilateur MSVC natif, x86_64 et arm64), `clang-cl` (frontend Clang avec l'ABI MSVC) et `mingw` (GCC via l'environnement MinGW).

## Ce qui manque
`jenga info -v` ne liste que ce qu'il trouve, pas ce qu'il ne trouve pas. En comparant avec la documentation de Jenga, plusieurs toolchains utilisees plus loin dans le livre ne figurent pas dans mon tableau :
* `android-ndk`, necessaire pour les exercices Android (14, 16, 17) ;
* `emscripten`, pour cibler le Web ;
* `zig`, propose comme toolchain multiplateforme alternative ;
* `clang-native`, une chaine Clang complete independante de l'ABI MSVC.

Aucune de ces quatre-la n'est detectee sur ma machine actuellement : je devrai les installer separement (par exemple le NDK Android) avant de pouvoir m'en servir dans les exercices suivants.

## Conclusion
Ma machine offre deja trois facons de compiler du C++ natif pour Windows, mais rien pour l'instant pour cibler l'Android, le Web, ou passer par une toolchain alternative comme Zig : ce sont des installations a prevoir avant les exercices 14 et suivants.
