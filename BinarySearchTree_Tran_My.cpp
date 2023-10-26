// Binary Search Tree - Homework 4 - CSCE 350
// My Tran

#include <iostream>

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    BSTNode* root;
    // insert
    BSTNode* insert(BSTNode* current, int value) {
        // if empty, insert as root
        if (current == nullptr) {
            return new BSTNode(value);
        }
        // if value lesser, insert left
        if (value < current->data) {
            current->left = insert(current->left, value);
        // if value greater, right
        } else if (value > current->data) {
            current->right = insert(current->right, value);
        }
        return current;
    }

    BSTNode* search(BSTNode* current, int value) {
        // If the current node is null 
        // or the current node's data = the value searching, return the current node.
        if (current == nullptr || current->data == value) {
            // If the current node is null
            if (current == nullptr)
                std::cout << "Search key not found" << std::endl;
            return current;
        }
        // If value searching < than the data of the current node,
        // continue the search on the left subtree.
        if (value < current->data) {
            std::cout << current->data << " > ";
            return search(current->left, value);
        }
        // ie: 
        std::cout << current->data << " > ";
        return search(current->right, value);
    }
    
    BSTNode* findMin(BSTNode* current) {
        // keep going left until you reach the lefmost node
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    BSTNode* remove(BSTNode* current, int value) {
        if (current == nullptr) {
            return current;
        }
        // If the value removing < than the data of the current node,
        // continue on the left subtree.
        if (value < current->data) {
            current->left = remove(current->left, value);
         // If the value we're removing > than the data of the current node,
        // continue on the right subtree.
        } else if (value > current->data) {
            current->right = remove(current->right, value);
        
        // If the value removing = to the data of the current node,
        // then this is the one we want to remove.
        } else {
            // If the current node has no left child, then swap with right child
            if (current->left == nullptr) {
                BSTNode* tmp = current->right;
                delete current;
                return tmp;
            // If the current node has no right child, swap with left child
            } else if (current->right == nullptr) {
                BSTNode* tmp = current->left;
                delete current;
                return tmp;
            }
            // If the current node has two children, find the min in right subtree,
            // then replace the current node's data with this min,
            // then remove this min from the right subtree.
            BSTNode* tmp = findMin(current->right);
            current->data = tmp->data;
            current->right = remove(current->right, tmp->data);
        }
        return current;
    }

    void inOrderTr(BSTNode* current) {
        if (current == nullptr) {
            return;
        }
        // keep travese left until theres none to visit
        inOrderTr(current->left);
        std::cout << current->data << ", ";
        // vice versa 
        inOrderTr(current->right);
    }

public:
    BST() {
        root = nullptr;
    }
    
    bool dupe(BSTNode* current, int value) {
        if (current == nullptr) {
        return false;
    }
        if (value < current->data) {
            return dupe(current->left, value);
        } else if (value > current->data) {
            return dupe(current->right, value);
        } else {
        return true;
    }
}

    void insert(int value) {
        if (root == nullptr) {
            root = new BSTNode(value);
            std::cout << "Inserted " << value << " as the root node." << std::endl;
        } else {
        if (dupe(root, value)) {
            std::cout << "Node " << value << " is a duplicate node. Cannot insert Node " << value << " again." << std::endl;
        } else {
            root = insert(root, value);
            std::cout << "Inserted " << value << " into the BST." << std::endl;
        }
    }
        printTraversal();
}


    void search(int value) {
        std::cout << "Searching for node " << value << " : ";
        if (search(root, value) == nullptr) {
            std::cout << "search key not found :(";
        }
        std::cout << std::endl;
        printTraversal();
    }

    void remove(int value) {
        root = remove(root, value);
        std::cout << "Removed node " << value << " from the BST." << std::endl;
        printTraversal();
    }

    void findMin() {
        BSTNode* current = root;
        if (current == nullptr) {
            std::cout << "BST is empty" << std::endl;
        } else {
               // keep going left until you reach the lefmost node
        while (current->left != nullptr) {
            current = current->left;
        }
            std::cout << "BST node with the largest value: " << current->data << std::endl;
            printTraversal();
        }
    }
;

    void findMax() {
        BSTNode* current = root;
        if (current == nullptr) {
            std::cout << "BST is empty" << std::endl;
        } else {
            // keep going right
            while (current->right != nullptr) {
                current = current->right;
            }
            std::cout << "BST node with the largest value: " << current->data << std::endl;
            printTraversal();
        }
    }
    
    void printTraversal() {
        std::cout << "BST nodes are: ";
        inOrderTr(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;
    int choice, value;

    while (true) {
        std::cout << "\n<3 Binary Search Tree Operations <3\n";
        std::cout << "1. Insert Node\n";
        std::cout << "2. Delete Node\n";
        std::cout << "3. Search Node\n";
        std::cout << "4. Find Minimum Node\n";
        std::cout << "5. Find Maximum Node\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the value to be inserted: ";
                std::cin >> value;
                bst.insert(value);
                break;
            case 2:
                std::cout << "Enter the value to be deleted: ";
                std::cin >> value;
                bst.remove(value);
                break;
            case 3:
                std::cout << "Enter the value to be searched: ";
                std::cin >> value;
                bst.search(value);
                break;
            case 4:
                bst.findMin();
                break;
            case 5:
                bst.findMax();
                break;
            case 6:
                std::cout << "Exiting... Have a good one!!" << std::endl;
                exit(0);
            default:
                std::cout << "Invalid choice! Please choose a valid option.\n";
        }
    }

    return 0;
}