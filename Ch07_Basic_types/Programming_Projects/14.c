/* Write a program that uses Newton's method to compute the square root of 
 * a positive floating-point number
 * Let x be the number entered by the user. Newton's method requires an itial guess y for the square 
 * root of x (we'll use y = 1). Successive guesses are found by computing the average of y and x/y. 
 * The following table shows how the square root of 3 would be found
 *  x	y	        x/y	        Average of y and x/y
    3	1	        3	        2
    3	2	        1.5	        1.75
    3	1.75	    1.71429	    1.73214
    3	1.73214	    1.73196	    1.73205
    3	1.73205	    1.73205	    1.73205
 * Note that the values of y get progressively closer to the true square root of x. 
 * For greater accuracy, your program should use variable of type double rather than float.
 * Have the program terminate when the absolute value of the difference between 
 * the old value of y and the new value of y is less then the product of .00001 and y.
 * Hint: Call the fabs function to find the absolute value of a double. 
 * (You'll need to include the <math.h> header at the begging of your program in order to use fabs.) */

#include <stdio.h>
#include <math.h> // fabs() 를 이용해 double의 absolute 값을 구한다.

int main(void) // 제곱근을 가장 효율적으로 구하는 뉴턴-랩슨법
{   
    double x;
    double y = 1.0f, average;
    double old_y;
    int i = 1;
    // y의 기존 값과 Y의 새 값의 차이의 절대 값이 .00001과 y의 곱보다 작을 때.

    printf("Enter a positive number: ");
    scanf("%lf",&x);
    
    do {
        average = ((x/y) + y) / 2;
        old_y = y;
        y = average;
        printf("%d\n", i++); 
    } while (fabs(y - old_y) > (.00001 * y));

    printf("Square root: %.5lf\n", y);

    return 0;
}
