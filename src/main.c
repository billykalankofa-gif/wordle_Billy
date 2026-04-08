#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordle.h"

int main() {
    load_words("ressource/bdd_wordle.txt");

    char *target = get_random_word();
    char guess[WORD_LENGTH];

    int attempts = 0;

    printf("Bienvenue dans Wordle !\n");

    while (attempts < 6) {
        printf("Proposez un mot : ");
        scanf("%s", guess);

        if (!is_valid_word(guess)) {
            printf("Mot invalide !\n");
            continue;
        }

        check_word(guess, target);
        attempts++;

        if (strcmp(guess, target) == 0) {
            printf("Bravo, vous avez gagné en %d coups !\n", attempts);
            return 0;
        }
    }

    printf("Perdu ! Le mot était : %s\n", target);
    return 0;
}
