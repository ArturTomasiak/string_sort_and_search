#pragma once 
#include <stdbool.h>

struct search_data {
    bool is_match;
    int  length;
    int* result;
};
struct search_data output;

unsigned int length(const char* const str);
char to_lowercase(char c);
bool is_higher_alphabetical_order(const char* const questioned, const char* const compared_to);
long long strarr_length(char* str_arr[]);
void str_insertion_sort(char* str_arr[]);
bool str_compare(char* tested, char* target);
void search_recursion(char* str_arr[], char* target, unsigned int left, unsigned int right, unsigned int arr_length);
void str_binary_search(char* str_arr[], char* target, unsigned int arr_length);