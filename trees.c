#include <stdio.h>
#include <stdlib.h>

///trees in algorithm 
typedef struct  TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createNode(char data){
    TreeNode* newNode = (TreeNode*)calloc(sizeof(TreeNode),100);
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int main(){


    TreeNode* root = createNode('R');
    TreeNode* nodeA = createNode('A');
    TreeNode* nodeB = createNode('B');
    TreeNode* nodeC = createNode('C');
    TreeNode* nodeD = createNode('D');
    TreeNode* nodeE = createNode('E');
    TreeNode* nodeF = createNode('F');
    TreeNode* nodeG = createNode('G');

    root->left = nodeA;
    root->right = nodeB;


    nodeA->left =  nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;
    nodeB->right = nodeF;

    nodeF->left = nodeG;


    printf("root->right->left->data: %c\n",root->right->left->data);

    free(nodeG);
    free(nodeF);
    free(nodeE);
    free(nodeB);
    free(nodeC);
    free(nodeD);
    free(nodeA);
    free(root);


    return 0;
}



