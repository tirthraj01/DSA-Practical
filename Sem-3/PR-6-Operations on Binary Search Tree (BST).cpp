
#include <iostream>
using namespace std;

// Create a node
struct Node {
    int data;
    Node *left, *right;
};

// Insert a new node
Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* temp = new Node;
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find height of tree
int height(Node* root) {
    if (root == NULL)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    if (l > r)
        return l + 1;
    else
        return r + 1;
}

// Find minimum value
int minimum(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root->data;
}

// Swap left and right pointers
void mirror(Node* root) {
    if (root == NULL)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Search a value
bool search(Node* root, int value) {
    if (root == NULL)
        return false;

    if (root->data == value)
        return true;

    return search(root->left, value) ||
           search(root->right, value);
}

// Display tree
void display(Node* root) {
    if (root != NULL) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    // Insert new node
    cout << "Enter value to insert: ";
    cin >> value;
    root = insert(root, value);

    // Find longest path
    cout << "Longest path (number of nodes): "
         << height(root) << endl;

    // Find minimum value
    cout << "Minimum value: " << minimum(root) << endl;

    // Mirror the tree
    mirror(root);
    cout << "Tree after mirroring: ";
    display(root);

    // Search a value
    cout << "\nEnter value to search: ";
    cin >> value;

    if (search(root, value))
        cout << "Value found!";
    else
        cout << "Value not found!";

    return 0;
}

Algorithm
1. Start.
2. Create an empty Binary Search Tree.
3. Read the number of nodes and insert the given values.
4. Insert a new node into the BST.
5. Find the longest path from the root by calculating the height of the tree.
6. Find the minimum value by moving towards the leftmost node.
7. Mirror the tree by swapping the left and right pointers of every node.
8. Display the mirrored tree.
9. Search for the given value.
10. Display whether the value is found or not.
11. Stop.
