#include <stdio.h>
int cnt[10]={0};
void count(char x); 
int main()
{
	int i,j; 
	char str[100];	
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)//ͳ�Ƴ��ִ��� 
		count(str[i]);
	int max,loc;
	for(i=9;i>=0;i--)if(cnt[i]>max)max=cnt[i],loc=i;//�ҳ��������� 
	while(max){
		for(j=0;j<max;j++)printf("%d",loc);
		cnt[loc]=max=0;
		for(i=9;i>=0;i--)if(cnt[i]>max)max=cnt[i],loc=i;//�ҳ��������� 
	}
	return 0;
}
void count(char x)//ͳ�Ƴ��ִ��� 
{
	int a=x-'0',j;
	for(j=0;j<10;j++)if(a==j)cnt[j]++;
}

