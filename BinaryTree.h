#ifndef ALGORITHMS_BINARYTREE_H_
#define ALGORITHMS_BINARYTREE_H_

template <class N>
class node {
public:
    node *left;
    node *right;
    node *parent;
    N data;
};

template <class T>
class binaryTree {
public:
    binaryTree<T>();

    node<T> * search(T key);
    void insert(T key);

private:
    node<T> * root;
    node<T> * r_search(T key, node<T> * leaf);
    void r_insert(T key, node<T> * leaf);
    node<T> * initNode(T key);
};


template <class T>
binaryTree<T>::binaryTree() {

}

template <class T>
inline node<T> * binaryTree<T>::initNode(T key) {
    node<T> leaf = new node<T>();
    leaf->data = key;
    leaf->left = NULL;
    left->right = NULL;
    left->parent = NULL;
    return leaf;
}

template <class T>
void binaryTree<T>::insert(T key) {
    if (root != NULL) {
        r_insert(key, root);
    }
    else {
        root = initNode(key);
    }
}


template <class T>
node<T> * binaryTree<T>::search(T key) {
    if (root != NULL) {
        return r_search(key, root);
    }    
    else
    {
        return NULL;
    }
}

template <class T>
node<T> * binaryTree<T>::r_search(T key, node<T> * leaf) {
    if (leaf->data == key) {
        return leaf;
    }
    else if (leaf->data < key) {
        r_search(key, leaf->right);
    }
    else {
        r_search(key, leaf->left);
    }
}

template <class T>
void binaryTree<T>::r_insert(T key, node<T> *leaf) {

    else if (key > leaf->data) {
        if (leaf->right == NULL) {
            node<T> newnode = initNode(key);
            newnode->parent = leaf;
            leaf->right = newnode;            
        } 
        else {
            r_insert(key, leaf->right);
        }        
    }
    else {
        r_insert(key, leaf->left);
    }
}

#endif ALGORITHMS_BINARYTREE_H_

