#ifndef LINE_H

#define LINE_H

#define MAX_LINE_LEN (60)

// 라인을 초기화
void clear_line(void);

// 라인에 단어추가
void add_word(const char* word);

// 라인에 남은 공간 (MAX_LINE_LEN에 의존)
int space_remaining(void);

// 현재의 라인을 정렬하여 출력
void write_line(void);

// 현재의 라인을 정렬없이 출력
void flush_line(void);

#endif