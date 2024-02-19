#include <stdio.h>


int main() {

	float n;
	int i, a = 0;

	printf("Enter a positive integer: ");
	scanf("%f", &n);
	

 
	if (n == 0 || n == 1 ||n<0 || n!= (int) n  )
	a= 1;
	

	for (i = 2; i <= n / 2; ++i) {

    
	if ((int)n % i == 0) {
	a = 1;	
	break;
    }
  }

 
	if (a == 0){
	printf("%d is a prime number.", (int) n);}
	else
	printf("%f is not a prime number.", n);
	return 0;
}
