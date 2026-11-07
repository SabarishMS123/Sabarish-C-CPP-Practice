#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary search tree
struct bst {
    int data;
    struct bst *left;
    struct bst *right;
};

// Function to initialize a new node
struct bst* initialise(int val) {
    struct bst *newn = (struct bst *)malloc(sizeof(struct bst));
    newn->data = val;
    newn->left = newn->right = NULL;
    return newn;
}

// Function to insert a new node into the BST
struct bst* insertion(struct bst *root, int val) {
    if (root == NULL) 
        return initialise(val);

    if (val <= root->data)
        root->left = insertion(root->left, val);
    else if (val > root->data)
        root->right = insertion(root->right, val);

    return root;
}

// Function to perform inorder traversal
void inorder(struct bst *root) {
    if (root != NULL) {
        inorder(root->left);
        printf(" -> %d", root->data);
        inorder(root->right);
    }
}

// Function to search for a value in the BST
struct bst* search(struct bst *root, int item) {
    if (root == NULL || root->data == item)
        return root;

    if (item < root->data)
        return search(root->left, item);

    return search(root->right, item);
}

// Function to find the node with the minimum value
struct bst* minValueNode(struct bst *node) {
    struct bst *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from the BST
struct bst* deletion(struct bst *root, int item) {
    if (root == NULL)
        return root;

    if (item < root->data)
        root->left = deletion(root->left, item);
    else if (item > root->data)
        root->right = deletion(root->right, item);
    else {
        if (root->left == NULL) {
            struct bst *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct bst *temp = root->left;
            free(root);
            return temp;
        }

        struct bst *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }

    return root;
}

int main() {
    int ch, val;
    struct bst *root = NULL;
    printf("\n------Binary Search Tree----\n");

    while (1) {
        printf("\nMENU::\n\t1.INSERTION\n\t2.SEARCH\n");
        printf("\t3.DELETION\n\t4.exit()\nChoice:: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n-----------------INSERTION---------------\n");
                printf("\nEnter the data :: ");
                scanf("%d", &val);
                root = insertion(root, val);
                printf("\nThe IN-ORDER list is:: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("\nSEARCH");
                printf("\nEnter the data :: ");
                scanf("%d", &val);
                struct bst *temp = search(root, val);
                if (temp == NULL)
                    printf("\nData is NOT FOUND!!\n");
                else
                    printf("\nData is FOUND!!\n");
                break;
            case 3:
                printf("\n::::::::::::::::DELETION:::::::::::::::\n");
                printf("\nEnter the data to be deleted:: ");
                scanf("%d", &val);
                root = deletion(root, val);
                printf("\nThe INORDER list is:: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("\nWRONG CHOICE!!!\n");
        }

        printf("\n");
        int i; // Declare loop variable outside
        for (i = 0; i < 20; i++) 
            printf("---");
        printf("\n");
    }

    return 0;
}

