#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};



void display(struct node *h)
{   
    struct node *cur;
    printf("linked list:\t");
  for(cur=h;cur->next!=h;cur=cur->next)
  {
      printf("%d\t",cur->data);
  }
  printf("%d",cur->data);
}


void insert(struct node **head, int v) 
{ 
  struct node *cur;
  cur=*head; 
  struct node *ptr;
  cur=(struct node *)malloc(sizeof(struct node));
  ptr->data=v;
  ptr->next=NULL;
  
  if (*head == NULL) 
  { 
     ptr->next = ptr; 
     *head = ptr; 
  } 
  
  else if (cur->data >= ptr->data) 
  { 
    while(cur->next != *head) 
        cur = cur->next; 
    cur->next = ptr; 
    ptr->next = *head; 
    *head = ptr; 
  } 
  

  else
  { 

    while (cur->next!= *head &&  cur->next->data < ptr->data) 
      cur = cur->next; 
  
    ptr->next = cur->next; 
    cur->next = ptr; 
  } 
}

void removeDuplicates(struct node* head) 
{ 
    /* Pointer to traverse the linked list */
    struct node* current = head; 
  
    /* Pointer to store the next pointer of a node to be deleted*/
    struct node* next_next;  
    
    /* do nothing if the list is empty */
    if (current == NULL)  
       return;  
  
    /* Traverse the list till last node */
    while (current->next != NULL)  
    { 
       /* Compare current node with next node */
       if (current->data == current->next->data)  
       { 
           /* The sequence of steps is important*/               
           next_next = current->next->next; 
           free(current->next); 
           current->next = next_next;   
       } 
       else /* This is tricky: only advance if no deletion */
       { 
          current = current->next;  
       } 
    } 
} 
int main()
{
    struct node *head=NULL;
    insert(&head,3);//creating a sorted linked list
    display(head);
    printf("\n");
    insert(&head,2);
    display(head);
    printf("\n");
    insert(&head,1);
    display(head);
    printf("\n");
    insert(&head,1);
    display(head);
    printf("\n");
    insert(&head,5);
    display(head);
    printf("\n");

    // Remove duplicates from linked list 
    removeDuplicates(head);
    display(head);


    return 0;
}
 