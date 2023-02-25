#include "sort.h"
#include <stdio.h>

void cocktail_sort_list(listint_t **list)
{
    listint_t *head, *forward, *backward, *tmp;
    int flag;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    head = *list;

    do {
        flag = 0;
        for (forward = head; forward->next != NULL; forward = forward->next) {
            if (forward->n > forward->next->n) {
                tmp = forward->next;
                forward->next = tmp->next;
                tmp->next = forward;
                if (forward == head) {
                    head = tmp;
                    tmp->prev = NULL;
                } else {
                    forward->prev->next = tmp;
                    tmp->prev = forward->prev;
                }
                forward->prev = tmp;
                tmp->next->prev = forward;
                flag = 1;
                print_list(*list);
            }
        }

        if (flag == 0)
            break;

        flag = 0;
        for (backward = forward; backward != head; backward = backward->prev) {
            if (backward->n < backward->prev->n) {
                tmp = backward->prev;
                backward->prev = tmp->prev;
                tmp->next = backward->next;
                if (backward->next != NULL)
                    backward->next->prev = tmp;
                tmp->prev->next = backward;
                backward->next = tmp;
                backward->prev = tmp;
                flag = 1;
                print_list(*list);
            }
        }
        head = backward;
    } while (flag);
    *list = head;
}

