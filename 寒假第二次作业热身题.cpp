#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fp=fopen("Request.txt","r");
	FILE *fw=fopen("output.txt","w");
	char a[30];
	while(fgets(a,30,fp)){
		fputs(a,fw);
	}
	fclose(fp);
	fclose(fw);	
	return 0;
 } 
