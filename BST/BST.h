//
// Created by Shinelon on 2017/9/14.
//

#ifndef LEETCODE_DEMO_BST_H
#define LEETCODE_DEMO_BST_H

#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

template<typename Key, typename Value>
class BST {
private:
    struct Node{
        Key key;
        Value value;
        Node *leftChild, *rightChild;
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->leftChild = this->rightChild = NULL;
        }
        Node(Node *node) {
            this->key = node->key;
            this->value = node->value;
            this->leftChild = node->leftChild;
            this->rightChild = node->rightChild;
        }
    };

    Node *root;
    int count;

public:
    BST() {
        root = NULL;
        count = 0;
    }
    ~BST() {
        destroy(root);
    }
    int size() {
        return count;
    }
    bool isEmpty() {
        return count == 0;
    }
    void insert(Key key, Value value) {
        insert(root, key, value);
    }
    bool contain(Key key) {
        return contain(root, key);
    }
    Value* search(Key key) {
        return search(root, key);
    }
    void preOrder() {
        preOrder(root);
    }
    void inOrder() {
        inOrder(root);
    }
    void postOrder() {
        postOrder(root);
    }
    void levelOrder() {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *node = q.front();
            q.pop();
            cout<<node->key<<endl;
            if(node->leftChild != NULL) {
                q.push(node->leftChild);
            }
            if(node->rightChild != NULL) {
                q.push(node->rightChild);
            }
        }
    }
    Key minimum() {
        assert( count > 0);
        Node *node = minimum(root);
        return node->key;
    }
    Key maximum() {
        assert( count > 0);
        Node *node = maximum(root);
        return node->key;
    }
    void removeMin() {
        if(root != NULL) {
            root = removeMin(root);
        }
    }
    void removeMax() {
        if(root != NULL) {
            root = removeMax(root);
        }
    }
    void remove(Key key) {
        remove(root, key);
    }
private:
    Node* insert(Node *node, Key key, Value value) {
        if(node == NULL) {
            count++;
            return new Node(key, value);
        }
        if(key < node->key) {
            node->leftChild = insert(node->leftChild, key, value);
        }else if(key > node->key) {
            node->rightChild = insert(node->rightChild, key, value);
        }else{
            node->value = value;
        }
        return node;
    }

    bool contain(Node *node, Key key) {
        if(node == NULL) {
            return false;
        }

        if(key == node->key) {
            return true;
        }else if(key < node->key) {
            return contain(node->leftChild, key);
        }else{
            return contain(node->rightChild, key);
        }
    }

    Value* search(Node *node, Key key) {
        if(node == NULL) {
            return NULL;
        }
        if(key == node->key) {
            return &(node->value);
        }else if(key < node->leftChild) {
            return search(node->leftChild, key);
        }else{
            return search(node->rightChild, key);
        }
    }

    void preOrder(Node *node) {
        if(node != NULL) {
            cout << node->value << " ";
            preOrder(node->leftChild);
            preOrder(node->rightChild);
        }
    }

    void inOrder(Node *node) {
        if(node != NULL) {
            inOrder(node->leftChild);
            cout << node->value << " ";
            inOrder(node->rightChild);
        }
    }

    void postOrder(Node *node) {
        if(node != NULL) {
            postOrder(node->leftChild);
            postOrder(node->rightChild);
            cout << node->value << " ";
        }
    }

    void destroy(Node *node) {
        if(node != NULL) {
            destroy(node->leftChild);
            destroy(node->rightChild);
            delete node;
            count--;
        }
    }

    Node* minimum(Node *node) {
        if(node->leftChild == NULL) {
            return node;
        }
        return minimum(node->leftChild);
    }

    Node* maximum(Node *node) {
        if(node->rightChild == NULL) {
            return node;
        }
        return maximum(node->rightChild);
    }

    Node* removeMin(Node* node) {
        if(node->leftChild == NULL) {
            Node *rightChild = node->rightChild;
            delete node;
            count--;
            return rightChild;
        }
        node->leftChild = removeMin(node->leftChild);
        return node;
    }

    Node* removeMax(Node* node) {
        if(node->rightChild == NULL) {
            Node* leftChild = node->leftChild;
            delete node;
            count--;
            return leftChild;
        }
        node->rightChild = removeMax(node->rightChild);
        return node;
    }

    Node* remove(Node* node, Key key) {
        if(node == NULL) {
            return NULL;
        }
        if(key < node->key) {
            node->leftChild = remove(node->leftChild, key);
            return node;
        }else if(key > node->key) {
            node->rightChild = remove(node->rightChild, key);
            return node;
        }else{
            if(node->leftChild == NULL) {
                Node *right = node->rightChild;
                delete node;
                count--;
                return right;
            }
            if(node->rightChild == NULL) {
                Node *left = node->leftChild;
                delete node;
                count--;
                return left;
            }
            // node->leftChild!=NULL && node->rightChild!=NULL
            Node *successor = new Node(minimum(node->rightChild));
            count++;
            successor->leftChild = node->leftChild;
            successor->rightChild = removeMin(node->rightChild);
            delete node;
            count--;
            return successor;

        }
    }
};

#endif //LEETCODE_DEMO_BST_H
