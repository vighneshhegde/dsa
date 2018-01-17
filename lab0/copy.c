#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int num;
	struct node *next;
}node;

typedef struct node *link;

typedef struct
{
	node *head;
	int size;
}list;

list createlist();//creates a new linked list
void push(int,list*);//add a new element to the list
int pop(list*);//pop from the beginning LIFO
int popl(list*);//pop from the end FIFO
void printlist(list l);
void printhelp();

int main(int argc, char* argv[])
{
	if (argc==2 && (strcmp(argv[1], "-h")==0))
	{
		printhelp();
		return 0;
	}
	if (argc<3|| argc>5)
	{
		printf("Incorrect number of arguments. Use the \"-h\" flag for help.\n");
		return 0;
	}
	system("date");

	int flag = 0;//this flag changes based on the command line arguments
	//printf("%s\n", argv[1]);
	if (strcmp(argv[1], "-o")==0)
	{
		flag = 2;
		//printf("flag set to 2. argc = %d\n", argc);
		if(argc<5)
		{
			printf("Insufficient Arguments. Use the \"-h\" flag for help.\n");
			return 0;
		}
	}


	FILE *f1, *f2;
	f1 = fopen(argv[flag+1], "r+");
	f2 = fopen(argv[flag+2], "w");
	list l = createlist();

	int a;
	while(fscanf(f1, "%d", &a) != EOF)
	{
		push(a,&l);
	}

	//printlist(l);

	if(flag==0)
	{
		// printf("ljh\n");
		while(l.size >0)
		{	
			a = popl(&l);
			fprintf(f2,"%d ",a);
		}
	}
	else
	{
		if(strcmp(argv[2],"alt") == 0)
		{
			// printf("abc\n");

			while(l.size >0)
			{	
				a = popl(&l);
				if(l.size>0)
					popl(&l);
				fprintf(f2,"%d ",a);
			}
		}
		else if(strcmp(argv[2],"rev") == 0)
		{
			// printf("xyz\n");
			//printf("rev");
			while(l.size >0)
			{	
				a = pop(&l);
				fprintf(f2,"%d ",a);
			}
		}
		else
		{
			printf("ERROR: Incorrect arguments. 'alt' and 'rev' are accepted.\n");
			return 0;
		}
	}
	fclose(f1);
	fclose(f2);
	//printf("done.\n");
}

list createlist()
{
	list *l=(list*)malloc(sizeof(list));
	l->head=NULL;
	l->size=0;
	return *l;
}

void push(int num, list* l)
{
	node *new;
	new = (node*)malloc(sizeof(node));
	new->num = num;
	new->next = l->head;
	l->head = new;
	l->size++;
}

int pop(list* l)
{
	int a=-1;
	if(l->head == NULL)
	{
		printf("ERROR: Nothing to pop");
		return a;
	}

	a = l->head->num;
	l->head = l->head->next;
	l->size--;
	return a;

}

int popl(list *l)
{
	int a=-1;
	if(l->head == NULL)
	{
		printf("ERROR: Nothing to pop");
		return a;
	}

	node *temp=(node*)malloc(sizeof(node));
	temp->next=l->head;
	
	for(;temp!=NULL;temp=temp->next)
	{
		if (temp->next->next==NULL)
		{	
			a = temp->next->num;
			temp->next=NULL;
			l->size--;
			//printf("%d\n", l->size);
		}
	}
	//printlist(*l);
	return a;
}

void printlist(list l)
{
	int i;
	node *temp=(node*)malloc(sizeof(node));
	temp->next=l.head;

	for (i=1; temp->next!=NULL; i++)
	{
		temp=temp->next;
		printf("%d ", temp->num);
		
	}
	printf("\n");
}

void printhelp()
{
	printf("Copies integers from one file to another.\n"
		"Usage: \t./copy [filepath1] [filepath2]\n"
		"\t./copy [flag] [command] [filepath1] [filepath2]\n"
		"Flags:\n\t\"-o\" - Copies in an order specified by following command.\n"
		"\tCommands:\n"
		"\t\t\"alt\" - Copies only alternate integers.\n"
		"\t\t\"rev\" - Copies in the reverse order\n"
		"\t\"-h\" - prints this help\n");

}