/* Write a program that calculates the average word length for a sentence. 
 * For simplicity, your program should consider a punctuation mark to be part of the word 
 * to which it is attached. Display the average word length to one decimal place.*/

#include <stdio.h>

int main(void)
{
    int cha;
    int each_length = 0, sentence = 0;

    printf("Enter a sentence: ");

    while (1) {
        cha = getchar();
        if (cha == ' ') {
            sentence++;
            continue;
        } else if (cha == '.') {
            sentence++;
            printf("Average word length: %.1f\n", (float)each_length / sentence);
            return 0;
        }
        each_length++;
    }
}