/*-------------------------------------------------------------------------------
 * Programmer: TODO: Jason Ryan
 * Name: main.cpp
 * Description: This program contains in-class examples and the mini-assignment
 *              associated with lecture 26 on recursive functions and
 *              binary trees.
 *
 *         For the mini-assignment, you must:
 *         (R1) call the correct tree traversal function within the
 *              printBinarySearchTreeValuesInAscendingOrder function so that
 *              the values of the nodes will be printed in ascending order.
 *         (R2) Complete the getNumberOfNodesInBinaryTree function to return
 *              the total number of nodes in the given binary tree.
 *
 *         You may optionally consider to complete the following (NOT required):
 *         (O1) computing (by hand) the pre-order, in-order, and post-order tree
 *              traversals of the tree associated with clicker question 1
 *              (see lecture notes or clickerQuestion1() for tree)
 *         (O2) completing the function optionalComputeResultOfArithmeticExpressionTree
 *              to evaluate a binary tree representation of an arithmetic
 *              expression
 *         (O3) completing the function optionalPrintBinarySearchTreeValuesInDescendingOrder
 *              to print the nodes of a binary search tree in descending order
 *         (O4) completing the function getHeightOfBinaryTree for returning
 *              the height of a binary tree
 -------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

/* struct treeNode is used to represent a node in a binary tree */
struct treeNode {
    struct treeNode *leftPtr;     /* pointer to left subtree */
    int data;                     /* integer data value */
    struct treeNode *rightPtr;    /* pointer to right subtree */
};

typedef struct treeNode TreeNode;
typedef TreeNode * TreeNodePtr;

/* function prototypes associated with recursive function example */
void computeFactorialExample();
long computeFactorial(long n);

/* function prototypes for tree traversal functions */
void preOrderPrint(TreeNodePtr rootPtr);
void inOrderPrint(TreeNodePtr rootPtr);
void postOrderPrint(TreeNodePtr rootPtr);

/* function prototype for printing postfix notation of
   an arithmetic expression */
void postOrderArithmeticExpressionPrint(TreeNodePtr rootPtr);

/* function prototype associated with clicker question 1 */
void clickerQuestion1();

/* function prototype for function to print arithmetic expression tree */
void printTreeAsArithmeticExpression(TreeNodePtr treePtr, int indent);

/* function prototype associated with optionally computing the result
   of an arithmetic expression tree */
float optionalComputeResultOfArithmeticExpressionTree(TreeNodePtr rootPtr);

/* function prototype associated with function to illustrate tree traversal */
void traversalExamples();

/* function prototypes associated with clicker question 2 */
void clickerQuestion2();
void printBinarySearchTreeValuesInAscendingOrder(TreeNodePtr rootPtr);
void optionalPrintBinarySearchTreeValuesInDescendingOrder(TreeNodePtr rootPtr);

/* function prototype for function to create new tree node */
TreeNodePtr createNewTreeNode(int newNodeData);

/* function prototypes associated with node insertion functions */
void insertTreeNodeRandomly(TreeNodePtr *rootPtr, int newNodeData);
void insertBinarySearchTreeNode(TreeNodePtr *rootPtr, int newNodeData);

/* function prototype for function to print tree */
void printTree(TreeNodePtr treePtr, int indent);

/* function prototypes for remainder of mini-assignment */
void remainderOfMiniAssignment();
int getNumberOfNodesInBinaryTree(TreeNodePtr rootPtr);
int getHeightOfBinaryTree(TreeNodePtr rootPtr);


int main(void)
{
    cout << "\n**************************" << endl ;
    cout << "computeFactorialExample():" << endl ;
    cout << "**************************" << endl ;
    computeFactorialExample();

    cout << "\n********************" << endl ;
    cout << "clickerQuestion1():" << endl ;
    cout << "********************" << endl ;
    clickerQuestion1();

    cout << "\n********************" << endl ;
    cout << "traversalExamples():" << endl ;
    cout << "********************" << endl ;
    traversalExamples();

    cout << "\n********************" << endl ;
    cout << "clickerQuestion2():" << endl ;
    cout << "********************" << endl ;
    clickerQuestion2();

    cout << "\n***************************" << endl ;
    cout << "remainderOfMiniAssignment():" << endl ;
    cout << "****************************" << endl ;
    remainderOfMiniAssignment();

    return 0;
}

/* function to call the computeFactorial function */
void computeFactorialExample()
{
    int i;

    for (i=0; i <= 10; i++)
    {
        cout << setw(2) << right << i << "! = " << computeFactorial(i) << endl;
    }
}

/*
   Given an integer, this function uses recursion to compute/return
   the factorial of the given integer.
*/
long computeFactorial(long n)
{
    if (n <= 0) /* base case */
    {
        return 1;
    }
    else /* recursive case */
    {
        return n*computeFactorial(n-1);
    }
}


