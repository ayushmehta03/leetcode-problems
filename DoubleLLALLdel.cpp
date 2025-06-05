#include<iostream>
#include<vector>
using namespace std;

// Define the Node structure
struct Node {
    public:
    int data;
    Node* next;
    Node*back;

    // Constructor with two parameters
    Node(int data1, Node* next1,Node*back1) {
        data = data1;
        next = next1;
        back=back1;
    }

    // Constructor with only data, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
        back=nullptr;
    }

};
Node*convertarr2DLL(vector<int>&arr){
    Node*head= new Node(arr[0]);
    Node*prev= head;
    for(int i=1;i<arr.size();i++){
        Node*temp= new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;

}
void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node*deleteHead(Node*head){
    if(head==NULL|| head->next==NULL) return head;
    Node*prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;



}
Node* deleteTail(Node*head){
    if(head==NULL || head->next==NULL) return NULL;
    Node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node*prev=tail->back;
    prev->next=nullptr;
    tail->back=nullptr;
    free(tail);
    return head;
}
Node*deleteLLbyK(Node*head,int k ){
  if(head==NULL) return NULL;

    Node*temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node*prev=temp->back;
    Node*front=temp->next;
    if(prev==NULL && front==NULL) {
        return NULL;

    }
    else if(prev==NULL)  return deleteHead(head);
    else if(front==NULL)  return deleteTail(head);

        prev->next=front;
        front->back=prev;
        temp->back=nullptr;
        temp->next=nullptr;
        free(temp);
    
    return head;
}

int main(){
      vector<int> arr = {12, 15, 19, 11,10};

    Node* head = convertarr2DLL(arr);
    head=deleteLLbyK(head,1);
    print(head);
}