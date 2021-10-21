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