/*-------------------------------------------------------------------------------
 * Programmer: Jason Ryan
 * Name: main.cpp
 * Description: This program contains in-class examples and the mini-assignment
 *              associated with lecture 23 on deleting nodes from
 *              linked lists using a function.
 *
 *              For the mini-assignment, you must complete the implementation
 *              of the function that deletes the FIRST node from a given linked
 *              list.
 -------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* struct node is used to represent a node in a linked list of integers */
struct node {
    int data;                 /* value of node */
    struct node * nextPtr;    /* pointer to next node in linked list */
};

typedef struct node Node;       /* Node is now an alias for struct node */
typedef struct node * NodePtr;  /* NodePtr is now an alias for struct node * */

/* prototypes for general linked list functions */
void printLinkedList(NodePtr startPtr);
void insertNodeInLinkedList(NodePtr *startPtr, int value);
void deleteNodeInLinkedList(NodePtr *startPtr, int value);
void freeAllMemoryInLinkedList(NodePtr *startPtr);

/* prototype for function to delete first node from linked list */
/* (your mini-assignment) */
void deleteFirstNodeInLinkedList(NodePtr *startPtr);


int main( void )
{
    int done = 0;
    int choice;
    int nodeValue;
    NodePtr startPtr = NULL; /* pointer to initial, empty list */

    cout << "\nWelcome to the linked list management system." << endl ;
    while (! done)
    {
        cout << "\nPlease enter a choice:" << endl ;
        cout << "  1. insert node" << endl ;
        cout << "  2. delete node" << endl ;
        cout << "  3. delete first node" << endl ; /* added for mini-assignment */
        cout << "  4. print list" << endl ;
        cout << "  5. delete list" << endl ;
        cout << "  6. quit" << endl ;
        cout << "Your choice = ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter value for new node: ";
                cin >> nodeValue;
                insertNodeInLinkedList(&startPtr, nodeValue);
                cout << "New list:" << endl ;
                printLinkedList(startPtr);
                break;
            case 2:
                cout << "\nEnter value of node to delete: ";
                cin >> nodeValue;
                deleteNodeInLinkedList(&startPtr, nodeValue);
                cout << "New list:" << endl ;
                printLinkedList(startPtr);
                break;
            case 3:
                deleteFirstNodeInLinkedList(&startPtr);
                cout << "New list:" << endl ;
                printLinkedList(startPtr);
            case 4:
                cout << "\nCurrent linked list:" << endl ;
                printLinkedList(startPtr);
                break;
            case 5:
                cout << "\nDeleting all nodes in list." << endl ;
                freeAllMemoryInLinkedList(&startPtr);
                cout << "New list:" << endl ;
                printLinkedList(startPtr);
                break;
            case 6:
                cout << "Thanks for using the linked list management system." << endl ;
                done = 1;
                break;
            default:
                cout << "Invalid choice." << endl ;
                break;
        }
    }

    freeAllMemoryInLinkedList(&startPtr);
    return 0;
}

/*-----------------------------------------------------------------------------
 * Function name: printLinkedList
 * Description: This function prints all of the values in a linked list.
 * Input: startPtr = NodePtr = pointer to first node of linked list
 ----------------------------------------------------------------------------*/
void printLinkedList(NodePtr startPtr)
{
    NodePtr currentPtr;
    for (currentPtr = startPtr; currentPtr != NULL; currentPtr = currentPtr->nextPtr)
    {
        cout << currentPtr->data << " ";
    }
    cout << endl ;
}

/*-----------------------------------------------------------------------------
 * Function name: insertNodeInLinkedList
 * Description: This function creates a new node with the given value and
 *              inserts it in the sorted linked list. The list is maintained
 *              in ascending order.
 * Input: startPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                        node of the list. The list is
 *                                        assumed to be in ascending order.
 *        value = int = integer value of node to be created/inserted in
 *                      sorted linked list
 * Output: startPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                         node of the list. If a node
 *                                         was inserted at the beginning of
 *                                         the list, the value of *startPtr
 *                                         will have changed.
 ----------------------------------------------------------------------------*/
