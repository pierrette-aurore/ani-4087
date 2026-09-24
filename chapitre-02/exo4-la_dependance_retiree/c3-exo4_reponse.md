# Exercice 4 - Le module manquant

## Consigne
Ajoutez a votre projet un module qui depend lui-meme d'un autre, puis retirez ce second de votre liste. Rendez le message d'erreur exact, en entier, et dites a laquelle des quatre etapes de la chaine de construction il appartient : preprocesseur, compilation, assemblage, ou edition de liens.

## Mise en place
J'ai cree une classe `Accueil` declaree dans [include/Accueil.hpp](include/Accueil.hpp) et implementee dans un fichier `src/Accueil.cpp` (methode `saluer()` qui affiche un message). Le fichier [src/main.cpp](src/main.cpp) appelle `accueil.saluer()`.

J'ai ensuite retire `src/Accueil.cpp` du motif `files([...])` du fichier [chantier.jenga](chantier.jenga), sans toucher au `.hpp` ni a `main.cpp`.

## Commande et sortie
```text
jenga build --config Debug
```

```text
[jenga] compilation : src/main.cpp
[jenga] edition de liens : CabineTest.exe
LNK2019: symbole externe non resolu "public: void __thiscall Accueil::saluer(void)"
    (?saluer@Accueil@@QAEXXZ) referencee dans la fonction main
LNK1120: 1 symboles externes non resolus
[jenga] echec de la construction (CabineTest)
```

## Etape concernee
Le fichier `.hpp` etant toujours present, le preprocesseur et le compilateur ne voient aucune anomalie : `main.cpp` sait que `Accueil::saluer()` existe (declaration visible), il compile donc sans probleme et produit un fichier objet valide. C'est **l'edition de liens** qui echoue, car elle cherche le code compile de `saluer()` dans les objets fournis et ne le trouve nulle part : le symbole est declare mais jamais defini.

## Conclusion
Retirer un `.cpp` de la liste `files` casse la construction au dernier maillon de la chaine : l'edition de liens. C'est une erreur typique et son message (`symbole externe non resolu` / `unresolved external symbol`) est reconnaissable, contrairement a une erreur de preprocesseur ou de compilation qui pointerait vers une ligne precise du code source.
