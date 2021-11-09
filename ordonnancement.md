# Ordonnancement

![exemple-intro](https://user-images.githubusercontent.com/19282069/141006053-3b97eb52-0cc0-40c9-a17c-c991795700d8.png)

## L'ordonnancement
L'organisation de l'exécution des tâches sur le CPU

## Politique d'ordonnancement
Règle d'organisation de l'exécution des tâches sur le CPU

## Durée d'exécution (notée C)

Temps nécessaire pour un processeur d'effectuer tâche (dépend vitesse processeur, mais non-constant)

### XCET
- **Worst Case Execution Time (WCET)** : correspond généralement au temps d'exécution
- **Best Case Execution Time (BCET)**

### Attributs temporels d'un job
- **Td**: Date de début au plus tôt
- **Tf (échéance)**: Date de fin au plus tard
- **Ci**: Durée de l'exécution

## Cas non-préemptif
Marge statique: `Ms = (Tf - Td) - Ci`     
*où* Ms >= 0

![marge-statique](https://user-images.githubusercontent.com/19282069/141007221-d89ef055-ddb9-4028-a37d-0c3db7521518.png)

## Cas préemptif
Marge dynamique: `Md = (Tf - Tc) - Ri` avec
- *Tc*: temps courant
- *Ri*: durée restante du travail

![marge-dynamique](https://user-images.githubusercontent.com/19282069/141007556-5e988e46-f21f-492a-9f9f-8a1319901c0f.png)