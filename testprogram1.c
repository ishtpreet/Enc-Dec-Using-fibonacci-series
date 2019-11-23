#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct list {
char *val;
struct list *next;
};

struct list *root;
struct list *head;
FILE *f;

/*
int node_counter=0;

int main(char *argv[], int argc)
{
	int i;
	i=init_list();
	open_file();
	print_list(head);
	return 0;
}

int init_list()
{
	node_counter = 0;
	root = (struct list *)malloc(sizeof(struct list));
	if(root==NULL)
	{
		printf("Init list failed \n");
		return(1);
	}
	root->next=NULL;
	return(0);
}


//insert a node at the end of the list
int list_add(char *string)
{
	struct list *curr;
	curr = (struct list*)malloc(sizeof(struct list));
	if(curr==NULL)
	{
		printf("Adding to a list failed \n");
		return(1);
	}
	if(node_counter==0)
	head=curr;
	curr->val=string;
	root->next=curr;
	curr->next=NULL;
	root=curr;
	node_counter++;
	return(0);
}

void print_list(struct list *head)
{
	struct list *ptr = head;
	while(ptr!=NULL)
	{
		printf("%s", ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
}

int stringtoken(char str[])
{
	char *pch;
	pch=strtok(str,",.-");
	while(pch!=NULL)
	{
		print_list(head);
		list_add(pch);
		pch=strtok(NULL,",.-");
	}
	return 0;
}

open_file()
{
	char fname[60];
	char line[128];
	printf("Give the name of the file\n");
	scanf("%s",fname);
	f=fopen(fname,"r");
	if(f!=NULL)
	{
		while(fgets(line,sizeof line,f)!=NULL) //read a line
		{
			stringtoken(line); //split line to tokens
		}
		fclose(f);
	}
	else
	{
		printf("Error opening the file");
		return(1);
	}
	return 0;
} 
*/
//however this code fragment would be much easier to code into if we take and read the contents of the file to an array and enque it into the queue for further processing.

int main()
{
/*
	int i=0;
	char *string[100];
	char line[100];
	FILE *file;
	file=fopen("text.txt","r");
	while(fgets(line, sizeof(line), file)!=NULL)
	{
		printf("%s",line);
		string[i]=line;
		i++;
	}
	for(i=0;i<4;i++)
	{
		printf("\n%s",string[i]);
	}
	fclose(file);
	return 0;  */
//
//However there was a problem
//like if string was "Hello this is the first iteration: the breaked strings we were getting were hello, this, is and so on...
//We can get this to work with fscanf to get all the data
//We will read all the characters that are not white space and after every character, remove any white space after it.
//The improved code will be like this

char line[100];
char junk[100];
FILE *file = fopen("text.txt","r");
if(!file)
{
	printf("Could not open file. Exiting application. Bye!");
	return 1;
}
while(!feof(file))
{
	fscanf(file,"%[^\n\t\r]s",line); //Get text
	printf("%s\n",line);
	fscanf(file,"%[\n\t\r]s",junk); //Remove any 'white space' characters
}
fclose(file); 
}
//It is based on iterations over getting all the character and this would be used inside the previous code

//We can enque these elements to queue using ENQUE and DEQUEUE









