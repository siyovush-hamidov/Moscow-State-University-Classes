#include <iostream>

using namespace std;

class TreeSort
{
    struct Node
    {
        int Key;
        Node *left_node, *right_node;
    };
    public: 
    Node *root;
    TreeSort();
    void add_node_to_tree(Node *&, int);
    void print_left_root_right(Node *);
    void print_the_tree(Node*, short, short, short, char);
};

int main()
{
    return 0;
}