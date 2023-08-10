/*  Maintaining a Parts Database (array version)
 *  | supporting operations |
 *  1. Add a new part number, part name, and initial quantity on hand
 *  2. Given a part number, print the name of the part and the current quantity on hand.
 *  3. Given a part number, change the quantity on hand.
 *  4. Print a table showing all information in the database.
 *  5. Terminate program execution.
 */

// s17(p1) 
// inventory[10] --> malloc
// if full realloc double size of part structure

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN (25)

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

struct part *g_inventory;

int g_num_parts = 0; // number of parts currently stored
int g_max_parts = 10;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/*******************************************************************
 * main: 사용자가 계산 코드를 입력하게함 -> 코드에 맞는 함수를 호출해서 계산 실행.  *
 *       사용자가 'q' 코드를 입력하기 전까지 반복.                          *
 *       틀린 코드를 입력 시 에러메시지 출력                                *
 *******************************************************************/

int main(void)
{
    char code;

    if ((g_inventory = malloc(sizeof(struct part) * g_max_parts)) == NULL) {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    printf("%zu\n", sizeof(struct part));
    printf("%zu\n", sizeof(*g_inventory));
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');
        
        switch (code) {
            case 'i':   insert();
                        break;
            case 's':   search();
                        break;
            case 'u':   update();
                        break;
            case 'p':   print();
                        break;
            case 'q':   return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(int number)
{
    for (int i = 0; i < g_num_parts; i++) {
        if (g_inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}

void insert(void)
{
    int part_number;

    if (g_num_parts == g_max_parts) {
        printf("%zu\n", sizeof(struct part));
        printf("%zu\n", sizeof(*g_inventory));
        if ((g_inventory = realloc(g_inventory, sizeof(struct part) * (g_max_parts *= 2))) == NULL) {
            // if ((g_inventory = realloc(g_inventory, sizeof(g_inventory) * (g_max_parts *= 2))) == NULL) {
            printf("Error: realloc failed\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    g_inventory[g_num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(g_inventory[g_num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &g_inventory[g_num_parts].on_hand);
    g_num_parts++;
}

void search(void)
{
    int number;
    int i;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part name: %s\n", g_inventory[i].name);
        printf("Quantity on hand: %d\n", g_inventory[i].on_hand);
    } else {
        printf("Part not found.\n");
    }
}

void update(void)
{
    int i;
    int number;
    int change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        g_inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

void print(void)
{
    printf("Part number    Part Name                "
           "Quantity on Hand\n");
    for (int i = 0; i < g_num_parts; i++) {
        printf("%7d        %-25s%11d\n", g_inventory[i].number, g_inventory[i].name, g_inventory[i].on_hand);
    }
}