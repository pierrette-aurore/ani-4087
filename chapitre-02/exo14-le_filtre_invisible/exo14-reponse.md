# Exercice 14 - Le filtre invisible

## Consigne
Ajoutez a votre fichier de projet le filtre pour Android, avec ses bibliotheques et ses definitions. Commencez par constater que `jenga info` ne vous apprendra rien ici. Puis dites, en une phrase, comment vous verifieriez qu'il s'active bien pour Android, du cote des commandes qui prennent un `--platform`.

## Ajout du filtre
Apres avoir installe le NDK, j'ai ajoute dans [chantier.jenga](chantier.jenga) :
```python
with filter("system:Android"):
    usetoolchain("ndk-clang")
    androidabis(["arm64-v8a"])
    androidminsdk(29)
    defines(["PLATEFORME_ANDROID"])
    links(["EGL", "GLESv3", "android", "log"])
```

## `jenga info` avant et apres
Sortie avec le filtre Android absent puis present : rigoureusement identique dans les deux cas, aucune mention d'Android, d'ABI ou de toolchain NDK n'apparait dans le resume, que le filtre soit ecrit ou non dans le fichier. Cela confirme, comme pour l'exercice 6, que `jenga info` ne reflete pas l'activation reelle d'un filtre conditionnel.

## Verification avec `--platform`
En une phrase : je verifierais que le filtre Android s'active bien en lancant `jenga build --platform android-arm64`, et en controlant que la sortie mentionne l'usage de la toolchain `ndk-clang` et produit un binaire dans un dossier `Build/Bin/Debug-Android/...` plutot qu'un echec ou un binaire Windows.

```text
jenga build --platform android-arm64
```
```text
[jenga] toolchain selectionnee : ndk-clang (NDK r27)
[jenga] compilation : main.cpp (arm64-v8a, minSdk 29)
[jenga] construction terminee en 2,04 s
[jenga] binaire : Build/Bin/Debug-Android/CabineTest/libCabineTest.so
```

## Conclusion
`jenga info` reste muet sur l'activation reelle du filtre Android ; seule une commande qui accepte `--platform`, comme `jenga build`, force reellement le filtre a s'evaluer et permet de constater, dans la toolchain choisie et l'emplacement du binaire produit, que la configuration Android a bel et bien ete appliquee.
