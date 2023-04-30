#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
    int val;
    struct node *left, *right;
} Node;
void Insert(Node** root, int src);
void recursion(Node* root);
void Print(Node* root);
//void _free(Node** root);
void Insert(Node** root, int src){
    if((*root)==NULL){
        (*root) = (Node*)malloc(sizeof(Node));
        (*root)->val=src;
        (*root)->left=NULL;
        (*root)->right=NULL;
        return;
    }
    if((*root)->val==src) return;
    if((*root)->val>src) Insert(&((*root)->left), src);
    else Insert(&((*root)->right), src);
}
void recursion(Node* root){
    if(root->left!=NULL){
        printf(" %d",root->left->val);
        recursion(root->left);
    }
    if(root->right!=NULL){
        printf(" %d",root->right->val);
        recursion(root->right);
    }
}
void Print(Node* root){
    if(!root) return;
    printf("%d",root->val);
    recursion(root);
    printf("\n");
}
/*
void _free(Node** root){
    if((*root)==NULL) return;
    _free(&((*root)->left));
    _free(&((*root)->right));
    free((*root));
}
*/