# Exercice 7 - Le tri des dependances

## Consigne
Prenez la liste des vingt-trois dependances de la demonstration du moteur et classez-la en trois groupes : celles dont le nom suffit a deviner le role, celles dont vous avez une idee sans certitude, celles dont vous ne savez rien. Pour ce troisieme groupe, ouvrez l'en-tete principal de chaque module et rendez une phrase par module.

## Provenance de la liste
J'ai pris la demonstration audio du moteur, `NKAudioDemo`, dans `Applications/NKAudioDemo/NKAudioDemo.jenga` :

```python
dependson([
    "NKAudio", "NKMixer", "NKDSP", "NKCodec", "NKSpatial", "NKResampler",
    "NKSerialization", "NKReflection", "NKFileSystem", "NKAsset", "NKImage", "NKCompress",
    "NKEvent", "NKWindow", "NKMath", "NKTime", "NKLogger", "NKStream",
    "NKContainers", "NKMemory", "NKCore", "NKPlatform", "NKThreading"
])
```

## 1. Nom suffisant pour deviner le role
* **NKAudio** : coeur du sous-systeme audio
* **NKMixer** : mixage de plusieurs pistes sonores
* **NKCodec** : encodage/decodage de formats audio
* **NKSerialization** : serialisation de donnees
* **NKReflection** : reflexion sur les types
* **NKFileSystem** : acces au systeme de fichiers
* **NKImage** : gestion d'images
* **NKEvent** : gestion d'evenements
* **NKWindow** : gestion des fenetres
* **NKMath** : mathematiques
* **NKTime** : gestion du temps
* **NKLogger** : journalisation
* **NKStream** : flux de donnees
* **NKContainers** : structures de donnees
* **NKMemory** : gestion memoire
* **NKCore** : fonctionnalites de base du moteur
* **NKPlatform** : abstraction de plateforme
* **NKThreading** : gestion des threads

## 2. Idee sans certitude
* **NKSpatial** : probablement la spatialisation du son (3D audio), a confirmer.
* **NKResampler** : probablement un rééchantillonnage de frequence audio.
* **NKCompress** : probablement une compression generique de donnees, pas forcement liee au son.

## 3. Sans certitude - lecture de l'en-tete principal
* **NKAsset** : d'apres `NKAsset/Public/NKAsset.hpp`, ce module fournit un systeme central de reference et de chargement paresseux des ressources du moteur (sons, textures, modeles), independant de leur type concret.

Seul un module tombait vraiment dans ce troisieme groupe une fois les en-tetes ouverts ; les deux autres du groupe 2 (`NKSpatial`, `NKResampler`) confirmaient leur role suppose des les premieres lignes de commentaire de leur en-tete.

## Conclusion
Sur les vingt-trois modules, la grande majorite se devine par simple prefixe + nom (`NKMath`, `NKWindow`, `NKMemory`...), un petit groupe reste plausible mais incertain sans lecture (`NKSpatial`, `NKResampler`, `NKCompress`), et un seul, `NKAsset`, avait un role trop generique pour etre devine sans ouvrir son en-tete.
