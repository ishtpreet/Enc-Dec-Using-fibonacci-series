#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
int final_code;
char keyword[1];
printf("Enter Final code to decrypt\n");
scanf("%d",&final_code);

printf("Enter Keyword letter\n");
scanf("%s",keyword);
//printf("%s",original);
int as1=(int)keyword[0];
//int as2=(int)keyword[0];


//Function1 to convert final code decimal to binary fibonacci format

int * decimaltobinary(int n)
{
static int a[8];
int i=0,c=0;
while(n>0)
{
if(n%2==0)
{
a[i]=0;
i++;
}
else
{
a[i]=1;
i++;
}
n=n/2;
c++;
}
printf("\n");
for(i=c;i<8;i++)
{
a[i]=0;
}
return a;
}

int i;
int * bin1=decimaltobinary(final_code);
int arr1[8];
printf("Fibonacci Binary code = ");
for(i=7;i>=0;i--)
{
arr1[i]=bin1[i];
printf("%d ",bin1[i]);
}
printf("\n");

int Fibonacci[30]; //Array with first 30 fibonacci numbers
int Arr[15];   //Storing Indexes of Fibonacci numbers

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
fibonacci();

int xor_code=0;
for(i=0;i<8;i++)
{
if(arr1[i]==1)
{
xor_code=xor_code + Fibonacci[i+1];
}
else
{
}
}
printf("Xor code = %d\n", xor_code);

int * bin2=decimaltobinary(xor_code);
int arr2[8];
printf("XOR Binary code of plain letter and keyword letter = ");
for(i=7;i>=0;i--)
{
arr2[i]=bin2[i];
printf("%d ",bin2[i]);
}
printf("\n");

printf("\n");
printf("ASCII code of keyword letter = %d\n",as1);

int * bin3=decimaltobinary(as1);
int arr3[8];
printf("XOR Binary code of plain letter and keyword letter = ");
for(i=7;i>=0;i--)
{
arr3[i]=bin3[i];
printf("%d ",bin3[i]);
}
printf("\n");


int * binaryXOR(int A1[], int B1[])
{
static int C1[8];
for(i=0;i<8;i++)
{
if(A1[i]==B1[i])
{
C1[i]=0;;
}
else
{
C1[i]=1;
}
}

//printf("\n");
return C1;
}
printf("XOR of plain letter and keyword letter = ");
int arr4[8];
int *og=binaryXOR(arr2, arr3);
for(i=7;i>=0;i--)
{
arr4[i]=og[i];
printf("%d ",og[i]);
}
printf("\nASCII code of plain letter = ");

int og_binarycodetodecimal(int D1[])
{
float decimal=0.0;
for(i=0;i<8;i++)
{
decimal=decimal+D1[i]*pow(2.0,i);
}
return decimal;
}
int as2=og_binarycodetodecimal(arr4);
printf("%d\n",as2);

char plain=(char)as2;
printf("Plain letter : %c\n", plain);






}
