#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void print_recursive(Node *head){
    if(head != NULL){
        cout<<head->data<<" ";
         print_recursive(head->next);
    }
}

int find_iterative(Node *head,int key){
    int pos = 1;
    Node *cur = head;
    while(cur != NULL){
        if(cur->data == key){
            return pos;
        }else{
            pos++;
            cur=cur->next;
        }
    }
    return -1;
}

int find_recursive(Node * head,int key){
    if(head == NULL){
        return -1;
    }
    if(head->data == key){
        return 1;
    }else{
        int res = find_recursive(head->next,key);
        if(res ==  -1) return -1;
        else{
            return (res+1);
        }
    }
}

Node* addbegin(Node* head,int v){
    Node* temp = new Node(v);
    temp->next = head;
    return temp;
}

Node* addend(Node* head,int v){
    Node* temp = new Node(v);
    if(head == NULL){
        return temp;
    }
    while(head->next != NULL){
        head = head->next;
    }
    head->next = temp;
    return head;
}

Node* deletefirst(Node* head){
    if(head == NULL){
        return NULL;
    }else{
        Node* temp = head->next;
        delete head;
        return temp;
    }

}

Node* deletelast(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    while(head->next->next != NULL){
        head = head->next;
    }
    delete(head->next);
    head->next = NULL;
    return head;
}

Node* insert(Node* head,int p,int data){
    Node* temp;
    Node* cur = head;
    if(p == 1){
        temp->next = head;
        return temp;
    }
    for(int i=1;i<=p-2 && cur != NULL;i++){
        cur = cur->next;
    }
    if(cur == NULL){
        return head;
    }
    temp->next = cur->next;
    cur->next = temp;
    return head;
}



int main(){
     Node *head = new Node(10);
     head->next = new Node(20);
     Node* i;
    // head->next->next = new Node(30);
    // int key = 40;
    i = insert(head,2,45);
    printList(i);
    cout<<endl;
    // head = addbegin(head,40);
    // printList(head);
    // cout<<endl;
    // cout<<"position of "<<key<< " is "<<find_recursive(head,key);
    // cout<<endl;
    // addend(head,50);
    // print_recursive(head);
    // cout<<endl;
    // head = deletefirst(head);
    // printList(head);
    // cout<<endl;
    // deletelast(head);
    // printList(head);
    
    return 0;
}