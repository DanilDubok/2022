#include <stdlib.h>
#include "dk11_tool.h"

static void deleteNode(floatNode *aNode);
static floatNode *createNodeWithFloatValue(float value);

floatTree *createFloatTree() // створюю дерево
{
	floatTree *newTree = (floatTree *)malloc(sizeof(floatTree));

	if (newTree != NULL)
	{
		newTree->root = NULL;
		newTree->count = 0;
	}
	return newTree;
}

void deleteFloatTree(floatTree *aTree) // видаляю дерево
{
	deleteNode(aTree->root);
	free(aTree);
}

static void deleteNode(floatNode *aNode) // видаляю елемент дерева
{
	if (NULL != aNode)
	{
		deleteNode(aNode->leftChild);
		deleteNode(aNode->rightChild);
		free(aNode);
	}
}

static floatNode *createNodeWithFloatValue(float value) // створюю елемент дерева
{
	floatNode *newNode = (floatNode *)malloc(sizeof(floatNode));

	if (NULL != newNode)
	{
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
		newNode->value = value;
	}
	return newNode;
}

void insertFloatValueToTree(floatTree *aTree, float aValue) // вставка елемента у дерево
{
	if (NULL == aTree)
		return;

	floatNode *theNode = createNodeWithFloatValue(aValue);
	if (NULL == theNode)
		return;

	if (NULL == aTree->root)
		aTree->root = theNode;

	else
	{
		floatNode *theCurrent = aTree->root;
		floatNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;

			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}
	}
	aTree->count++;
}

float deleteValueFromTree(floatTree *aTree, float aValue) // видаляю елемент з дерева з його можливим заміщенням
{
	float theResult = 1;
	floatNode *theCurrent = aTree->root;
	floatNode *theParent = aTree->root;
	float LeftChild = 1;

	while (aValue != theCurrent->value)
	{
		theParent = theCurrent;
		if (aValue < theCurrent->value)
		{
			LeftChild = 1;
			theCurrent = theCurrent->leftChild;
		}
		else
		{
			LeftChild = 0;
			theCurrent = theCurrent->rightChild;
		}

		if (NULL == theCurrent)
			return 0;
	}

	if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
			aTree->root = NULL;

		else if (LeftChild)
			theParent->leftChild = NULL;

		else
			theParent->rightChild = NULL;
	}
	else if (NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
			aTree->root = theCurrent->leftChild;

		else if (LeftChild)
			theParent->leftChild = theCurrent->leftChild;

		else
			theParent->rightChild = theCurrent->leftChild;
	}
	else if (NULL == theCurrent->leftChild)
	{
		if (aTree->root == theCurrent)
			aTree->root = theCurrent->rightChild;

		else if (LeftChild)
			theParent->leftChild = theCurrent->rightChild;

		else
			theParent->rightChild = theCurrent->rightChild;
	}
	else
	{
		floatNode *theRecipient = getRecipient(aTree, theCurrent);
		if (aTree->root == theRecipient)
			aTree->root = NULL;

		else if (LeftChild)
			theParent->leftChild = theRecipient;

		else
			theParent->rightChild = theRecipient;
	}

	free(theCurrent);
	theResult = 1;
	return theResult;
}

void printTree(floatNode *aRoot) // вивожу дерево у консоль
{
	if (NULL == aRoot)
		return;

	printf("%.2f ", aRoot->value);
	printTree(aRoot->leftChild);
	printTree(aRoot->rightChild);
}
