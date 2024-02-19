#include <stdio.h>
#include <ctype.h>
#define CHAR_SIZE 20
void check_strong_passward(char s[])
{
	int string_length = 0, isContainNumber = 0, isContainCapital = 0, isContainSymbol = 0;
	
	while ( s[string_length] != '\0')
	{
		if (s[string_length] >= '0' && s[string_length] <= '9')
			isContainNumber = 1;
		else if (s[string_length] == '%' || s[string_length] == '!' || s[string_length] == '#' || s[string_length] == '@')
			isContainSymbol = 1;
		else if (s[string_length] >= 'A' && s[string_length] <= 'Z')
			isContainCapital = 1;
		string_length += 1;
	}
	
	if(isContainNumber && isContainCapital && isContainSymbol && string_length > 8)
		printf("The password is strong\n");
	else
		printf("The password is not strong\n");
}

int main(){
	char s[CHAR_SIZE];
	printf("Enter your password: ");
	scanf("%s", s);
	check_strong_passward(s);
}


