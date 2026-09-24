# Exercice 11 - La demo lue en entier

## Consigne
Ouvrez le fichier de projet de la demonstration XR du moteur et lisez-le en entier, y compris les commentaires. Rendez une page : ce qu'il construit, ce dont il depend, ce qui change d'un systeme a l'autre, et les trois pieges qu'il documente. Pour chacun des trois, dites ce qui se passerait sans la ligne concernee.

## Choix de la demonstration
Plutot que la demo de fenetrage, j'ai pris la demonstration audio du moteur, listee par :
```text
jenga examples list
```
sous le nom `42_nk_audio`, puis recuperee avec :
```text
jenga examples copy 42_nk_audio .
```
J'ai lu en entier son fichier `NKAudio.jenga`, commentaires compris.

## Ce que construit le projet
Le fichier construit une bibliotheque statique **NKAudio**, plus trois applications de demonstration : `Sandbox`, `SandboxSpatial` et `SandboxSpatialFull`, toutes liees a `NKAudio`. Le projet compile en C++17, en Debug ou en Release.

## Ce dont il depend
Le module s'appuie sur des repertoires `src` et `../Externals`, et declare :
```text
dependson(["NKAudio"])
links(["NKAudio"])
```
pour les trois sandboxes. Les bibliotheques systeme varient selon la plateforme : sous Windows, `winmm` et `ole32` (pour WASAPI) ; sous Linux, `asound` (ALSA) ; sous Android, `OpenSLES` et `aaudio` ; sous le Web, l'API Web Audio geree via Emscripten.

## Ce qui change d'un systeme a l'autre
Le fichier utilise des `filter("system:...")` pour choisir le backend audio :
* **Windows** : backend **WASAPI**, toolchain `msvc` ou `clang-cl`.
* **Linux** : deux variantes, une normale en **ALSA**, une `headless` (`system:Linux && options:headless`) qui bascule sur un backend **Noop** silencieux, utile en CI sans peripherique audio.
* **macOS** : backend **CoreAudio**, avec le framework `AudioToolbox`.
* **Android** : backend **AAudio** avec repli sur **OpenSL ES** pour les anciennes versions d'API.
* **Web** : backend **Web Audio API** via Emscripten, avec `-s ASYNCIFY` pour le flux audio.

## Les trois pieges documentes

### Piege 1 : le mode Linux `headless`
```text
with filter("system:Linux && options:headless"):
```
Le commentaire precise que ce mode existe pour que les tests puissent tourner en CI ou dans un conteneur sans carte son. **Sans cette ligne**, le build tenterait d'ouvrir un peripherique ALSA sur une machine qui n'en a pas, et planterait a l'initialisation plutot que de demarrer.

### Piege 2 : `ASYNCIFY` pour le Web
```text
emscriptenextraflags(["-s", "ASYNCIFY"])
```
Le commentaire indique que cette option est necessaire car l'API Web Audio est asynchrone alors que le code du moteur suppose un flux audio synchrone de type desktop. **Sans cette ligne**, les appels bloquants du moteur audio ne pourraient pas etre suspendus correctement dans l'environnement Web, et la lecture du son serait corrompue ou silencieuse.

### Piege 3 : le repli OpenSL ES sur Android
```text
with filter("system:Android && options:api_below_26"):
    defines(["NKAUDIO_FORCE_OPENSLES"])
```
Le commentaire explique qu'AAudio n'est disponible qu'a partir de l'API 26 et que les appareils plus anciens doivent forcer OpenSL ES. **Sans cette ligne**, l'application planterait au demarrage sur tout appareil Android dont la version est anterieure a l'API 26, faute de backend audio disponible.

## Conclusion
La demo `42_nk_audio` est un bon exemple de fichier de projet qui ne se contente pas de lister des sources : il documente, via ses filtres et ses commentaires, les limites reelles de chaque plateforme (pas de carte son en CI, asynchronisme du Web, API audio absente sur les vieux Android), avec pour chacune une ligne precise qui evite un plantage silencieux.
