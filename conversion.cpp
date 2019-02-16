#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fp=fopen("pakcet_capture.txt","r");
	char I[1000],O[100],t[10]; //I:输入的文件； O：输出的文件 
	int j,k,z;
	while(fgets(I,1000,fp)){
		for(j=19,k=0;I[j]!=':';j++,k++) O[k]=I[j];	//把"请求的用户"存入数组
		O[k]=' ',k++; 
		for(j=strlen(I),z=0;I[j]!=' ';j--,z++) t[z]=I[j];	//逆序存入length 
		for(z--;z>=0;z--)if (t[z]>='0'&&t[z]<='9') O[k]=t[z],k++;	//把length数值存入数组  
		O[k]='\0';
		printf("%s\n",O);
	}
	fclose(fp);	
	return 0;
 } 
