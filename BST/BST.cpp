#include <iostream>
using namespace std;


struct node {
  int key;
  struct node *left, *right;
};


// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL){
    return;
  }

  //First recurse on left child.
  traverseInOrder(root -> left);

  //Print the data of the node.
  cout << root -> key << " ";

  //now traverse the right sub tree.
  traverseInOrder(root->right);
}


// Insert a node
struct node *insertNode(struct node *node, int key) {

  //Checking whether a node is existing and if not inseting the key to the node.
  if (node == NULL){
    node = new struct node;
    node -> key = key;
    node -> left = NULL;
    node -> right = NULL;
  }

  //If the key is greater than the node key recurse the function with the right node.
  else if (node->key < key){
    node->right = insertNode(node->right, key);
  }

  //If the key is lessser than the node key recurse the function with the left node.
  else {
    node->left = insertNode(node->left, key);
  }
  return node;
}


//Finding the minimum of the tree.
struct node *FindMin(struct node *root){
  if (root->left == NULL){
    return root;
  }

  else {
    return FindMin(root->left);
  }
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {

  //If the key is not found in the BST the node is returned.
  if (root == NULL){
    return root;
  }

  //If the key is greater than the root key recursing the function on the right node.
  else if (root->key < key){
    root->right = deleteNode(root->right, key);
    return root;
  }

  //If the key is lesser than the root key recursing the function on the left node.
  else if (root->key > key){
    root->left = deleteNode(root->left, key);
    return root;
  }

  //When the root to be deleted is found.
  else{

    //Case 1 : No child.
    if (root->left==NULL && root->right==NULL){
      delete root;
      root = NULL;
      return root;
    }

    //Case 2 : One child.
    else if(root->left == NULL){
      struct node *temp = root;
      root = root->right;
      delete temp;
      return root;
    }

    else if(root->right ==NULL){
      struct node *temp = root;
      root = root->left;
      delete temp;
      return root;
    }

    //Case 3 : Two children.
    else {
      struct node *temp = FindMin(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
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