#include <iostream>
#include <string>

using namespace std;

struct Student{
    int arrive;
    int tolerance;
    int tea_time;
};

struct Link{
    Student element;
    Link* next;
};

Link* create_link(Student it, Link* nextval){
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

void enqueue(Queue* q, Student it){
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

Student dequeue(Queue* q){
    if(q->size == 0){
        throw "error";
    }
    Student it = q->front->next->element;
    q->front->next = q->front->next->next;
    if(q->front->next == NULL){
        q->rear = q->front;
    }
    q->size--;
    return it;
}

void print_queue(Queue* q) {
    Link* current = q->front->next; // Start from the first actual element
    while (current != NULL) {
        cout << current->element.tea_time << " ";
        current = current->next;
    }
    cout << endl;
}


int main(){

    int n_cases;
    cin >> n_cases;

    for(int i=0; i<n_cases; i++){
        int qt_students;
        int current_time = 1;
        cin >> qt_students;
        Queue* queue = create_queue();
        for(int i=0; i<qt_students; i++){
            Student student;
            cin >> student.arrive;
            cin >> student.tolerance; 

            if (student.arrive > current_time){
                current_time = student.arrive;
            }
            if (student.tolerance >= current_time){
                student.tea_time=current_time;
                enqueue(queue, student);
                current_time++;
            } else{
                student.tea_time=0;
                enqueue(queue, student);
            }

        }
        print_queue(queue);
    }
    
    return 0;
}