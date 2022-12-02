// Remove the numi nrank, numi nsuit, and card_exists arrays from the poker. c program of Section 10.5.
// Have the program store the cards ni a 5 x 2 array instead.
// Each row of the array will represent a card. For example, if the array is named hand, then hand [0] [0] will store the rank of the first card and hand [0] [1] will store the suit of the first card.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS (13)
#define NUM_SUITS (4)
#define NUM_CARDS (5)

bool g_straight;
bool g_flush;
bool g_four;
bool g_three;
int g_pairs;

void read_cards(char hand[][2]);
void analyze_hand(char hand[][2]);
void print_result(void);
void sort(char hand[][2]);

int main(void)
{
    char hand[5][2];
    for (;;) {
        read_cards(hand);
        sort(hand);
        // analyze_hand(hand);
        // print_result();
    }
}

void read_cards(char hand[][2])
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int hand_rank = 5, hand_suit = 2;
    int cards_read = 0;

    // initializing card array
    for (rank = 0; rank < hand_rank; rank++) {
        for (suit = 0; suit < hand_suit; suit++) {
            hand[rank][suit] = 0;
        }
    }

    // card(deck) input
    while (cards_read < NUM_CARDS) {
        bad_card = false;
        rank = 0;
        suit = 0;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }
        
        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        } 
        
        // white space 거르기 (getchar의 특성때문에;)
        while ((ch = getchar()) != '\n') {
            if (ch != ' ') {
                bad_card = true;
            }
        }

        if (bad_card) {
            printf("Bad card; ignored.\n");
        } else {
            for (int rank_check = cards_read; rank_check >= 0; rank_check--) {
                if (hand[rank_check][0] == rank && hand[rank_check][1] == suit) {
                    printf("Already exist; try again.\n");
                    continue;
                }
            }
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            ++cards_read;
        }
    }
}

// void analyze_hand(char hand[][2])
// {
//     int rank, suit;
//     g_straight = false;
//     g_flush = false;
//     g_four = false;
//     g_three = false;
//     g_pairs = 0;

//     // 플러시인지 검사
//     if (hand[0][1] == hand[1][1] && hand[1][1] == hand[2][1] && hand[2][1] == hand[3][1] && hand[3][1] == hand[4][1]) {
//         g_flush = true;
//         return;
//     }

//     // 스트레이트인지 검사
//     sort(hand[][2]);


//     // 포카드, 트리플, 페어 검사
//     for (rank = 0; rank < NUM_RANKS; rank++) {
//         if (num_in_rank[rank] == 4) {
//             g_four = true;
//         }
//         if (num_in_rank[rank] == 3) {
//             g_three = true;
//         }
//         if (num_in_rank[rank] == 2) {
//             g_pairs++;
//         }
//     }
// }

void print_result(void)
{
    if (g_straight && g_flush) {
        printf("Straight flush");
    } else if (g_four) {
        printf("Four of a kind");
    } else if (g_three && g_pairs == 1) {
        printf("Full house");
    } else if (g_flush) {
        printf("Flush");
    } else if (g_straight) {
        printf("Straight");
    } else if (g_three) {
        printf("Three of a kind");  
    } else if (g_pairs == 2 ) {
        printf("Two pairs");
    } else if (g_pairs == 1) {
        printf("Pair");
    } else {
        printf("High card");
    }

    printf("\n\n");
}

void sort(char hand[][2])
{
    int high = 0;
    int last = NUM_CARDS;

    char temp_rank, temp_suit;
    
    while (last > 0) {
        for (int i = 0; i < last; i++) {
            if (hand[high][0] < hand[i][0]) {
                high = i;
            }
            printf("high_index: %d -> \n", high);
        }
        puts("");
        temp_rank = hand[last][0];
        temp_suit = hand[last][1];
        hand[last][0] = hand[high][0];
        hand[last][1] = hand[high][1];
        hand[high][0] = temp_rank;
        hand[high][1] = temp_suit;
        last--;
        high = 0;
    }
    for (int i = 0; i < 5; i++)
        printf("%d\n", hand[i][0]);
}