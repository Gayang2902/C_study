#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN (20)

int compare_words(const void* p, const void* q);

int main(void)
{
    char** words = NULL;
    char* word = NULL;
    int num_word = 0;
    int words_size = 1;

    words = (char**)malloc((size_t)sizeof(char*));

    for (int i = 0; ; i++) {
        word = (char*)malloc(MAX_WORD_LEN + 1);
        printf("Enter a word: ");
        // fgets 함수는 파일스트림용 함수이기 때문에 문자열 마지막에 \n도 삽입된다.
        fgets(word, MAX_WORD_LEN + 1, stdin);
        // fgets 함수로 인한 \n을 문자열에서 제거
        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }
        if (word[0] == '\0') {
            break;
        }

        *(words + i) = word;
        num_word++;

        // words가 다 찰때마다 사이즈를 두배로 늘린다.
        if (words_size == num_word) {
            if ((words = (char**)realloc(words, sizeof(char*) * (words_size *= 2))) == NULL) {
                puts("realloc failed");
                exit(EXIT_FAILURE);
            }
        }
    }

    qsort(words, num_word, sizeof(char*), compare_words);
    printf("\nIn sorted order: ");

    for (int i = 0; i < num_word; i++) {
        printf("%s ", *(words + i));
    }
    puts("");
}

int compare_words(const void* p, const void* q)
{
    return strcmp(*(char**)p, *(char**)q);
}