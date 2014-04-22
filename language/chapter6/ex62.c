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
struct gp* add_to_groups(struct gp* groups, char *var, int first_n);
void print_groups(struct gp* groups);
int get_para(int argc, char **argv);
int getword(char *word, int maxlen);
int is_c_type(char *t, char *types[], int type_len, int maxlen);
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
        groups = add_to_groups(groups, var, first_n);
    }

    print_groups(groups);
    return 0;
}

int is_valid_varchar(int c) {
    /*if (isspace(c) != 0) {
        return 0;
    } else {
        return 1;
    }*/
    if (isdigit(c) || isalpha(c) || c == '_') {
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

    if (c != EOF) {
        i = 0;
        word[i++] = c;
        while ((c=getchar()) != EOF && is_valid_varchar(c)) {
            word[i++] = c;
        }
        word[i] = '\0';
    }
    
    return (c != EOF) ? 1: 0;
}

int is_c_type(char *t, char *types[], int type_len, int maxlen) {
    int i;

    for (i=0; i<type_len; i++) {
        if (strncmp(t, types[i], maxlen) == 0) {
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
    int type_len = sizeof(types) / sizeof(char *);

    while (getword(word, maxlen) > 0) {
        if (is_c_type(word, types, type_len, maxlen)) {
            return getword(var, maxlen);
        }
    }

    return 0;
}


struct gp* add_to_groups(struct gp* groups, char *var, int first_n) {
    struct wd *new_wd = NULL;
    int cmp = 0;

    if (groups == NULL) {
        groups = (struct gp *)malloc(sizeof(struct gp));
        groups->words = (struct wd *)malloc(sizeof(struct wd));
        groups->words->word = (char *)malloc(sizeof(char) * (strlen(var) + 1));
        strncpy(groups->words->word, var, strlen(var) + 1);
        groups->words->next = NULL;
        groups->left = NULL;
        groups->right = NULL;
    } else {
        cmp = strncmp(var, groups->words->word, first_n);
        if (cmp == 0) {
            new_wd = (struct wd *)malloc(sizeof(struct wd));
            new_wd->word = (char *)malloc(sizeof(char) * (strlen(var) + 1));
            strncpy(new_wd->word, var, strlen(var) + 1);
            new_wd->next = groups->words;
            groups->words = new_wd;
        } else if (cmp < 0){
            groups->left = add_to_groups(groups->left, var, first_n);
        } else {
            groups->right = add_to_groups(groups->right, var, first_n);
        }
    }

    return groups;
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
