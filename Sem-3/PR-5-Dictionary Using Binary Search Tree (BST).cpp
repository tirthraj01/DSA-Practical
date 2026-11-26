
#include <iostream>
using namespace std;

// Structure of each node
struct Node {
    string key, meaning;
    Node *left, *right;
};

// Add keyword
Node* insert(Node* root, string key, string meaning) {
    if (root == NULL) {
        Node* temp = new Node;
        temp->key = key;
        temp->meaning = meaning;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (key < root->key)
        root->left = insert(root->left, key, meaning);
    else if (key > root->key)
        root->right = insert(root->right, key, meaning);
    else
        root->meaning = meaning;

    return root;
}

// Search keyword
Node* search(Node* root, string key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Delete keyword
Node* deleteNode(Node* root, string key) {
    if (root == NULL)
        return NULL;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;

        while (temp->left != NULL)
            temp = temp->left;

        root->key = temp->key;
        root->meaning = temp->meaning;

        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Display ascending order
void ascending(Node* root) {
    if (root != NULL) {
        ascending(root->left);
        cout << root->key << " : " << root->meaning << endl;
        ascending(root->right);
    }
}

// Display descending order
void descending(Node* root) {
    if (root != NULL) {
        descending(root->right);
        cout << root->key << " : " << root->meaning << endl;
        descending(root->left);
    }
}

// Find height of tree
int height(Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if (left > right)
        return left + 1;

    return right + 1;
}

int main() {
    Node* root = NULL;
    int choice;
    string key, meaning;

    do {
        cout << "\n1. Add Keyword";
        cout << "\n2. Delete Keyword";
        cout << "\n3. Update Meaning";
        cout << "\n4. Ascending Order";
        cout << "\n5. Descending Order";
        cout << "\n6. Maximum Comparisons";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter keyword: ";
            cin >> key;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, meaning);

            root = insert(root, key, meaning);
            cout << "Keyword added!";
            break;

        case 2:
            cout << "Enter keyword to delete: ";
            cin >> key;

            if (search(root, key) != NULL) {
                root = deleteNode(root, key);
                cout << "Keyword deleted!";
            } else {
                cout << "Keyword not found!";
            }
            break;

        case 3: {
            cout << "Enter keyword to update: ";
            cin >> key;

            Node* temp = search(root, key);

            if (temp != NULL) {
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, meaning);
                temp->meaning = meaning;
                cout << "Meaning updated!";
            } else {
                cout << "Keyword not found!";
            }
            break;
        }

        case 4:
            cout << "\nAscending Order:\n";
            ascending(root);
            break;

        case 5:
            cout << "\nDescending Order:\n";
            descending(root);
            break;

        case 6:
            cout << "Maximum comparisons: " << height(root);
            break;

        case 7:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 7);

    return 0;
}
