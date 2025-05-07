#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string word, meaning;
    Node *left, *right;

    Node(string w, string m) {
        word = w;
        meaning = m;
        left = right = NULL;
    }
};

class Dictionary {
    Node *root;

    // Helper for Inorder (Ascending)
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->word << " = " << node->meaning << endl;
        inorder(node->right);
    }

    // Helper for Reverse Inorder (Descending)
    void reverseInorder(Node* node) {
        if (!node) return;
        reverseInorder(node->right);
        cout << node->word << " = " << node->meaning << endl;
        reverseInorder(node->left);
    }

    // Helper for Deletion
    Node* deleteNode(Node* root, string key) {
        if (!root) return root;

        if (key < root->word)
            root->left = deleteNode(root->left, key);
        else if (key > root->word)
            root->right = deleteNode(root->right, key);
        else {
            // Node found
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Two children: get inorder successor
            Node* temp = root->right;
            while (temp->left) temp = temp->left;

            root->word = temp->word;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->word);
        }
        return root;
    }

public:
    Dictionary() {
        root = NULL;
    }

    void insert(string word, string meaning) {
        Node* newNode = new Node(word, meaning);
        if (!root) {
            root = newNode;
            return;
        }

        Node* current = root;
        while (true) {
            if (word < current->word) {
                if (!current->left) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            } else if (word > current->word) {
                if (!current->right) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            } else {
                cout << "Word already exists.\n";
                delete newNode;
                return;
            }
        }
    }

    void search(string word) {
        Node* current = root;
        int comparisons = 0;
        while (current) {
            comparisons++;
            if (current->word == word) {
                cout << "Found: " << current->word << " = " << current->meaning << endl;
                cout << "Comparisons made: " << comparisons << endl;
                return;
            }
            current = (word < current->word) ? current->left : current->right;
        }
        cout << "Word not found. Comparisons made: " << comparisons << endl;
    }

    void update(string word, string newMeaning) {
        Node* current = root;
        while (current) {
            if (current->word == word) {
                current->meaning = newMeaning;
                cout << "Meaning updated!\n";
                return;
            }
            current = (word < current->word) ? current->left : current->right;
        }
        cout << "Word not found.\n";
    }

    void deleteWord(string word) {
        root = deleteNode(root, word);
        cout << "Word deleted (if it existed).\n";
    }

    void displayAscending() {
        inorder(root);
    }

    void displayDescending() {
        reverseInorder(root);
    }
};

int main() {
    Dictionary dict;
    int choice;
    string word, meaning;

    while (true) {
        cout << "\n--- Dictionary Menu ---\n";
        cout << "1. Add Word\n2. Search Word\n3. Update Meaning\n4. Delete Word\n5. Display Ascending\n6. Display Descending\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word: ";
                cin >> word;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                dict.insert(word, meaning);
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> word;
                dict.search(word);
                break;
            case 3:
                cout << "Enter word to update: ";
                cin >> word;
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, meaning);
                dict.update(word, meaning);
                break;
            case 4:
                cout << "Enter word to delete: ";
                cin >> word;
                dict.deleteWord(word);
                break;
            case 5:
                cout << "\nDictionary in Ascending Order:\n";
                dict.displayAscending();
                break;
            case 6:
                cout << "\nDictionary in Descending Order:\n";
                dict.displayDescending();
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
