#include <stdio.h>
#include <stdlib.h>

typedef struct Cel 
{ 
    int value; 
    struct Cel *next; 
} Cel; 

void printList(Cel *lst) 
{ 
    Cel *p;
    for(p = lst; p != NULL; p = p->next)
        printf("%d->", p->value);
} 

void insertQueue(int value, Cel **iniCel, Cel **finiCel)
{
    Cel *newCel;
    
    newCel = malloc(sizeof(Cel)); 
    newCel->value = value;
    newCel->next = NULL;

    if (*finiCel == NULL) *finiCel = *iniCel = newCel;
    else
    {
        (*finiCel)->next = newCel;
        *finiCel = newCel;
    }
}

int main() 
{
    Cel *pi = NULL, *pf = NULL;

    insertQueue(10, &pi, &pf);
    insertQueue(20, &pi, &pf);
    insertQueue(30, &pi, &pf);

    printList(pi);

    return 0;
}