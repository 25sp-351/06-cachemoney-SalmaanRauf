#include "memoization.h"
#include "cache.h"
#include <stdio.h>

#define BUFFER_SIZE 256

int main() {
    int money;
    char buffer[BUFFER_SIZE];

    init_cache(); // initialize cache with file persistence

    // read inpuit vals until EOF
    while (scanf("%d", &money) != EOF) {
        if (money < 0) {
            printf("%d = Invalid amount\n", money);
            continue;
        }

        // check if val is cached
        if (get_cached_value(money, buffer)) {
            printf("%d = %s (cached)\n", money, buffer);
        } else {
            convert_money_to_text(money, buffer, BUFFER_SIZE);
            store_in_cache(money, buffer); // store result for future use
            printf("%d = %s\n", money, buffer);
        }
    }

    save_cache_to_file(); // persist cache to a file
    return 0;
}
