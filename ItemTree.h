// Jeong Min Lee
// Final Project

#ifndef ITEMTREE_H
#define ITEMTREE_H

#include <vector>

struct ItemNode
{
    std::string item;
    int price;
    std::string category;
    ItemNode *parent;
    ItemNode *leftChild;
    ItemNode *rightChild;

    ItemNode(){};

    ItemNode(std::string in_item, int in_price, std::string in_cat)
    {
        item = in_item;
        price = in_price;
        category = in_cat;
    }
};

class ItemTree
{
    public:
        ItemTree();
        virtual ~ItemTree();
        void addItemNode(std::string item, int price, std::string cat);
        void deleteItemNode(std::string item);
        void findItem(std::string item);
        int countItemNodes();
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
        void printSold();
        void printFromCat(std::string cat);

    protected:

    private:
        ItemNode* minimumNode(ItemNode *node);
        ItemNode* searchItemTree(ItemNode *node, std::string item);
        int countItemNodes(ItemNode *node);
        void printInOrder(ItemNode *node);
        void printPreOrder(ItemNode *node);
        void printPostOrder(ItemNode *node);
        void DeleteAll(ItemNode *node); //use this for the post-order traversal deletion of the tree
        void printFromCat(ItemNode *node, std::string cat);

        ItemNode *root;
        int cnt;
        std::vector <std::string> soldList;
};

#endif // MOVIETREE_H
