#include <iostream>

// Define the structure of a binary tree node
struct TreeNode {
    TreeNode* left;  // Pointer to the left child node
    TreeNode* right; // Pointer to the right child node
    char data;       // Data stored in the node (char type)
};

// Function declarations for tree traversals
void postOrder(TreeNode* node);
void inOrder(TreeNode* node);
void preOrder(TreeNode* node);
TreeNode* createNode(TreeNode* root);

int main() {
    TreeNode* root = nullptr; // Initialize the root of the tree as NULL
    char continueChoice;

    while (true) {
        // Create a new node and add it to the tree
        root = createNode(root);

        // Ask user if they want to continue adding nodes
        std::cout << "Do you want to continue (y/n)? ";
        std::cin >> continueChoice;

        // If user chooses 'n' or 'N', break the loop
        if (continueChoice == 'n' || continueChoice == 'N') {
            break;
        }

        // Perform and display Inorder traversal
        std::cout << "Inorder is: ";
        inOrder(root);
        std::cout << std::endl;

        // Perform and display Preorder traversal
        std::cout << "Preorder is: ";
        preOrder(root);
        std::cout << std::endl;

        // Perform and display Postorder traversal
        std::cout << "Postorder is: ";
        postOrder(root);
        std::cout << std::endl;
    }

    return 0;
}

// Function to create a new node in the binary tree
TreeNode* createNode(TreeNode* root) {
    if (root == nullptr) {
        // Allocate memory for a new node
        root = new TreeNode;
        root->left = nullptr;  // Initialize left child as NULL
        root->right = nullptr; // Initialize right child as NULL

        // Input data for the new node
        std::cout << "Enter the node data: ";
        std::cin >> root->data;

        return root;
    }

    char choice;
    std::cout << "Enter the left or right child (l/r): ";
    std::cin >> choice;

    // Recursively create left or right child based on user's choice
    if (choice == 'r' || choice == 'R') {
        root->right = createNode(root->right);
    } else if (choice == 'l' || choice == 'L') {
        root->left = createNode(root->left);
    }

    return root;
}

// Function to perform Inorder traversal
void inOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);        // Traverse the left subtree
    std::cout << node->data;    // Visit the root node
    inOrder(node->right);       // Traverse the right subtree
}

// Function to perform Preorder traversal
void preOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data;    // Visit the root node
    preOrder(node->left);       // Traverse the left subtree
    preOrder(node->right);      // Traverse the right subtree
}

// Function to perform Postorder traversal
void postOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    postOrder(node->left);      // Traverse the left subtree
    postOrder(node->right);     // Traverse the right subtree
    std::cout << node->data;    // Visit the root node
}

/*Explanation
TreeNode structure: Defines a node in the binary tree with left and right pointers and data.
Traversal functions: Implement different tree traversal methods (inorder, preorder, postorder).
Main function: Manages user interaction and performs tree traversal after creating nodes.
createNode function: Handles the creation and linking of new nodes in the binary tree.
Comments:
Each function is documented to explain its purpose and the steps it performs.
Meaningful variable names are used to improve code readability.
The loop in main() continues to create nodes and perform traversals until the user decides to stop.
Clear prompts and outputs guide the user through the process. */