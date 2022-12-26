#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
} * start, *tail, *t, *p, *q, *n;

void create()
{
    n = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter the Data : ");
    scanf("%d", &x);
    n->data = x;
    n->next = 0;
    n->prev = 0;
} // create

void display()
{
    if (start == 0)
    {
        printf("List is EMPTY\n");
    }
    else
    {
        t = start;
        while (t != 0)
        {
            printf("%u  %u  %d  %u\n", t, t->prev, t->data, t->next);
            t = t->next;
        }
    }
}

void add_beg()
{
    if (start == 0)
    {
        start = n;
        tail = n;
    }
    else
    {
        n->next = start;
        start->prev = n;
        start = n;
    }
}

void add_end()
{
    create();
    if (start == 0)
    {
        start = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

void del_beg()
{
    if (start == 0)
    {
        printf("List is EMPTY\n");
    }
    else
    {
        t = start;
        start = start->next;
        start->prev = 0;
        free(t);
    }
}

void del_end()
{
    if (start == 0)
    {
        printf("List is EMPTY\n");
    }
    else
    {
        t = tail->prev;
        free(tail);
        tail = t;
        tail->next = 0;
        if (t == 0)
            start = 0;
    }
}

void add_inBet()
{
    int x;
    if (start == 0)
    {
        printf("List is EMPTY\n");
    }
    else
    {
        create();
        printf("Enter the Data after which you want to add the node : ");
        scanf("%d", &x);
        t = start;
        while (t->data != x && t != 0)
        {
            t = t->next;
        }
        if (t == 0)
        {
            printf("Entered Node is not present\n");
        }
        else
        {
            p = t->next;
            n->next = p;
            p->prev = n;
            t->next = n;
            n->prev = t;
        }
    }
}

void del_inBet()
{
    int x;
    if (start == 0)
    {
        printf("List is EMPTY\n");
    }
    else
    {
        printf("Enter the Data of the node want to delete : ");
        scanf("%d", &x);
        if (start->data == x)
        {
            del_beg();
        }
        else
        {
            t = start;
            while (t->data != x && t != 0)
            {
                t = t->next;
            }
            if (t == 0)
            {
                printf("Entered Node is not present\n");
            }
            else
            {
                p = t->prev;
                q = t->next;
                p->next = q;
                q->prev = p;
                free(t);
            }
        }
    }
}

void count()
{
    int count = 0;
    if (start == 0)
    {
        printf("%d", count);
    }
    else
    {
        t = start;
        while (t != 0)
        {
            count++;
            t = t->next;
        } // while
        printf("Number of nodes :%d\n", count);
    } // else
} // count

void search()
{
    int x;
    if (start == 0)
    {
        printf("List is EMPTY\n");
    }
    else
    {
        printf("Enter the Data which you want to search: ");
        scanf("%d", &x);
        t = start;
        while (t->data != x && t != 0)
        {
            t = t->next;
        }
        if (t == 0)
        {
            printf("Entered Node is not present\n");
        }
        else
        {
            printf("the data found at location %u\n", t);
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("1.Display\n2.Add at Beginning\n3.Add at Ending\n4.Delete Beginning\n5.Delete Ending\n6.Add in Between\n7.Delete in Between\n8.Count\n9.Search\n10.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            add_beg();
            break;
        case 3:
            add_end();
            break;
        case 4:
            del_beg();
            break;
        case 5:
            del_end();
            break;
        case 6:
            add_inBet();
            break;
        case 7:
            del_inBet();
            break;
        case 8:
            count();
            break;
        case 9:
            search();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}