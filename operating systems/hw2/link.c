    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct node_t {
        int id;
        char name[10];
        struct node_t *next;
    }node_t;

    /* Iterate through the sorted list (by node_t::id), and find the position after
     * which the new 'node' should be inserted in the list. Ensure that the list
     * is kept sorted. Return the element just before the newly inserted one.
     * If the new 'node' should be inserted at the beginning, return NULL.
     */

    node_t *
    find_insert_pos(node_t *head, node_t *node)
    {
        if (head == NULL) return NULL;

        node_t *ret = NULL;

        // 2.1 your code here
        if(node -> id < head -> id)
        {
            return NULL;
        }

        ret = head;
        while(ret)
        {
            if( ret -> id >= node -> id ) 
            {   
                return ret;
            }
            if(ret -> next -> id > node -> id) 
            {
                return ret;
            }
            ret = ret -> next;
        }

        return ret;
    }

    /* insert a new 'node' into the list 'head', return the new head of the list.
    node_t */
    node_t * 
    list_insert(node_t *head, node_t *node)
    {
        if (head == NULL) return node;

        // find the proper position to insert this node pair.
        node_t *pos = find_insert_pos(head, node);

        // 2.2 your code here

        if(!pos)
        {
            node -> next = head;
            head = node;
        }
        else
        {
            node -> next = pos -> next;
            pos -> next = node;
        }
    }

    int
    main(void)
    {
        node_t *student_list = NULL;

        // init first student Alice
        node_t *student_1 = (node_t *)malloc(sizeof(node_t));
        student_1->id = 1002;
        strcpy(student_1->name, "Alice");
        student_1->next = NULL;

        // init second student Bob
        node_t *student_2 = (node_t *)malloc(sizeof(node_t));
        student_2->id = 1000;
        strcpy(student_2->name, "Bob");
        student_2->next = NULL;

        node_t *student_3 = (node_t *)malloc(sizeof(node_t));
        student_3->id = 13;
        strcpy(student_3->name, "xi");
        student_3->next = NULL;

        node_t *student_4 = (node_t *)malloc(sizeof(node_t));
        student_4->id = 14;
        strcpy(student_4->name, "anqi");
        student_4->next = NULL;

        student_list = list_insert(student_list, student_1);
        student_list = list_insert(student_list, student_2);
        student_list = list_insert(student_list, student_3);
        student_list = list_insert(student_list, student_4);

        // now we should have a student list:
        //    <1000, Bob> -> <10002, Alice> -> NULL

        //... free resources ...

        node_t * w = student_list;
        while(w)
        {
            printf("%s is %d\n", w -> name, w -> id);
            w = w -> next;
        }
        return 0;
    }