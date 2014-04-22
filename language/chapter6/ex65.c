/*
 * Exercise 6-5
 * Write a function undef that will remove a name
 * and definition from the table maintained by lookup
 * and install.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
char *strdup(char *);
void undef(char *name);
void print_nlist(struct nlist* np);

int main(void) {
    struct nlist *np;
    int i, n;

    n = 3;
    for (i=0; i<n; i++) {
        np = lookup("HASHSIZE");
        print_nlist(np);
        printf("--\n");

        install("HASHSIZE", "101");
        np = lookup("HASHSIZE");
        print_nlist(np);
        printf("--\n");

        undef("HASHSIZE");
        np = lookup("HASHSIZE");
        print_nlist(np);
        printf("==\n");
    }
    return 0;
}

unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if(strcmp(s, np->name) == 0) {
            return np;
        }
    }
    return NULL;
}

struct nlist *install(char *name, char *defn) {
    struct nlist* np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free((void*) np->defn);
    }

    if ((np->defn = strdup(defn)) == NULL) {
        return NULL;
    }
    return np;
}

char *strdup(char *str) {
    char *new_str =  (char *)malloc(sizeof(char) * strlen(str));
    strncpy(new_str, str, strlen(str));
    return new_str;
}

void free_nlist(struct nlist* np) {
    if (np) {
        free((void *)np->name);
        free((void *)np->defn);
        free((void *)np);
    }
}

void undef(char *name) {
    struct nlist* np;
    struct nlist* np_next;
    int hashval = hash(name);

    np = hashtab[hashval];
    if (strcmp(name, np->name) == 0) {
        np_next = np->next;
        free_nlist(np);
        hashtab[hashval] = np_next;
    } else {
        np_next = np->next;
        while (np_next != NULL) {
            if (strcmp(name, np_next->name) == 0) {
                np->next = np_next->next;
                free_nlist(np_next);
            } else {
                np = np_next;
                np_next = np->next;
            }
        }
    }
}

void print_nlist(struct nlist* np) {
    if (np == NULL) {
        printf("null\n");
    } else {
        printf("%s %s\n", np->name, np->defn);
    }
}
