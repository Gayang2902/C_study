#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS (13)
#define NUM_SUITS (4)
#define NUM_CARDS (5)

int g_num_in_rank[NUM_RANKS];
int g_num_in_suit[NUM_SUITS];
bool g_straight;
bool g_flush;
bool g_four;
bool g_three;
int g_pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

void read_cards(void)
{
    bool card_exists[NUM_RANKS][NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for (rank = 0; rank < NUM_RANKS; rank++) {
        g_num_in_rank[suit] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++) {
            card_exists[rank][suit] = false;
        }
    }
    for (suit = 0; suit < NUM_SUITS; suit++) {
        g_num_in_suit[suit] = 0;
    }
    while (cards_read < NUM_CARDS) {
        bad_card = false;

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
    }

    while ((ch = getchar()) != '\n') {
        if (ch != ' ') {
            bad_card = true;
        }
    }
    if (bad_card) {
        printf("Bad card; ignored.\n");
    } else if (card_exists[rank][suit]) {
        printf("Duplicate card; ignored.\n");
    } else {
        g_num_in_rank[rank]++;
        g_num_in_suit[suit]++;
        card_exists[rank][suit] = true;
        cards_read++;
    }
}

void analyze_hand(void)
{
    int num_consec = 0;
    int rank, suit;
    g_straight = false;
    g_flush = false;
    g_four = false;
    g_three = false;
    g_pairs = 0;

    for (suit = 0; suit < NUM_SUITS; suit++) {
        if (g_num_in_suit[suit] == NUM_CARDS) {
            g_flush = true;
        }
    }

    rank = 0;
    while (g_num_in_rank[rank] == 0 && ++rank)
    for (; rank < NUM_RANKS && g_num_in_rank[rank] > 0; rank++) {
        num_consec++;
    }
    if (num_consec == NUM_CARDS) {
        g_straight = true;
        return;
    }

    for (rank = 0; rank < NUM_RANKS; rank++) {
        if (g_num_in_rank[rank] == 4) {
            g_four = true;
        }
        if (g_num_in_rank[rank] == 3) {
            g_three = true;
        }
        if (g_num_in_rank[rank] == 2) {
            g_pairs++;
        }
    }
}

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