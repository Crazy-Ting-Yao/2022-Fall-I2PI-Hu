#include <string.h>
#include <stdlib.h>
typedef struct node {
    int idx;
    struct node* next;
} Node;
void AddFront(Node** head, Node** back, int num){
    Node* new = (Node*)malloc(sizeof(Node));
    Node* temp = (*head)->next;
    if((*back)==(*head)) (*back)=new;
    (*head)->next = new;
    new->next = temp;
    new->idx=num;
}
void AddBack(Node** head, Node** back, int num){
    Node* new = (Node*)malloc(sizeof(Node));
    new->next=NULL;
    new->idx=num;
    (*back)->next = new;
    (*back) = new;
    return;
}
void DeleteFront(Node** head, Node** back){
    Node* temp = (*head)->next;
    if(temp!=NULL){
        (*head)->next = temp->next;
        free(temp);
    }
    return;
}
void Delete(Node** head, Node** back, int num){
    Node* n = (*head);
    if (n->next == NULL) return;
    while (n->next != NULL) {
        if (n->next->idx == num){
            Node* del = n->next;
            n->next = n->next->next;
            free(del);
            continue;
        }
        n = n->next;
    }
    (*back) = n;
}
void Swap(Node** head, Node** back){
    Node* now = (*head)->next;
    Node* n = now->next;
    while(n!=NULL){
        Node* temp = n->next;
        n->next = now;
        now = n;
        n = temp;
    }
    (*head)->next->next = NULL;
    (*back) = (*head)->next;
    (*head)->next = now;
    return;
}