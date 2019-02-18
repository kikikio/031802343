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
  struct man{	//黑客名单 
  	char name[50];
  }hac[100];
  
  char IP[50]={},t[10]={};
  int lenIP,length,z,h=0,sign;
  
  while(fgets(IP,50,fp)){
  	lenIP=strlen(IP);
  	z=0;
  	for(int j=lenIP-1;IP[j]!=' ';j--,z++)t[z]=IP[j];  //逆序保存length数值 
	for(int i=0,k=0;i<lenIP;i++){	//对于每一组数据，去掉length的数值
  		if(IP[i]==' ')k++;
  		if(k==3){
  			IP[i]='\0';
			break; 
		  }
	  }
	for(z--,length=0;z>=0;z--){
		length+=(t[z]-'0')*pow(10,z);//计算原本length的值 
	} 
	c.update(IP,length);	//更新此IP的总请求值 
	sign=0;
	for(int j=0;j<h;j++)	//判断是否在名单内 
		if(strcmp(IP,hac[j].name)==0)sign=1; 
	if(sign==0&&c.estimate(IP)>=T)strcpy(hac[h].name,IP),h++;//记录新黑客 
  }
  
  for(int i=0;i<h;i++){
  	printf("%s\n",hac[i].name);
  }
	fclose(fp);
	return 0;
}


