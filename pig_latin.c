#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

char* convert_to_lowercase(char* str) {
	char *str2 = strdup(str);
	for (int i = 0; str2[i]; i++) {
		str2[i] = tolower(str2[i]);
	}
	return str2;
}

char* word_to_pig_latin(char* str) {
	if(tolower(str[0]) == ‘a’ || tolower(str[0]) == ‘e’ || tolower(str[0]) == ‘i’ || tolower(str[0]) == ‘o’ || tolower(str[0]) == ‘u’) {
		char* new_str = malloc(strlen(str) + 4);
		strcpy(new_str, str);
		strcat(new_str, “way”);
		new_str[strlen(str) + 3] = 0;
		return new_str;
	}
	else {
		int cap = isupper(str[0]);
		int nConsonant = 0;
		for(int i = 0; i < strlen(str); i++){
			if(tolower(str[i]) != ‘a’ && tolower(str[i]) != ‘e’ && tolower(str[i]) != ‘i’ && tolower(str[0]) != ‘o’ && tolower(str[0]) != ‘u’){
				break;	
			}
			nConsonant++;
		}
		char* new_str = malloc(strlen(str) + 3);
		strncpy(new_str, &str[nConsonant], strlen(str) - nConsonant);
		strncat(new_str, str, nConsonant);
		strcat(new_str, “ay\0”);
		return new_str;
	}
}
