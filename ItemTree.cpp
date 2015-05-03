// Jeong Min Lee
// Final Project

#include <iostream>
#include "ItemTree.h"
#include <vector>

using namespace std;

ItemTree::ItemTree()
{
    root = NULL;
}

ItemTree::~ItemTree()
{
    DeleteAll(root);
}

void ItemTree::addItemNode(string item, int price)
{
    ItemNode *next = new ItemNode(item, price);
    ItemNode *x = root;
    ItemNode *P = NULL;

    if (x == NULL)
    {
        root = next;
        root->parent = NULL;
        root->leftChild = NULL;
        root->rightChild = NULL;
    }
    else
    {
        while (x != NULL)
        {
            P = x;
            if (item.compare(x->item) < 0)
            {
                x = x->leftChild;
            }
            else
            {
                x = x->rightChild;
            }
        }

        next->parent = P;
        next->leftChild = NULL;
        next->rightChild = NULL;
        if (item.compare(P->item) < 0)
        {
            P->leftChild = next;
        }
        else
        {
            P->rightChild = next;
        }
    }
}

void ItemTree::deleteItemSoldNode(string item)
{
    ItemNode *nodeDelete = searchItemTree(root, item);

    if (nodeDelete == NULL)
    {
        cout << "Item not found." << endl;
    }
    else
    {
        soldList.push_back(nodeDelete->item);

        if (nodeDelete->leftChild==NULL || nodeDelete->rightChild==NULL)
        {
            // No Children
            if (nodeDelete->leftChild==NULL && nodeDelete->rightChild==NULL)
            {
                if (nodeDelete == nodeDelete->parent->leftChild)
                {
                    nodeDelete->parent->leftChild = NULL;
                }
                else if (nodeDelete == nodeDelete->parent->rightChild)
                {
                    nodeDelete->parent->rightChild = NULL;
                }

                delete nodeDelete;
            }
            // One child
            else
            {
                if (nodeDelete->leftChild == NULL)
                {
                    if (nodeDelete == nodeDelete->parent->leftChild)
                    {
                        nodeDelete->parent->leftChild = nodeDelete->rightChild;
                    }
                    else if (nodeDelete == nodeDelete->parent->rightChild)
                    {
                        nodeDelete->parent->rightChild = nodeDelete->rightChild;
                    }
                }
                else if (nodeDelete->rightChild == NULL)
                {
                    if (nodeDelete == nodeDelete->parent->leftChild)
                    {
                        nodeDelete->parent->leftChild = nodeDelete->leftChild;
                    }
                    else if (nodeDelete == nodeDelete->parent->rightChild)
                    {
                        nodeDelete->parent->rightChild = nodeDelete->leftChild;
                    }
                }

                delete nodeDelete;
            }
        }
        // Two children
        else if (nodeDelete->leftChild!=NULL && nodeDelete->rightChild!=NULL)
        {
            ItemNode *replNode = minimumNode(nodeDelete->rightChild);
            nodeDelete->item = replNode->item;
            nodeDelete->price = replNode->price;

            if (replNode->rightChild != NULL)
            {
                replNode->rightChild->parent = replNode->parent;
            }
            if (replNode == replNode->parent->leftChild)
            {
                replNode->parent->leftChild = replNode->rightChild;
            }
            else if (replNode == replNode->parent->rightChild)
            {
                replNode->parent->rightChild = replNode->rightChild;
            }

            delete replNode;
        }
    }
}

void ItemTree::deleteItemNotSoldNode(string item)
{
    ItemNode *nodeDelete = searchItemTree(root, item);

    if (nodeDelete == NULL)
    {
        cout << "Item not found." << endl;
    }
    else
    {
        if (nodeDelete->leftChild==NULL || nodeDelete->rightChild==NULL)
        {
            // No Children
            if (nodeDelete->leftChild==NULL && nodeDelete->rightChild==NULL)
            {
                if (nodeDelete == nodeDelete->parent->leftChild)
                {
                    nodeDelete->parent->leftChild = NULL;
                }
                else if (nodeDelete == nodeDelete->parent->rightChild)
                {
                    nodeDelete->parent->rightChild = NULL;
                }

                delete nodeDelete;
            }
            // One child
            else
            {
                if (nodeDelete->leftChild == NULL)
                {
                        if (nodeDelete == nodeDelete->parent->leftChild)
                    {
                        nodeDelete->parent->leftChild = nodeDelete->rightChild;
                    }
                    else if (nodeDelete == nodeDelete->parent->rightChild)
                    {
                        nodeDelete->parent->rightChild = nodeDelete->rightChild;
                    }
                }
                else if (nodeDelete->rightChild == NULL)
                {
                    if (nodeDelete == nodeDelete->parent->leftChild)
                    {
                        nodeDelete->parent->leftChild = nodeDelete->leftChild;
                    }
                    else if (nodeDelete == nodeDelete->parent->rightChild)
                    {
                        nodeDelete->parent->rightChild = nodeDelete->leftChild;
                    }
                }

                delete nodeDelete;
            }
        }
        // Two children
            else if (nodeDelete->leftChild!=NULL && nodeDelete->rightChild!=NULL)
        {
            ItemNode *replNode = minimumNode(nodeDelete->rightChild);
            nodeDelete->item = replNode->item;
            nodeDelete->price = replNode->price;

            if (replNode->rightChild != NULL)
            {
                replNode->rightChild->parent = replNode->parent;
            }
            if (replNode == replNode->parent->leftChild)
            {
                replNode->parent->leftChild = replNode->rightChild;
            }
            else if (replNode == replNode->parent->rightChild)
            {
                replNode->parent->rightChild = replNode->rightChild;
            }

            delete replNode;
        }
    }
}

