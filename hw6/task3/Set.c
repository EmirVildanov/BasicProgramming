#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

typedef struct SetElement SetElement;
struct SetElement
{
    SetElement *leftChild;
    SetElement *rightChild;
    int value;
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

void addToSet(Set* set, int value)
{
    SetElement *newSetElement = createSetElement(value);
    if (isSetEmpty(set))
    {
        set->root = newSetElement;
        return;
    }
    SetElement *currentElement = set->root;
    while(true)
    {
        if (value < currentElement->value)
        {
            if (currentElement->leftChild == NULL)
            {
                currentElement->leftChild = newSetElement;
                return;
            }
            currentElement = currentElement->leftChild;
        }
        else if (value > currentElement->value)
        {
            if (currentElement->rightChild == NULL)
            {
                currentElement->rightChild = newSetElement;
                return;
            }
            currentElement = currentElement->rightChild;
        }
        else
        {
            return;
        }
    }
}

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
}

SetElement* findNewRoot(SetElement* setElement)
{
    SetElement *maxLeftElement = setElement->leftChild;
    while (maxLeftElement->rightChild != NULL)
    {
        maxLeftElement = maxLeftElement->rightChild;
    }
    return maxLeftElement;
}

void deleteElement(Set* set, int value)
{
    SetElement *parent = NULL;
    SetElement *currentElement = set->root;
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
        }
        else
        {
            parent = currentElement;
            currentElement = currentElement->rightChild;
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
            set->root = newRoot;
            int rememberValue = newRoot->value;
            deleteElement(set, rememberValue);
            currentElement->value = rememberValue;
            free(newRoot);
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
}
