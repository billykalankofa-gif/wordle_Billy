#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "wordle.h"

char words[MAX_WORDS][WORD_LENGTH];
int word_count = 0;

void load_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erreur ouverture fichier\n");
        exit(1);
    }

    while (fscanf(file, "%5s", words[word_count]) != EOF) {
        word_count++;
    }

    fclose(file);
}

char* get_random_word() {
    srand(time(NULL));
    int index = rand() % word_count;
    return words[index];
}

int is_valid_word(const char *word) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word, words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_word(const char *guess, const char *target) {
    for (int i = 0; i < 5; i++) {
        if (guess[i] == target[i]) {
            printf("v"); // bien placé
        } else {
            int found = 0;
            for (int j = 0; j < 5; j++) {
                if (guess[i] == target[j]) {
                    found = 1;
                    break;
                }
            }
            printf(found ? "o" : "x");
        }
    }
    printf("\n");
}
