# Exercice 17 - Le transfert sur appareil

## Consigne
Installez votre paquet sur un appareil et lancez-le. Rendez une photographie de l'ecran de l'appareil. Si l'installation echoue, rendez le message exact : il est plus instructif qu'une reussite.

## Detection de l'appareil
```text
adb devices
```
```text
List of devices attached
a1b2c3d4e5f6    device
```
L'appareil est bien detecte par ADB : une tablette Android conservee pour les tests, dont je sais qu'elle tourne une version relativement ancienne du systeme.

## Tentative d'installation
```text
adb install -r dist/CabineTest.apk
```
```text
Performing Streamed Install
adb: failed to install dist/CabineTest.apk: Failure [INSTALL_FAILED_OLDER_SDK: Failed to install dist/CabineTest.apk: INSTALL_FAILED_OLDER_SDK: Requires newer sdk version #29, but is #24]
```

## Resultat
Comme aucune installation reussie n'a ete obtenue, je rends le message d'echec exact plutot qu'une photographie d'ecran : c'est ce que demande explicitement l'enonce dans ce cas.

L'echec est du a une incompatibilite de version : le fichier [chantier.jenga](../exo14-le_filtre_android/chantier.jenga) de l'exercice 14 fixe `androidminsdk(29)`, alors que la tablette de test tourne l'API 24. L'APK refuse donc de s'installer, l'appareil etant trop ancien pour le niveau d'API minimal declare dans le projet.

## Ce que je ferais ensuite
Pour reellement lancer l'application sur cet appareil, il faudrait soit abaisser `androidminsdk` a une valeur compatible avec l'API 24 (si le code le permet), soit tester sur un appareil ou un emulateur plus recent que l'API 29 declaree dans le projet.

## Conclusion
Le message `INSTALL_FAILED_OLDER_SDK` est en soi une information utile : il confirme que la chaine de construction (jusqu'a la signature de l'exercice 16) a fonctionne, et que le seul obstacle restant est un choix de configuration (`androidminsdk`) a confronter au parc d'appareils reellement disponibles pour les tests.
