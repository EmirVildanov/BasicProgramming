#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

struct SetElement
{
    SetElement *leftChild;
    SetElement *rightChild;
    int value;
    int height;
};

struct Set
{
    SetElement *root;
};

Set* createSet()
{
    Set *set = (Set*) malloc(sizeof(Set));
    set->root = NULL;
    return set;
}

SetElement* createSetElement(int value)
{
    SetElement* setElement = (SetElement*) malloc(sizeof(SetElement));
    setElement->value = value;
    setElement->leftChild = NULL;
    setElement->rightChild = NULL;
    setElement->height = 1;
    return setElement;
}

bool isSetEmpty(Set* set)
{
    if (set->root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void updateParentsHeight(Set* set, SetElement* parents[], int length)
{
    for (int i = length - 1; i >= 0; --i)
    {
        updateHeight(parents[i]);
        if (i != 0 && parents[i] == parents[i - 1]->leftChild)
        {
            parents[i - 1]->leftChild = balance(set, parents[i]);
        }
        else if (i != 0 && parents[i] == parents[i - 1]->rightChild)
        {
            parents[i - 1]->rightChild = balance(set, parents[i]);
        }
        else
        {
            balance(set, parents[i]);
        }
    }
}

void addToSet(Set* set, int value)
{
    SetElement *newSetElement = createSetElement(value);
    int parentsCounter = 1;
    if (isSetEmpty(set))
    {
        set->root = newSetElement;
        return;
    }
    SetElement *currentElement = set->root;
    SetElement *parents[set->root->height + 1];
    parents[0] = set->root;
    while(true)
    {
        if (value < currentElement->value)
        {
            if (currentElement->leftChild == NULL)
            {
                currentElement->leftChild = newSetElement;
                updateParentsHeight(set, parents, parentsCounter);
                return;
            }
            currentElement = currentElement->leftChild;
            parents[parentsCounter] = currentElement;
            ++parentsCounter;
        }
        else if (value > currentElement->value)
        {
            if (currentElement->rightChild == NULL)
            {
                currentElement->rightChild = newSetElement;
                updateParentsHeight(set, parents, parentsCounter);
                return;
            }
            currentElement = currentElement->rightChild;
            parents[parentsCounter] = currentElement;
            ++parentsCounter;
        }
        else
        {
            return;
        }
    }
}

bool findElement(Set* set, int value)
{
    SetElement* currentElement = set->root;
    while (true)
    {
        if (currentElement == NULL)
        {
            return false;
        }
        if (currentElement->value == value)
        {
            return true;
        }
        else if (value < currentElement->value)
        {
            currentElement = currentElement->leftChild;
        }
        else
        {
            currentElement = currentElement->rightChild;
        }
    }
}

void checkElement(Set* set, int value)
{
    if (findElement(set, value))
    {
        printf("Element %d in the set\n", value);
    }
    else
    {
        printf("Element %d is not in the set\n", value);
    }
}


SetElement* findNewRoot(SetElement* setElement)
{
    SetElement *minRightElement = setElement->rightChild;
    while (minRightElement->leftChild != NULL)
    {
        minRightElement = minRightElement->leftChild;
    }
    return minRightElement;
}

void deleteElement(Set* set, int value)
{
    SetElement *parent = NULL;
    SetElement *currentElement = set->root;
    int parentsCounter = 1;
    SetElement *parents[set->root->height + 1];
    parents[0] = set->root;
    //Finding element
    while (true)
    {
        if (currentElement == NULL)
        {
            return;
        }
        if (value == currentElement->value)
        {
            break;
        }
        else if (value < currentElement->value)
        {
            parent = currentElement;
            currentElement = currentElement->leftChild;
            parents[parentsCounter] = currentElement;
            ++parentsCounter;
        }
        else
        {
            parent = currentElement;
            currentElement = currentElement->rightChild;
            parents[parentsCounter] = currentElement;
            ++parentsCounter;
        }
    }
    //If the element is a root
    if (currentElement == set->root)
    {
        if (currentElement->leftChild == NULL && currentElement->rightChild == NULL)
        {
            free(currentElement);
        }
        else if (currentElement->leftChild == NULL)
        {
            set->root = currentElement->rightChild;
            free(currentElement);
        }
        else if (currentElement->rightChild == NULL)
        {
            set->root = currentElement->leftChild;
            free(currentElement);
        }
        else
        {
            SetElement *newRoot = findNewRoot(currentElement);
            int rememberValue = newRoot->value;
            deleteElement(set, rememberValue);
            currentElement->value = rememberValue;
        }
    }
    //If the element is parent's left child
    else if (currentElement == parent->leftChild)
    {
        if (currentElement->leftChild == NULL && currentElement->rightChild == NULL)
        {
            parent->leftChild = NULL;
            free(currentElement);
        }
        else if (currentElement->leftChild == NULL)
        {
            parent->leftChild = currentElement->rightChild;
            free(currentElement);
        }
        else if (currentElement->rightChild == NULL)
        {
            parent->leftChild = currentElement->leftChild;
            free(currentElement);
        }
        else
        {
            SetElement *newRoot = findNewRoot(currentElement);
            int rememberValue = newRoot->value;
            deleteElement(set, rememberValue);
            currentElement->value = rememberValue;
        }
    }
    //If the element is parent's right child
    else
    {
        if (currentElement->leftChild == NULL && currentElement->rightChild == NULL)
        {
            parent->rightChild = NULL;
            free(currentElement);
        }
        else if (currentElement->leftChild == NULL)
        {
            parent->rightChild = currentElement->rightChild;
            free(currentElement);
        }
        else if (currentElement->rightChild == NULL)
        {
            parent->rightChild = currentElement->leftChild;
            free(currentElement);
        }
        else
        {
            SetElement *newRoot = findNewRoot(currentElement);
            int rememberValue = newRoot->value;
            deleteElement(set, rememberValue);
            currentElement->value = rememberValue;
        }
    }
    updateParentsHeight(set, parents, parentsCounter);
}

int height(SetElement* setElement)
{
    if (setElement == NULL)
    {
        return 0;
    }
    return setElement->height;
}

int balanceFactor(SetElement* setElement)
{
    return height(setElement->rightChild) - height(setElement->leftChild);
}

void updateHeight(SetElement* setElement)
{
    int rightChildHeight = height(setElement->rightChild);
    int leftChildHeight = height(setElement->leftChild);
    if (rightChildHeight > leftChildHeight)
    {
        setElement->height = rightChildHeight + 1;
    }
    else
    {
        setElement->height = leftChildHeight + 1;
    }
}

SetElement* rotateRight(Set* set, SetElement* setElement)
{
    SetElement *newNode = setElement->leftChild;
    setElement->leftChild = newNode->rightChild;
    newNode->rightChild = setElement;
    updateHeight(newNode);
    updateHeight(setElement);
    if (setElement == set->root)
    {
        set->root = newNode;
    }
    return newNode;
}

SetElement* rotateLeft(Set* set, SetElement* setElement)
{
    SetElement *newNode = setElement->rightChild;
    setElement->rightChild = newNode->leftChild;
    newNode->leftChild = setElement;
    updateHeight(newNode);
    updateHeight(setElement);
    if (setElement == set->root)
    {
        set->root = newNode;
    }
    return newNode;
}

SetElement* balance(Set* set, SetElement* setElement)
{
    updateHeight(setElement);
    if (balanceFactor(setElement) == 2)
    {
        if (balanceFactor(setElement->rightChild) < 0)
        {
            setElement->rightChild = rotateRight(set, setElement->rightChild);
        }
        return rotateLeft(set, setElement);
    }
    if (balanceFactor(setElement) == -2)
    {
        if (balanceFactor(setElement->leftChild) > 0)
        {
            setElement->leftChild = rotateLeft(set, setElement->leftChild);
        }
        return rotateRight(set, setElement);
    }
    return setElement;
}

//functions to print set and to put it on the array

void processIncreasingOrder(SetElement *setElement, int* array, int* sizeOfArray)
{
    if (setElement == NULL)
    {
        return;
    }
    processIncreasingOrder(setElement->leftChild, array, sizeOfArray);
    array[*sizeOfArray] = setElement->value;
    printf("%d ", setElement->value);
    *sizeOfArray += 1;
    processIncreasingOrder(setElement->rightChild, array, sizeOfArray);
}

void getInIncreasingOrder(Set* set, int* array, int* sizeOfArray)
{
    printf("Set in the increasing order : ");
    processIncreasingOrder(set->root, array, sizeOfArray);
    printf("\n");
}

void processDecreasingOrder(SetElement* setElement, int* array, int* sizeOfArray)
{
    if (setElement == NULL)
    {
        return;
    }
    processDecreasingOrder(setElement->rightChild, array, sizeOfArray);
    array[*sizeOfArray] = setElement->value;
    printf("%d ", setElement->value);
    *sizeOfArray += 1;
    processDecreasingOrder(setElement->leftChild, array, sizeOfArray);
}

void getInDecreasingOrder(Set* set, int* array, int* sizeOfArray)
{
    printf("Set in the decreasing order : ");
    processDecreasingOrder(set->root, array, sizeOfArray);
    printf("\n");
}

void processPrint(SetElement* setElement)
{
    if (setElement == NULL)
    {
        printf("null ");
    }
    else
    {
        printf("(");
        printf("%d ", setElement->value);
        processPrint(setElement->leftChild);
        processPrint(setElement->rightChild);
        printf(") ");
    }
}

void printSet(Set* set)
{
    printf("The hole set : ");
    processPrint(set->root);
    printf("\n");
}