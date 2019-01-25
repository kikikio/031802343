#include <stdio.h>
int cnt[10]={0};
void count(char x); 
int main()
{
	int i,j; 
	char str[100];	
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)//统计出现次数 
		count(str[i]);
	int max,loc;
	for(i=9;i>=0;i--)if(cnt[i]>max)max=cnt[i],loc=i;//找出出现最多次 
	while(max){
		for(j=0;j<max;j++)printf("%d",loc);
		cnt[loc]=max=0;
		for(i=9;i>=0;i--)if(cnt[i]>max)max=cnt[i],loc=i;//找出出现最多次 
	}
	return 0;
}
void count(char x)//统计出现次数 
{
	int a=x-'0',j;
	for(j=0;j<10;j++)if(a==j)cnt[j]++;
}