ItemNode* ItemTree::minimumNode(ItemNode *node)
{
    while (node->leftChild != NULL)
    {
        node = node->leftChild;
    }

    return node;
}

void ItemTree::findItem(string item)
{
    if (searchItemTree(root, item) == NULL)
    {
        cout << "Item not found" << endl;
    }
    else
    {
        cout << "Item Information:" << endl
             << "******************" << endl
             << "Item:" << searchItemTree(root, item)->item << endl
             << "Price:" << searchItemTree(root, item)->price << endl;
    }
}

ItemNode* ItemTree::searchItemTree(ItemNode *node, string item)
{
    if (node == NULL)
    {
        return node;
    }
    else if (node->item == item)
    {
        return node;
    }
    else
    {
        if (node->item.compare(item) <= 0)
        {
            return searchItemTree(node->rightChild, item);
        }
        else
        {
            return searchItemTree(node->leftChild, item);
        }
    }
}

int ItemTree::countItemNodes()
{
    cnt = 0;
    countItemNodes(root);

    return cnt;
}

int ItemTree::countItemNodes(ItemNode *node)
{
    if (node->leftChild != NULL)
    {
        countItemNodes(node->leftChild);
    }

    cnt++;

    if (node->rightChild != NULL)
    {
        countItemNodes(node->rightChild);
    }
}

void ItemTree::printInOrder()
{
    if (root == NULL)
    {
        cout << "List empty" << endl;
    }
    else
    {
        cout << "<ITEM:PRICE>" << endl;
        printInOrder(root);
    }
}

void ItemTree::printInOrder(ItemNode *node)
{
    if (node->leftChild != NULL)
    {
        printInOrder(node->leftChild);
    }

    cout << node->item << ":" << node->price << endl;

    if (node->rightChild != NULL)
    {
        printInOrder(node->rightChild);
    }
}

void ItemTree::printPreOrder()
{
    if (root == NULL)
    {
        cout << "List empty" << endl;
    }
    else
    {
        cout << "<ITEM:PRICE>" << endl;
        printPreOrder(root);
    }
}

void ItemTree::printPreOrder(ItemNode *node)
{
    cout << node->item << ":" << node->price << endl;

    if (node->leftChild != NULL)
    {
        printPreOrder(node->leftChild);
    }

    if (node->rightChild != NULL)
    {
        printPreOrder(node->rightChild);
    }
}

void ItemTree::printPostOrder()
{
    if (root == NULL)
    {
        cout << "List empty" << endl;
    }
    else
    {
        cout << "<ITEM:PRICE>" << endl;
        printPostOrder(root);
    }
}

void ItemTree::printPostOrder(ItemNode *node)
{
    if (node->leftChild != NULL)
    {
        printPostOrder(node->leftChild);
    }

    if (node->rightChild != NULL)
    {
        printPostOrder(node->rightChild);
    }

    cout << node->item << ":" << node->price << endl;
}

void ItemTree::printSold()
{
    if (soldList.size() == 0)
    {
        cout << "List of sold items unavailable" << endl;
    }
    else
    {
        cout << "<ITEM>" << endl;

        for (int i=0; i<soldList.size(); i++)
        {
            cout << soldList[i] << endl;
        }
    }
}

void ItemTree::DeleteAll(ItemNode *node)
{
    if (node->leftChild != NULL)
    {
        DeleteAll(node->leftChild);
    }

    if (node->rightChild != NULL)
    {
        DeleteAll(node->rightChild);
    }

    delete node;
}
