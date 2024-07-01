#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
	char data[20];
	struct treenode *left;
	struct treenode *right;
}treenode;

treenode *createnode(char data[20]){
	treenode *result = malloc(sizeof(treenode));
	if (result != NULL){
		result->left =NULL;
		result->right = NULL;
		result->data = data;
	}
	return result;
}

void printtree(treenode *root){
	if(root == NULL){
		printf("------Tree is Empty!!----");
		return;
	}
	printf("Value = %s\n", root->data);
	printf("left\n");
	printtree(root->left);
	printf("right\n");
	printtree(root->right);
	
	
}

int main() {
	treenode *n1 = createnode("child");
	treenode *n2 = createnode("Parent1");
	treenode *n3 = createnode("Parent2");
	treenode *n4 = createnode("Parent3");
	treenode *n5 = createnode("Parent4");
	treenode *n6 = createnode("Parent5");
	treenode *n7 = createnode("Parent6");
	
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	
	printtree(n1);
	
	
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);
	free(n7);
	return 0;
}
