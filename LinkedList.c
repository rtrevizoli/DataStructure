#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>


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

List* findLast(List* lst, bool rm) 
{
    if (!lst)
        return lst;
    
    List* o = NULL;
    List* p = lst;
    List* q = lst->next;
    
    while (q != NULL) {
        o = p;
        p = q;
        q = q->next;
    }
    
    if (rm)
        return o;

    return p;
}

void insertLast(int value, List* cel)
{
    List* newCel; 

    newCel = malloc(sizeof(List)); 
    
    newCel->value = value; 
    
    List* p = findLast(cel, false);
        
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
        newCel->next = cel->next;
        cel->next = newCel;
    }
    else if (i == pos)
    {
        newCel->next = p;
        o->next = newCel;
    }
    else
    {
        p->next = newCel;
        newCel->next = q;
    }

    return cel;
} 

void removeLast(List* lst)
{
    List* o = findLast(lst, true);
    free(o->next);
    o->next = NULL;
}

List* removePos(List* cel, int pos)
{
    List* o = NULL;
    List* p = cel;
    List* q = cel->next;
    int i = 0;
    
    /* If pos not found removeLast */
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
        p->next = q->next;
        free(q);
    }
    else 
    {
        if (i == pos && q)
        {
            p->next = q->next;
            free(q);
        }
        else
        {
        free(o->next);
        o->next = NULL;
        }
    }
    
    return cel;
}

List* createHList(List* lst)
{
    printf("List with head\n---\n");
    
    lst = malloc(sizeof(List));
    lst->next = NULL;
    
    /* Insert first */
    lst = insertPos(10, lst, 0);
    lst = insertPos(20, lst, 0);
    lst = insertPos(30, lst, 0);
    
    /* Insert last */
    insertLast(40, lst);
    
    /* Insert Last */
    lst = insertPos(99, lst, 10);
    
    /* Insert pos 0 || 1 inserting on same position FIX IT*/
    lst = insertPos(35, lst, 1);
    
    /* Remove last position */
    //removeLast(lst);
    
    /* Remove last position */
    //lst = removePos(lst, 10);
    
    /* Remove first position, head not counting */
    //lst = removePos(lst, 0);
    
    return lst;
}

List* createList(List* lst)
{
    printf("List without head\n---\n");
    
    lst = insertFirst(10, lst);
    lst = insertFirst(20, lst);
    lst = insertFirst(30, lst);

    insertLast(40, lst);
    
    lst = insertPos(99, lst, 10);
    
    removeLast(lst);
    
    return lst;
}

void printList(List* lst) 
{ 
    List *p;
    for(p = lst; p != NULL; p = p->next)
        printf("%d->", p->value);
} 

int main() 
{ 
    bool m_head = true;
    List* lst = NULL;
    
    lst = m_head ? createHList(lst) : createList(lst);
    
    /* 30 - 20 - 10 - 40 - 99 */
    printList(lst);
    
    return 0;
} 
