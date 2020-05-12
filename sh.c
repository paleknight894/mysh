#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
char **cutarg(char *,char **);
void freem(void *,void *);
void cmdline();
void sh(int infd,int outfd,int errfd)
{
	char **argv,*freep,*p1;
	int p,re,i;
	dup2(infd,0);
	dup2(outfd,1);
	dup2(errfd,2);
	p1=(char*)malloc(1024*sizeof(char));
	if(p1==NULL)
	{
		perror("malloc error\n");
		exit(0);
	}
	while(1)
	{
		cmdline();
		i=read(0,p1,1023);
		p1[i]='\0';
		if(p1[i-1]=='\n')
		{
			p1[i-1]='\0';
			i--;
		}
		argv=cutarg(p1,&freep);
		if(!(strcmp(argv[0],"cd")))
		{
			if(chdir(argv[1]))
			{
				perror("chdir error\n");
			}
			continue;
		}
		if(!(strcmp(argv[0],"exit")))
		{
			freem((void *)freep,(void *)argv);
			break;
		}
		p=fork();
		if(!p)
		{
			execvp(argv[0],argv);
			perror("unknown command\n ");
			exit(-1);
		}
		waitpid(p,&re,0);
		freem((void *)freep,(void *)argv);
		printf("return is %d\n",WEXITSTATUS(re));
	}
	free(p1);
}
