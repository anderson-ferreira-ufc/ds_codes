#include <stdio.h>

int length(char* str);
void copy(char* dest, char* orig);
void concatenate(char* dest, char* orig);

int main(void) {
	char str[101], str1[51], str2[51];
	
	printf("Enter a character string: ");
	scanf("%50[^\n]", str1);
	printf("Enter another character string: ");
	scanf("%50[^\n]", str2);
	
	return 0;
}


