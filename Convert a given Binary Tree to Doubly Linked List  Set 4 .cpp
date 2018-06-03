#include <stdio.h>
#include <stdlib.h>

using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void BToDLL(Node *root, Node **head)
{
    if(!root)
       return ;
    BToDLL(root->right,head);
    root->right=*head;

    if(*head)
        (*head)->left=root;
    *head=root;
    BToDLL(root->left,head);
}
void printList(Node* head)
{
    printf("Extracted Double Linked list is:\n");
    while (head)
    {
        printf("%d ", head->data);
        head = head->right;
    }
}

int main()
{
    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->right = newNode(8);
    root->left->left->left = newNode(0);
    root->left->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(9);

    Node* head = NULL;
    BToDLL(root, &head);
    printList(head);
    return 0;
}
