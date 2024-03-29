#ifndef LINE_H
#define LINE_H

/* 현재 줄을 치운다. */
void clear_line();

/* 현재 줄의 끝에 단어를 추가한다. 
 * 줄의 첫번째 단어가 아니라면,
 * 단어 이전에 띄어쓰기 한 번 해준다. 
 * */
void add_word(const char *word);

/* 현재 줄에 남아있는 문자의 개수를 반환한다. */
int space_remaining(void);

/* 현재 줄을 정렬해서 작성한다. with justification */
void write_line(void);

/* 현재 줄에 정렬 없이 작성한다. without justification
 * 만약 줄이 비어있다면 아무 것도 하지 않는다. */
void flush_line(void);

#endif