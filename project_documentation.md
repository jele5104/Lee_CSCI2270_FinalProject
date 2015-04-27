# Methods In Library

## addItemNode



```javascript
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
```


## deleteItemNode

```javascript
void ItemTree::deleteItemNode(string item)
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
```
