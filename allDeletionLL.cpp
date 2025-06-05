#include<iostream>
#include<vector>
using namespace std;

// Define the Node structure
struct Node {
    public:
    int data;
    Node* next;

    // Constructor with two parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert array to linked list
Node* convertarr2LL(vector<int>& arr) {
    if (arr.empty()) return nullptr; // safety check for empty vector

    Node* head = new Node(arr[0]); // create head node with first value
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head; // return the start of the linked list
}
void print(Node*head){
    Node*temp=head;
    while(temp){
    cout<<" "<<temp->data<<" ";
    temp=temp->next;
    }
}
// Delete the Head Node 

Node *deleteHead(Node *head){
    if(head==NULL) return head;
    Node*temp=head;
    head=head->next;
    free(temp);
    return head;
}
// Delete the tail node 

Node *deleteTail(Node*head){
    if(head==NULL || head->next==NULL) return NULL;
    Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    return head;
}
// Delete By Position
Node* deleteK(Node*head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node*temp=head;
    Node*prev=NULL;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
    if(cnt==k){
    prev->next=prev->next->next;
    free(temp);
    break;
    }
    prev=temp;
    temp=temp->next;
    }
    return head;
}
// Delete by Targeting the Element

Node* deleteEl(Node*head,int el){
    if(head==NULL) return head;
    if(head->data==el){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node*temp=head;
    Node*prev=NULL;
    
    while(temp!=NULL){
        
    if(temp->data==el){
    prev->next=prev->next->next;
    free(temp);
    break;
    }
    prev=temp;
    temp=temp->next;
    }
    return head;
}



// Main function
int main() {
    vector<int> arr = {2, 5, 9, 11};

    Node* head = convertarr2LL(arr);
    head=deleteEl(head,2);
    print(head);
    
   

    return 0;
}
