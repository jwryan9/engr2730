/*-------------------------------------------------------------------------------
 * Programmer: TODO: Jason Ryan
 * Name: main.cpp
 * Description: This program contains in-class examples and the mini-assignment
 *              associated with lecture 25 on binary trees.
 *
 *         For the mini-assignment, you must:
 *         1. finish the implementation of miniAssignmentTreeRepresentation1()
 *            associated with clicker question 1
 *         2. add your sketched tree to the comments and finish the implementation
 *            of miniAssignmentTreeRepresentation2() (see lecture notes)
 -------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* struct treeNode is used to represent a node in a binary tree */
struct treeNode {
    struct treeNode *leftPtr;     /* pointer to left subtree */
    int data;                     /* integer data value */
    struct treeNode *rightPtr;    /* pointer to right subtree */
};

typedef struct treeNode TreeNode;
typedef TreeNode * TreeNodePtr;

/* function prototype for function to create new tree node */
TreeNodePtr createNewTreeNode(int newNodeData);

/* function prototypes associated with first example and the
   clicker question + first part of mini-assignment */
void exampleTreeRepresentation1();
void miniAssignmentTreeRepresentation1();
void optionalExtraPractice1();

/* function prototype associated with remainder of mini-assignment */
void miniAssignmentTreeRepresentation2();

/* function prototype for function to print tree */
void printTree(TreeNodePtr treePtr, int indent);

int main(void)
{
    cout << "\nexampleTreeRepresentation1():" << endl ;
    exampleTreeRepresentation1();

    cout << "\nminiAssignmentTreeRepresentation1():" << endl ;
    miniAssignmentTreeRepresentation1();

    cout << "\noptionalExtraPractice1():" << endl ;
    optionalExtraPractice1();

    cout << "\nminiAssignmentTreeRepresentation2():" << endl ;
    miniAssignmentTreeRepresentation2();

    return 0;
}

/*
   Given desired data member value for new node, this function
   returns a pointer to a dynamically allocated tree node with
   the desired data member value. Both the left and right
   pointers are initialized to NULL.
*/
TreeNodePtr createNewTreeNode(int newNodeData)
{
    TreeNodePtr newNodePtr = NULL;
    newNodePtr = (TreeNodePtr) malloc(sizeof(TreeNode));

    if (newNodePtr != NULL)
    {
        newNodePtr->leftPtr = NULL;
        newNodePtr->data = newNodeData;
        newNodePtr->rightPtr = NULL;
    }

    return newNodePtr;
}

/* function associated with first tree representation example */
void exampleTreeRepresentation1()
{
    TreeNodePtr rootPtr;

    rootPtr = createNewTreeNode(4);
    rootPtr->leftPtr = createNewTreeNode(3);
    rootPtr->rightPtr = createNewTreeNode(8);

    rootPtr->leftPtr->leftPtr = createNewTreeNode(1);

    rootPtr->rightPtr->leftPtr = createNewTreeNode(6);
    rootPtr->rightPtr->rightPtr = createNewTreeNode(10);

    printTree(rootPtr, 0);
}

/* function associated with the first part of the mini-assignment */
void miniAssignmentTreeRepresentation1()
{
    TreeNodePtr rootPtr = NULL;

    rootPtr = createNewTreeNode(1);
    rootPtr->leftPtr = createNewTreeNode(2);
    rootPtr->rightPtr = createNewTreeNode(3);
    rootPtr->leftPtr->rightPtr = createNewTreeNode(4);
    rootPtr->rightPtr->leftPtr = createNewTreeNode(5);

    printTree(rootPtr, 0);
}


/*
   function for extra tree-representation practice (see lecture notes)
   completing this function is NOT required for your mini-assignment
*/
void optionalExtraPractice1()
{
    /* create the following trees using for loops:
TREE 1:

                    4
               4
          4
     4
4
     4
          4
               4
                    4
TREE 2:

     0
               0
                    2
          2
2
          2
                    2
               0
     0

*/

    /* YOUR OPTIONAL CODE HERE */


}

/* function associated with the second part of the mini-assignment */
void miniAssignmentTreeRepresentation2()
{
    /* Step 1 and 2: sketch of binary search tree resulting from
       inserting the following numbers (from left to right):
       40, 38, 36, 45, 39, 37, 42, 44, 56
       TODO: replace 9 instances of xx below with the appropriate number from above

                      40
              38              45
          36      39      42      56
        xx  37  xx  xx  xx  44  xx  xx
    */

    /* Step 3: write the code to explictly represent your tree above */
    TreeNodePtr rootPtr = NULL;

    rootPtr = createNewTreeNode(40);
    rootPtr->leftPtr = createNewTreeNode(38);
    rootPtr->rightPtr = createNewTreeNode(45);
    rootPtr->leftPtr->leftPtr = createNewTreeNode(36);
    rootPtr->leftPtr->rightPtr = createNewTreeNode(39);
    rootPtr->leftPtr->leftPtr->rightPtr = createNewTreeNode(37);

    rootPtr->rightPtr = createNewTreeNode(45);
    rootPtr->rightPtr->leftPtr = createNewTreeNode(42);
    rootPtr->rightPtr->rightPtr = createNewTreeNode(56);
    rootPtr->rightPtr->leftPtr->rightPtr = createNewTreeNode(44);


    /* print tree */
    printTree(rootPtr, 0);
}

/*xx
   function to print tree (note: we will cover recursive
   functions next time, so don't worry if this function
   is confusing at the moment)
*/
void printTree(TreeNodePtr treePtr, int indent)
{
    int i;
    if (treePtr != NULL)
    {
        printTree(treePtr->rightPtr, indent+5);
        for (i=1; i <= indent; i++)
        {
            cout << " ";
        }
        cout << treePtr->data << endl;
        printTree(treePtr->leftPtr, indent+5);
    }
}
