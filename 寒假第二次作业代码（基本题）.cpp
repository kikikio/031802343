#include <stdio.h>
#include <string.h>
int main()
{
	FILE * fp=fopen("Request.txt","r");
	struct date{
		char name[10];
		char bob[10];
		int sum;
	}n[20000];
	int i=0,cnt=0;
	while(fscanf(fp,"%s %s %d",&n[i].name,&n[i].bob,&n[i].sum)!=EOF){
		for(int j=0;j<i;j++)	//新读入的是否已经出现过	 
			if(strcmp(n[i].name,n[j].name)==0){
				n[j].sum+=n[i].sum;//若已经出现过，就加到最先出现的 
				n[i].sum=0;
				break;	
			}
		i++;
	}
	for(int j=0;j<i+1;j++)
		if (n[j].sum>=1500)cnt++;//统计黑客数目
	printf("%d\n",cnt);
	for(int j=0;j<i+1;j++)
		if (n[j].sum>=1500)printf("%s\n",n[j].name);//输出名字 
	
	fclose(fp); 
	return 0;
}

