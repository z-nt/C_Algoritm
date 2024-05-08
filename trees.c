#include <stdio.h>
#include <stdlib.h>

/*trees data structure*/
//create struct node
typedef struct  TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

//crete new node of node struct and pass data
TreeNode* createNode(char data){
    TreeNode* newNode = (TreeNode*)calloc(sizeof(TreeNode),100);
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

///pre _order traversal function
/// is going up to down from left

void pre_orderTeraversal(TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%c,",root->data);
    pre_orderTeraversal(root->left);
    pre_orderTeraversal(root->right);
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
    pre_orderTeraversal(root);

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



