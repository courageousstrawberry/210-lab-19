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
    Node *reviews;
public:
    Movie(string t, Node* r) {
        title = t;
        reviews = r;
    }
    void print() {
        int count = 1;
        cout << "\t> Title: " << title;
        Node *current = reviews;
        cout << "\t> Reviews:" << endl;
        while(current) {
            cout << count << ". " << current->rating << "/5.0, " << current->comment << endl;
            count++;
        }
    }
};

// Function declarations.
void addToHead(Node *&, Node *);
double calcAverage(Node *&);

int main() {
    // Initialize the head and current nodes.
    Node *head = nullptr;
    Node *current = nullptr;
    int count = 0;

    vector<Movie> movies;

    // Prompt user for movie review.
    ifstream file("comments.txt");
    if (file.is_open()) {
        while(getline(file, current->comment)){
            current = new Node;
            srand(time(0));
            current->rating = 1.0 + ((rand() % 5001) / 1000.0); 
            current->next = nullptr;
            addToHead(head, current);
            count++;
            if(count == 3){
                Movie movie("Movie 1", head);
                movies.push_back(movie);
                head = nullptr;
                count = 0;
            }
        }
    }
    else {
        cout << "Error. Unable to open file." << endl;
    }

    for (Movie movie : movies) {
        movie.print();
    }

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