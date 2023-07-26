#include <iostream>
using namespace std;

// A class to represent a node of a singly linked list
class Node {
public:
    int data; // The value stored in the node
    Node* next; // The pointer to the next node

    // A constructor to create a new node with a given value
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// A function to reverse a singly linked list iteratively
Node* reverseList(Node* head) {
    // If the list is empty or has only one node, return it as it is
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Create three pointers: prev, curr, and next
    Node* prev = NULL; // The previous node
    Node* curr = head; // The current node
    Node* next = NULL; // The next node

    // Traverse the list from left to right using curr
    while (curr != NULL) {
        // Store curr's next node in next
        next = curr->next;
        // Make curr's next pointer point to prev
        curr->next = prev;
        // Move prev and curr one step forward
        prev = curr;
        curr = next;
    }

    // Return prev as the new head of the reversed list
    return prev;
}

// A main function to test the algorithm
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Print the original list
    cout << "Original list: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Reverse the list and print the reversed list
    cout << "Reversed list: ";
    head = reverseList(head);
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
