# Introduction

## Généralités

#### Système d'exploitation
- Pilote
- Exécute demandes
- Sécurise

#### Approche modulaire
- Diviser complexité
- Partager travail

## Programmation multitâche
*Problèmatique*: Allocation des tâches aux différentes ressources au cours du temps

#### Ordonnancement
Organisation de l'exécution des tâches sur les ressources du système

#### Politique d'Ordonnancement
Règle d'organisation de l'exécution des tâches

### Monoprogramming
Tout faire en une tâche (programmation séquentielle et en boucle)
#### Avantages
- Simple
- Déterministe
#### Désavantages 
- Non évolutive
- Mauvaise utilisation des ressources

### Multiprogramming
Faire fonctionner plusieurs programmes en parallèle
#### Nécessite
- Processeur(s) virtuel(s)
- Mémoire virtuelle
- Ressources virtuelles

#### Exemple du processus UNIX
1 processus = 1 processeur virtuel

**L'OS est en charge de la multiprogrammation**
- Il isole les programmes (surêté et sécurité)
- Il partage les ressources (spatio-temporelle)
- Permet la **Synchronisation** et la **Communication** entre les processus qui assure:
    - Cohérence
    - Déterminisme

### Intéractions avec le monde extérieur
#### Polling (cyclique)
- 👍 Simple 
- 👎 Ingérable avec gd nombre de périphériques
- 👎 Données non-dispo = perte de temps
#### Interruptions
Évènement provoquant un changement de l'exécution normale, traitement mis en pause le temps de traiter une autre tâche prioritaire
- 👍 Simple 
- 👎 Cohérence des données
- 👎 Pertinence

## Gestion du parallèlisme 
### Pourquoi synchroniser ?
- Résoudre pb de cohérence
- Spécifier dépendances entre traitements
- Régler problèmes de concurrence
### Modes de communication
- FIFO
- Buffer circulaire
- Mémoire partagée
### Section critique
Portion de code où tâche utilise des ressources utilisable par d'autres tâches en même temps
#### Sériabilité
A // B, indépendant de l'ordonnancement
#### Atomicité
- A non // avec B
- A non préemptable pour B
- A dure un temps nul pour B

### Sémaphore
Objet sur lequel une opération atomique est possible:
- P(sem): décrémentation, permet d'acquérir une ressource
- V(sem): incrémentation, permet de libérer une ressource

#### Sémaphore privé
Un processus doit être activé par un autre sur un évènement

#### Exemple de sémaphore 
![exemple-imprimante](https://user-images.githubusercontent.com/19282069/140651622-3215740d-3f76-4012-a9a7-e89119a76b36.png)