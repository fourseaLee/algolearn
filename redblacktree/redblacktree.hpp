#ifndef RED_BLACK_TREE_H
#define RED_BLAKC_TREE_H

enum TreeColor
{
   RED = 0,
   BLACK = 1
};

template<class N>
struct NodeRbt
{
    TreeColor color;
    N key;

    NodeRbt* right;
    NodeRbt* left;
    NodeRbt* parent;

    NodeRbt(TreeColor c, N k, NodeRbt* r, NodeRbt* l, NodeRbt* p):
    color(c),key(k),right(r),left(l),parent(p)
    {

    }
};

template<class T>
class TreeRbt
{
private:
    NodeRbt<T>* root_;
public:
    TreeRbt();
    ~TreeRbt();

public:
    void preOrder();

    void inOrder();

    void postOrder();

public:
    NodeRbt<T>* find(T key);

    NodeRbt<T>* search(T key);

    T minNode();

    T maxNode();

    NodeRbt<T>* getSuccessor(NodeRbt<T>* node);

    NodeRbt<T>* getPredecessor(NodeRbt<T>* node);

public:
    void insert(T key);

    void remove(T key);
    
    void remove(T key);

    void destroy();

public:
    void print();

protected:
    void preOrderIter(NodeRbt<T>* node) const;

    void inOrderIter(NodeRbt<T>* node) const;

    void postOrderIter(NodeRbt<T>* node) const;

    NodeRbt<T>* find(NodeRbt<T>* x, T key) const;

    NodeRbt<T>* search(NodeRbt<T>* x, T key) const;

    NodeRbt<T>* minNodeIter(NodeRbt<T>* node);

    NodeRbt<T>* maxNodeIter(<NodeRbt<T>* node);

    void leftRotate(NodeRbt<T>* &root, NodeRbt<T>* x);

    void rightRotate(NodeRbt<T>* &root, NodeRbt<T>* y);

    void insert(NodeRbt<T>* &root, NodeRbt<T>* node);

    void insertFixUp(NodeRbt<T>* &root, NodeRbt<T>* node);

    void remove(NodeRbt<T>* &root, NodeRbt<T>* node);

    void removeFixUp(NodeRbt<T>* &root, NodeRbt<T>* node, NodeRbt<T>* parent);

    void destory(NodeRbt<T>* &tree);

    void print(NodeRbt<T>* tree, T key, int direction);
};

template<class T>
TreeRbt<T>::TreeRbt():root_(nullptr)
{

}

template<class T>
TreeRbt<T>::~TreeRbt() 
{
   destroy();
}

