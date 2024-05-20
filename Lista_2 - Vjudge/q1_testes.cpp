#include <iostream>
// #include <string>

using namespace std;

struct Link{
    char element;
    Link* next;
};

Link* create_link(char it, Link* nextval){
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

struct List{
    Link* head = new Link;
    Link* tail = new Link;
    Link* curr = new Link;
    int cnt;
};

List* create_list(){
    List* l = new List;
    l->curr = l->tail = l->head = create_empty_link(NULL);
    l->cnt = 0;
    return l;
}


void insert(List* l, char it){
    l->curr->next = create_link(it, l->curr->next);
    if(l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->cnt++;   
}

void moveToStart(List* l){
    l->curr = l->head;
}

void next(List* l){
    if(l->curr != l->tail){
        l->curr = l->curr->next;
    }
}

void prev(List* l){
    if(l->curr == l->head){
        return;
    }
    Link* temp = l->head;
    while(temp->next != l->curr){
        temp = temp->next;
    }
    l->curr = temp;
}


void print_list(List* l){
    Link* temp = new Link;
    temp = l->head->next;
    while(temp!=nullptr){
        cout << temp->element;
        temp = temp->next;
    }
    cout << '\n';
}

int main(){
    List* list = create_list();
    char variable;

    while(cin >> variable) {
        if(variable == '['){
            moveToStart(list);
        } else if(variable == ']'){
            list->curr = list->tail;
        } else{
            insert(list, variable);
            next(list);
        }
    }

    print_list(list);

    return 0;
}