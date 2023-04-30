#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int val;
    struct _Node *next;
}Node;
Node* Solver(Node* head, int k){
    Node* now = head;
    Node* before=NULL;
    while(1){
        if(now==NULL) {
            if(before) before->next = NULL;
            return head;
        }
        Node* search = now;
        int i=1;
        while(search->next!=NULL){
            search = search->next;
            if((++i)==k) break;
        }
        if(i!=k) {
            if(before) before->next = now;
            return head;
        }
        Node* first = now;
        Node* n = now->next;
        for(int j=1;j<k;j++){
            Node* temp = n->next;
            n->next = now;
            now = n;
            n = temp;
        }
        if(!before) head = now;
        else before->next = now;
        before = first;
        now = n;
    }
}