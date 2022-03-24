#include <stdlib.h>
#include <stdio.h>

// A box. Each box has an ID and a pointer to the box that resides inside
// of it. If the box has nothing inside of it, inner_box should be equal
// to NULL.
struct box {
    int id; 
    struct box *inner_box;
};

// Insert box: places the box "inner" inside of the box "outer".
// Since "outer" is being modified, we pass a pointer to "outer".
// Since "inner" is not being modified, we pass in "inner" directly.
void insert_box(struct box* outer, struct box * inner) {
    printf("insert box: placing id %d inside id %d\n", inner->id, outer->id);
    outer->inner_box = inner;
}

// Print box: prints a box and the box inside of it. This function
// is recursive and will end once a box is empty.
void print_box(struct box* first, int level) {
    int i;
    if (!first) 
        return;

    for (i=0; i < level; ++i) {
        printf("- ");
    }       
    printf("id: %d\n", first->id);
    print_box(first->inner_box, level+1);
}

int main() {
    // Create three boxes.
    struct box box1 = { .id = 37, .inner_box = NULL };
    struct box box2 = { .id = 12, .inner_box = NULL };
    struct box box3 = { .id = 19, .inner_box = NULL };

    // The box ordering should be box1 -> box2 -> box3
    insert_box(&box1, &box2);
    insert_box(&box2, &box3);
    
    // Print the boxes starting from the outside box.
    print_box(&box1, 0);

    return 0;
}