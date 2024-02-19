#include <stdio.h>
#include <stdlib.h>
#include "q3.h"

Node* newNode(int data) {
	Node *p = (Node*) malloc (sizeof(Node));
	p->data = data;
	p->ls = p->rs = NULL;
	return p;
}
void insert(Node **root, int data) {
	if (*root==NULL){
		*root=newNode(data);
		return;}
	if ((*root)-> data >data)
		insert(&(*root)->ls,data);
	else 
		insert(&(*root)->rs,data);
	
	}
int treeHeight(Node *root) {
	if(root==NULL)
		return 0;
	
	int height_rs = treeHeight(root->rs);
    	int height_ls = treeHeight(root->ls);

    	return 1 + max(height_ls, height_rs);
  }
int numOfNodes(Node *root) {
	if(root==NULL)
		return 0;
	int Nodesnum=1+ numOfNodes(root->ls)+numOfNodes(root->rs);
	return Nodesnum; }
	
void printTreeRec(Node *root) {
	printf("%d, ", root->data);}
	
void printTree(Node *root) {
	if(root==NULL)
		return;
	printTree(root->ls);
	printTreeRec(root);
	printTree(root->rs);
}

void freeTree(Node *root) {
	if(root==NULL)
		return ;
		
	freeTree(root->ls);
	freeTree(root->rs);
	free(root);
		}
		
int isIn(Node *root, int data) {
	if (root==NULL)
		return 0;
	if (root->data==data)
		return 1;
	if(root->data>data)
		return isIn(root->ls,data);
	if(root->data<data)
		return isIn(root->rs,data);	}

int max(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    return num2;
}

