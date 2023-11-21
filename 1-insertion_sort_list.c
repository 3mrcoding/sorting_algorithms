#include "sort.h"


void swap(listint_t **p_1, listint_t **p_2)
{
    listint_t *temp1, *temp2;

    temp2 = (*p_1)->prev;
    temp1 = (*p_2)->next;
    (*p_1)->next = temp1;
    temp1->prev = *p_1;
    (*p_2)->next = *p_1;
    temp2->next = *p_2;
    (*p_1)->prev = *p_2;
    (*p_2)->prev = temp2;
}

void insertion_sort_list(listint_t **list)
{
    listint_t *p1, *p2, *tmp;

    tmp = *list;
    p1 = *list;
    p2 = p1->next;

    while (p2->next != NULL)
    {
        if (p2->n < p1->n)
        {
            swap(&p1, &p2);
            while (tmp->prev != NULL)
            {
                if (p1->n < tmp->n)
                {
                    swap(&tmp, &p1);
                    tmp = tmp->prev;
                    p1 = p1->prev;
                    if (tmp->n < p1->n)
                    {
                        p2 = p2->next;
                        p1 = p2->prev;
                        tmp = p1->prev;
                        break;
                    }
                }
                else
                {
                    p2 = p2->next;
                    p1 = p1->next;
                    tmp = p1->prev;
                    break;
                }
            }
        }
        else
        {
            p2 = p2->next;
            p1 = p2->prev;
            tmp = p1->prev;
        }
    }
}
