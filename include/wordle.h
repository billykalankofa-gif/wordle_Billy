#ifndef WORDLE_H
#define WORDLE_H

#define MAX_WORDS 10000
#define WORD_LENGTH 6

void load_words(const char *filename);
char* get_random_word();
int is_valid_word(const char *word);
void check_word(const char *guess, const char *target);

#endif
