/*
 * 글자로 이루어진 파일을 정렬해준다. 
 * Formats a file of text 
 * 실행시 I/O redirection을 이용 <input_file >output_file
 */

#include "line.h"
#include "word.h"

#define MAX_WORD_LEN (20)

int main(void)
{
    char word[MAX_WORD_LEN + 2]; // 20줄 넘어가는 단어는 끝에 *을 붙이기 위해 20 + 1(*) + 1('\0')
    int word_len;

    clear_line();
    for (;;) {
        word_len = read_word(word, MAX_WORD_LEN + 1);
        if (word_len == 0) { // 더이상 읽을 단어가 없음. (마지막 줄의 끝부분)
            flush_line();
            return 0;
        }
        if (word_len > MAX_WORD_LEN) { 
            word[MAX_WORD_LEN] = '*';
        }
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}