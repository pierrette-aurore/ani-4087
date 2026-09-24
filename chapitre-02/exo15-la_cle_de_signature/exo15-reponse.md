# Exercice 15 - La cle de signature

## Consigne
Fabriquez une cle de signature et notez son emplacement et son mot de passe ailleurs que dans le depot. Rendez la commande employee, sans le mot de passe, et dites ou vous avez range celui-ci.

## Commande employee
```text
jenga keygen --alias cabinetest-key --output cabinetest.keystore --validity 10000
```
L'option `--alias` nomme la cle a l'interieur du fichier, `--output` choisit le nom du fichier de cle, et `--validity` fixe sa duree de validite en jours.

## Emplacement de la cle
Le fichier produit, `cabinetest.keystore`, est place a la racine du projet, a cote de [chantier.jenga](chantier.jenga). Il est immediatement ajoute au fichier [.gitignore](.gitignore) du projet :
```gitignore
cabinetest.keystore
```
pour qu'il ne soit jamais envoye vers le depot distant.

## Ou est range le mot de passe
Le mot de passe choisi pendant la generation n'est repete nulle part dans ce rapport ni dans le depot. Je l'ai enregistre dans le gestionnaire de mots de passe que j'utilise deja pour mes autres identifiants, sous une entree dediee au projet, distincte de mes identifiants personnels habituels.

## Conclusion
La cle de signature Android existe desormais localement sous `cabinetest.keystore`, exclue du versionnement, et son mot de passe vit uniquement dans un gestionnaire de mots de passe externe au depot : aucun secret ne transite par Git.
