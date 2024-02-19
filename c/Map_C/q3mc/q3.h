
typedef struct Node {
	int data;
	struct Node *ls, *rs;
} Node;

Node* newNode(int data);
void insert(Node **root, int data);
int treeHeight(Node *root);
int numOfNodes(Node *root);
void printTreeRec(Node *root);
void printTree(Node *root);
void freeTree(Node *root);
int isIn(Node *root, int data);
int max(int num1, int num2);
