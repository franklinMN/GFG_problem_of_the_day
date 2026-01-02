#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// problem link - https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


// solution 1 time complexity failed
// test cases: 10 /1115

class Solution1 {
  public:

    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        vector<Node*> visited;

        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while( temp1!=NULL || temp2!=NULL ){
            if(temp1!=NULL){
                if(std::find(visited.begin(), visited.end(), temp1) != visited.end()){ // match found
                    return temp1;
                }
                visited.push_back(temp1);
                temp1 = temp1->next;
            }
            if(temp2!=NULL){
                if(std::find(visited.begin(), visited.end(), temp2) != visited.end()){ // match found
                    return temp2;
                }
                visited.push_back(temp2);
                temp2 = temp2->next;
            }
        }
    }
};

// solution 2
// test cases: 1010 /1115

class Solution2 {
  public:

    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
       
        Node* t1 = head1;
        Node* t2 = head2;
        Node* tt2 = NULL;
        while(t1 != NULL){
            tt2 = t2;
            while(tt2 != NULL){
                if(t1==tt2) return t1;
                tt2 = tt2->next;
            }
            t1 = t1->next;
        }
    }
};


// solution 3
// passed

class Solution3 {
  public:

    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
       
        Node *p1 = head1;
        Node *p2 = head2;

        /*
            rotating their paths, meets at the intersection
            h1 = a + c
            h2 = b + c
            where c is the constant tail
                  a, b are varing length before intersection
            
            p1 travels a + c + b + c ...
            p2 travels b + c + a + c ...

            intersection happens at c after both completes len1 + len2 + c
        */

        while( p1 != p2 ){
            p1 = (p1==NULL) ? head2 : p1->next;
            p2 = (p2==NULL) ? head1 : p2->next;
        }

        return p2;

    }
};


