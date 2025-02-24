#include "memoization.h"
#include <string.h>

// arrays to store words # 1-19 + mults of ten
static const char *ones[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static const char *tens[] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};


static void number_to_words(int num, char *buffer) {
    if (num == 0) {
        strcat(buffer, "zero");
        return;
    }

    // handling thousdands 
    if (num >= 1000) {
        strcat(buffer, ones[num / 1000]);
        strcat(buffer, " thousand");
        num %= 1000;
        if (num > 0) strcat(buffer, " ");
    }
    // handling hundreds
    if (num >= 100) {
        strcat(buffer, ones[num / 100]);
        strcat(buffer, " hundred");
        num %= 100;
        if (num > 0) strcat(buffer, " ");
    }

    // handling tens and one places
    if (num >= 20) {
        strcat(buffer, tens[num / 10]);
        if (num % 10) {  
            strcat(buffer, "-");
            strcat(buffer, ones[num % 10]);
        }
    } else if (num > 0) {
        strcat(buffer, ones[num]);
    }
}


 //main func - converts $ to words
void convert_money_to_text(int money, char *buffer, size_t buffer_size) {
    if (money < 0) {
        snprintf(buffer, buffer_size, "Invalid amount");
        return;
    }

    int dollars = money / 100; // get dollars amt
    int cents = money % 100;   // gets cents amt

    buffer[0] = '\0'; //clear buffer

    // conv dollars to words if any
    if (dollars > 0) {
        number_to_words(dollars, buffer);
        strcat(buffer, " dollars");
    }

    // conv cents to words if any
    if (cents > 0) {
        if (dollars > 0) strcat(buffer, " and ");
        number_to_words(cents, buffer);
        strcat(buffer, (cents == 1) ? " cent" : " cents");
    }
}
