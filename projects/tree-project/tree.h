#ifndef TREE_H

#include <vector>
#include <string>


class Node
{
private:
   int size() const;
   void print() const;
   std::string data;
   std::vector<Node*> children;
friend class Tree;   
};

class Tree
{
public:

   Tree();
   Tree(std::string root_data);
   void add_subtree(const Tree& subtree);
   int size() const;
   void print() const;

private:   
   Node* root;
};

#endif