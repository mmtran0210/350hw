// Binary Search Tree - Homework 4 - CSCE 350
// My Tran

#include <iostream>
using namespace std;

// define node
struct bstNode {
    int data;
    bstNode *left;
    bstNode *right;
};

// to access to newly credted node
bstNode* getNewNode(int data) {
    bstNode *newNode = new bstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bstNode* Insert(bstNode* root, int data){
    // tree is empty
    if(root==NULL){
        root = getNewNode(data);
    }
    
    // if data is less than existing node, insert to left subtree
    else if(data <= root->data){
        root->left = Insert(root->left, data);
        printf("Node %d has been inserted", data);
    }
    // if data is greater than existing node, insert to right subtree
    else if{
        root->right = Insert(root->right, data);
        printf("Node %d has been inserted", data);
    }
    return root;
}

bstNode* Search(bstNode* root, int data){

}

void Inorder(bstNode* root){
    if(root == NULL) return;
    Inorder(root->left);
    printf(root->data, ", ")
    Inorder(root->right);
}