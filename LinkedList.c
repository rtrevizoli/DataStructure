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

List* insertPos(int value, List* cel, int pos)  
{ 
    List* newCel; 

    newCel = malloc(sizeof(List)); 
    
    newCel->value = value; 

    List* o = NULL;
    List* p = cel;
    List* q = cel->next;
    int i = 0;
    
    /* If pos not found insertLast */
    while (q != NULL) 
    {
        if (i == pos)
            break;
        
        o = p;    
        p = q;
        q = q->next;
        
        i++;
    }
    
    if (i == 0)
    {
        newCel->next = cel;
        
        return newCel;
    } else if (i == pos)
    {
        newCel->next = p;
        o->next = newCel;
        
    } else
    {
        p->next = newCel;
        newCel->next = q;
    }

    return cel;
} 

void print(List* lst) { 
    List *p;
    for(p = lst; p != NULL; p = p->next)
        printf("%d\n", p->value);
} 

int main() 
{ 
    List* lst = NULL;
    
    /* Uncommente these lines above to make a headed list */
    /*lst = malloc(sizeof(List));
    lst->value=0;
    lst->next=NULL;*/


    lst = insertFirst(10, lst);
    lst = insertFirst(20, lst);
    lst = insertFirst(30, lst);

    insertLast(40, lst);
    
    lst = insertPos(99, lst, 10);
    

    /* 30 - 20 - 10 - 40*/
    print(lst);
    
    return 0;
} 
