#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


class Solution {
  public:

    void bubbleSort(Node* head) {
        if (!head) return;

        bool swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->bottom != lptr) {
                if (ptr1->data > ptr1->bottom->data) {
                    int temp = ptr1->data;
                    ptr1->data = ptr1->bottom->data;
                    ptr1->bottom->data = temp;
                    swapped = true;
                }
                ptr1 = ptr1->bottom;
            }
            lptr = ptr1;
        } while (swapped);
    }


    Node *flatten(Node *root) {
        // code here
        Node* current = root;
        Node* end = NULL;
        // int count = 0;

        while(current != NULL){
            // count++;
            if(end != NULL){ 
                // except first time update the prevend with current head
                end->bottom = current;
            }
            Node* temp = current;
            while(temp->bottom != NULL){ 
                // count++;
                // gets the last element
                temp = temp->bottom;
            }
            end = temp;
            current = current->next;
        }

        // sort
        bubbleSort(root);
        // cout << "count: " << count << endl;
        return root;

    }
};


class Solution2 {
  public:
    Node* merge(Node* a, Node* b){
        if(!a) return b;
        if(!b) return a;
        Node *result;
        if(a->data < b->data){
            result = a;
            result->bottom = merge(a->bottom, b);
        }else{
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        result->next = NULL;
        return result;
    }
    Node *flatten(Node *root) {
        if(!root || !root->next)
            return root;
        
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};


int main(){
    Node a = Node(5);
    Node b = Node(10);
    Node c = Node(19);
    Node d = Node(28);

    Node a1 = Node(7);
    Node a2 = Node(8);
    Node a3 = Node(30);
    
    Node c1 = Node(22);
    Node c2 = Node(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    a.bottom = &a1;
    a1.bottom = &a2;
    a2.bottom = &a3;

    c.bottom = &c1;
    c1.bottom = &c2;

    Node* head = &a;

    // Solution s = Solution();
    // s.flatten(head);

    // Node* temp = head;
    // while(temp!=NULL){
    //     cout << temp->data << ", ";
    //     temp = temp->bottom;
    // }
    // cout << endl;

    Solution2 s2 = Solution2();
    s2.flatten(head);

    Node* temp2 = head;
    while(temp2!=NULL){
        cout << temp2->data << ", ";
        temp2 = temp2->bottom;
    }
    cout << endl;

    
}