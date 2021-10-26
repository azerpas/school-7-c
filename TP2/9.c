// Non le programme ne fonctionnera plus
// -> la fonction do_work étant liée à la vitesse du processeur
//      notre programme verra ses temps de traitement divisé par 2,
//      avec pour effet un déréglement dans la périodicité 

// Pour cela, on va réécrire la fonction do_work en utilisant pas 
// de constante processeur 