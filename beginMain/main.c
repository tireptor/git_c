#include <stdio.h>
#include <stdlib.h>

int main()
{
    exercice_5();
    //exercice_2();

    return 0;
}

int exercice_1 ()
{
    char response [100];
    int monNombre = 0;
    int *monPointeur;
    char *monPointeurChar;
    printf("Saisir votre age ? \n");
    scanf("%s",response);
    monNombre = atoi(response);
    monPointeurChar = &response;
    printf("Vous avez %s ans \n",response);
    monPointeur = &monNombre;
    printf("Vous avez %d ans \n", *monPointeur);
    monNombre = 10;
    printf("Maintenant vous avez %d ans \n",*monPointeur);
    printf("En pointeur char vous avez %s ans \n",monPointeurChar);
    printf("Saisir votre age ? \n");
    scanf("%s",response);
    printf("Apres modification vous avez %s ans \n",monPointeurChar);
    response[0] = 'a';
    response[1] = 'B';
    response[2] = '\0';
    printf("Apres modification interne, vous avez %d ans \n",*monPointeurChar);
    printf("Apres modification interne, vous avez %s ans \n",monPointeurChar); // Même résultat que la ligne du dessus.
    printf("L'adresse de response : %d et monPointeurChar pointe sur %d \n",&response,monPointeurChar);
    char responseAlternative = *monPointeurChar;
    printf("La valeur de responseAlternative = %d ",responseAlternative);
    return 0;
}
int exercice_2 ()
{
    char prenom [100];
    char *pointeurPrenom;
    pointeurPrenom = &prenom;
    printf("Saisir votre prenom ? \n");
    scanf("%s",prenom);
    printf("Vous vous appelez %s \n",prenom);
    printf("Vous vous appelez %s \n",*pointeurPrenom);


    return 0;
}
int exercice_3 ()
{
    char response [100];
    int monNombre = 0;
    int *monPointeur;
    char *monPointeurChar;

    monPointeurChar = &response;
    printf("Saisir votre age ? \n");
    scanf("%s",response);
    monNombre = atoi(response);
    printf("Vous avez %s ans \n",response);
    monPointeur = &monNombre;
    printf("Vous avez %d ans \n", *monPointeur);
    monNombre = 10;
    printf("Maintenant vous avez %d ans \n",*monPointeur);
    printf("En pointeur char vous avez %s ans \n",monPointeurChar);
    printf("Saisir votre age ? \n");
    scanf("%s",response);
    printf("Apres modification vous avez %s ans \n",monPointeurChar);
    response[0] = 'a';
    response[1] = 'B';
    response[2] = '\0';
    printf("Apres modification interne, vous avez %s ans \n",*monPointeurChar);
    printf("Apres modification interne, vous avez %s ans \n",monPointeurChar);
    printf("L'adresse de response : %d et monPointeurChar pointe sur %d \n",&response,monPointeurChar);
    char responseAlternative = *monPointeurChar;
    printf("La valeur de responseAlternative = %d ",responseAlternative);
    return 0;
}
int exercice_4 ()
{
    int var = 5;
    int* ptr = &var;
    printf("var :\t %d\n", var);
    printf("*ptr :\t %d\n", *ptr);
    printf("ptr[0] :\t %d\n", ptr [0]);
    printf("&var :\t %p\n", &var);
    printf("ptr :\t %p\n", ptr);
    printf("&ptr :\t %p\n", &ptr);
}
int exercice_5()
{
    int taille = 7;
    int * tab = (int *) malloc ( taille * sizeof(int));
    //int * tab = (int *) malloc ( taille);
    int tabConst [taille];
    tab[0] = 1946785;
    tab[1] = 292345678;
    tab[2] = 162345;
    tab[3] = 459987;
    tab[4] = 231234;
    tab[5] = 4810987;
    tab[6] = 292890;
    tab[7] = 25461098;
    taille = 10;
    (int *) realloc( tab, taille * sizeof(int) );
    //tab[5] = 600;
    printf("La valeur de tab : %d \n",tab[0]);
    printf("La valeur de tab : %d \n",tab[1]);
    printf("La valeur de tab : %d \n",tab[2]);
    printf("La valeur de tab : %d \n",tab[3]);
    printf("La valeur de tab : %d \n",tab[4]);
    printf("La valeur de tab : %d \n",tab[5]);
    printf("La valeur de tab : %d \n",tab[6]);
    printf("La valeur de tab : %d \n",tab[7]);
    //printf("La valeur de tab : %d \n",tab[5]);
    free ( tab );
}
