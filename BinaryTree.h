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
    void remove(T key);
    node<T> * minimum();
    node<T> * next(node<T> * leaf);
    node<T> * prev(node<T> * leaf);

private:
    node<T> * root;
    node<T> * r_search(T key, node<T> * leaf);
    void r_insert(T key, node<T> * leaf);
    node<T> * initNode(T key);
    node<T> * r_minimum(node<T> *leaf);
};


template <class T>
binaryTree<T>::binaryTree() {

}

template <class T>
inline node<T> * binaryTree<T>::initNode(T key) {
    node<T> *leaf = new node<T>();
    leaf->data = key;
    leaf->left = NULL;
    leaf->right = NULL;
    leaf->parent = NULL;
    return leaf;
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
    if (leaf == NULL) {
        return NULL;
    }
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
void binaryTree<T>::insert(T key) {
    if (root != NULL) {
        r_insert(key, root);
    }
    else {
        root = initNode(key);
    }
}

template <class T>
void binaryTree<T>::r_insert(T key, node<T> *leaf) {

    if (key > leaf->data) {
        if (leaf->right == NULL) {
            node<T> *newnode = initNode(key);
            newnode->parent = leaf;
            leaf->right = newnode;
        }
        else {
            r_insert(key, leaf->right);
        }
    }
    else {
        if (leaf->left == NULL) {
            node<T> *newnode = initNode(key);
            newnode->parent = leaf;
            leaf->left = newnode;
        }
        else {
            r_insert(key, leaf->left);
        }        
    }            
}

template <class T>
void binaryTree<T>::remove(T key) {
    node<T> *del = search(key);
    if (del != NULL) {
        // no children
        if (del->left == NULL && del->right == NULL) {
            if (del->parent->key >= del->key) {
                del->parent->left = NULL;
            }
            else {
                del->parent->right = NULL;
            }
        }
        // one child
        else if (del->left == NULL && del->right != NULL) {
            del->parent->right = del->right;
            del->right->parent = del->parent;
        }
        else if (del->left != NULL && del->right == NULL) {
            del->parent->left = del->left;
            del->left->parent = del->parent;
        }
        // two children
        else {
            node temp = r_minimum(del->right);
            del->data = temp->data;
            temp->parent
        }

        delete del;
    }
    else
    {
        return NULL;
    }
}

template <class T>
node<T> * binaryTree<T>::minimum() {
    if (root == NULL) {
        return NULL;
    }
    else {
        return r_minimum(root);
    }
}

template <class T>
node<T> * binaryTree<T>::r_minimum(node<T> * leaf) {
    if (leaf->left == NULL) {
        return leaf;
    }
    else {
        return r_minimum(leaf->left);
    }
}

template <class T>
node<T> * binaryTree<T>::next(node<T> * leaf) {
    if (leaf == NULL) {
        return NULL;
    }
    if (leaf->right != NULL) {
        return minimum(leaf->right);
    }
    else {

        while (leaf->parent->left != leaf) {
            leaf = 
        }
        else {

        }
    }
}

template <class T>
node<T> * binaryTree<T>::prev(node<T> * leaf) {

}

#endif ALGORITHMS_BINARYTREE_H_

