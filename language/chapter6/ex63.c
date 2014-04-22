/*
 * exercise 6-3
 * wirte a cross-referencer that prints a list of all words
 * in a document, and, for each-word, a list of the line number on
 * which it occurs
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_LEN 500
#define WORD_LEN 100

struct list {
    int line;
    struct list* next;
};

struct words_tree {
    char *wd;
    struct list *lines;
    struct words_tree* left;
    struct words_tree* right;
};

struct words_tree *
add_line_to_words_tree(
        struct words_tree * wd_tree,
        char *cline,
        int line_num);

struct words_tree*
add_word_to_words_tree(
        struct words_tree* wd_tree,
        char *word,
        int line_num);


int getword(char *word, char *line, int pos);

void print_words_tree(struct words_tree *);

int is_stop_word(char *word) {
    char *stop_words[] = {
        "the", 
        "and",
        "a"
    };
    int stop_words_len = sizeof(stop_words) / sizeof(char *);
    int i;

    for (i=0; i<stop_words_len; i++) {
        if (strncmp(stop_words[i], word, WORD_LEN) == 0) {
            return 1;
        }
    }

    return 0;
}


int main(void) {
    char cline[LINE_LEN];
    int line_num = 1;
    struct words_tree *wd_tree = NULL;

    while(fgets(cline, LINE_LEN, stdin)) {
        wd_tree = add_line_to_words_tree(wd_tree, cline, line_num);
        line_num ++;
    }
    
    print_words_tree(wd_tree);
    return 0;
}




struct words_tree*
add_line_to_words_tree(
        struct words_tree* wd_tree,
        char *cline,
        int line_num) {

    int pos = 0;
    char word[WORD_LEN];

    while ((pos = getword(word, cline, pos)) > 0) {
        if (is_stop_word(word) == 0) {
            wd_tree = add_word_to_words_tree(wd_tree, word, line_num);
        }
    }
    return wd_tree;
}

struct words_tree*
add_word_to_words_tree(
        struct words_tree* wd_tree,
        char *word,
        int line_num) {
    
    int word_len = strlen(word) + 1;
    int cmp = 0;
    struct list *new_line = NULL;

    if (wd_tree == NULL) {
        wd_tree = (struct words_tree*)malloc(sizeof(struct words_tree));
        wd_tree->wd = (char *)malloc(sizeof(char) * word_len);
        strncpy(wd_tree->wd, word, word_len);

        wd_tree->lines = (struct list*)malloc(sizeof(struct list));
        wd_tree->lines->line = line_num;
        wd_tree->lines->next = NULL;
    } else {
        cmp = strncmp(wd_tree->wd, word, word_len);  
        if (cmp == 0) {
            new_line = (struct list *)malloc(sizeof(struct list));        
            new_line->line = line_num;
            new_line->next = wd_tree->lines;
            wd_tree->lines = new_line;
        } else if (cmp < 0) {
            wd_tree->left = add_word_to_words_tree(
                    wd_tree->left,
                    word,
                    line_num);
        } else {
            wd_tree->right = add_word_to_words_tree(
                    wd_tree->right,
                    word,
                    line_num);
        }
    }
    return wd_tree;
}

int getword(char *word, char *line, int pos) {
    int i = 0;
    while (line[pos] != '\0' && isspace(line[pos]) == 0) {
        word[i++] = line[pos++];
    }
    word[i] = '\0';

    if (line[pos] == '\0') {
        return -1;
    } else {
        return pos + 1;
    }
}


void print_words_tree(struct words_tree *wd_tree) {
    struct list *cline = NULL;
    if (wd_tree == NULL) {
        return;
    }

    printf("%s ", wd_tree->wd);
    printf("%d", wd_tree->lines->line);
    cline = wd_tree->lines->next;
    while (cline) {
        printf(",%d", cline->line);
        cline = cline->next;
    }
    printf("\n");

    print_words_tree(wd_tree->left);
    print_words_tree(wd_tree->right);
}
