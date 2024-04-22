#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
    int value; 
    struct Node* ptr;
} typedef Node;

void * my_malloc(int size) {
    void* ptr = malloc(size);

    if (ptr == NULL) {
        printf("Error");
        exit(1);
    }

    return ptr;
}

Node* instance(int val) {
    Node * node = (Node*) my_malloc(sizeof(Node));
    node -> value = val;
    node -> ptr = NULL;

    return node;
}

void freeList(Node** node) {
    Node * hasce = NULL; 
    while ((*node) && (*node) -> ptr) {
        hasce = (*node) -> ptr -> ptr;
        free((*node) -> ptr);
        (*node) = hasce;
    }
}

void append(Node** node, int val) {
    if (*node == NULL)  
    {
        *node = (Node*) my_malloc(sizeof(Node));
        (*node) -> ptr = NULL;
        (*node) -> value = val;
    } else {
        Node * tmp =  (*node);
        while (tmp -> ptr) {
            tmp = tmp -> ptr;
        }

        tmp -> ptr = (Node*) my_malloc(sizeof(Node));
        tmp -> ptr -> ptr = NULL;
        tmp -> ptr -> value = val;
    }
}

void prepand(Node **node, int val) {
    if (*node == NULL)  
    {
        *node = (Node*) my_malloc(sizeof(Node));
        (*node) -> ptr = NULL;
        (*node) -> value = val;
    } else {
        Node * new = (Node*) my_malloc(sizeof(Node));
        new -> value = val;
        new -> ptr = (*node);

        *node = new;
    }
}

void printList(Node**head) {
    Node* node = (*head);
    while (node) {
        printf("%d \n", node -> value);
        node = node -> ptr;
    }
}

int isEmpty(Node ** node) {
    return *node == NULL;
}

int getSize (Node ** node) {
    if (*node == NULL) return 0;

    Node * tmp = *node;
    int count = 0;
    while (tmp)
    {
        count++;
        tmp = tmp -> ptr;
    }

    return count;
}

void insertAfter(Node** node, int index, int val) {
    if (index > -1 && index >= getSize(node)) return;
    if (*node == NULL)  
    {
        *node = (Node*) my_malloc(sizeof(Node));
        (*node) -> ptr = NULL;
        (*node) -> value = val;
    } else {

        Node * tmp = *node;
        int count = 0;
        while (tmp -> ptr) {
            if (count == index) break;
            count++;
            tmp = tmp -> ptr;
        }        
        Node * nextAdd = tmp -> ptr;

        tmp -> ptr = (Node*) my_malloc(sizeof(Node));
        tmp -> ptr -> value = val;
        tmp -> ptr -> ptr = nextAdd;
    }
}

void deleteNode(Node ** node, int index) {
    if (*node == NULL) return;
    if (index > -1 && index >= getSize(node)) return;

    Node* tmp = *node;
    int count = 0;
    while (tmp -> ptr)
    {
        if (count == index -1) break;
        count++;
        tmp = tmp -> ptr;
    }

    if (count == 0) {
        *node = tmp -> ptr;
    } else {
        tmp -> ptr = tmp -> ptr -> ptr;
        // free(tmp->ptr);
    } 
}

void push_back(Node ** head, int val) {
    Node * newNode = instance(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    } else {
        Node* tmp = *head;
        while (tmp -> ptr)
        {
            tmp = tmp -> ptr;
        }
        
        tmp -> ptr = newNode;
    }
}

void push_front(Node**head, int val) {
    Node * newNode = instance(val);
    newNode->ptr = *head;
    *head = newNode;
}

bool insert(Node** head, int index, int val) {
    if (index < 0) {
        return false;
    }
    if (index == 0) push_front(head, val);

    Node* tmp = *head;
    Node* new = instance(val);

    for (int i = 0; i < index && tmp != NULL; i++) {
        tmp = tmp -> ptr;
    }

    if (tmp == NULL) {
        printf("wrong");
        return false;
    }

    new -> ptr = tmp -> ptr;
    tmp->ptr = new;
}

void print(const Node* head) {

    while (head)
    {
        printf("%d \n", head -> value);
        head = head -> ptr;
    }
    
}

Node* find(Node* head, int val ) {
    while (head)
    {
       if (head -> value == val) return head;
        head = head -> ptr;
    }
    return NULL;
}

void insertAfterLyovFunction(Node * prev, int val) {
    Node* node = instance(val);

    node -> ptr = prev -> ptr;
    prev -> ptr = node;

}

bool delete(Node** head, int index) {
    if (index < 0 || *head == NULL) return false;
    
    Node * tmp = *head;

    if (index == 0)  {
        *head = (*head) -> ptr;
        free(tmp);
    }

    for (int i = 0; i < index -1 && tmp != NULL; i++) {
        tmp = tmp -> ptr;
    }

    if (!tmp || !tmp -> ptr) {
        puts("msg");
        return false;
    }

    Node* add = tmp -> ptr;
    tmp -> ptr = tmp -> ptr -> ptr;
    free(add);

    return true;
}


void clear(Node** head) {
    Node* tmp = *head;

    while (*head)
    {
        *head = (*head) ->ptr;
        free(tmp);
        tmp = *head;
    }
    
}

int main () {
    Node* head =  NULL;

    push_front(&head, 1);
    push_front(&head, 2);

    push_back(&head, 3);
    insert(&head, 1, 10);
    delete(&head, 1);

    print(head);

    // append(&head, 20);
    // append(&head, 30);
    // append(&head, 40);

    // prepand(&head, 10);
    // prepand(&head, 0);

    // insertAfter(&head, 1, 8);
    // insertAfter(&head, 1, 99);

    // // deleteNode(&head, 0);
    // // deleteNode(&head, 0);
    // deleteNode(&head, getSize(&head) -1);


    // int empty = isEmpty(&head);
    // int size = getSize(&head);

    // printList(&head);
    // freeList(&head);
}