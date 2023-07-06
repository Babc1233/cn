#include<stdio.h>
#include<stdlib.h>
int prime(int n) 
{
	int i;
	int m = n / 2;
	for (i = 2; i <= m; i++) 
	{
		if (n % i == 0) 
		{
			return 0; 
		}
	}
	return 1; 
}

int GCD(int a, int b) {
	if(a==0)
	    return b;
	    
	return GCD(b%a , a); 
}


int powmod(int a, int m, int n)
{
    int r;
    int y = 1;
    while (m > 0)
    {
        r = m % 2;
        if (r == 1) {
            y = (y*a) % n;
        }
        a = a*a % n;
        m = m / 2;
    }
    return y%n;
}

int main()
{
	int n,p,q,phi_n;
	int data,cipher,decrypt;
	printf("Enter p and q:\n");
	scanf("%d %d",&p,&q);
	if(prime(p)==0 || prime(q)==0)
	{
		printf("invalid input");
		exit(1);
	}
	n=p*q;
	phi_n=(p-1)*(q-1);
	int e,d;
	printf("Enter the value of e: \n");
	scanf("%d",&e);
	for (e = e; e <= 100; e++) {
		if (GCD(phi_n, e) == 1)
			break;
	}
	for (int i = 1; i < phi_n; i++)
		if ((i * e) %phi_n== 1)
				d=i;	
	printf("Value of d: %d\n",d);
	printf("Enter some numerical data: ");
	scanf("%d", &data);
	cipher = powmod(data, e, n);
	printf("The cipher text is: %d\n", cipher);
	decrypt = powmod(cipher, d, n);
	printf("The decrypted text is: %d\n", decrypt);
	return 0;
}

