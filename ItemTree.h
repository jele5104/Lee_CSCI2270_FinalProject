// Jeong Min Lee
// Final Project

#ifndef ITEMTREE_H
#define ITEMTREE_H

#include <vector>

struct ItemNode
{
    std::string item;
    int price;
    ItemNode *parent;
    ItemNode *leftChild;
    ItemNode *rightChild;

    ItemNode(){};

    ItemNode(std::string in_item, int in_price)
    {
        item = in_item;
        price = in_price;
    }
};

class ItemTree
{
    public:
        ItemTree();
        virtual ~ItemTree();
        void addItemNode(std::string item, int price);
        void deleteItemNode(std::string item);
        void findItem(std::string item);
        int countItemNodes();
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
        void printSold();

    protected:

    private:
        ItemNode* minimumNode(ItemNode *node);
        ItemNode* searchItemTree(ItemNode *node, std::string item);
        int countItemNodes(ItemNode *node);
        void printInOrder(ItemNode *node);
        void printPreOrder(ItemNode *node);
        void printPostOrder(ItemNode *node);
        void DeleteAll(ItemNode *node); //use this for the post-order traversal deletion of the tree

        ItemNode *root;
        int cnt;
        std::vector <std::string> soldList;
};

#endif // MOVIETREE_H
