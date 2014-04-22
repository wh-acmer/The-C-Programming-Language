/*
 * exercise 6-2
 *
 * read C programs,
 *
 * group variables by first n character,
 * print group by alphebetically
 *
 * ignore variable in string and comment
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define VARLEN 256

struct wd {
    char *word;
    struct wd *next;
};

struct gp {
    struct wd* words;
    struct gp* left;
    struct gp* right;
};

int readvar(char *var, int maxlen);
void add_to_groups(struct gp* groups, char *var, int first_n);
void print_groups(struct gp* groups);
int get_para(int argc, char **argv);
int getword(char *word, int maxlen);
int is_c_type(char *t, char *types[]);
int is_valid_varchar(int c);

int main(int argc, char *argv[]) {
    char var[VARLEN];
    int maxlen = VARLEN;
    int first_n = 0;
    struct gp* groups = NULL;
    
    /* get parameter */
    if ((first_n = get_para(argc, argv)) < 0) {
        printf ("%s: input group flag n.\n", argv[0]);
        return -1;
    }

    while (readvar(var, maxlen) > 0) {
        add_to_groups(groups, var, first_n);
    }

    print_groups(groups);
    return 0;
}

int is_valid_varchar(int c) {
    if (!isspace(c)) {
        return 1;
    } else {
        return 0;
    }
}

int getword(char *word, int maxlen) {
    int c, i;

    /* ignore invalid character */
    while ((c=getchar()) != EOF && is_valid_varchar(c) == 0) {
        ;
    }

    i = 0;
    while ((c=getchar() != EOF && is_valid_varchar(c))) {
        word[i++] = c;
    }
    
    return (c != EOF) ? 1: 0;
}

int is_c_type(char *t, char *types[]) {
    int type_len = sizeof(types) / sizeof(char *);
    int i;

    for (i=0; i<type_len; i++) {
        if (strcmp(t, types[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int readvar(char *var, int maxlen) {
    char *types[] = {
        "short",
        "int",
        "float",
        "double",
        "void"
    };
    char word[maxlen];

    while (getword(word, maxlen) > 0) {
        if (is_c_type(word, types)) {
            return getword(var, maxlen);
        }
    }

    return 0;
}


void add_to_groups(struct gp* groups, char *var, int first_n) {
    struct wd *new_wd = NULL;
    int cmp = 0;

    if (groups == NULL) {
        groups = (struct gp *)malloc(sizeof(struct gp));
        groups->words = (struct wd *)malloc(sizeof(struct wd));
        groups->words->word = var;
        groups->words->next = NULL;
    } else {
        cmp = strncmp(var, groups->words->word, first_n);
        if (cmp == 0) {
            new_wd = (struct wd *)malloc(sizeof(struct wd));
            new_wd->word = var;
            new_wd->next = groups->words;
            groups->words = new_wd;
        } else if (cmp < 0){
            add_to_groups(groups->left, var, first_n);
        } else {
            add_to_groups(groups->right, var, first_n);
        }
    }
}


void print_groups(struct gp* groups) {
    struct wd *words = NULL;

    if (groups == NULL) {
        return;
    }

    words = groups->words;
    while (words) {
        printf("%s ", words->word);
        words = words->next;
    }
    printf("\n");

    print_groups(groups->left);
    print_groups(groups->right);
}


int get_para(int argc, char **argv) {
    return (argc < 2) ? -1 : atoi(argv[1]);
}
