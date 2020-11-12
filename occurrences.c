#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int most_occurrences(int nums[], size_t length) {
    int max_occurrence = 0;
    int max_mode;
    for (size_t i = 0; i < length; i++) {
        int new_num = nums[i];
        int new_length = 0;
        for (size_t i = 0; i < length; i++) {
            if (nums[i] == new_num) {
                new_length++;
            }
        }
        if (new_length > max_occurrence) {
            max_occurrence = new_length;
            max_mode = nums[i];
        }
        else  if (new_length == max_occurrence) {
            if (nums[i] < max_mode) {max_mode = nums[i];}
        }
    }
    return max_mode;
}

int main(int argc, char *argv[]) {
    int nums[] = {7};
    printf("%d \n", most_occurrences(nums, 1));
    return 0;
}