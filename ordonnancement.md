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

## Notion de tâche
- Crée des jobs
- 3 classes:
    - Périodique
    - Sporadique
    - Apériodique

## Période d'étude (cas périodique)
[0, PPCM(Pi)], avec Pi période de toutes les tâches

## Plan d'ordonnancement
Méthode de prévision pour l'allocation des ressources. 
- **Optimal** ssi les contraintes temporelles sont respectées.
- **Surcharge** sinon
### Exemple
![exemple-optimal](https://user-images.githubusercontent.com/19282069/141008410-9257dfd8-2a6e-414f-a440-c986aa0f3426.png)

# Algorithme d'ordonnancement
Classe de problème données d'ordonnancement

## Types
- Statique (hors ligne)
    - dates figées
    - modèle périodique
    - simplicité et régularité
- Dynamique (en ligne)
    - flexible
    - efficace
    - non oisif (tjrs utilisé)

## Modèles & Hypothèses
Un énoncé de problème demande un choix parmis toutes ces hypothèses:
- Sur les tâches
    - Séquentiel et parallèle
    - Mutuellement dépendantes / indépendantes
    - Valeurs identiques / différentes, constantes / dépendantes de l'instant de terminaison
    - Abandon si violation des contraintes
- Sur les ressources
    - Multiplicité
    - Mode d'accès
    - Réquisition
- Sur les lois évènementielles
    - Connues totalement ou partiellement 
    - Pré-déterminées ou statistiques
- Sur les lois d'activations des tâches
    - Instant d'activation
    - Instant d'accès aux ressources

## Algorithmes connus

### FP
- Priorité fixe
- Préemption possible

#### Avantages / Désavantages
- Proche Hardware
- Ponctualité
- Peu sûr et vivace

### RMS