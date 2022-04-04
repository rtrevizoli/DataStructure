#include <stdio.h> 
#include <stdlib.h> 


typedef struct List 
{ 
    int value; 
    struct List* next; 
} List; 

List* insertFirst(int value, List* cel)
{
    List* newCel; 

    newCel = malloc(sizeof(List)); 
    
    newCel->value = value; 
    newCel->next = cel;

    return newCel;
}

List* findLast(List* lst) 
{
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

void insertLast(int value, List* cel)
{
    List* newCel; 

    newCel = malloc(sizeof(List)); 
    
    newCel->value = value; 
    
    List* p = findLast(cel);
        
    p->next = newCel;
    newCel->next = NULL;
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
    
    /* Uncommente these lines above to make a headed list */
    /*lst = malloc(sizeof(List));
    lst->value=0;
    lst->next=NULL;*/
    

    melo = insertFirst(10, melo);
    melo = insertFirst(20, melo);
    melo = insertFirst(30, melo);

    insertLast(40, melo);
    
    /* 30 - 20 - 10 - 40*/
    print(melo);
    
    return 0;
} 
