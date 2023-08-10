/*  Maintaining a Parts Database (array version)
 *  | supporting operations |
 *  1. Add a new part number, part name, and initial quantity on hand
 *  2. Given a part number, print the name of the part and the current quantity on hand.
 *  3. Given a part number, change the quantity on hand.
 *  4. Print a table showing all information in the database.
 *  5. Terminate program execution.
 */

#include <stdio.h>
#include "readline.h"   
#include "4.h"
#include "quicksort.h"

int find_part(const struct part inventory[], int num_parts, int number);
void insert(struct part inventory[], int *num_parts);
void search(const struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);

/*******************************************************************
 * main: 사용자가 계산 코드를 입력하게함 -> 코드에 맞는 함수를 호출해서 계산 실행.  *
 *       사용자가 'q' 코드를 입력하기 전까지 반복.                          *
 *       틀린 코드를 입력 시 에러메시지 출력                                *
 *******************************************************************/

int main(void)
{
    struct part inventory[MAX_PARTS];
    char code;
    int num_parts = 0; // number of parts currently stored

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');
        
        switch (code) {
            case 'i':   insert(inventory, &num_parts);
                        break;
            case 's':   search(inventory, num_parts);
                        break;
            case 'u':   update(inventory, num_parts);
                        break;
            case 'p':   print(inventory, num_parts);
                        break;
            case 'q':   return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(const struct part inventory[], int num_parts, int number)
{
    for (int i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}

void insert(struct part inventory[], int *num_parts)
{
    int part_number;

    if (*num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(inventory, *num_parts, part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);
    printf("Enter price of part: ");
    scanf("%lf", &inventory[*num_parts].price);
    (*num_parts)++;
}

void search(const struct part inventory[], int num_parts)
{
    int number;
    int i;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price of part: %lf\n", inventory[i].price);
    } else {
        printf("Part not found.\n");
    }
}

void update(struct part inventory[], int num_parts)
{
    int i;
    int number;
    int change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

void print(struct part inventory[], int num_parts)
{
    quicksort(inventory, 0, num_parts - 1);

    printf("Part number    Part Name                "
           "Quantity on Hand            Price of part\n");
    for (int i = 0; i < num_parts; i++) {
        printf("%7d        %-25s%11d%17.2lf\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price);
    }
}