/*
   function to print the values of the nodes of a tree using
   a pre-order traversal
*/
void preOrderPrint(TreeNodePtr rootPtr)
{
    if (rootPtr != NULL)
    {
        cout << rootPtr->data << " ";
        preOrderPrint(rootPtr->leftPtr);
        preOrderPrint(rootPtr->rightPtr);
    }
}

/*
   function to print the values of the nodes of a tree using
   an in-order traversal
*/
void inOrderPrint(TreeNodePtr rootPtr)
{
    if (rootPtr != NULL)
    {
        inOrderPrint(rootPtr->leftPtr);
        cout << rootPtr->data << " ";
        inOrderPrint(rootPtr->rightPtr);
    }
}

/*
   function to print the values of the nodes of a tree using
   a post-order traversal
*/
void postOrderPrint(TreeNodePtr rootPtr)
{
    if (rootPtr != NULL)
    {
        postOrderPrint(rootPtr->leftPtr);
        postOrderPrint(rootPtr->rightPtr);
        cout << rootPtr->data << " ";
    }
}

/*
   function to print the given binary tree representation
   of an arithmetic expression in postfix notation
*/
void postOrderArithmeticExpressionPrint(TreeNodePtr rootPtr)
{
    if (rootPtr != NULL)
    {
        postOrderArithmeticExpressionPrint(rootPtr->leftPtr);
        postOrderArithmeticExpressionPrint(rootPtr->rightPtr);
        if (rootPtr->rightPtr != NULL && rootPtr->leftPtr != NULL)
        {
            cout << (char) rootPtr->data << " "; /* if has two children, print as char */
        }
        else
        {
            cout << rootPtr->data << " "; /* otherwise, print as integer */
        }
    }
}

/* function associated with clicker question 1 */
void clickerQuestion1()
{
    TreeNodePtr rootPtr = NULL;

    rootPtr = createNewTreeNode(42);
    rootPtr->leftPtr = createNewTreeNode(3);
    rootPtr->rightPtr = createNewTreeNode(43);
    rootPtr->rightPtr->leftPtr = createNewTreeNode(1);
    rootPtr->rightPtr->rightPtr = createNewTreeNode(4);


    cout << "tree:" << endl ;
    printTree(rootPtr,0);
    cout << "post order traversal:" << endl ;
    postOrderPrint(rootPtr);
    cout << "" << endl ;
    cout << "arithmetic expression tree:" << endl ;
    printTreeAsArithmeticExpression(rootPtr, 0);
    cout << "postfix notation:" << endl ;
    postOrderArithmeticExpressionPrint(rootPtr);
    cout << endl ;
    cout << "Result of evaluating arithmetic expression: " << optionalComputeResultOfArithmeticExpressionTree(rootPtr) << endl;

}



/*
   Given a pointer to a binary tree representation of an arithmetic expression,
   this function evaluates/returns the result of the expression.
   Note that completing this function is NOT required for your mini-assignment.
*/
float optionalComputeResultOfArithmeticExpressionTree(TreeNodePtr rootPtr)
{
    /* OPTIONAL EXTRA PRACTICE (NOT REQUIRED FOR MINI-ASSIGNMENT) */
    float result = 0.0;

    /* YOUR CODE HERE */


    return result;
}

/*
   Function to illustrate printing the nodes of a tree
   using pre-order, in-order, and post-order traversals
*/
void traversalExamples()
{
    int i, value;
    TreeNodePtr rootPtr = NULL;

    /* create example tree by inserting 10 nodes with random values
       into random positions of tree */
    srand(time(NULL)); /* seed random number generator */
    for (i=0; i < 10; i++)
    {
        value = rand() % 100;
        insertTreeNodeRandomly(&rootPtr, value);
    }

    cout << "RANDOM TREE:" << endl ;
    printTree(rootPtr, 0);
    cout << "\nPre-order traversal:" << endl ;
    preOrderPrint(rootPtr);
    cout << "\nIn-order traversal:" << endl ;
    inOrderPrint(rootPtr);
    cout << "\nPost-order traversal:" << endl ;
    postOrderPrint(rootPtr);
    cout << "" << endl ;
}

/* function associated with clicker question 2 */
void clickerQuestion2()
{
    int array[9] = {40, 38, 36, 45, 39, 37, 42, 44, 56};
    int n = 9;
    int i;
    TreeNodePtr rootPtr = NULL;

    /* create binary search tree from the array elements */
    for (i = 0; i < n; i++)
    {
        insertBinarySearchTreeNode(&rootPtr, array[i]);
    }
    /* print tree */
    printTree(rootPtr, 0);

    /* print values of tree in ascending order */
    cout << "Values in ascending order:" << endl ;
    printBinarySearchTreeValuesInAscendingOrder(rootPtr);
    cout << "" << endl ;

    /* (optional) print values of tree in descending order */
    cout << "Values in descending order (if implemented):" << endl ;
    optionalPrintBinarySearchTreeValuesInDescendingOrder(rootPtr);
    cout << endl ;
}

