#include <stdio.h>
#include <string.h>
#define S 50  //�ٶ������ֽ���Ϊ50
#define T 150 //�ٶ�����ֵ�ֽ���Ϊ150 
int main()
{
	FILE * fp=fopen("output.txt","r");
	struct date{
		char name[10];
		int x;	//����ֵ��С 
		int sum=0;	//��������Ĵ��� 
	}n[20000];
	struct man{
		char name[10];	//�ڿ��û��� 
	}hac[20];
	int i=0,cnt=0,j,k=0,sign;
	while(fscanf(fp,"%s %*s %d",&n[i].name,&n[i].x)!=EOF){
		sign=1;
		for(int z=0;z<k;z++)if(strcmp(hac[z].name,n[i].name)==0){sign=0;i--;break;}//�����Ѿ���¼�ĺڿ������� 
		for(j=0;j<i&&sign;j++)	//�¶���ģ��Ǻڿͣ��Ƿ��Ѿ����ֹ�	 
			if(strcmp(n[i].name,n[j].name)==0&&n[i].x<=T){	//����Ѿ����ֹ���Ϊ�������� 
				n[j].sum++;
				if(n[j].sum>=S)strcpy(hac[k].name,n[j].name),k++;  //��¼�ºڿ��û��� 
				break;
			}
		if(n[i].x<=T&&j==i)n[i].sum++;//���û�г��ֹ���Ϊ�������� 
		i++; 
	}
	printf("%d\n",k);//����ڿ���Ŀ 
	for(int j=0;j<k;j++)
		printf("%s\n",hac[j].name);//������� 
	fclose(fp); 
	return 0;
}

