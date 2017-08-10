#include <iostream>
using namespace std;

template <class Type>
class BSTNode
{
    public:
        BSTNode(Type key=0, BSTNode* parent=NULL, BSTNode* left=NULL, BSTNode* right=NULL);
        ~BSTNode();
    public:
        Type m_tKey;
        BSTNode* m_pParent;
        BSTNode* m_pLeft;
        BSTNode* m_pRight;
};

template <class Type>
BSTNode<Type>::BSTNode(Type key, BSTNode* parent, BSTNode* left, BSTNode* right)
: m_tKey(key)
, m_pParent(parent)
, m_pLeft(left)
, m_pRight(right)
{

}

template <class Type>
class BSTree
{
    public:
        BSTree();
        ~BSTree();
        void preOrder();
        void inOrder();
        void postOrder();
        BSTNode<Type>* rsearch(Type key);
        BSTNode<Type>* search(Type key);
        Type max();
        Type min();
        BSTNode<Type>* predeccessor(BSTNode<Type>* node);
        BSTNode<Type>* successor(BSTNode<Type>* node);
        void insert(Type key);
        bool remove(Type key);
    private:
        void preOrder(BSTNode<Type>* node) const;
        void inOrder(BSTNode<Type>* node) const;
        void postOrder(BSTNode<Type>* node) const;
        BSTNode<Type>* rsearch(BSTNode<Type>* node, Type key) const;
        BSTNode<Type>* search(BSTNode<Type>* node, Type key) const;
        BSTNode<Type>* max(BSTNode<Type>* node) const;
        BSTNode<Type>* min(BSTNode<Type>* node) const;
        void insert(BSTNode<Type>* node, BSTNode<Type>* inode);
        void remove(BSTNode<Type>* node);
    private:
        BSTNode<Type>* m_pRoot;
};

template <class Type>
BSTree<Type>::BSTree(): m_pRoot(NULL)
{
    
}

template <class Type>
BSTree<Type>::~BSTree()
{

}

template <class Type>
void BSTree<Type>::preOrder()
{
    preOrder(m_pRoot);
}

template <class Type>
void BSTree<Type>::preOrder(BSTNode<Type>* node) const
{
    if (node) {
        cout << node->m_tKey << " ";
        preOrder(node->m_pLeft);
        preOrder(node->m_pRight);
    }
}
template <class Type>
void BSTree<Type>::inOrder()
{
	inOrder(m_pRoot);
}

template <class Type>
void BSTree<Type>::inOrder(BSTNode<Type>* node) const
{
	if (node) {
        inOrder(node->m_pLeft);
        cout << node->m_tKey << " ";
        inOrder(node->m_pRight);
	}
}

template <class Type>
void BSTree<Type>::postOrder()
{
	postOrder(m_pRoot);
}

template <class Type>
void BSTree<Type>::postOrder(BSTNode<Type>* node) const
{
	if (node) {
        postOrder(node->m_pLeft);
        postOrder(node->m_pRight);
        cout << node->m_tKey << " ";
	}
}

template <class Type>
BSTNode<Type>* BSTree<Type>::rsearch(Type key)
{
    return rsearch(m_pRoot, key);
}

template <class Type>
BSTNode<Type>* BSTree<Type>::rsearch(BSTNode<Type>* node, Type key) const
{
    if (node == NULL || node->m_tKey == key) {
        return node;
    }
    if (key < node->m_pLeft) {
        return rsearch(node->m_pLeft, key);
    }
    else {
        return rsearch(node->m_pRight, key);
    }
}

template <class Type>
BSTNode<Type>* BSTree<Type>::search(Type key)
{
    return search(m_pRoot, key);
}

template <class Type>
BSTNode<Type>* BSTree<Type>::search(BSTNode<Type>* node, Type key) const
{
    while(node != NULL && node->m_tKey != key) {
        if (key < node->m_tKey) {
            node = node->m_pLeft;
        }
        else {
            node = node->m_pRight;
        }
    }
    return node;
}

