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
		for(int j=0;j<i;j++)	//�¶�����Ƿ��Ѿ����ֹ�	 
			if(strcmp(n[i].name,n[j].name)==0){
				n[j].sum+=n[i].sum;//���Ѿ����ֹ����ͼӵ����ȳ��ֵ� 
				n[i].sum=0;
				break;	
			}
		i++;
	}
	for(int j=0;j<i+1;j++)
		if (n[j].sum>=1500)cnt++;//ͳ�ƺڿ���Ŀ
	printf("%d\n",cnt);
	for(int j=0;j<i+1;j++)
		if (n[j].sum>=1500)printf("%s\n",n[j].name);//������� 
	
	fclose(fp); 
	return 0;
}

