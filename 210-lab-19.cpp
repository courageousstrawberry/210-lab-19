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
    void printR() {
        int count = 1;
        cout << "\t> Title: " << title << endl;
        Node *current = reviews;
        cout << "\t> Reviews:" << endl;
        while(current) {
            cout << count << ". " << current->rating << "/5.0, " << current->comment << endl;
            count++;
            current = current->next;
        }
    }
};

// Function declarations.
void addToHead(Node *&, Node *);

int main() {
    // Initialize the head and current nodes.
    Node *head = nullptr;
    Node *splitHead = nullptr;
    int count = 0;
    int movieCount = 1;

    srand(time(0));

    vector<Movie> movies;

    // Prompt user for movie review.
    ifstream file("comments.txt");
    if (file.is_open()) {
        string line;
        while(getline(file, line)){
            cout << "read line: " << line << endl;
            Node *current = new Node;
            current->comment = line;
            current->rating = 1.0 + ((rand() % 5001) / 1000.0); 
            current->next = nullptr;
            addToHead(head, current);
            count++;
            if(count == 3){
                splitHead = head;
                Movie movie("Movie " + to_string(movieCount), splitHead);
                movies.push_back(movie);
                movieCount++;

                for (int i = 0; i < 3; i++){
                    splitHead = splitHead->next;
                }
                count = 0;
            }
        }
        file.close();
    }
    else {
        cout << "Error. Unable to open file." << endl;
    }

    for (Movie movie : movies) {
        movie.printR();
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
