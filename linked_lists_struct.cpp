#include <iostream>

using namespace std;



struct Node{
    int num;
    Node* next = nullptr;
};

typedef Node* PNode;

class LinkedList{
private:
    PNode head = nullptr;
    unsigned int count{0};
public:

    LinkedList() {}

    void addBegg(int num){

        PNode newElement = new Node;

        newElement->num = num;
        newElement->next = head;
        head = newElement;
        ++count;
    }

    void addEnd(int num){

        if(head == nullptr){ 
            addBegg(num);
            return;
        }

        PNode newElement = new Node;

        PNode current = head;

        while (current->next != nullptr) current = current->next;

        current->next = newElement;
        newElement->num = num;
        newElement->next = nullptr;
        ++count;
    }

    void addPos(int pos, int num){

        if( pos <= 1 || head == nullptr){ 
            addBegg(num);
            return;
        }

        if(head->next == nullptr){ 
            addEnd(num);
            return;
        }

        PNode newElement = new Node;
        PNode current = head;

        for (int i = 0; i < pos - 2; i++){
            if(current->next == nullptr) break;
            current = current->next;
        } 

        newElement->num = num;
        newElement->next = current->next;
        current->next = newElement;
    
    
        ++count;

    }

    void delBegg(){
        PNode oldHead = head;
        head = head->next;
        delete oldHead;
        --count;
    }

    void delEnd(){
        PNode current = head;
        if (head->next == nullptr) {
        delBegg();
        return;
        }

        while (current->next->next != nullptr) current = current->next;

        PNode oldEnd = current->next;
        delete oldEnd;
        current->next = nullptr;

        --count;

    }

    void delPos(int pos){

        if( pos <= 1 || head == nullptr){ 
            delBegg();
            return;
        }

        if(head->next == nullptr){ 
            delEnd();
            return;
        }

        PNode current = head;

        for (int i = 0; i < pos - 3; i++){
            if(current->next == nullptr) break;
            current = current->next;
        } 

        PNode toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
        --count;

    }

    void print(){
        PNode current = head;
        while (current != nullptr){
            cout << current->num << " ";
            current = current->next;
        } 

    }

    void printCount(){ cout << count << "\n"; }

};


int main(){

    std::ios_base::sync_with_stdio(false);

    LinkedList list;

    

    list.print();




    return 0;
}
