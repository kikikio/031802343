#include <stdio.h>
#include <string.h>
#define S 50  //假定次数分界线为50
#define T 150 //假定请求值分界线为150 
int main()
{
	FILE * fp=fopen("output.txt","r");
	struct date{
		char name[10];
		int x;	//请求值大小 
		int sum=0;	//垃圾请求的次数 
	}n[20000];
	struct man{
		char name[10];	//黑客用户名 
	}hac[20];
	int i=0,cnt=0,j,k=0,sign;
	while(fscanf(fp,"%s %*s %d",&n[i].name,&n[i].x)!=EOF){
		sign=1;
		for(int z=0;z<k;z++)if(strcmp(hac[z].name,n[i].name)==0){sign=0;i--;break;}//碰到已经记录的黑客名跳过 
		for(j=0;j<i&&sign;j++)	//新读入的（非黑客）是否已经出现过	 
			if(strcmp(n[i].name,n[j].name)==0&&n[i].x<=T){	//如果已经出现过且为垃圾请求 
				n[j].sum++;
				if(n[j].sum>=S)strcpy(hac[k].name,n[j].name),k++;  //记录新黑客用户名 
				break;
			}
		if(n[i].x<=T&&j==i)n[i].sum++;//如果没有出现过且为垃圾请求 
		i++; 
	}
	printf("%d\n",k);//输出黑客数目 
	for(int j=0;j<k;j++)
		printf("%s\n",hac[j].name);//输出名字 
	fclose(fp); 
	return 0;
}

