// On a le tableau suivant
/*
| Process | Execution Time | Period |
|---------|----------------|--------|
| t2      | 1/3            | 2      |
| t3      | 1              | 3      |
| t4      | 2              | 4      |

Pour calculer son utilisation on fait: 

((1/3)/2) + (1/3) + (2/4) = 10/12 
(2/12) + 4/12 + 6/12 = 12/12 = 100% d'utilisation
U(n) = 3 * (2^(1/3) - 1) = 0.78

Les 3 tâches s'exécutent donc correctement avec EDF
*/