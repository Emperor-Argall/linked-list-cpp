#include <iostream>

using namespace std;


struct Node{
    int num;
    Node* next = nullptr;
};

typedef Node* PNode;


void addBegg(PNode& head, int num){

    PNode newElement = new Node;

    newElement->num = num;
    newElement->next = head;

    head = newElement;


}

void addEnd(PNode& head, int num){

    if(head == nullptr){ 
        addBegg(head, num);
        return;
    }

    PNode newElement = new Node;

    PNode current = head;

    while (current->next != nullptr) current = current->next;

    current->next = newElement;


    newElement->num = num;
    newElement->next = nullptr;


}

void addPos(PNode& head, int pos, int num){

    if( pos <= 1 || head == nullptr){ 
        addBegg(head, num);
        return;
    }



    if(head->next == nullptr){ 
        addEnd(head, num);
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
    
    


}



void delBegg(PNode& head){
    PNode oldHead = head;
    head = head->next;
    delete oldHead;

}

void delEnd(PNode& head){
    PNode current = head;
    if (head->next == nullptr) {
    delBegg(head);
    return;
    }

    while (current->next->next != nullptr) current = current->next;

    PNode oldEnd = current->next;

    delete oldEnd;
    current->next = nullptr;

    

}

void delPos(PNode& head, int pos){

    if( pos <= 1 || head == nullptr){ 
        delBegg(head);
        return;
    }

    if(head->next == nullptr){ 
        delEnd(head);
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

}



void print(PNode& head){
    PNode current = head;
    while (current != nullptr){
        cout << current->num << " ";
        current = current->next;
    } 

}



int main(){

    std::ios_base::sync_with_stdio(false);


    PNode head = nullptr;

    addBegg(head, 1);

    addBegg(head, 3);

    addEnd(head, 4);

    addPos(head, 1, 2);

    print(head);

    cout << endl;
    
    delPos(head, 1);



    print(head);




    return 0;
}
