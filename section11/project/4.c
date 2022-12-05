// poker 최선의 수 뽑기 

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS (13)
#define NUM_SUITS (4)
#define NUM_CARDS (5)

void read_cards(char hand[NUM_CARDS][2]);
void analyze_hand(char hand[NUM_CARDS][2], bool* straight, bool* ace_low_straight, bool* flush, bool* royal_flush, bool* four, bool* three, int* pairs);
void print_result(bool straight, bool ace_low_straight, bool flush, bool royal_flush, bool four, bool three, int pairs);
void selection_sort(char hand[NUM_CARDS][2]);
bool duplicate_card(int rank, int suit, char hand[NUM_CARDS][2], int cards_read);

int main(void)
{
    bool straight = false;
    bool ace_low_straight = false;
    bool flush = false;
    bool royal_flush = false;
    bool four = false;
    bool three = false;
    int pairs = 0;

    char hand[5][2];
    for (;;) {
        read_cards(hand);
        analyze_hand(hand, &straight, &ace_low_straight, &flush, &royal_flush, &four, &three, &pairs);
        print_result(straight, ace_low_straight, flush, royal_flush, four, three, pairs);
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
        } else if (duplicate_card(rank, suit, hand, cards_read)) {
            printf("Duplicate card; ignored.\n");
        } else {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

// 카드 중복검사
bool duplicate_card(int rank, int suit, char hand[NUM_CARDS][2], int cards_read)
{
    for (int i = 0; i < cards_read; i++) {
        if (hand[i][0] == rank && hand[i][1] == suit) {
            return true;
        }
    }
    return false;
}

void analyze_hand(char hand[NUM_CARDS][2], bool* straight, bool* ace_low_straight, bool* flush, bool* royal_flush, bool* four, bool* three, int* pairs)
{
    int card, rank, matches;

    selection_sort(hand);

    // flush check (나중에 NUM_CARDS가 수정되어도 유지 가능한 코드로 작성됨)
    for (card = 1; card < NUM_CARDS; card++) {
        if (hand[card][1] != hand[0][1]) {
            break;
        }
        if (card == NUM_CARDS - 1) {
            *flush = true;
        }
    }

    // straight check
    for (card = 1; card < NUM_CARDS; card++) {
        if (hand[card][0] - hand[card - 1][0] != 1) {
            break;
        }
        if (card == NUM_CARDS - 2 && hand[NUM_CARDS - 1][0] == 12) {
            *ace_low_straight = true;
            break;
        }
        if (card == NUM_CARDS - 1) {
            *straight = true;
            if (flush && hand[0][0] == 8) {
                *royal_flush = true;
                return;
            }
        }
    }

    // all pairs check
    for (int i = 0; i < NUM_CARDS; i++) {
        matches = 0;
        for (int j = i + 1; j < NUM_CARDS; j++) {
            if (hand[j][0] == hand[i][0]) {
                matches++;
            }
        }

        if (matches == 1) {
            (*pairs)++;
        }
        if (matches == 2) {
            *three = true;
        }
        if (matches == 3) {
            *four = true;
        }
    }
}

void print_result(bool straight, bool ace_low_straight, bool flush, bool royal_flush, bool four, bool three, int pairs)
{
    if (royal_flush) {
        printf("Royal straight");
    } else if (straight && flush) {
        printf("Straight flush");
    } else if (four) {
        printf("Four of a kind");
    } else if (three && pairs == 1) {
        printf("Full house");
    } else if (flush) {
        printf("Flush");
    } else if (ace_low_straight) {
        printf("Ace-low straight");
    } else if (straight) {
        printf("Straight");
    } else if (three) {
        printf("Three of a kind");  
    } else if (pairs == 2) {
        printf("Two pairs");
    } else if (pairs == 1) {
        printf("Pair");
    } else {
        printf("High card");
    }

    printf("\n\n");
}

// 선택정렬: 제일 작은 것을 찾아서 첫번째 인덱스에 넣는 것을 반복
void selection_sort(char hand[][2])
{
    int smallest;
    char temp_rank, temp_suit;
    
    for (int index = 0; index < NUM_CARDS; index++) {
        smallest = index;
        for (int j = index + 1; j < NUM_CARDS; j++) {
            if (hand[smallest][0] > hand[j][0]) {
                smallest = j;
            }
        }
        temp_rank = hand[index][0];
        temp_suit = hand[index][1];
        hand[index][0] = hand[smallest][0];
        hand[index][1] = hand[smallest][1];
        hand[smallest][0] = temp_rank;
        hand[smallest][1] = temp_suit;
    }
}