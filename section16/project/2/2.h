#ifndef TWO_H

#define TWO_H

#define NAME_LEN (25)
#define MAX_PARTS (100)

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} g_inventory[MAX_PARTS];

#endif