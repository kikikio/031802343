# include <iostream>
# include <map>
# include <cstdlib>
# include <cmath>
# include "count_min_sketch.hpp"
# include <string.h>
# include <stdio.h>
# define T 5000
using namespace std;

int main(int argc, char **argv) 
{
  CountMinSketch c(0.01, 0.1);
  FILE *fp=fopen("Request.txt","r");
  struct man{	//�ڿ����� 
  	char name[50];
  }hac[100];
  
  char IP[50]={},t[10]={};
  int lenIP,length,z,h=0,sign;
  
  while(fgets(IP,50,fp)){
  	lenIP=strlen(IP);
  	z=0;
  	for(int j=lenIP-1;IP[j]!=' ';j--,z++)t[z]=IP[j];  //���򱣴�length��ֵ 
	for(int i=0,k=0;i<lenIP;i++){	//����ÿһ�����ݣ�ȥ��length����ֵ
  		if(IP[i]==' ')k++;
  		if(k==3){
  			IP[i]='\0';
			break; 
		  }
	  }
	for(z--,length=0;z>=0;z--){
		length+=(t[z]-'0')*pow(10,z);//����ԭ��length��ֵ 
	} 
	c.update(IP,length);	//���´�IP��������ֵ 
	sign=0;
	for(int j=0;j<h;j++)	//�ж��Ƿ��������� 
		if(strcmp(IP,hac[j].name)==0)sign=1; 
	if(sign==0&&c.estimate(IP)>=T)strcpy(hac[h].name,IP),h++;//��¼�ºڿ� 
  }
  
  for(int i=0;i<h;i++){
  	printf("%s\n",hac[i].name);
  }
	fclose(fp);
	return 0;
}


