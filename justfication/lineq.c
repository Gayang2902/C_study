#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "line.h"

int g_num_word = 0;
int g_line_len = 0;

struct Node {
    struct Node* next;
    char word[];
} * line_word = NULL;

void clear_line(void)
{
    struct Node* temp;
    while (line_word != NULL) {
        temp = line_word;
        line_word = line_word->next;
        free(temp);
    }
    line_word = NULL;
    g_line_len = 0;
    g_num_word = 0;
}

void add_word(char* word)
{
    // line_word가 항상 노드의 앞부분을 pointing하도록(line_word 자체는 값변경 x) 더블 포인터를 이용한다.
    struct Node** dp = &line_word;
    struct Node* new_line_word;
    if ((new_line_word = malloc(sizeof(struct Node) + strlen(word) + 1)) == NULL) {
        puts("malloc failed");
        exit(EXIT_FAILURE);
    }
    strcpy(new_line_word->word, word);
    new_line_word->next = NULL;

    while (*dp != NULL) { dp = &((*dp)->next); }
    (*dp) = new_line_word;
    g_line_len += strlen(word);
    if (g_num_word > 0) { g_line_len++; }
    g_num_word++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - g_line_len;
}

void write_line(void)
{
    int extra_space = space_remaining();
    int space_to_insert; // 단어들 간 띄어쓰기 계산용
    struct Node* cur = line_word;
    int word_len_count = 0;

    while (word_len_count < g_line_len && cur != NULL) {
        printf("%s", cur->word);
        // 단어가 하나이상이라면 띄어쓰기 계산 후 삽입
        if (g_num_word > 1) {
            space_to_insert = extra_space / (g_num_word - 1);
            for (int i = 0; i < space_to_insert; i++) { putchar(' '); }
            extra_space -= space_to_insert;
        }
        word_len_count += strlen(cur->word) + 1;
        g_num_word--;
        cur = cur->next;
    }
    putchar('\n');
}

void flush_line(void)
{
    struct Node* first = line_word;

    // 라인에 단어가 하나라도 있다면
    if (g_line_len > 0) {
        for (int i = 0; first != NULL; i++, first = first->next) {
            // 첫번째 단어가 아니고 뒤에 단어가 더 있다면 띄어쓰기
            if (i > 0 && first->next != NULL) { putchar(' '); }
            printf("%s", first->word);
        }
    }
    // 없다면 그냥 공백만
    puts("");
    clear_line();
}