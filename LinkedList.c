#include <stdio.h> 
#include <stdlib.h> 


typedef struct List 
{ 
    int value; 
    struct List* next; 
} List; 

List* findLast(List* lst) {
    if (!lst)
        return lst;
    
    List *p = lst;
    List *q = lst->next;
    
    while (q != NULL) {
        p = q;
        q = q->next;
    }

    return p;
}

List* insert(int value, List* cel, int pos)  
{ 
    List* newCel; 

    newCel = malloc(sizeof(List)); 
    
    newCel->value = value; 
    
    if (pos == 0) {
        newCel->next = cel;
    } else if (pos == -1) {
        List *p = cel;
        List *q = cel->next;
        
        while (q != NULL) {
            p = q;
            q = q->next;
        }
        
        p->next = newCel;
        newCel->next = NULL;

        return cel;
    } else {
        List *p = cel;
        List *q = cel->next;
        int i = 1;
        
        while (q != NULL) {
            p = q;
            q = q->next;
            
            i++;
            
            if (i == pos)
                break;
                
        }
        
        p->next = newCel;
        newCel->next = q;
        
        return cel;
    }
    
    return newCel;
} 

void print(List* lst) { 
    List *p;
    for(p = lst; p != NULL; p = p->next)
        printf("%d\n", p->value);
} 

int main() 
{ 
    List* lst; 
    
    List* melo = NULL;

    melo = insert(10, melo, 0); 
    
    List* p = findLast(melo);
    
    List* newCel = malloc(sizeof(List));
    newCel->value = 13;
    newCel->next = NULL;
    
    p->next = newCel;
    
    /*if (!p) {
        melo=p=newCel;
    }*/
        
    print(melo);
    
    /*10 lines wrote above is about findLast and identify null_ptr*/
    
    /*lst = malloc(sizeof(List));
    lst->next=NULL;*/
    
    lst = insert(10, lst, 0); 
    lst = insert(20, lst, 0); 
    lst = insert(30, lst, -1);
    lst = insert(40, lst, -1);
    lst = insert(50, lst, 0);
    lst = insert(60, lst, 2);
    
    /*50 - 20 - 10 - 30 - 40*/
    
    print(lst);

    return 0;
} 
