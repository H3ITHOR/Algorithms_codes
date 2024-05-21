#include <iostream>
#include <string>

using namespace std;

// FIFO -> QUEUE

// struct question{
//     int name;
//     int 
// };

struct Link{
    int element;
    Link* next;
};

Link* create_link(int it, Link* nextval){
    Link* n = new Link;
    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_empty_link(Link* nextval){
    Link* n = new Link;
    n->next = nextval;
    return n;
}

struct Queue{
    Link* front = new Link;
    Link* rear = new Link;
    int size;
};

Queue* create_queue(){
    Queue* q = new Queue;
    q->front = q->rear = create_empty_link(NULL);
    q->size = 0;
    return q;
}

void add(Queue* q, int it){
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

int solve(Queue* q){
    if(q->size == 0){
        throw "error";
    }
    int it;
    it = q->front->next->element;
    q->front->next = q->front->next->next;
    if(q->front->next == NULL){
        q->rear = q->front;
    }
    q->size--;
    return it;
}

void print(Queue* q) {
    Link* current = q->front->next; // Start from the first actual element
    while (current != NULL) {
        cout << current->element;
        if (current->next != NULL){
            cout << " ";
        }
        current = current->next;
    }
    cout << "\n";
}

int main(){
    Queue* q = create_queue();
    string variable;
    int number;
    int questions_resolved=0;
    int questions_remaining=0;

    while(variable != "end"){
        cin >> variable;
        if(variable == "add" && variable != "end"){
            cin >> number;
            add(q, number);
            questions_remaining++;
        }else if(variable == "solve" && variable != "end"){
            if(questions_remaining>0){
            solve(q);
            questions_resolved++;
            questions_remaining--;
            }
        }else if(variable == "print" && variable != "end"){
            if(questions_remaining>0){
            print(q);
            } else{
                cout << "x" << "\n";
            }
        }else if(variable == "stats" && variable != "end"){
            cout << questions_resolved << " " << questions_remaining << "\n";
        }
    }
    return 0;
}