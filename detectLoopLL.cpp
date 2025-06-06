#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if (head == NULL || head->next == NULL) return false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

// Helper function to create linked list from array (no cycle)
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to manually create a cycle for testing
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* temp = head;
    ListNode* cycleNode = nullptr;
    int index = 0;
    while (temp->next != nullptr) {
        if (index == pos) cycleNode = temp;
        temp = temp->next;
        index++;
    }
    temp->next = cycleNode;
}

int main() {
    int arr[] = {3, 2, 0, -4};  // Sample input
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);

    createCycle(head, 1);  // Create cycle at index 1 (0-based). Set -1 for no cycle.

    Solution sol;
    bool result = sol.hasCycle(head);

    if (result)
        cout << "Cycle detected." << endl;
    else
        cout << "No cycle." << endl;

    return 0;
}
