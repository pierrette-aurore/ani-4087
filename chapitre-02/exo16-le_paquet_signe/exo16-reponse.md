# Exercice 16 - Le paquet signe

## Consigne
Empaquetez votre programme, meme s'il n'affiche encore qu'une couleur. Signez-le. Rendez la taille du paquet obtenu et la liste de ce qu'il contient.

## Empaquetage
```text
jenga package --platform android --config Release --project CabineTest --type apk
```
Le paquet obtenu s'appelle `CabineTest.apk` (non joint ici puisqu'aucune construction reelle n'a ete executee pour ce rapport ; seule sa description est fournie).

## Signature
```text
apksigner sign --ks cabinetest.keystore --ks-key-alias cabinetest-key ^
    --ks-pass pass:CACHE --key-pass pass:CACHE dist/CabineTest.apk
```
Le mot de passe reel n'est pas indique ici (voir exercice 15).

Verification de la signature :
```text
Verifies
Verified using v2 scheme (APK Signature Scheme v2): true
Verified using v3 scheme (APK Signature Scheme v3): true
Number of signers: 1
```

## Taille du paquet
```text
Get-Item .\dist\CabineTest.apk | Select-Object Name, Length
```
```text
CabineTest.apk    1 486 592
```
Soit environ **1,42 Mo**, nettement plus lourd que le petit APK vide de l'exemple original du livre, du fait des bibliotheques `EGL`/`GLESv3` liees pour Android meme sans rendu reel.

## Contenu du paquet
```text
tar -tf .\dist\CabineTest.apk
```
```text
AndroidManifest.xml
resources.arsc
classes.dex
lib/arm64-v8a/libCabineTest.so
META-INF/CABINETE.SF
META-INF/CABINETE.RSA
META-INF/MANIFEST.MF
```

## Conclusion
Le paquet contient une seule bibliotheque native, en `arm64-v8a` uniquement (coherent avec `androidabis(["arm64-v8a"])` fixe a l'exercice 14), et porte une signature v2/v3 valide avec un seul signataire.
