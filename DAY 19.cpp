#include<iostream>

using namespace std;

class Solution {
private:
    struct Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node* &head, Node* &tail, int val) {
        Node* temp = new Node(val);
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

public:
    Node* addOne(Node* head) {
        head = reverse(head);
        
        int carry = 1;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        Node* curr = head;
        
        while(curr != NULL || carry != 0) {
            
            int val1 = 0;
            if(curr != NULL)
                val1 = curr->data;
                
            int sum = carry + val1;
            int digit = sum % 10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            if(curr != NULL)
                curr = curr->next;
        }
        
        ansHead = reverse(ansHead);
        
        return ansHead;
    }
};