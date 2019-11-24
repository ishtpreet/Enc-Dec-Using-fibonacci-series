#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LIMIT 400

int Fibonacci[30]; //Array with first 30 fibonacci numbers
int Arr[15];	   //Storing Indexes of Fibonacci numbers

int ASCIIKeyword;
char keyword[1];
char Finall[10];

struct originalString
{
	int length;
	char String[100];
	int Ascii[100];
	unsigned long int Binary[100];
	int XORDecimal[100];
	unsigned long int FibonacciBinary[100];
}S;

struct Binary
{
	double Binary[100];
}B;

//Function4  Decimal to Fibonacci Format (Step 5)

void fibonacci()
{
	Fibonacci[0] = 0;
	Fibonacci[1] = 1;
	int i;
	for (i = 2; i < 30; i++)
	{
		Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
	}
}
int check(int number)
{
	int i = 2;
	while (number >= Fibonacci[i])
	{
		i++;
	}
	return i;
}

void decimaltofibonacci()
{
	int no; //XORDecimal
	char *eptr;
	int final[8];
	fibonacci();
	int i, n, number, a, b, c, sum = 0, z = 0, j, k;
	printf("\nEncrypted Text is ");
	for(j=0; j< S.length-1; j++)
	{
		no = S.XORDecimal[j];
		number = no;
		i = 0;
		z = 0;
		sum = 0;
		while (sum != no)
		{
			a = check(number) - 1;
			if (a == 0)
			{
				Arr[i] = 1;
				sum++;
				i++;
				z++;
			}
			else if (a < 0)
			{
				break;
			}
			else
			{
				number = number - Fibonacci[a];
				sum += Fibonacci[a];
				Arr[i] = a;
				z++;
				i++;
			}
		}
		printf("\n");

		for (i = 0; i < 8; i++)
		{
			final[i] = 0;
		}
		int q = 0;
		while (q < z)
		{
			final[Arr[q++] - 1] = 1;
		}
		FILE *fp;
		fp=fopen("abc.txt","w");     
		for(k=0;k<8;k++) 
		{
			fprintf(fp,"%d",final[k]);
		}	
		fclose(fp);
		fp = fopen("abc.txt","r");
		//fscanf(fp, "%lu", &Finally);
		//printf("%lu", Finally);
		fscanf(fp ,"%s", Finall);
		fclose(fp);
		//printf("\n%s", Finall);
		S.FibonacciBinary[j] = strtol(Finall, &eptr, 2);
		printf("%lu ", S.FibonacciBinary[j]);
	}
	printf("\n");
	//S.XORDecimal[j] = final;
}
//Function3 Converting XORed output to decimal (Step 4)

//Function2 XOR the plain letter and keyword letter (Step 3)
void binaryXOR()
{
	int i;
	for(i=0;i<S.length-1;i++)
	{
		S.XORDecimal[i] = S.Ascii[i] ^ ASCIIKeyword;
		//printf("\n%d",S.XORDecimal[i]);
	}
}

//Function1 Converting ascii code to binary code (Preliminary Step)

void decToBinary() 
{ 
	int i;
	int j,k;
	int dn,n;
	int binno;
	for(k=0; k<S.length-1; k++)
	{
		i = 1;
		binno = 0;
		n = S.Ascii[k];
		dn = n;
		for(j=n;j>0;j=j/2)
		{
			binno=binno+(n%2)*i;
			i=i*10;
			n=n/2;
		}
		S.Binary[k] = (long int)binno;
	}
}

int main()
{
	printf("Enter Keyword letter\n");
	fgets(keyword, MAX_LIMIT, stdin);
	printf("Enter a string\n");
	fgets(S.String, MAX_LIMIT, stdin);
	for(S.length = 0; S.String[S.length] != '\0'; S.length++);
	int j;
	for(j = 0; j<S.length-1; j++)
	{
		S.Ascii[j] = (int)S.String[j];
		//printf("\n%d",S.Ascii[j]);
	}
	ASCIIKeyword = (int)keyword[0];
	printf("\n");
	decToBinary();
	// for(j = 0; j<S.length; j++)
	// {
	// 	printf("\n%lu",S.Binary[j]);
	// }
	printf("\n");
	binaryXOR();
	decimaltofibonacci();
	return 0;	
}
