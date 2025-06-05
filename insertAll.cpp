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
Node *insertHead(Node*head,int value){
    return new Node(value,head);
}
Node*insertTail(Node*head,int value){
    if(head==NULL){
      return  new Node(value);
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node*newNode=new Node(value);
    return head;
}
Node*insertK(Node*head, int value,int k){
    if(head==NULL){
        if(k==1) return new Node(value);
        else return head;
    }
    if(k==1){
        return new Node(value,head);
    }
    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node *x=new Node(value,temp->next);
            temp->next=x;
            break;
            
        }
        temp=temp->next;
    }
    return head;
}
Node*insertbeforeVal(Node*head, int value,int el){
    if(head==NULL) return NULL;
       
    if(head->data==value){
        return new Node(el,head);
    }
    
    Node*temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==value){
            Node *x=new Node(el,temp->next);
            temp->next=x;
            break;
            
        }
        temp=temp->next;
    }
    return head;
}

// Main function
int main() {
    vector<int> arr = {2, 5, 9, 11};

    Node* head = convertarr2LL(arr);
    
    print(head);
    
   

    return 0;
}
