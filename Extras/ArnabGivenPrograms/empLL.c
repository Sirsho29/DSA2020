
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node1
{
    int empId;
    char empName[20];
    int salary;

    struct node1 *prev;
    struct node1 *next;
};

struct node2
{
    int empId;
    char empCity[20];
    char dept[20];

    struct node2 *prev;
    struct node2 *next;
};

struct node1 *head1 = NULL;
struct node2 *head2 = NULL;

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int swapC(char *a, char *b)
{
    char temp[20];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void insertAtTheBeginNode1(struct node1 **h, int empId, char *name, int salary)
{
    struct node1 *ptr;
    ptr = (struct node1 *)malloc(sizeof(struct node1));
    ptr->empId = empId;
    ptr->salary = salary;
    strcpy(ptr->empName, name);
    ptr->next = *h;
    if (*h != NULL)
        (*h)->prev = ptr;
    *h = ptr;
}

void insertAtTheBeginNode2(struct node2 **h, int empId, char *city, char *dept)
{
    struct node2 *ptr;
    ptr = (struct node2 *)malloc(sizeof(struct node2));
    ptr->empId = empId;

    strcpy(ptr->empCity, city);
    strcpy(ptr->dept, dept);
    ptr->next = *h;
    if (*h != NULL)
        (*h)->prev = ptr;
    *h = ptr;
}

void printList(struct node1 *head, struct node2 *head2)
{
    struct node1 *temp = head;
    struct node2 *temp2 = head2;
    printf("\n");
    while (temp != NULL)
    {
        printf("(%d , %d , %s , %s , %s) \n", temp->empId, temp->salary, temp->empName, temp2->empCity, temp2->dept);
        temp = temp->next;
        temp2 = temp2->next;
    }
}

void printListCity(struct node1 *head, struct node2 *head2)
{
    struct node1 *temp = head;
    struct node2 *temp2 = head2;
    int flag = 0;
    printf("\n");
    while (temp != NULL)
    {
        if (strcmp(temp2->empCity, "BBS") == 0)
        {
            flag = 1;
            printf("(%d , %d , %s , %s , %s) \n", temp->empId, temp->salary, temp->empName, temp2->empCity, temp2->dept);
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    if(flag == 0){
        printf("\nEmployee in BBS not found\n");
    }
}

void bubbleSort(struct node1 *head)
{
    int swapped, i;
    struct node1 *ptr;
    struct node1 *lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr)
        {
            if (ptr->empId > ptr->next->empId)
            {
                swap(&ptr->empId, &ptr->next->empId);
                swap(&ptr->salary, &ptr->next->salary);
                swapC(ptr->empName, ptr->next->empName);

                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

int searchList(struct node1 *head, int id)
{
    int flag = 0;
    struct node1 *temp = head;

    while (temp != NULL)
    {
        if (temp->empId == id)
        {
            flag = 1;
        }
        temp = temp->next;
    }
    return flag;
}

void addNewEmployee(int empId, char *name, int salary, char *city, char *dept)
{
    if (searchList(head1, empId) == 1)
    {
        printf("\nEmployee already exists !! \n");
    }
    else
    {
        insertAtTheBeginNode1(&head1, empId, name, salary);
        insertAtTheBeginNode2(&head2, empId, city, dept);
    }
}

int main()
{
    addNewEmployee(1, "Sirsha", 3000, "Kalyani", "CSE");
    addNewEmployee(5, "Sirsha", 4000, "BBS", "CSE");
    bubbleSort(head1);
    printList(head1, head2);
    printf("\n\n\n\n");
    printListCity(head1, head2);

    return 0;
}
