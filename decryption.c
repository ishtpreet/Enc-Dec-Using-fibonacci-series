#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int Fibonacci[30]; //Array with first 30 fibonacci numbers
int Arr[15];	   //Storing Indexes of Fibonacci numbers

struct EncryptedString
{
	int finalCode[100];
	int length;
	char String[100];
	int Ascii[100];
	unsigned long int Binary[100];
	int XORDecimal[100];
	unsigned long int FibonacciBinary[100];
	unsigned long int XorBinary[100];
}S;

char keyword[1];

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

	printf("Fibonacci Numbers : ");
	/*	
	for(i=1;i<30;i++)
	{
		printf("%d ",Fibonacci[i]);
	}
*/
	printf("\n");
}

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

int og_binarycodetodecimal(int D1[])
{
	int i;
	float decimal = 0.0;
	for (i = 0; i < 8; i++)
	{
		decimal = decimal + D1[i] * pow(2.0, i);
	}
	return decimal;
}

//Function1 to convert final code decimal to binary fibonacci format

void decToBinary() 
{ 
	int i;
	int j,k;
	int dn,n;
	int binno;
	for(k=0; k<S.length; k++)
	{
		i = 1;
		binno = 0;
		n = S.finalCode[k];
		dn = n;
		for(j=n;j>0;j=j/2)
		{
			binno=binno+(n%2)*i;
			i=i*10;
			n=n/2;
		}
		S.Binary[k] = (long int)binno;
		printf("\n%lu", S.Binary[k]);
	}
}

void Xor()
{
	int i,j, xor_code;
	for(j=0; j< S.length; j++)
	{
	xor_code = 0;
	for (i = 0; i < 8; i++)
	{
		if (S.[i] == 1)
		{
			xor_code = xor_code + Fibonacci[i + 1];
		}
	}
	S.XorBinary[j] = xor_code;
	printf("Xor code = %d\n", xor_code);
	}
}

int main()
{
	int i;
	printf("Enter Keyword letter\n");
	scanf("%s", keyword);
	printf("\nEnter number of string");
	scanf("%d",&S.length);
	for(i=0;i<S.length;i++)
	{
		printf("\nEnter %d Final Code\t",i+1);
		scanf("%d", &S.finalCode[i]);
		//printf("\n%d",S.finalCode[i]);
	}	

	decToBinary();
	//printf("%s",original);
	int as1 = (int)keyword[0];
	//int as2=(int)keyword[0];

	
	 printf("\n");
	 fibonacci();

	// int xor_code = 0;
	// for (i = 0; i < 8; i++)
	// {
	// 	if (arr1[i] == 1)
	// 	{
	// 		xor_code = xor_code + Fibonacci[i + 1];
	// 	}
	// 	else
	// 	{
	// 	}
	// }
	// printf("Xor code = %d\n", xor_code);

	// int *bin2 = decimaltobinary(xor_code);
	// int arr2[8];
	// printf("XOR Binary code of plain letter and keyword letter = ");
	// for (i = 7; i >= 0; i--)
	// {
	// 	arr2[i] = bin2[i];
	// 	printf("%d ", bin2[i]);
	// }
	// printf("\n");

	// printf("\n");
	// printf("ASCII code of keyword letter = %d\n", as1);

	// int *bin3 = decimaltobinary(as1);
	// int arr3[8];
	// printf("XOR Binary code of plain letter and keyword letter = ");
	// for (i = 7; i >= 0; i--)
	// {
	// 	arr3[i] = bin3[i];
	// 	printf("%d ", bin3[i]);
	// }
	// printf("\n");

	// printf("XOR of plain letter and keyword letter = ");
	// int arr4[8];
	// int *og = binaryXOR(arr2, arr3);
	// for (i = 7; i >= 0; i--)
	// {
	// 	arr4[i] = og[i];
	// 	printf("%d ", og[i]);
	// }
	// printf("\nASCII code of plain letter = ");

	// int as2 = og_binarycodetodecimal(arr4);
	// printf("%d\n", as2);

	// char plain = (char)as2;
	// printf("Plain letter : %c\n", plain);
	return 0;
}
