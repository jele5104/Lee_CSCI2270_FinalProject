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
