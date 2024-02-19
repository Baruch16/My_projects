#define HASHSIZE 101

struct nlist
{
	struct nlist *next;
	char *name;
	char *defn;
};


static struct nlist *hashtab[HASHSIZE];
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
unsigned hash(char *s);
char *strdup1(char *s);
void undef(char *s);
void printHashtable(void);