template <class Type>
Type BSTree<Type>::max()
{
    BSTNode<Type>* node = max(m_pRoot);
    if (node) {
        return node->key;
    }
    return (Type)NULL;
}

template <class Type>
BSTNode<Type>* BSTree<Type>::max(BSTNode<Type>* node) const
{
    while (node != NULL && node->m_pRight) {
        node = node->m_pRight;
    }
    return node;
}


template <class Type>
Type BSTree<Type>::min()
{
    BSTNode<Type>* node = min(m_pRoot);
    if (node) {
        return node->m_tKey;
    }
    return (Type)NULL;
}

template <class Type>
BSTNode<Type>* BSTree<Type>::min(BSTNode<Type>* node) const
{
   while(node != NULL && node->m_pLeft) {
       node = node->m_pLeft;
   }
   return node;
}

/*
 *查找前驱结点，即小于node的最大结点
 * */
template <class Type>
BSTNode<Type>* BSTree<Type>:: predeccessor(BSTNode<Type>* node)
{
    if (node->m_pLeft) {
        return max(node->m_pLeft);
    }
    BSTNode<Type>* p = node->m_pParent;
    while(p != NULL && node == p->m_pLeft) {
        node = p;
        p = p->m_pParent;
    }
    return p;
}


/*
 *查找后继结点，即大于node的最小结点
 * */
template <class Type>
BSTNode<Type>* BSTree<Type>:: successor(BSTNode<Type>* node)
{
    if (node->m_pRight) {
        return min(node->m_pRight);
    }
    BSTNode<Type>* p = node->m_pParent;
    while(p != NULL && node == p->m_pRight) {
        node = p;
        p = p->m_pParent;
    }
    return p;
}

template <class Type>
void BSTree<Type>::insert(Type key)
{
    BSTNode<Type>* inode = new BSTNode<Type>(key, NULL, NULL, NULL);
    if (inode == NULL) {
       return; 
    }
    insert(m_pRoot, inode);
}

template <class Type>
void BSTree<Type>::insert(BSTNode<Type>* node, BSTNode<Type>* inode)
{
    if (node == NULL) {
        m_pRoot = inode;
        return;
    }
    BSTNode<Type>* parent;
    while (node) {
        parent = node;
        if (inode->m_tKey < node->m_tKey) {
            node = node->m_pLeft;
        }
        else {
            node = node->m_pRight;
        }
    }
    inode->m_pParent = parent;
    if (inode->m_tKey < parent->m_tKey) {
        parent->m_pLeft = inode;
    }
    else {
        parent->m_pRight = inode;
    }
}

template <class Type>
bool BSTree<Type>::remove(Type key)
{
    BSTNode<Type>* node = search(m_pRoot, key);
    if (node == NULL) {
        return false;
    }
    remove(node);
    return true;
}

template <class Type>
void BSTree<Type>::remove(BSTNode<Type>* node)
{
    BSTNode<Type>* node_handle = NULL;
    BSTNode<Type>* node_child = NULL;
    //如果node有一个(或没有)子结点，其父结点直接指向其子结点(若存在)
    if (node->m_pLeft == NULL || node->m_pRight == NULL) {
        node_handle = node;
    }
    //如果node有两个子结点，则使其与其后继结点交换
    else {
        node_handle = successor(node);
        node->m_tKey = node_handle->m_tKey;
    }

    if (node_handle->m_pLeft) {
        node_child = node_handle->m_pLeft;
    }
    else if (node_handle->m_pRight) {
        node_child = node_handle->m_pRight;
    }

    if (node_child != NULL) {
        node_child->m_pParent = node_handle->m_pParent;
    }

    if (node_handle->m_pParent == NULL) {
        node = node_child;
    }
    else if (node_handle->m_pParent->m_pLeft == node_handle) {
        node_handle->m_pParent->m_pLeft = node_child;
    }
    else {
        node_handle->m_pParent->m_pRight = node_child;
    }
}
