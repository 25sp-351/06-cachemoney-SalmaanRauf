#ifndef MONEY_TO_TEXT_H
#define MONEY_TO_TEXT_H

#include <stdio.h>
#include <stdlib.h>

//  def max amt that will memoized
#define MAX_MONEY_VALUE 150000 

void convert_money_to_text(int money, char *buffer, size_t buffer_size);

#endif // MONEY_TO_TEXT_H
