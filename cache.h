#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// def cache size - vals less than 1500 are memoized
#define CACHE_SIZE 150000 

// func prototypes for cache ops
void init_cache();
bool get_cached_value(int money, char *buffer);
void store_in_cache(int money, const char *text);
void save_cache_to_file();
void load_cache_from_file();

#endif // CACHE_H
