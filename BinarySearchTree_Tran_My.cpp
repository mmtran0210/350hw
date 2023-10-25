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
        if (root == nullptr || root->data == data) {
            if (root == nullptr)
                std::cout << "Search key not found" << std::endl;
            return root;
        }
        if (data < root->data) {
            std::cout << root->data << " → ";
            return Search(root->left, data);
        }
        std::cout << root->data << " → ";
        return Search(root->right, data);

}

void InOrder(bstNode* root){
    if(root == NULL) return;
    InOrder(root->left);
    printf(root->data, ", ")
    Inorder(root->right);
}

  bstNode* Remove(bstNode* root, int data) {
        if (root == nullptr) {
            return root;
        }
        
        else
        if (data < root->data) {
            root->left = Remove(root->left, data);
        
        } else if (data > root->data) {
            root->right = Remove(root->right, data);

        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;

            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            bstNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Remove(root->right, temp->data);
        }
        return root;
    }
        bstNode* findMin(bstNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }


        void findMin() {
        if (root == nullptr) {
            std::cout << "BST is empty" << std::endl;
        } else {
            Node* minNode = findMin(root);
            std::cout << "BST node with the smallest value: " << minNode->data << std::endl;
            std::cout << "BST nodes are: ";
            InOrder(root);
            std::cout << std::endl;
        }
    }

    void findMax() {
        bstNode* current = root;
        if (current == nullptr) {
            std::cout << "BST is empty" << std::endl;
        } else {
            while (current->right != nullptr) {
                current = current->right;
            }
            std::cout << "BST node with the largest value: " << current->data << std::endl;
            std::cout << "BST nodes are: ";
            InOrder(root);
            std::cout << std::endl;
        }
    }
