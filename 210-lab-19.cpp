#include <iostream>
#include <limits>

using namespace std;

// Create node struct with double and string variables.
struct Node {
    double rating;
    string comment;
    Node* next;
};

// Function declarations.
void addToTail(Node *&, Node *);
void addToHead(Node *&, Node *);
double calcAverage(Node *&);

int main() {
    int choice = 0;
    char repeat = 'Y';
    // Initialize the head and current nodes.
    Node *head = nullptr;
    Node *current = nullptr;

    // Prompt user to pick 1 or 2.
    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list." << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list." << endl;
    cout << "Choice: ";
    // While loop for input validation.
    while (!(cin >> choice)|| (choice != 1 && choice !=2)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Error Invalid input. Enter 1 or 2: ";
    }
    
    // While the user's choice to repeat is yes, create a new node in the linked list.
    while (repeat == 'Y') {
        current = new Node;

        // Prompt user for review rating and do input validation.
        cout << "Enter review rating 0-5: ";
        while (!(cin >> current->rating)|| current->rating < 0 || current->rating > 5){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Error Invalid input. Enter 1 or 2: ";
        }

        cin.ignore();
        // Prompt user for movie review.
        cout << "Enter review comments: ";
        getline(cin, current->comment);
        current->next = nullptr;

        // Depending on if the user picked 1 or 2, run a function to add the node to linked list.
        if (choice == 1) {
            addToHead(head, current);
        }
        else if (choice == 2) {
            addToTail(head, current);
        }
        // Ask if user wants to add another review.
        cout << "Enter another review? Y/N: ";
        cin >> repeat;
        repeat = toupper(repeat);
        // Input validation to check if user enters 1 or 2.
        while (repeat != 'Y' && repeat != 'N') {
            cout << "Error! Please enter Y or N." << endl;
            cin >> repeat;
            repeat = toupper(repeat);
        }
    }

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

// Function that adds a node to the tail of a linked list.
void addToTail(Node *&head, Node *add){
    // If the head doesn't exist, set the head to the new node.
    if (!head){
        head = add;
    }
    else {
        //Otherwise, loop to the end of the linked list.
        Node *temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        // Make the last node point to the new node.
        temp->next = add;
    }
    // Make the new node point to nullptr.
    add->next = nullptr;
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