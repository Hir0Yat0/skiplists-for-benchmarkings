#ifndef SKIPLISTS_HPP
#define SKIPLISTS_HPP

#include <vector>

namespace skiplists {
    
constexpr int maxNumberOfLevel = 64; // Maximum Level of the skip list

class Node {

    public:

    int data;
    std::vector<Node*> next;     // To maintain the levels of the skip list
    Node(int data, int level) : data(data), next(level + 1, nullptr) {} // declaring the data and the level of the node 

};

class SkipList  {

    private:

    Node* head; 
    int Level;

    public:

    SkipList();

    void insert(const int data);  // To insert the value 
    void remove(const int data);  // To delete the value
    bool search(const int data) const ;  // To search for a value
    void display(void) const ;         // Function to display a skip List

};

} // namespace skiplists

#endif // SKIPLISTS_HPP
