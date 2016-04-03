#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "structs.h"
#include <assert.h>

struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};

void getUserInput(char * input) {
	printf("\n(Y)es/(N)o?\n");
	scanf("%s", input);
}

int isLeafNode(struct Node *node) {
	return node->left == 0 && node->right == 0;
}

int isYes(char * input) {
	return input[0] == 'y' || input[0] == 'Y';
}

int main() {

	
	FILE *fp;
	
	fp = fopen("tree.txt", "r");

	assert(fp!=0);
	
	char line[200];
    struct BSTree *tree	= newBSTree();

	while (fgets(line, 200, fp) != NULL) {
		int num;
		char *str = malloc(sizeof(char) * 200);
		
		sscanf(line, "%d,%[^\t\n]", &num, str);
		struct data *newNode = (struct data *) malloc(sizeof(struct data));
		newNode->number = num;
		newNode->name = str;
		addBSTree(tree, newNode);
	}

	struct Node *cur = tree->root;
	char input[100];

	while (cur != 0 && ! isLeafNode(cur)) {
		struct data *currData = (struct data*)cur->val;

		printf ("%s",currData->name);
		getUserInput(input);
		if (isYes(input)) {
			cur = cur->left;
		} else {
			cur = cur->right;
		}
	}

	if (cur == 0) {
		printf("Hey buddy! Cheese isn't an animal! J/K. My database is incomplete.\n");
	} else {
		struct data *currData = (struct data*)cur->val;
		printf("Is your animal a(n) %s?", currData->name);
		getUserInput(input);
		if (isYes(input)) {
			printf("Success! Thanks for playing!\n");
		} else {
			printf("Sorry. I guess I am not as smart as you. Going into sleep mode, disappointment overload.\n");
		}
	}

	return 0;
}