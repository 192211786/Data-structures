#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int balanceFactor(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct TreeNode* rotateLeft(struct TreeNode* z) {
    struct TreeNode* y = z->right;
    struct TreeNode* T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct TreeNode* rotateRight(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct TreeNode* balance(struct TreeNode* node) {
    if (node == NULL)
        return node;

    int bf = balanceFactor(node);

    if (bf > 1) {
        if (balanceFactor(node->left) >= 0)
            return rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    if (bf < -1) {
        if (balanceFactor(node->right) <= 0)
            return rotateLeft(node);
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;  // Duplicate keys are not allowed

    root->height = 1 + max(height(root->left), height(root->right));

    return balance(root);
}

struct TreeNode* getMinValueNode(struct TreeNode* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct TreeNode* delete(struct TreeNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct TreeNode* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct TreeNode* temp = getMinValueNode(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    return balance(root);
}

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* avl_tree = NULL;

    avl_tree = insert(avl_tree, 10);
    avl_tree = insert(avl_tree, 20);
    avl_tree = insert(avl_tree, 30);
    avl_tree = insert(avl_tree, 40);
    avl_tree = insert(avl_tree, 50);

    printf("In-order traversal: ");
    inorderTraversal(avl_tree);
    printf("\n");

    int searchKey = 30;
    struct TreeNode* searchResult = search(avl_tree, searchKey);
    printf("Search %d: %s\n", searchKey, searchResult ? "Found" : "Not found");

    int deleteKey = 30;
    avl_tree = delete(avl_tree, deleteKey);
    printf("Search %d after deletion: %s\n", deleteKey, search(avl_tree, deleteKey) ? "Found" : "Not found");

    freeTree(avl_tree);

    return 0;
}
