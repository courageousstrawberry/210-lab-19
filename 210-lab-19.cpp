#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Create node struct with double and string variables.
struct Node {
    double rating;
    string comment;
    Node* next;
};

class Movie {
private:
    string title;
    Node *review;
public:
};

// Function declarations.
void addToHead(Node *&, Node *);
double calcAverage(Node *&);

int main() {
    int choice = 0;
    char repeat = 'Y';
    // Initialize the head and current nodes.
    Node *head = nullptr;
    Node *current = nullptr;

    current = new Node;

    // fix
    srand(time(0));
    current->rating = rand() % 5; 

    // Prompt user for movie review.
    cout << "Enter review comments: ";
    getline(cin, current->comment);
    current->next = nullptr;


    addToHead(head, current);

    // Once user enters no, output all the reviews.
    int count = 1;
    current = head; // Set current to point to head.
    cout << "\nOutputting all reviews:" << endl;
    while(current) {
        cout << "\t> Review #" << count << ": " << current->rating << ": " << current->comment << endl;
        count++;
        current = current->next;
    }
    // Output the average of the reviews after running the function.
    cout << "\t> Average: " << calcAverage(head);

    return 0;
}

// Function to add a node to the head of a linked list.
void addToHead(Node *&head, Node *add){
    // If the head doesn't exist, set the head to the new node.
    if (!head){
        head = add;
    }
    else {
        // Otherwise, make the new pointer point to head.
        add->next = head;
        // Update the head to point to the new pointer.
        head = add;
    }
}

// Function to calculate the average ratings.
double calcAverage(Node *&head) {
    Node *current = head;
    double total = 0;
    int count = 0;
    // Loop through each value of the linked list.
    while(current) {
        // Keep track of the total ratings.
        total += current->rating;
        // Keep track of the number of ratings.
        count++;
        current = current->next;
    }
    // Return the average.
    return (total/count);
}