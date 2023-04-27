#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL) return;
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node0, int key) {
    node *newNode = new node();
    newNode->key = key;

    if (node0 == NULL){
        node0 = newNode;
    }
    else if (node0->key > key){
        delete newNode;
        node0->left = insertNode(node0->left, key);
    }
    else{
        delete newNode;
        node0->right = insertNode(node0->right, key);
    }
    return node0;
}

struct node* minimum_node(struct node *root){
    if (root->left == NULL) return root;
    else return minimum_node(root->left);
};

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL and root->right == NULL){
            delete root;
            root = NULL;
            return root;
        }
        else if (root->left == NULL){
            root = root->right;
            return root;
        }
        else if (root->right == NULL){
            root = root->left;
            return root;
        }
        else{
            struct node *p = minimum_node(root->right);
            root->key = p->key;
            root->right = deleteNode(root->right, p->key);
            return root;
        }
    }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}