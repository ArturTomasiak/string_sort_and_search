#include <stdio.h>
#include <stdlib.h> 
#include "c_sort.h"

unsigned int length(const char* const str) {
    unsigned int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char to_lowercase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    else
        return c;
}


bool is_higher_alphabetical_order(const char* const questioned, const char* const compared_to) {
    unsigned int i = 0, j = 0;
    while (questioned[i] != '\0' || compared_to[j] != '\0') {
        if (!(to_lowercase(questioned[i]) >= 'a' && to_lowercase(questioned[i]) <= 'z'))
            i++;
        if (!(to_lowercase(compared_to[j]) >= 'a' && to_lowercase(compared_to[j]) <= 'z'))
            j++;
        if (to_lowercase(questioned[i]) < to_lowercase(compared_to[j])) 
            return true;
        if (to_lowercase(questioned[i]) > to_lowercase(compared_to[j])) 
            return false;
        i++; j++;
    }
    return length(questioned) < length(compared_to);
}

long long strarr_length(char* str_arr[]) {
    long long i = 0;
    while (str_arr[i] != NULL)
        i++;
    return i;
}

void str_insertion_sort(char* str_arr[]) {
    long long length = strarr_length(str_arr);
    for(long long i = 1; i < length; i++) {
        char* temp = str_arr[i];
        long long j = i - 1;
        while(j > -1 && is_higher_alphabetical_order(temp, str_arr[j])) {
            str_arr[j + 1] = str_arr[j];
            j--;
        }
        str_arr[j + 1] = temp;
    }
}

bool str_compare(char* tested, char* target) {
    for (unsigned int i = 0; target[i] != '\0'; i++){
        if (to_lowercase(tested[i]) != to_lowercase(target[i]))
            return false;
    }
    return true;
}

void str_binary_search(char* str_arr[], char* target, unsigned int arr_length) {
    unsigned int left  = 0; unsigned int right = strarr_length(str_arr) - 1; 
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (str_compare(str_arr[mid], target)){
            output.is_match = true;
            unsigned int up_match = 0, down_match = 0, result_index = 0;  //this section tests more positive matches
            int i = mid + 1;
            while (i < arr_length && str_compare(str_arr[i], target)){
                up_match++; i++;
            }
            i = mid - 1;
            while (i > -1 && str_compare(str_arr[i], target)){
                down_match++; i--;
            }
            output.length = up_match + down_match + 1;
            int matches[output.length];
            while (down_match != 0) {
                matches[result_index] = mid - down_match;
                down_match--; result_index++;
            }
            matches[result_index] = mid;
            result_index++;
            while (up_match != 0) {
                matches[result_index] = mid + up_match;
                up_match--; result_index++;
            }
            output.result = (int*)calloc(output.length, sizeof(int));
            for (int i = 0; i < output.length; i++)
                output.result[i] = matches[i];
            return;
        }

        else if(is_higher_alphabetical_order(target, str_arr[mid]))
            right = mid - 1;
        else
            left = mid + 1;
    }
}

int main(void) {
    char* array[20] = {
        "FREEZER",
        "cold",
        "canon",
        "apple",
        "AAAAAAAAAAAAAAAAAA",
        "distance",
        "tarrot cards",
        "microphone",
        "hair dryer",
        "candle",
        "Coffee mug",
        "Notebook",
        "Pen set",
        "Headphones",
        "Backpack",
        "Water bottle",
        "Sunglasses",
        "Smartphone case",
        "Watch",
        "canon event"
    };
    unsigned int arr_length = strarr_length(array);
    printf("\n%s\n", "unsorted array:");
    for (long long i = 0; i < arr_length; i++)
        printf("%s\n", array[i]);
    str_insertion_sort(array);
    printf("\n%s\n", "sorted array:");
    for (long long i = 0; i < arr_length; i++)
        printf("%s\n", array[i]);
    str_binary_search(array, "n", arr_length);
    printf("\n%s\n", "(index) search results:");
    if (output.is_match == false) 
        printf("%s\n", "no matches");
    else 
        for (int i = 0; i < output.length; i++)
            printf("%s\n", array[output.result[i]]);
    return 0;
}