#include "stdio.h"

struct node
{
    int data_element;
    struct node *next;
};

/* fucntion definations */
void display_all_elements(struct node *n);



void display_all_elements(struct node *n) 
{
    while (n != NULL)
    {
        printf("%d,",n->data_element);
        n = n->next;
    }
}

void display_element( struct node *n)
{
    printf("%d",n->data_element);
}


int main(void)
{
    struct node *first_element;
    struct node *second_element;
    struct node *third_element;

    first_element = (struct node*) malloc(sizeof(struct node));
    second_element = (struct node*) malloc(sizeof(struct node));
    third_element = (struct node*) malloc(sizeof(struct node));

    first_element->data_element = 10;
    first_element->next = second_element;

    second_element->data_element = 20;
    second_element->next = third_element;

    third_element->data_element = 30;
    third_element->next = NULL;

    display_all_elements(first_element);

    free(first_element);
    free(second_element);
    free(third_element);

    return 0;
}