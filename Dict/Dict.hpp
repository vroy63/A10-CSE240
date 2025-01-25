#ifndef DICT_HPP
#define DICT_HPP

#include <iostream>
#include <stdexcept>

template <typename K, typename V>
class BSTNode {
public:
    K key;
    V value;
    BSTNode* left;
    BSTNode* right;

    BSTNode(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

template <typename K, typename V>
class BST {
private:
    BSTNode<K, V>* root;

    BSTNode<K, V>* add(BSTNode<K, V>* node, K key, V value) {
        if (!node) return new BSTNode<K, V>(key, value);
        if (key < node->key) node->left = add(node->left, key, value);
        else if (key > node->key) node->right = add(node->right, key, value);
        else node->value = value;
        return node;
    }

    BSTNode<K, V>* search(BSTNode<K, V>* node, K key) const {
        if (!node || node->key == key) return node;
        if (key < node->key) return search(node->left, key);
        return search(node->right, key);
    }

    void destroyTree(BSTNode<K, V>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() { destroyTree(root); }

    void add(K key, V value) { root = add(root, key, value); }

    V get(K key) const {
        BSTNode<K, V>* node = search(root, key);
        if (node) return node->value;
        throw std::runtime_error("Key not found");
    }
};

template <typename K, typename V>
class Dict {
private:
    BST<K, V> bst;

public:
    void add(K key, V value) { bst.add(key, value); }

    V operator[](K key) const { return bst.get(key); }
};

#endif