#include <stdio.h>

#define SIZE 20
void expand(char s[SIZE])
{
	int string_length = 0;
	while ( s[string_length] != '\0')
		string_length += 1;
		
	if(s[1] == '-' && string_length == 3)
		for(char i = s[0]; i <= s[2]; ++i)
			if (i <= '9' || (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
				printf("%c, ", i);
}
int main()
{printf("Enter your abbreviations: ");
	char s[SIZE];
	scanf("%s", s);
	expand(s);
	printf("\n");
	
}
