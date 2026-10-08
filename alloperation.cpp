#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeginning(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at specific position
void insertPosition(int value, int position) {
    if (position == 1) {
        insertBeginning(value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete from specific position
void deletePosition(int position) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;

    delete deleteNode;
}

// Search an element
void search(int value) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Element found at position "
                 << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Element not found!" << endl;
}

// Display linked list
void display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    int choice, value, position;

    do {
        cout << "\n----- LINKED LIST MENU -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertEnd(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            insertPosition(value, position);
            break;

        case 4:
            deleteBeginning();
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> position;

            deletePosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;

            search(value);
            break;

        case 8:
            display();
            break;

        case 9:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 9);

    return 0;
}