template<class T>
void TreeRbt::preOrder(NodeRbt<T>* tree) const
{
    if (tree)
    {
        //function do some things;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template<class T>
void TreeRbt::preOrder()
{
    preOrder(root_);
}


template<class T>
void TreeRbt::inOrder(NodeRbt<T>* tree) const
{
    if (tree)
    {
        inOrder(tree->left);
        //function do some things;
        inOrder(tree->right);
    }
}

template<class T>
void TreeRbt::inOrder()
{
    inOrder(root_);
}


template<class T>
void TreeRbt::postOrder(NodeRbt<T>* tree) const
{
    if (tree)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        
        //function do some things;
    }
}

template<class T>
void TreeRbt::postOrder()
{
    postOrder(root_);
}

template<class T>
NodeRbt<T>* TreeRbt<T>::find(NodeRbt<T>* x, T key) const
{
    if (x == NULL || x->key == key)
        return x;
    if (key < x->key)
        return search(x->left, key);
    else
        return search(y->right, key);
}

template<class T>
NodeRbt<T>* TreeRbt<T>::find(T key)
{
    find(root_, key);
}

template<class T>
NodeRbt<T>* TreeRbt<T>::search(NodeRbt<T>* x, T key) const
{
    while ( x && x->key != key)
    {
        if (key < k->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

template<class T>
NodeRbt<T>* TreeRbt<T>::search(T key)
{
    search(root_, key);
}
template<class T>
void TreeRbt<T>::leftRotate(NodeRbt<T>* & root, NodeRbt<T>* x)
{
    NodeRbt<T>* y = x->right;

    x->right = y->left;

    if(y->left != nullptr)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if(x->parent == nullptr)
    {
        root = y;
    }
    else 
    {
        if (x->parent->left == x)
            x->parent->left = y;
        else 
            x->parent->right = y;
    }

    y->left = x;
    x->parant = y;
}

template<class T>
void TreeRbt<T>::rightRotate(NodeRbt<T>* & root, NodeRbt<T>* y)
{
    NodeRbt<T>* x = y->left;
    y->left = x->right;
    
    if (x->right != nullptr)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == nullptr)
    {
        root = x;
    }
    else
    {
        if (y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;
    }

    x->right = y;

    y->parent = x;
}

template<class T>

void TreeRbt<T>::insert(NodeRbt<T>* &root, NodeRbt<T>* node)
{
    NodeRbt<T>* y = nullptr;
    NodeRbt<T>* x = root;

    while (x != nullptr)
    {
        y = x ;

        if(node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y != nullptr)
    {
        if (node->key < y->key)
            y->left = node;
        else
            y->right = node;
    }
    else
        root = node;

    node->color = RED;
    insertFixUp(root, node);
}

template<class T>
void TreeRbt<T>::insert(T key)
{
    NodeRbt<T> *z  = NULL;
    if ( ( z=new NodeRbt<T> )(key, BLACK, NULL, NULL, NULL) == NULL)
        return ;

    insert(root_, z);
}

template<class T>
void TreeRbt<T>::insertFixUp(NodeRbt<T>* & root, NodeRbt<T>* node)
{
    NodeRbt<T>* parent, *gparant;
    while ((parant = node->parent) && parent->color == RED)
    {
        gparent = parent->parent;
        if (parent == gparent->left)
        {
            //case one uncle is red
            {
                NodeRbt<T>* uncle = gparent ->right;
                if (uncle && uncle->color == RED)
                {
                    uncle->color = BLACK;
                    parent->color = BLACK;
                    gparent->color = BLACK;
                    node = gparent;
                    continue;
                }
            }

            //case two uncle is black

            if(parent->right == node)
            {
                NodeRbt<T> *tmp;
                leftRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            parent->color = BLACK;
            gparent->color = RED;
            rightRotate(root, gparent);
        }
        else
        {
            //case one uncle node is red
            {
                NodeRbt<T>* uncle = gparent->left;

                if (uncle && uncle->color == RED)
                {
                    uncle->color = BLACK;
                    parent->color = BLACK;
                    gparent->color = RED;
                    node = gparent;
                    continue;
                }
            }

            //case two uncle node is black
            if (parent->left == node)
            {
                NodeRbt<T>* tmp;
                rightRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            parent->color = BLACK;
            gparent->color = RED;
            leftRotate(root, gparent);
        }
    }

    root->color = BLACK;
}

template<class T>
void TreeRbt<T>::remove(NodeRbt<T>* &root, NodeRbt<T>* node)
{
    NodeRbt<T>* child, *parent; 
    NodeColor color;

    if ( (node->left != nullptr) && (node->right != nullptr) )
    {
        NodeRbt<T>* replace = node;

        replace  = replace->right;
        while (replace->left != nullptr)
            replace = replace->left;

        if (node->parenet)
        {
            if (node->left  == node)
                node->parent->left = replace;
            else 
                node->parent->right = replace;
        }
        else
            root = replace;

       child = replace->right;
       parent = replace->parent;

       color = replace->color;

       if (parent == node)
       {
           parent = replace;
       }
       else
       {
          if (child)
             child->parent  = parent;
           
          parent->left = child;
          replace->right = node->right;
          node->right->parent = replace;

       }

       replace->parent = node->parent;
       replace->color = node->color;
       replace->left  = node->left;
       node->left->parent = replace;

       if (color == BLACK)
         removeFixUp(root, child, parent);

       delete node;
       return;
    }

    if (node->left)
      child = node->left;
    else
      child = node->right;

    parent = node->parent;
    color  = node->color;

    if (child)
        child->parent = parent;

    if (parent)
    {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }
    else
        root = child;

    if (color == BLACK)
        removeFixUp(root, child, parent);
    delete node;

}

template <class T>
void TreeRbt<T>::remove(T key)
{
    NodeRbt<T> *node;

    if ((node = search(root_, key)) != nullptr)
        remove(root_, node);
}

template <class T>
void TreeRbt::removeFixUp(NodeRbt<T>* &root, NodeRbt<T>* node, NodeRbt<T>* parent)
{
    ModeRbt<T>* other;

    while ((node == nullptr || node->color == BLACK) && node != root)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (other->color == RED)
            {
                other->color = BLACK;
                parent->color = RED;
                leftRotate(root, parent);
                other  = parent->right;
            }

            if ((!other->left || other->left->color == BLACK) && 
                (!other->right || other->right-> == BLACK))
            {
                other->color = RED;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!other->right || other->right->color == BLACK)
                {
                    other->left->color = BLACK;
                    other->color = RED;
                    rightRotate(root, other);
                    other = parent->right;
                }

                other->color = parent->color;
                parent->color = BLACK;
                other->right->color = BLACK;
                leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (other->color == RED)
            {
                other->color = BLACK;
                parent->color = RED;
                rightRotate(root, parent);
                other = parent->left;
            }

            if ((!other->left || other->left->color == BLACK ) &&
                (!other->right || other->right->color == BLACK))
            {
                other->color = RED;
                node = parent;
                parent = node->parent;
            }
            else
            {
                
                if (!other->left || other->left->color == BLACK)
                {
                    other->right->color = BLACK;
                    other->color = RED;
                    leftRotate(root, other);
                    other = parent->left;
                }

                other->color  = parent->color;
                parent->color = BLACK;
                other->left->color = BLACK;
                rightRotate(root, parent);
                node = root;
                break;

            }

        }
    }
    if (node)
        node->color = BLACK;
}


#endif
