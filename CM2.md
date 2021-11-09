# Ordonnancement 

Application est un ensemble de **n** tâches qu'on appelle système de tâches
-> Départ simultané (même 1er date de réveil) ou échélonné

## Terminologie
- **Ordonnancement** est l'orga de l'exécution des tâches sur le(s) CPU
- **Politique d'ordo** est la règle d'organisation de l'exécution des tâches sur les CPU

## Durée d'exec (notée C)
Temps nécessaire à un proc pour exec le code d'un travail sans interruption
- Durée exec dépend de vitesse du proc
- Durée exec est théorique (non constante)

## Attributs d'un job
- Date de début au plus tôt **Td**
- Date de fin au plus tard, échéance **Tf**
- Durée d'exec d'un travail 'i' **Ci**

### Paramètres dérivés
- Délai critique (fenêtre temporelle)
- Date de début au plus tard

## Cas non-préemptif
**Préemptif**: Basculer d'une tâche à l'autre = interrompre une tâche

## Cas préemptif
### Marge dynamique ou laxité
Md = (Tf - Tc) - Ri
- *Tc*: Instant courant
- *Ri*: Durée d'exec restante
- *Md* n'évolue pas pour le travail actif 
- *Md* évolute dynamiquement pour les travaux non actifs

## Notion de tâche
Une tâche est une entitée qui crée des travaux (job release)
### Trois classes majeures
- **Périodique**: Crée un travail toutes les périodes T (> 0)
- **Sporadiques**: Création de travaux séparés par un terval de temps minimal connu
- **Apériodique**: Modèle le + général, créeations de travaux doivent être connu

## Plan d'ordonnancement
Méthode de prévision pour alloc de ressource
### Optimal
Si toutes contraintes temporelles sont respectées
### Surcharge 
Lorsque volume des tâches à ordonnancer est tel que tous les ordonnancements conduisent au **non respect d'au moins une tâche**
### Algorithme optimal
Si pour une classe de pb donnée, il produit des ordonnancements optimaux

## hors ligne: avantages / inconvénients
Nécessite la connaissance à priori du système et     
// TODO

## En ligne: avantages / inconvénients
- Flexible
- Efficacité calculatoire requise
- Difficulté à prendre en compte des contraintes variées
- Oisif

## Modèles - hypothèses
### Sur les tâches
### Sur les lois évènementielles
### Sur les lois d'activations des tâches
### Un énoncé de pb = un choix parmi toutes ces hypothèses

## Algorithmes connus
### Algos de bases
À retenir pour le DE: RMS, EDF, LLF
### Statiques
- FP
- RMS
### Dynamiques
- FCFS
- RR (tourniquet)
- EDF (priorité échéance proche)
- LLF (priorité à la plus petite laxité)

## RMS
- Tâches (*n*)     
### Taux d'occupation (W)
= somme des:
- Durée d'exécution (*Ci*)   
**sur**
- Échéance de chaque travail (*Ti*)

Si W =< U(n), RMS est optimal (sauf à `U(n) = 1` où le ça peut être juste)
### Condition nécessaire
**W =< 1** (sinon surcharge) 
### Condition suffisante
**W =< U(n)**

- Entre 0 et U(n): **optimal**
- Entre U(n) et 1: **?**, tracer le plan d'ordo
- Après 1: **pas optimal**, on peut également tracer pour montrer première faute temporelle 

*U(n) sera donné dans l'exam*

# Exercices

## Exo 1
|   | C | P |
|---|---|---|
| A | 1 | 4 |
| B | 4 | 8 |

*W* = (1/4) + (4/8) = 3/4 **OK**    
&     
*U(n)* = 2 * (2^(1/2) - 1) = 0.83 **OK**     

**Optimal**

### Pour le plan d'ordonnancement 
- T1 a la périodité la plus petite, donc a la priorité (propriété RMS)

![IMG_5576](https://user-images.githubusercontent.com/19282069/139204146-8dd1846b-8eb7-446b-96d8-f47a4f4599c6.jpg)

## Exo 2
|   | C | P |
|---|---|---|
| A | 1 | 2 |
| B | 1 | 3 |
| C | 1 | 6 |

*W* = (1/2) + (1/3) + (1/6) = 1     
&    
*U(n)* = 3 * (2^(1/3) - 1) = 0.78
- Condition nécessaire vérifiée car W =< 1
- Condition suffisante pas respectée, 1 n'est pas inf à 0.78

### Pour le plan d'ordonnancement 
- PPCM(2,3,6) = 6 car 6 multiple de 3

![IMG_5577](https://user-images.githubusercontent.com/19282069/139205769-182ed78e-bdd7-4950-a86b-57a7a84e0301.jpg)

## EDF
- Tâche apériodique
- Pas de deps entre tâches
- Échéances connues
- Durées inconnues
- Priorité est l'inverse de l'échéance relative
### Hypothèse de faisabilité
**Optimal** si pas de surcharge (*W <= 1*)

## LLF
- Tâche apériodique
- Pas de deps entre tâches
- Échéances connues
- Priorité est l'inverse de la laxité

## Différence EDF LLF
**Si** les valeurs de laxité utilisées sont celles qui sont calculées aux dates de réveil des tâches     
- Ordonnancement équivalent

**Si** les valeurs de laxité sont calculées à chaque instant   
- LLF entraîne beaucoup plus de changement de contexte

# Exercices
## Travaux apériodiques    
|   | C | Tdeb | Échéance |
|---|---|------|----------|
| A | 5 | 0    | 9        |
| B | 3 | 3    | 8        |
| C | 2 | 2    | 11       |
| D | 2 | 7    | 12       |

![IMG_5581](https://user-images.githubusercontent.com/19282069/139209538-2644562d-3648-4435-abef-03f83b6fd80a.jpg)

## Travaux périodiques
|    | C | P  | Échéance |
|----|---|----|----------|
| T1 | 1 | 20 | 8        |
| T2 | 2 | 5  | 4        |
| T3 | 4 | 10 | 10       |

![IMG_5584](https://user-images.githubusercontent.com/19282069/139213284-d8d36ab4-cbd7-4e8d-a200-2b7f7251e50c.jpg)

## LLF
### Rappel
`MD = (Tf - Tc) - R`
- *Tf*: Date d'échéance
- *Tc*: Date période actuelle
- *R*: temps restant
### Tableau
|    | C | P  | Échéance |
|----|---|----|----------|
| T1 | 3 | 20 | 7        |
| T2 | 2 | 5  | 4        |
| T3 | 1 | 10 | 8        |

### Pour le plan d'ordonnancement 
- Priorité: inverse de marge dynamique

![IMG_5585](https://user-images.githubusercontent.com/19282069/139221166-2610f0ef-a76b-4e57-9e3a-482bda2a383c.jpg)

# Ordonnancement multiprocesseur
#### À tout moment t
- Un travail est exécuté par au plus un proc
- Un proc exécute au plus un travail
#### Ordonnancement non-accumulatif
Complexifie énormément pb par rapport à mono-proc 

|   | Tdeb | E  | C | Prio |
|---|------|----|---|------|
| A | 4    | 8  | 3 | 3    |
| B | 3    | 10 | 3 | 2    |
| C | 1    | 12 | 4 | 1    |

![IMG_5586](https://user-images.githubusercontent.com/19282069/139226895-dc2f35ea-3a31-422f-be20-e19edfa9afc4.jpg)