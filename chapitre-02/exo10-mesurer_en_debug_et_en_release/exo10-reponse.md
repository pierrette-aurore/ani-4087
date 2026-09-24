# Exercice 10 - Le budget de onze millisecondes

## Consigne
Ecrivez une boucle qui fait un calcul lourd et le chronometre. Construisez en Debug puis en Release et mesurez. Rendez le rapport. Puis dites, sachant qu'une image de casque dure onze millisecondes, laquelle des deux mesures vous aurait fait prendre une mauvaise decision.

## Le calcul mesure
Le fichier [main.cpp](main.cpp) fait, pour chaque image simulee, 400 000 iterations combinant `sin`, `tan` et `sqrt`, et chronometre chaque image avec `std::chrono::steady_clock`, sur 30 images.

## Protocole
```text
jenga clean
jenga build --config Debug
jenga run --config Debug
jenga clean
jenga build --config Release
jenga run --config Release
```

## Mesures (trois passages par configuration)

| Configuration | Essai 1 | Essai 2 | Essai 3 | Moyenne |
|---|---|---|---|---|
| Debug   | 12,71 ms | 12,08 ms | 12,45 ms | **12,41 ms** |
| Release | 9,62 ms  | 9,94 ms  | 9,71 ms  | **9,76 ms** |

Ecart relatif entre les deux moyennes : environ **27 %**.

## Comparaison au budget de 11 ms
* Debug   : 12,41 ms -> **au-dessus** du budget de 11 ms.
* Release : 9,76 ms -> **en dessous** du budget de 11 ms.

## Quelle mesure aurait fait prendre une mauvaise decision
Ici, contrairement a un cas ou les deux configurations donneraient un resultat du meme cote du budget, les deux mesures **se contredisent** : en Debug, le calcul depasse le budget d'une image de casque et semblerait interdire la fonctionnalite ; en Release, il passe confortablement en dessous.

Comme le programme final est toujours livre et execute en Release, c'est **la mesure Debug** qui aurait ete trompeuse si je l'avais prise pour une decision definitive : elle aurait pu faire abandonner ou reecrire un calcul qui, en pratique, tient largement dans le budget de la boucle de rendu.

## Conclusion
Ce test confirme qu'une mesure de performance prise en configuration Debug n'a pas de valeur predictive pour le budget de temps reel : seule la mesure Release, ici a 9,76 ms contre un budget de 11 ms, refletait la situation reelle du programme livre.
