#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *createNode(int value)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}
void push_front(node **array, int value)
{
    node *new_node = createNode(value);
    if (*array == NULL)
    {
        *array = new_node;
    }
    else
    {
        new_node->next = *array;
        *array = new_node;
    }
}
void push_back(node **array, int value)
{
    node *temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    if (*array == NULL) // if array doesn't have any node yet
    {

        *array = temp;
    }
    else // if array has some node
    {
        node *p = *array;       // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next; // check next node until it a last node
        }

        p->next = temp; // change it next member point to address of new node have just create
    }
}

void pop_back(node **array)
{
    node *p, *temp;
    p = *array;
    int i = 0; // to

    while (p->next->next != NULL) // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);
}

int get(node *array, int pos)
{
    int i = 0;

    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}
// đếm số lượng node
int size(node *head)
{
    int count = 0;
    if (head == NULL)
        return 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
}
// chèn 1 node vào vị trí bất kì trên mảng
void insert(node **head, int data, int position)
{

    node *new_node = createNode(data);
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        if (position == size(*head) - 1)
        {
            push_front(head, data);
        }
        else if (position == 1)
        {
            push_back(head, data);
        }
        else
        {
            node *p = *head;
            int index = 0;
            while (p != NULL && index != position - 1)
            {
                p = p->next;
                index++;
            }
            if (index == position - 1)
            {
                new_node->next = p->next;
                p->next = new_node;
            }
        }
    }
}
void display(node *head)
{
    int index = 0;
    if (head == NULL)
    {
        printf("Khong co Node!!!");
    }
    else
    {
        while (head != NULL)
        {
            printf(" Node %d: %d \n", index, head->value);
            index++;
            head = head->next;
        }
    }
}
int main()
{
    node *node1 = createNode(1);
    node *node2 = createNode(2);
    node *node3 = createNode(3);

    node1->next = node2;
    node2->next = node3;
    printf("Danh sach ban dau\n");
    push_back(&node1, 10);
    push_front(&node1, 7);
    display(node1);
    return 0;
}