void insertNodeInLinkedList(NodePtr *startPtr, int value)
{
    NodePtr newNodePtr; /* will point to newly created node */
    NodePtr beforeNodePtr, afterNodePtr;

    /* dynamically allocate memory for new node */
    newNodePtr = (NodePtr) malloc(sizeof(Node));

    /* insert node in list */
    if (newNodePtr != NULL) /* if successfully allocated memory */
    {
        newNodePtr->data = value;
        newNodePtr->nextPtr = NULL;

        /* determine where node should be inserted    */
        /* by defining beforeNodePtr and afterNodePtr */
        beforeNodePtr = NULL;
        afterNodePtr = *startPtr;
        while (afterNodePtr != NULL && afterNodePtr->data < value)
        {
            beforeNodePtr = afterNodePtr;
            afterNodePtr = afterNodePtr->nextPtr;
        }

        /* case 1: insert at beginning of list (beforeNodePtr is still NULL) */
        if (beforeNodePtr == NULL)
        {
            newNodePtr->nextPtr = *startPtr; /* set link to prior start */
            *startPtr = newNodePtr;       /* set new value for the startPtr */
        }
        else /* case 2: insert in middle or at end of list */
        {
            beforeNodePtr->nextPtr = newNodePtr;
            newNodePtr->nextPtr = afterNodePtr;
        }
    }
    else
    {
        cout << "Error allocating memory for new node of linked list." << endl ;
    }
}

/*-----------------------------------------------------------------------------
 * Function name: deleteNodeInLinkedList
 * Description: This function finds the first node within the linked list
 *              with the given value and deletes it from the list.
 * Input: startPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                        node of the list. The list is
 *                                        assumed to be in ascending order.
 *        value = int = integer value of node to be deleted from list
 * Output: startPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                         node of the list. If the first node
 *                                         is deleted from the list, the value
 *                                         of *startPtr will change.
 ----------------------------------------------------------------------------*/
void deleteNodeInLinkedList(NodePtr *startPtr, int value)
{
    NodePtr nodeToDeletePtr; /* will point to node to be deleted */
    NodePtr priorNodePtr;    /* will point to node immediately preceding node to be deleted */

    /* 1. determine which node should be deleted by defining nodeToDeletePtr and priorNodePtr */
    /* at the end of the while loop:
           - if the list is empty or the node is not found, nodeToDeletePtr will equal NULL
           - else if the first node should be deleted, nodeToDeletePtr will point to the first node
                                                       and priorNodePtr will equal NULL
           - else nodeToDeletePtr will point to the node to be deleted
                  and priorNodePtr will point to the prior node
    */
    nodeToDeletePtr = *startPtr;
    priorNodePtr = NULL;
    while (nodeToDeletePtr != NULL && nodeToDeletePtr->data != value)
    {
        priorNodePtr = nodeToDeletePtr;
        nodeToDeletePtr = nodeToDeletePtr->nextPtr;
    }

    /* 2. delete node */
    if (nodeToDeletePtr == NULL) /* empty list or node not found */
    {
        return;
    }
    else if (priorNodePtr == NULL) /* first node should be deleted */
    {
        *startPtr = (*startPtr)->nextPtr; /* move startPtr to second node in list */
        free(nodeToDeletePtr);            /* free memory */
    }
    else /* middle or end node should be deleted */
    {
        priorNodePtr->nextPtr = nodeToDeletePtr->nextPtr; /* skip nodeToDelete in linked list */
        free(nodeToDeletePtr);                            /* free memory */
    }
}

/*-----------------------------------------------------------------------------
 * Function name: deleteFirstNodeInLinkedList
 * Description: This function deletes the first node in the given linked list.
 * Input: startPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                        node of the list
 * Output: startPtr = pointer to NodePtr = pointer to the pointer of the new
 *                                         first node of the list
 ----------------------------------------------------------------------------*/
void deleteFirstNodeInLinkedList(NodePtr *startPtr)
{
    NodePtr firstNodePtr;

    if (*startPtr != NULL) /* if the list is not empty */
    {
        firstNodePtr = *startPtr;
        *startPtr = (*startPtr)->nextPtr;
        free(firstNodePtr);
    }
}

/*-----------------------------------------------------------------------------
 * Function name: freeAllMemoryInLinkedList
 * Description: This function frees all the memory in a linked list and
 *              sets the start pointer to be equal to NULL. All
 *              nodes in the linked list must have been dynamically allocated.
 * Input: startPtr = NodePtr * = pointer to pointer to the first node of linked
 *                               list
 * Output: startPtr = NodePtr * = modification of the startPtr so that it
 *                                equals NULL to indicate an empty list
 ----------------------------------------------------------------------------*/
void freeAllMemoryInLinkedList(NodePtr *startPtr)
{
    NodePtr tmpPtr, currentPtr;
    currentPtr = *startPtr;

    while (currentPtr != NULL)
    {
        tmpPtr = currentPtr;              /* keep a pointer to the node to be deleted */
        currentPtr = currentPtr->nextPtr; /* before memory for the node is freed, obtain a pointer to the next node */

        free(tmpPtr);                     /* free memory for the node */
    }

    /* indicate that the list is empty */
    *startPtr = NULL;
}
