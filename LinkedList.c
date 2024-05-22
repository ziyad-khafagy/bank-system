#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "STD_TYPES.h"

extern node head;

u32 ListLength = 0;

// create first node 
void new_user(account value)
{
    
    if (ListLength == 0)
    {
        head.value = value;
        head.Next = NULL;
    }

    else
    {
        node *last;

      // Allocate New Node at heap
        node *new = (node *)malloc(sizeof(node));

          // Assign New Value to the node
        new->value = value;
         // New Node is the last Node, so the NEXT ptr should point to NULL
        new->Next = NULL;

        last = &head;

      // search for last node
        while ((last->Next) != NULL)
        {
            last = (last->Next);
        }

        last->Next = new;
    }

    // Increase the list length by one node 
    ListLength++;
    return;
}
/*------------------------------------------------------------------------------------*/

bool SearchUser(u64 x)
{
	
    node *now = &head; 
    while (now != NULL)
    {
        if (now->value.BankAccountID == x)
        return true;
        now = now->Next;
    }
    return false;
}
/*------------------------------------------------------------------------------------*/
node *GetUser(u64 y)
{   
    
    node *current = &head; 
    while (current != NULL)
    {
        if (current->value.BankAccountID == y)
        return current;
        current = current->Next;
    }
    return NULL;
}

