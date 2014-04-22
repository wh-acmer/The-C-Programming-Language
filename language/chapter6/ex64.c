/* 
 * exercise 6-4
 * Write a program that prints the distinct words in its input
 * sorted into decreasing order of frequency of occurence. Precede
 * each word by its count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WORDLEN 100

struct word_feq_tree {
    char *word;
    int feq;
    struct word_feq_tree* left;
    struct word_feq_tree* right;
};

int getword(char *word, int maxlen);

struct word_feq_tree* add_word_to_tree(
        struct word_feq_tree* tree,
        char *word,
        int wordlen);

void print_word_feq_tree(struct word_feq_tree* tree);

int main(void) {
    struct word_feq_tree *wd_feq_tree = NULL;
    char word[WORDLEN];
    int word_len;

    while ((word_len = getword(word, WORDLEN)) > 0) {
        wd_feq_tree = add_word_to_tree(wd_feq_tree, word, word_len);
    }

    print_word_feq_tree(wd_feq_tree);

    return 0;
}

int getword(char *word, int maxlen) {
    int c;
    int i;

    while ((c=getchar()) != EOF && isspace(c) != 0) {
        ;
    }

    i = 0;
    if (c != EOF) {
        word[i++] = c;
        while ((c=getchar()) != EOF && isspace(c) == 0) {
            word[i++] = c;
        }
        word[i] = '\0';
    }

    return i;
}

struct word_feq_tree* add_word_to_tree(
        struct word_feq_tree* tree,
        char *word,
        int wordlen) {

    int cmp = 0;

    if (tree == NULL) {
        tree = (struct word_feq_tree*)malloc(sizeof(struct word_feq_tree));
        tree->word = (char *)malloc(sizeof(char) * wordlen);
        strncpy(tree->word, word, wordlen);
        tree->feq = 1;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        cmp = strncmp(word, tree->word, wordlen);
        if (cmp == 0) {
            tree->feq ++;
        } else if (cmp < 0) {
            tree->left = add_word_to_tree(tree->left, word, wordlen);
        } else {
            tree->right = add_word_to_tree(tree->right, word, wordlen);
        }
    }
    return tree;
}

void print_word_feq_tree(struct word_feq_tree* tree) {
    if (tree == NULL) {
        return;
    } 

    printf("%s %d\n", tree->word, tree->feq);
    print_word_feq_tree(tree->left);
    print_word_feq_tree(tree->right);
}
