#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("Veuillez entre un mot de passe à brute-force\n");
    char password[100];
    scanf("%s", password);
    printf("Chargement de la wordlist\n");

    FILE *wordlist = fopen("wordlist.txt", "r");
    if (wordlist == NULL) {
        printf("Impossible d'ouvrir le fichier wordlist.txt\n");
        return 1;
    }
    char mot[100];
    while (fgets(mot, sizeof(mot), wordlist) != NULL) {
        mot[strcspn(mot, "\n")] = 0;
        printf("Mot lu %s\n", mot);
        if (strcmp(mot, password) == 0) {
            printf("Mot de passe trouvé : %s\n", mot);
            return 0;
        }
        else {
            printf("Mot de passe incorrect : %s\n", mot);
        }
    }

}