/* function to print nodes in binary search tree in ascending order */
void printBinarySearchTreeValuesInAscendingOrder(TreeNodePtr rootPtr)
{
    /* TODO: CALL APPROPRIATE TREE TRAVERSAL FUNCTION HERE */
    /* COMPLETING THIS LINE IS REQUIRED FOR YOUR MINI-ASSIGNMENT */
    inOrderPrint(rootPtr);

}

/* function to print nodes in binary search tree in descending order */
void optionalPrintBinarySearchTreeValuesInDescendingOrder(TreeNodePtr rootPtr)
{
    /* OPTIONAL: COMPLETE THIS FUNCTION (NOT REQUIRED FOR MINI-ASSINGMENT) */
    /* Hint: calling one of the pre-order, in-order, or post-order functions directly will NOT
       work here. Think about how you can modify one of them to get it to work.*/


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

/*
   Given a pointer to a pointer to a binary tree and desired node
   value, this function will create/insert a node with the given
   value in a random leaf position in the tree.
*/
void insertTreeNodeRandomly(TreeNodePtr *rootPtr, int newNodeData)
{
    if (*rootPtr == NULL) /* base case */
    {
        *rootPtr = createNewTreeNode(newNodeData);
    }
    else
    {
        if (rand() % 2 == 0)
        {
            insertTreeNodeRandomly(&((*rootPtr)->rightPtr), newNodeData);
        }
        else
        {
            insertTreeNodeRandomly(&((*rootPtr)->leftPtr), newNodeData);
        }
    }
}

/*
   Given a pointer to a pointer to a binary search tree and desired node
   value, this function will create/insert a node with the given
   value in the proper position. If the node value is a duplicate,
   it will NOT be inserted in the tree.
*/
void insertBinarySearchTreeNode(TreeNodePtr *rootPtr, int newNodeData)
{
    if (*rootPtr == NULL) /* base case */
    {
        *rootPtr = createNewTreeNode(newNodeData);
    }
    else
    {
        if (newNodeData < (*rootPtr)->data) /* insert in left subtree */
        {
            insertBinarySearchTreeNode(&((*rootPtr)->leftPtr), newNodeData);
        }
        else if (newNodeData > (*rootPtr)->data) /* insert in right subtree */
        {
            insertBinarySearchTreeNode(&((*rootPtr)->rightPtr), newNodeData);
        }
    }
}

/* function to print tree */
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

/* function to print arithmetic expression tree */
void printTreeAsArithmeticExpression(TreeNodePtr treePtr, int indent)
{
    int i;
    if (treePtr != NULL)
    {
        printTreeAsArithmeticExpression(treePtr->rightPtr, indent+5);

        for (i=1; i <= indent; i++)
        {
            cout << " ";
        }
        if (treePtr->rightPtr != NULL && treePtr->leftPtr != NULL)
        {
            cout << (char) treePtr->data << endl; /* if has two children, print as char */
        }
        else
        {
            cout << treePtr->data << endl; /* otherwise, print as integer */
        }

        printTreeAsArithmeticExpression(treePtr->leftPtr, indent+5);
    }
}

/* function for rest of mini-assignment */
void remainderOfMiniAssignment()
{
    int numRandomValues, i, val;
    TreeNodePtr rootPtr = NULL;

    srand(time(NULL)); /* seed random number generator */

    numRandomValues = rand() % 10 + 10; /* upperbound on number of nodes */

     /* create binary search tree with random node values with
       up to numRandomValues (may be less as duplicates won't be allowed) */
    for (i = 0; i < numRandomValues; i++)
    {
        val = rand() % 100;
        insertBinarySearchTreeNode(&rootPtr, val);
    }

    /* print tree */
    cout << "RANDOM SEARCH TREE:" << endl ;
    printTree(rootPtr,0);

    /* print number of nodes */
    cout << "Number of nodes: " << getNumberOfNodesInBinaryTree(rootPtr) << endl;

    /* print height of tree */
    cout << "Height of tree (if implemented): " << getHeightOfBinaryTree(rootPtr) << endl;
}

/*
   Given a pointer to a binary tree, this function returns the total number of
   nodes in the binary tree
*/
int getNumberOfNodesInBinaryTree(TreeNodePtr rootPtr)
{
    /* TODO: complete this function for the remainder of your mini-assignment */
    int numNodes = 0;

    if (rootPtr != NULL)
        numNodes = 1 + getNumberOfNodesInBinaryTree(rootPtr->leftPtr) + getNumberOfNodesInBinaryTree(rootPtr->rightPtr);

    return numNodes;
}

/*
   Given a pointer to a binary tree, this function returns the height of the binary
   tree. However, if the tree is empty, -1 is returned. If the tree only has one
   node, 0 is returned.
*/
int getHeightOfBinaryTree(TreeNodePtr rootPtr)
{
    /* optionally complete this function */
    int height = -1;

    return height;
}
