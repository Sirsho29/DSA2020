#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node1
{
    int empId;
    char empName[20];
    int salary;

    struct node1 *left;
    struct node1 *right;
};

struct node2
{
    int empId;
    char empCity[20];
    char dept[20];

    struct node2 *left;
    struct node2 *right;
};

struct node1 *root1 = NULL;
struct node2 *root2 = NULL;

struct node1 *newNode1(int id, char *name, int salary)
{
    struct node1 *temp = (struct node1 *)malloc(sizeof(struct node1));
    temp->empId = id;
    strcpy(temp->empName, name);
    temp->salary = salary;
    temp->left = temp->right = NULL;
    return temp;
}

struct node2 *newNode2(int id, char *city, char *dept)
{
    struct node2 *temp = (struct node2 *)malloc(sizeof(struct node2));
    temp->empId = id;
    strcpy(temp->empCity, city);
    strcpy(temp->dept, dept);
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node1 *root1, struct node2 *root2)
{
    if (root1 != NULL)
    {
        inorder(root1->left, root2->left);
        printf("(%d , %d , %s , %s , %s) \n", root1->empId, root1->salary, root1->empName, root2->empCity, root2->dept);

        inorder(root1->right, root2->right);
    }
}

void citySearch(struct node1 *root1, struct node2 *root2)
{

    if (root1 != NULL)
    {
        inorder(root1->left, root2->left);
        if (strcmp(root2->empCity, "BBS") == 0)
        {
            printf("(%d , %d , %s , %s , %s) \n", root1->empId, root1->salary, root1->empName, root2->empCity, root2->dept);
        }
        inorder(root1->right, root2->right);
    }
}

struct node2 *insert2(struct node2 *node1, int empId, char *city, char *dept)
{
    if (node1 == NULL)
        return newNode2(empId, city, dept);

    if (empId < node1->empId)
        node1->left = insert2(node1->left, empId, city, dept);
    else if (empId > node1->empId)
        node1->right = insert2(node1->right, empId, city, dept);
    return node1;
}

struct node1 *insert1(struct node1 *node1, int empId, char *name, int salary)
{
    if (node1 == NULL)
        return newNode1(empId, name, salary);

    if (empId < node1->empId)
        node1->left = insert1(node1->left, empId, name, salary);
    else if (empId > node1->empId)
        node1->right = insert1(node1->right, empId, name, salary);
    return node1;
}

struct node1 *search(struct node1 *root, int empId)
{
    if (root == NULL || root->empId == empId)
        return root;

    if (root->empId < empId)
        return search(root->right, empId);

    return search(root->left, empId);
}

void addNewEmployee(int empId, char *name, int salary, char *city, char *dept)
{
    if (search(root1, empId) != NULL)
    {
        printf("\nEmployee already exists !! \n");
    }
    else
    {
        if (root1 == NULL)
        {
            root1 = insert1(root1, empId, name, salary);
            root2 = insert2(root2, empId, city, dept);
        }
        else
        {
            insert1(root1, empId, name, salary);
            insert2(root2, empId, city, dept);
        }
    }
}

int main()
{
    addNewEmployee(1, "Sirsha", 3000, "Kalyani", "CSE");
    addNewEmployee(5, "Test", 3000, "Kolkata", "CS");
    addNewEmployee(3, "Riju", 3000, "BBS", "KIIT");
    //inorder(root1, root2);
    citySearch(root1,root2);

    return 0;
}
