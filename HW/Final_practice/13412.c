#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int val;
    struct _Node *next;
}Node;
Node* Solver(Node* head, int k);


Node* createNode(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}
void printList(Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->val);
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node* head = NULL;
    
    int tmp;
    scanf("%d", &tmp);
    head = createNode(tmp);
    Node* tail = head;
    
    while(1)
    {
        scanf("%d", &tmp);
        if(tmp==-1)
            break;
        tail->next = createNode(tmp);
        tail = tail->next;
    }
    
    int k;
    scanf("%d", &k);
    Node* res = Solver(head, k);
    printList(res);
    
    return 0;
}
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