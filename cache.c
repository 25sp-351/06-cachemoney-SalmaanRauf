#include "cache.h"
#include <string.h>
#include <stdio.h>

// cache can handle up to $1500 (150000 cents)
#define CACHE_SIZE 150000

// array to store text versions of money values we've seen before
static char cache[CACHE_SIZE][100];

// init cache and load from file
void init_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i][0] = '\0'; // Empty each cache entry
    }
    load_cache_from_file(); // Load persisted cache if available
}

// retrieves cached value if available
bool get_cached_value(int money, char *buffer) {
    if (money < CACHE_SIZE && cache[money][0] != '\0') {
        snprintf(buffer, 100, "%s", cache[money]); // copy cached value to buffer
        return true;
    }
    return false;
}

// stores computed val in cache
// 
// @param money - money val in cents
// @param text - text rep to store
void store_in_cache(int money, const char *text) {
    if (money < CACHE_SIZE) {
        snprintf(cache[money], 100, "%s", text); // Store the text in cache
    }
}

// saves cache to file for persistence across runs
void save_cache_to_file() {
    FILE *file = fopen("cache.dat", "w");
    if (!file) return;

    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i][0] != '\0') {
            fprintf(file, "%d=%s\n", i, cache[i]); // write cache entry to file
        }
    }
    fclose(file);
}

// loads cache from file if available
void load_cache_from_file() {
    FILE *file = fopen("cache.dat", "r");
    if (!file) return;

    int money;
    char text[100];
    while (fscanf(file, "%d=%99[^\n]\n", &money, text) == 2) {
        if (money < CACHE_SIZE) {
            snprintf(cache[money], 100, "%s", text); // restore cache entry
        }
    }
    fclose(file);
}
