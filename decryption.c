#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Fibonacci[30]; //Array with first 30 fibonacci numbers
int Arr[15];	   //Storing Indexes of Fibonacci numbers
char Finall[100];

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
  char FiboBinaryCode[100];
}S;

struct temp
{
  int temp[100];
}t;

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
  /*
	printf("Fibonacci Numbers : ");
		
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

int decToBinary() 
{ 
	int i;
	int j,k,c=0;
	int dn,n;
	int binno;
  static int temp[8];
	for(k=0; k<S.length; k++)
	{
    int k=0;
		i = 1;
		binno = 0;
		n = S.finalCode[k];
		dn = n;
    int TEMP1[8];
    /*
    while(n>0)
    {
      if(n%2==0)
      {
        TEMP1[k++]=0;
      }
      else
      {
        TEMP1[k++]=1;
      }
      n=n/2;
      c++;
    }
    for(i=c;i<8;i++)
    {
      TEMP1[i] = 0;
    }
    
    for(i=0;i<8;i++)
    {
      printf("%d", TEMP1[i] );
    }
    
    for(i=0;i<8;i++)
    {
      binno = binno*10 + TEMP1[i];
    }
    printf("Binno %lu", binno);
	
    */
    for(j=n;j>0;j=j/2)
		{
			binno=binno+(n%2)*i;
			i=i*10;
			n=n/2;
      c++;
		}
    
		for(i=c;i<8;i++)
    {
      TEMP1[i] = 0;
    }
    
    S.Binary[k] = (long int)binno;
		printf("decToBinary Function : %lu\n", S.Binary[k]);
    //t.temp[k] = S.Binary[k];
    //return S.Binary[k];
  }
  //return t.temp;
}

int Xor()
{
	int i,j, xor_code;
	for(j=0; j< S.length; j++)
	{
	xor_code = 0;
  printf("H %lu\n", S.Binary[j]);
  FILE *fp = fopen("xyz.txt","w");
	fprintf(fp,"%lu",S.Binary[j]);
	
	fclose(fp);
	fp = fopen("xyz.txt","r");
		//fscanf(fp, "%lu", &Finally);
		//printf("%lu", Finally);
	fscanf(fp ,"%s", Finall);

  //fscanf(fp, "%s", &Finall);
  printf("K %s\n", Finall);
  
  	for (i = 0; i < 8; i++)
	{
    const char t2 = Finall[i];
    int t3 = t2 - '0';
    printf("%d", t3);
    if (t3 == 1)
		{
      //printf("%d ",Fibonacci[i+1]);
			xor_code = xor_code + Fibonacci[8-i];
		}
	}
	S.XORDecimal[j] = xor_code;
	printf("\nXor code = %d\n", S.XORDecimal[j]);
	return xor_code;
  }
}

int * ConvertDeciToBinary1()
{
  static int a[8];
  int i=0,c=0,j;
  for(j=0;j<S.length;j++)
  {
    while(S.XORDecimal[j]>0)
    {
      if(S.XORDecimal[j]%2==0)
      {
        a[i++]=0;
      }
      else
      {
        a[i++]=1;
      }
      S.XORDecimal[j] = S.XORDecimal[j]/2;
      c++;
    }
    for(i=c;i<8;i++)
    {
      a[i]=0;
    }
    return a;
  }
}


int * ConvertDeciToBinary2(int val)
{
  static int a[8];
  int i=0,c=0,j;
  while(val>0)
  {
    if(val%2==0)
    {
      a[i++]=0;
    }
    else
    {
      a[i++]=1;
    }
    val = val/2;
    c++;
  }
  for(i=c;i<8;i++)
  {
    a[i]=0;
  }
  return a;
}

int *myxor(int a1[], int a2[])
{
  int i,j;
  int PlainBinary[8];
  
  for(i=0;i<8;i++)
  {
    if(a1[i]==a2[i])
    {
      PlainBinary[i]=0;
    }
    else
    {
      PlainBinary[i]=1;
    }
  }
  return PlainBinary;
}

int BinarytoDeci(int a1[])
{
  int i;
  float decimal = 0.0;
  for(i=0;i<8;i++)
  {
    decimal = decimal + a1[i]*pow(2.0,i);
  }
  //printf("%f", decimal);
  return decimal;
}

int main()
{
	int i;
	printf("Enter Keyword letter\n");
	scanf("%s", keyword);
	printf("\nEnter number of string");
	scanf("%d",&S.length);
  printf("%d",S.length);
	for(i=0;i<S.length;i++)
	{
		printf("\nEnter %d Final Code\t",i+1);
		scanf("%d", &S.finalCode[i]);
		//printf("\n%d",S.finalCode[i]);
	}	


  long unsigned int a = decToBinary();
	//printf("%s",original);
  fibonacci();
  int x = Xor();
  
  int as1 = (int)keyword[0];
  printf("As %d\nxor %d\n", as1, x );
  int * bin1 = ConvertDeciToBinary2(as1);
  for(i=7;i>=0;i--)
  {
    printf("%d",bin1[i]);
  }
  printf("\n");
  int * bin2 = ConvertDeciToBinary1();
  for(i=7;i>=0;i--)
  {
    printf("%d",bin2[i]);
  }
  printf("\n");
  int * bin3 = myxor(bin1, bin2);
  int arr10[8];
  for(i=7;i>=0;i--)
  {
    arr10[i]=bin3[i];
    printf("%d",bin3[i]);
  }

  int bin4 = BinarytoDeci(arr10);
  printf("\nHola %d", bin4);
  char plain = (char)bin4;
  printf("\nOriginal %c", plain);

	return 0;
}
