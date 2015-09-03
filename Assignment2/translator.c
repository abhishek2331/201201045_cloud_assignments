#include<stdio.h>
#include<stdlib.h>
int main()
{
	char str[1000];
	int i,j;
	FILE *fp,*fp1;
	fp = fopen("32_bit.asm","r");
	fp1=fopen("final_64_bit.asm","w");
	fscanf(fp,"%[^\n]\n",str);
	fprintf(fp1,"%s","extern printf\n");
	j=0;
	while(str[0]!=EOF)
	{
//		printf("%s %d\n",str,strcmp(str,"section .text"));
		if(strcmp(str,"section .text")==0)
		{
			fprintf(fp1,"%s","section .data\n");
		}
		else if(strcmp(str, "global _start")==0)
		{
			fprintf(fp1,"%s","msg: db \"Hello world\", 0\n");

		}
		else if(strcmp(str,"_start:")==0)
		{
			fprintf(fp1,"%s","fmt: db \"%s\", 10, 0\n");
		}
		else if(strcmp(str,"mov edx,len")==0)
		{
			fprintf(fp1,"%s","section .text\n");
		}
		else if(strcmp(str,"mov ecx,msg")==0)
		{
			fprintf(fp1,"%s","global _start\n");
		}
		else if(strcmp(str,"mov ebx,1")==0)
		{
			fprintf(fp1,"%s","_start:\n");
		}
		else if(strcmp(str,"mov eax,4")==0)
		{
			fprintf(fp1,"%s","push rbp\n");
		}
		else if(strcmp(str,"int 0x80")==0 && j==0)
		{
			j=1;
			fprintf(fp1,"%s","mov\trdi,fmt\n");
		}
		else if(strcmp(str,"mov ebx,0")==0)
		{
			fprintf(fp1,"%s","mov\trsi,msg\n");
		}
		else if(strcmp(str,"mov eax,1")==0)
		{
			fprintf(fp1,"%s","mov\trax,0\n");
		}
		else if(strcmp(str,"int 0x80")==0 && j==1)
		{
			j=2;
			fprintf(fp1,"%s","call printf\n");
		}
		else if(strcmp(str,"section .data")==0)
		{
			fprintf(fp1,"%s","pop\trbp\n");
		}
		else if(strcmp(str,"msg db \"Hello, world!\",0xa")==0)
		{
			fprintf(fp1,"%s","mov\trax,0\n");
		}
		else if(strcmp(str,"len equ $ - msg")==0)
		{
			fprintf(fp1,"%s","ret\n");
		}
		str[0]=EOF;
		fscanf(fp,"%[^\n]\n",str);
	}
	return 0;
}
