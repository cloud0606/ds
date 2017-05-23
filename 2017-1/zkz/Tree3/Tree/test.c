#include <stdio.h>
#include "Tree.h"

void SuperShow(Node* tree) {
	if (!tree)return;
	printf("(");
	SuperShow(tree->left);
	if (tree->left)printf("←");
	printf(" %d ",tree->data);
	if (tree->right)printf("→");
	SuperShow(tree->right);
	printf(")");
}

int main() {
	/*测试输入及其个数*/
	int inputs[] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int size1 = 12;
	int toFind[] = { 13, 8, 5, 20, 6 };
	int size2 = 5;

	/*初始化查找表*/
	BST bst = newBST(8);
	for (int i = 1; i < size1; ++i) {
		bst = BSTinsert(bst, inputs[i]);
	}
	Show(bst);
	printf("\n");
	/*开始查找操作*/
	for (int j = 0; j < size2; ++j) {
		/*如果找到就删除，没找到就插入*/
		BSTfind(bst, toFind[j]) ? BSTremove(bst, toFind[j]) : BSTinsert(bst, toFind[j]);
		Show(bst);
		printf("\n");
	}
}