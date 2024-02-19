#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void squeeze(int n, char str1[], char str2[],char str_re[]);
int main ()
{	int n,m;
	printf ("Enter the len of strings  1 and 2:\n");
	scanf("%d %d",&n,&m);
	
	char str1[n], str2[m] ,str_re[n];
	printf ("Enter the First string:\n");
	scanf("%s",str1);
	printf("Enter the Second string:\n");
	scanf("%s",str2);
	squeeze(n,str1,str2,str_re);
	}

void squeeze(int n, char str1[], char str2[],char str_re[]){
	int i,j;
	for ( i = 0,j=0; i<n; i++){
		if (str1[i]==str2[i])
			continue;
		else{
			str_re[j]=str1[i];
			j++;
			
		}
	}
	str_re[j]='\0';
	printf("%s\n",str_re);
}
