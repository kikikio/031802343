#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fp=fopen("pakcet_capture.txt","r");
	char I[1000],O[100],t[10]; //I:������ļ��� O��������ļ� 
	int j,k,z;
	while(fgets(I,1000,fp)){
		for(j=19,k=0;I[j]!=':';j++,k++) O[k]=I[j];	//��"������û�"��������
		O[k]=' ',k++; 
		for(j=strlen(I),z=0;I[j]!=' ';j--,z++) t[z]=I[j];	//�������length 
		for(z--;z>=0;z--)if (t[z]>='0'&&t[z]<='9') O[k]=t[z],k++;	//��length��ֵ��������  
		O[k]='\0';
		printf("%s\n",O);
	}
	fclose(fp);	
	return 0;
 } 
