#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LIMIT 400

int Fibonacci[30]; //Array with first 30 fibonacci numbers
int Arr[15];	   //Storing Indexes of Fibonacci numbers

int xortodecimal(int D1[])
{
	int i;
	float decimal = 0.0;
	for (i = 0; i < 8; i++)
	{
		decimal = decimal + D1[i] * pow(2.0, i);
	}
	return decimal;
}

//Function4  Decimal to Fibonacci Format (Step 5)

void fibonacci()
{
	Fibonacci[0] = 0;
	Fibonacci[1] = 1;
	int i;
	for (i = 2; i < 30; i++)
	{
		Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
		// printf("\n%d",Fibonacci[i]);
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

int *decimaltofibonacci(int no)
{

	static int final[8];
	fibonacci();
	int i, n, number, a, b, c;
	number = no;
	int sum = 0;
	i = 0;
	int z = 0;
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
	/*
	printf("Hello : ");
	for(i=0;i<8;i++)
	{
		printf("%d ",Arr[i]);
	}
	*/

	printf("\n");

	/*
Hey there

	int size = sizeof(Arr)/sizeof(Arr[0]); 
	//printf("\nSize : %d\n", z);
	for(i=0;i<8;i++)
	{
		int j;
		int con=0;
		for(j=0;j<z;j++)
		{
			if(i==(Arr[j]-1))
			{
				con++;
				//break;
			}
			else
			{
			}		
		}
		if(con==1)
		final[i]=1;
		else
		final[i]=0;
	}

Bye there
*/

	for (i = 0; i < 8; i++)
	{
		final[i] = 0;
	}
	int q = 0;
	while (q < z)
	{
		final[Arr[q++] - 1] = 1;
	}

	return final;
}

//Function3 Converting XORed output to decimal (Step 4)

//Function2 XOR the plain letter and keyword letter (Step 3)

int *binaryXOR(int A1[], int B1[])
{
	int i;
	static int C1[8];
	for (i = 0; i < 8; i++)
	{
		if (A1[i] == B1[i])
		{
			C1[i] = 0;
			;
		}
		else
		{
			C1[i] = 1;
		}
	}

	//printf("\n");
	return C1;
}

//Function1 Converting ascii code to binary code (Preliminary Step)

int *decimaltobinary(int n)
{
	static int a[8];
	int i = 0, c = 0;
	while (n > 0)
	{
		if (n % 2 == 0)
		{
			a[i] = 0;
			i++;
		}
		else
		{
			a[i] = 1;
			i++;
		}
		n = n / 2;
		c++;
	}
	printf("\n");
	for (i = c; i < 8; i++)
	{
		a[i] = 0;
	}
	/*for(i=7;i>=0;i--)
		{
			printf("%d",a[i]);		
		}*/
	return a;
}

int main()
{
	char originalstring[10];
	char keyword[1];
	printf("Enter Keyword letter\n");
	fgets(keyword, MAX_LIMIT, stdin);
	printf("Enter a string\n");
	fgets(originalstring, MAX_LIMIT, stdin);
	printf("%c ****",originalstring[0]);
	int as1 = (int)originalstring[0];
	int as2 = (int)keyword[0];
	printf("\n");
	printf("ASCII code of plain letter = %d \nASCII code of keyword letter = %d\n", as1, as2);

	/*
	int *A2=decimaltobinary(as1);
	int *B2=decimaltobinary(as2);

	printf("\n%d\n%d",*A2,*B2);
	*/
	int i;
	int *bin1 = decimaltobinary(as1);
	int arr1[8];
	printf("Binary code of plain letter   = ");
	for (i = 7; i >= 0; i--)
	{
		arr1[i] = bin1[i];
		printf("%d ", bin1[i]);
	}
	printf("\nBinary code of keyword letter = ");
	int *bin2 = decimaltobinary(as2);
	int arr2[8];
	for (i = 7; i >= 0; i--)
	{
		arr2[i] = bin2[i];
		printf("%d ", bin2[i]);
	}
	printf("\n");

	printf("XOR of plain letter and keyword letter = ");
	int arr4[8];
	int *xor = binaryXOR(arr1, arr2);
	for (i = 7; i >= 0; i--)
	{
		arr4[i] = xor[i];
		printf("%d ", xor[i]);
	}
	printf("\nDecimal of XORed code = ");
	int deci = xortodecimal(arr4);
	printf("%d\n", deci);
	int *fibo = decimaltofibonacci(deci);
	printf("\nFibonacci Format = ");
	int arr5[8];
	for (i = 7; i >= 0; i--)
	{
		arr5[i] = fibo[i];
		printf("%d ", fibo[i]);
	}
	printf("\n");

	// Converting the fibonacii format to decimal as final code to be sent (Step 6)

	int fibodeci = xortodecimal(arr5);
	printf("Final code to be sent = %d\n", fibodeci);

	return 0;

	
}

//--------------------------------------------------------------------

/*
	char *args[]={"./decryption", NULL};
	execvp(args[0],args);
*/
