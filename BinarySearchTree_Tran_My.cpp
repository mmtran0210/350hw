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