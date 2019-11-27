#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

struct SetElement
{
    SetElement *leftChild;
    SetElement *rightChild;
    SetElement *parent;
    int value;
    int height;
};

struct Set
{
    SetElement *root;
    int size;
};

Set *createSet()
{
    Set *set = (Set *) malloc(sizeof(Set));
    if (set == NULL)
    {
        exit(1);
    }
    set->root = NULL;
    set->size = 0;
    return set;
}

SetElement *createSetElement(int value)
{
    SetElement *setElement = (SetElement *) malloc(sizeof(SetElement));
    if (setElement == NULL)
    {
        exit(1);
    }
    setElement->value = value;
    setElement->leftChild = NULL;
    setElement->rightChild = NULL;
    setElement->height = 1;
    setElement->parent = NULL;
    return setElement;
}

int getSetSize(Set *set)
{
    if (set == NULL)
    {
        exit(1);
    }
    return set->size;
}

bool isSetEmpty(Set *set)
{
    if (set == NULL)
    {
        exit(1);
    }
    if (set->root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void balanceParents(Set *set, SetElement *setElement)
{
    if (set == NULL || setElement == NULL)
    {
        exit(1);
    }
    while (setElement->parent != NULL)
    {
        setElement = balance(set, setElement->parent);
    }
}

void addToSet(Set *set, int value)
{
    if (set == NULL)
    {
        exit(1);
    }
    SetElement *newSetElement = createSetElement(value);
    if (isSetEmpty(set))
    {
        set->root = newSetElement;
        ++set->size;
        return;
    }
    SetElement *currentElement = set->root;
    while (true)
    {
        if (value < currentElement->value)
        {
            if (currentElement->leftChild == NULL)
            {
                currentElement->leftChild = newSetElement;
                newSetElement->parent = currentElement;
                balanceParents(set, newSetElement);
                ++set->size;
                return;
            }
            currentElement = currentElement->leftChild;
        }
        else if (value > currentElement->value)
        {
            if (currentElement->rightChild == NULL)
            {
                currentElement->rightChild = newSetElement;
                newSetElement->parent = currentElement;
                balanceParents(set, newSetElement);
                ++set->size;
                return;
            }
            currentElement = currentElement->rightChild;
        }
        else
        {
            free(newSetElement);
            return;
        }
    }
}

bool findElement(Set *set, int value)
{
    if (set == NULL)
    {
        exit(1);
    }
    SetElement *currentElement = set->root;
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

void checkElement(Set *set, int value)
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

SetElement *findNewRoot(SetElement *setElement)
{
    if (setElement == NULL)
    {
        exit(1);
    }
    SetElement *minRightElement = setElement->rightChild;
    while (minRightElement->leftChild != NULL)
    {
        minRightElement = minRightElement->leftChild;
    }
    return minRightElement;
}

int findHeight(SetElement *setElement)
{
    if (setElement == NULL)
    {
        return 0;
    }
    return setElement->height;
}

int findBalanceFactor(SetElement *setElement)
{
    if (setElement == NULL)
    {
        exit(1);
    }
    return findHeight(setElement->rightChild) - findHeight(setElement->leftChild);
}

void updateHeight(SetElement *setElement)
{
    if (setElement == NULL)
    {
        exit(1);
    }
    int rightChildHeight = findHeight(setElement->rightChild);
    int leftChildHeight = findHeight(setElement->leftChild);
    if (rightChildHeight > leftChildHeight)
    {
        setElement->height = rightChildHeight + 1;
    }
    else
    {
        setElement->height = leftChildHeight + 1;
    }
}

SetElement *rotateRight(Set *set, SetElement *setElement)
{
    if (set == NULL || setElement == NULL)
    {
        exit(1);
    }
    SetElement *newNode = setElement->leftChild;
    newNode->parent = setElement->parent;
    setElement->leftChild = newNode->rightChild;
    if (setElement->leftChild != NULL)
    {
        setElement->leftChild->parent = setElement;
    }
    if (setElement == set->root)
    {
        set->root = newNode;
    }
    else if (setElement == setElement->parent->leftChild)
    {
        setElement->parent->leftChild = newNode;
    }
    else
    {
        setElement->parent->rightChild = newNode;
    }
    newNode->rightChild = setElement;
    setElement->parent = newNode;
    updateHeight(setElement);
    updateHeight(newNode);
    return newNode;
}

SetElement *rotateLeft(Set *set, SetElement *setElement)
{
    if (set == NULL || setElement == NULL)
    {
        exit(1);
    }
    SetElement *newNode = setElement->rightChild;
    newNode->parent = setElement->parent;
    setElement->rightChild = newNode->leftChild;
    if (setElement->rightChild != NULL)
    {
        setElement->rightChild->parent = setElement;
    }
    if (setElement == set->root)
    {
        set->root = newNode;
    }
    else if (setElement == setElement->parent->leftChild)
    {
        setElement->parent->leftChild = newNode;
    }
    else
    {
        setElement->parent->rightChild = newNode;
    }
    newNode->leftChild = setElement;
    setElement->parent = newNode;
    updateHeight(setElement);
    updateHeight(newNode);
    return newNode;
}

SetElement *balance(Set *set, SetElement *setElement)
{
    if (set == NULL || setElement == NULL)
    {
        exit(1);
    }
    updateHeight(setElement);
    int balanceFactor = findBalanceFactor(setElement);
    if (balanceFactor == 2)
    {
        if (findBalanceFactor(setElement->rightChild) < 0)
        {
            setElement->rightChild = rotateRight(set, setElement->rightChild);
        }
        return rotateLeft(set, setElement);
    }
    if (balanceFactor == -2)
    {
        if (findBalanceFactor(setElement->leftChild) > 0)
        {
            setElement->leftChild = rotateLeft(set, setElement->leftChild);
        }
        return rotateRight(set, setElement);
    }
    return setElement;
}

void deleteElement(Set *set, int value)
{
    if (set == NULL)
    {
        exit(1);
    }
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
            currentElement = currentElement->leftChild;
        }
        else
        {
            currentElement = currentElement->rightChild;
        }
    }
    SetElement *rememberCurrentElementParent = currentElement->parent;//we need it to balance parents after deletion current element
    //If the element is a root
    if (currentElement == set->root)
    {
        if (currentElement->leftChild == NULL && currentElement->rightChild == NULL)
        {
            set->root = NULL;
            free(currentElement);
            --set->size;
        }
        else if (currentElement->leftChild == NULL)
        {
            set->root = currentElement->rightChild;
            free(currentElement);
            --set->size;
        }
        else if (currentElement->rightChild == NULL)
        {
            set->root = currentElement->leftChild;
            free(currentElement);
            --set->size;
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
    else if (currentElement == currentElement->parent->leftChild)
    {
        if (currentElement->leftChild == NULL && currentElement->rightChild == NULL)
        {
            currentElement->parent->leftChild = NULL;
            free(currentElement);
            --set->size;
        }
        else if (currentElement->leftChild == NULL)
        {
            currentElement->parent->leftChild = currentElement->rightChild;
            currentElement->rightChild->parent = currentElement->parent;
            free(currentElement);
            --set->size;
        }
        else if (currentElement->rightChild == NULL)
        {
            currentElement->parent->leftChild = currentElement->leftChild;
            currentElement->leftChild->parent = currentElement->parent;
            free(currentElement);
            --set->size;
        }
        else
        {
            SetElement *newRoot = findNewRoot(currentElement);
            int rememberValue = newRoot->value;
            deleteElement(set, rememberValue);
            currentElement->value = rememberValue;
        }
    }
        //if element is parent's right child
    else
    {
        if (currentElement->leftChild == NULL && currentElement->rightChild == NULL)
        {
            currentElement->parent->rightChild = NULL;
            free(currentElement);
            --set->size;
        }
        else if (currentElement->leftChild == NULL)
        {
            currentElement->parent->rightChild = currentElement->rightChild;
            currentElement->rightChild->parent = currentElement->parent;
            free(currentElement);
            --set->size;
        }
        else if (currentElement->rightChild == NULL)
        {
            currentElement->parent->rightChild = currentElement->leftChild;
            currentElement->leftChild->parent = currentElement->parent;
            free(currentElement);
            --set->size;
        }
        else
        {
            SetElement *newRoot = findNewRoot(currentElement);
            int rememberValue = newRoot->value;
            deleteElement(set, rememberValue);
            currentElement->value = rememberValue;
        }
    }
    rememberCurrentElementParent = balance(set, rememberCurrentElementParent);
    while (rememberCurrentElementParent->parent != NULL)
    {
        rememberCurrentElementParent = balance(set, rememberCurrentElementParent->parent);
    }
}

void deleteSet(Set *set)
{
    if (set == NULL)
    {
        exit(1);
    }
    SetElement *currentElement = set->root;
    while (set->root != NULL)
    {
        while (currentElement->leftChild != NULL)
        {
            currentElement = currentElement->leftChild;
        }
        if (currentElement->rightChild != NULL)
        {
            currentElement = currentElement->rightChild;
        }
        else
        {
            if (currentElement != set->root)
            {
                SetElement *rememberElement = currentElement;
                if (currentElement == currentElement->parent->leftChild)
                {
                    currentElement = currentElement->parent;
                    currentElement->leftChild = NULL;
                    free(rememberElement);
                }
                else
                {
                    currentElement = currentElement->parent;
                    currentElement->rightChild = NULL;
                    free(rememberElement);
                }
            }
            else
            {
                set->root = NULL;
                free(currentElement);
            }
        }
    }
    free(set);
}

//functions to print set and to put it on the array

void processIncreasingOrder(SetElement *setElement, int *array, int *newElementIndex)
{
    if (setElement == NULL)
    {
        return;
    }
    processIncreasingOrder(setElement->leftChild, array, newElementIndex);
    array[*newElementIndex] = setElement->value;
    ++*newElementIndex;
    printf("%d ", setElement->value);
    processIncreasingOrder(setElement->rightChild, array, newElementIndex);
}

void getInIncreasingOrder(Set *set, int *array)
{
    if (set == NULL)
    {
        exit(1);
    }
    printf("Set in the increasing order : ");
    int newElementIndex = 0;
    processIncreasingOrder(set->root, array, &newElementIndex);
    printf("\n");
}

void processDecreasingOrder(SetElement *setElement, int *array, int *newElementIndex)
{
    if (setElement == NULL)
    {
        return;
    }
    processDecreasingOrder(setElement->rightChild, array, newElementIndex);
    array[*newElementIndex] = setElement->value;
    ++*newElementIndex;
    printf("%d ", setElement->value);
    processDecreasingOrder(setElement->leftChild, array, newElementIndex);
}

void getInDecreasingOrder(Set *set, int *array)
{
    printf("Set in the decreasing order : ");
    int newElementIndex = 0;
    processDecreasingOrder(set->root, array, &newElementIndex);
    printf("\n");
}

void processPrint(SetElement *setElement)
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

void printSet(Set *set)
{
    if (set == NULL)
    {
        exit(1);
    }
    printf("The hole set : ");
    processPrint(set->root);
    printf("\n");
}