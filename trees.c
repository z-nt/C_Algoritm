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


/*in order traversal trees*/
void in_orderTeraversal(TreeNode* root){
    if(root == NULL){
        return;
    }
    in_orderTeraversal(root->left);
    printf("%c, ", root->data);
    in_orderTeraversal(root->right);
}

/*post order traversa trees*/
void post_orderTeraversal(TreeNode* root){
    if(root == NULL){
        return;
    }
    post_orderTeraversal(root->left);
    post_orderTeraversal(root->right);
    printf("%c,",root->data);
}
/*array implementation of binary trees*/
char* get_data (char binary_treeArray[],int index);
int left_index(int index);
int right_index(int index);


#define Array_size 15





int main(){
char binary_Trees[Array_size] =  {'R', 'A', 'B', 'C', 'D', 'E', 'F', '\0', '\0', '\0', '\0', '\0', '\0', 'G', '\0'};
    int right_child = right_index(0);
    int left_child = left_index(right_child);

    char* data = get_data(binary_Trees,left_child);


    if(data != NULL){
        printf("root->right,left->data:%s\n",data);
    }else{
        printf("it is null stuped");
    }



    return 0;
}



/*array implementation of binary trees*/
char* get_data (char binary_treeArray[],int index){
    if(index >= 0 && index  <  Array_size){
        return &binary_treeArray[index];
    }
}
int left_index(int index){
    return 2 * index + 1;
}
int right_index(int index){
    return 2 * index + 2;
}















