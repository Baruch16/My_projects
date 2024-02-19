/***************************************************************************
 *                              From K&R2                                  *
 ***************************************************************************/
#include <stddef.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"


/* lookup: From K&R2 page 145. Look for s in hashtab. */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for(np = hashtab[hash(s)]; np != NULL; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

/* install: From K&R2 page 145. Put (name, defn) in hashtab. */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	
	if((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if(np == NULL || (np->name = strdup1(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else
		free((void *) np->defn);
	if((np->defn = strdup1(defn)) == NULL)
		return NULL;
	return np;
}

/* hash: From K&R2 page 144.  Form hash value for string s. */
unsigned hash(char *s)
{
	unsigned hashval;
	for(hashval = 0; *s != '\0'; ++s)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* strdup1: From K&R2 page 143. Makes a duplicate of s. */
char *strdup1(char *s)
{
	char *p;
	p = (char *) malloc(strlen(s) + 1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}
void undef1(char *s)
{
    struct nlist *np1, *np2;
    unsigned hashval = hash(s);

    for (np1 = hashtab[hashval], np2 = NULL; 
         np1 != NULL;
         np2 = np1, np1 = np1->next) 
        if (strcmp(s, np1->name) == 0) {
            /* found a match */
            free(np1->name);
            free(np1->defn);
            if (np2 == NULL) 
          	hashtab[hashval] = np1->next;
            else 
                np2->next = np1->next;
            free(np1);
            return;
        }
}

void undef(char *s)
{
   struct nlist * np=lookup(s);
   if (np){
   free(np->defn);
   free(np->name);
   np->defn=NULL;
   np->name=NULL;}
}




void printHashtable(void)
{
    struct nlist *p;
    for (int i = 0, j = 0; i < HASHSIZE; i++, j = 0)
    {
        p = hashtab[i];
        while (p != NULL)
        {
            
            printf("%p %p %s %s\n", (void *) p, (void *) p->next, p->name, p->defn);
            p = p->next;
            j++;
        }
    }
}        


