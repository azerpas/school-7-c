# Système temps-réel

Capacité de répondre à des évènements asynchrones issus du monde physique dans un délai prédéfini.    
**→ il n'est donc pas rapide**

![temps-reel](https://user-images.githubusercontent.com/19282069/140654969-70539a4d-1c52-484e-89e2-25e6e63d7441.png)

### Problématique
Vérifier que les contraintes temporelles sont respectées, pour cela:
**→ On organise les traitements associés aux entités**

## Deux types de temps-réel
Découle de ses spécifications:
- Contraintes temps
- Systèmes dédiés
- Contraintes industrielles
### Souple
Dépassements des contraintes de temps autorisé (téléphonie, jeux, etc...)
### Strict 
Une contrainte non-respectée est considérée comme une défaillance (aéronotique, nucléaire, etc...)
![utilite-temporelle-strict](https://user-images.githubusercontent.com/19282069/140654655-a262eeca-b11c-4886-b5da-df28c95c3e89.png)

## Caractéristiques d'un système temps-réel
### Déterministe
Toujours le même comportement
### Prédictibilité
Les perfs doivent ê définies dans tous les cas possibles
### Fiabilité 
Capacité à réaliser et maintenir ses fonctionnalités

# Gestion des interruptions
Indique à l'OS l'occurence d'un évènement interne/externe, attendu ou non      
**→ seul moyen de reprendre la main sur le processeur**

**Atomicité**: Une interruption ne peut survenir qu'entre deux instructions

## Gestionnaire
Programme appelé par le processeur lors d'une interruption     
→ chargé de gérer les conséquences et de sauvegarder le contexte

### Changement de contexte
Opération provoquée par le système à chq fois que le processeur doit être attribué à une autre tâche

## Étapes de l'interruption
1. Arrivée d'une interruption non-masquée
2. Sauvegarde du contexte de la tâche courante
3. Activation du gestionnaire d'interruption
4. Traitement de l'interruption
5. Reprendre la tâche interrompue

## Conditions
- Interruption n'est pas masquée
- CPU n'est pas à un point interruptible
- Niveau de priorité d'interruption respecté
### Contraintes tâches
- Tâche non-préemptible
- Tâche préemptible
### Contraintes ressources
- Ressources réquisitionnables
- Ressources non-réquisitionnables

## Interruptions sous Unix
Un signal désigne une interruption ou un déroutement    
- Soit un évènement externe au thread/proc (clavier, Kill, horloge)
- Soit un évènement interne au thread/proc (exception)

### À noter
- Il est possible de masquer ces signaux
- Un seul signal peut être mis en attente
- Prise en compte d'un signal appelle fonction "handler"

# Système multitâches
**Objectif classique**: Optimisation d'emploi des ressources       
**Objectif temps-réel**: Produire des résultats en fonction du temps

## Rôle de l'OS
- Interface avec le matériel 
- Ordonnancement des tâches
- Communication entre les tâches
- Cohabitation des tâches devant s'ignorer

## L'intérêt
- Optimiser l'utilisation matérielle
- Simplifier la conception
- Traiter évènements asynchrones
- Gérer un objectif temps-réel global  

## Niveaux tâches
### Niveau d'urgence
Urgence des données, **définie par l'échéance de la tâche**
### Niveau d'importance
Résister aux fautes temporelles 

![niveaux](https://user-images.githubusercontent.com/19282069/140656822-8eac247c-9a68-4e43-806d-00626fbf4738.png)

## Classifications des tâches
- Critiques: doivent toujours être assurées
- Essentielles: doivent être assurées autant que possible
- Sûreté: montrer qu'une chose ne peut pas se produire
- Vivacité: montrer qu'une chose se produire à un moment x
- Ponctualité: montrer que les traitements se finissent à temps

## Ordonnancer correctement un système temps-réel multitâche
1. 100% des tâches **critiques** doivent respecter leurs contraintes temporelles
2. tâches **essentielles** doivent faire au mieux
### Différence système temps-réel dur/mou
- Dur: aucune faute temporelle acceptée
- Mou: une faute temporelle acceptée