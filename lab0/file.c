#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* s;
	s = (char*)malloc(10*sizeof(char));
	FILE *f = fopen("test.txt", "r");
	// fprintf(f, "hello\n");
	fscanf(f,"%s", s);
	fclose(f);

	printf("%s as string\n", s);
	int sint = atoi(s);
	printf("%d as integer\n", sint);
}