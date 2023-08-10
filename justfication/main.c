#include <stdio.h>
#include "word.h"
#include "line.h"

int main(void)
{
    char word[MAX_WORD_LEN + _FOR_OVER20_STAR_ + _FOR_NULL_CHAR_];
    int len;

    clear_line();
    for (;;) {
        len = read_word(word, MAX_WORD_LEN + _FOR_OVER20_STAR_);

        // 더이상 읽을 단어가 없을때
        if (len == 0) {
            flush_line();
            return 0;
        }
        // 단어길이가 20이 넘어갈때
        if (len > MAX_WORD_LEN) {
            word[MAX_WORD_LEN] = '*';
        }
        // 라인이 다 찼을때 (단어수용불가능)
        // 띄어쓰기를 고려해 len + 1이 쓰임
        if (len + 1> space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}