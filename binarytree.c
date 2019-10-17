#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>

typedef int element;
typedef struct Treenode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode * search(TreeNode * node, int key) {
	if (node == NULL) {
		return NULL;
	}
	if (key == node->key) {
		return node;
	}
	else if (key < node->key) {
		return search(node->left, key);
	}
	else {
		return search(node->right, key);
	}
}

TreeNode * new_node(int item) {
	TreeNode * temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode * insert_node(TreeNode * node, int key) {
	if (node == NULL) {
		return new_node(key);
	}
	if (key < node->key) {
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert_node(node->right, key);
	}
	return node;
}

TreeNode * min_value_node(TreeNode* node) {
	TreeNode * current = node;

	while (current->left != NULL) {
		current = current->left;
	}

	return current;
}

TreeNode * delete_node(TreeNode * root, int key) {
	if (root == NULL) {
		return root;
	}

	if (key < root->key) {
		root->left = delete_node(root->left, key);
	}
	else if (key > root->key) {
		root->right = delete_node(root->right, key);
	}
	else {
		if (root->left == NULL) {
			TreeNode * temp = root->right;
			free(root); 
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}
		//중간에 있는 경우
		TreeNode * temp = min_value_node(root->right);

		root->key = temp->key;

		root->right = delete_node(root->right, temp->key);

	}
	return root;
}

void inorder(TreeNode * root) {
	if (root) {
		printf(" %d", root->key);
		inorder(root->left);
		inorder(root->right);
	}
}

int main(void) {
	TreeNode * root = NULL;
	TreeNode * tmp = NULL;
	char order;
	int num;

	while (1) {
		scanf("%c", &order);

		if (order == 'i') {
			scanf(" %d", &num);
			root = insert_node(root, num);
		}
		if (order == 'd') {
			scanf(" %d", &num);
			if (search(root, num) == NULL) {
				printf("X\n");
			}
			else {
				printf("%d\n", num);
			}
			root = delete_node(root, num);
		}
		if (order == 's') {
			scanf(" %d", &num);
			if (search(root, num) != NULL) {
				printf("%d\n", num);
			}
			else {
				printf("X\n");
			}
		}
		if (order == 'p') {
			inorder(root);
			printf("\n");
		}
		if (order == 'q') {
			break;
		}
		getchar();
	}

	free(root);
	free(tmp);

	return 0;
}
