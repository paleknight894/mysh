#include<string.h>
#include<stdlib.h>
char **cutarg(char *str,char **tofree)
{
	char *t=(char *)malloc((sizeof(char)+1)*strlen(str));
	if(t==NULL)
	{
		perror("malloc error\n");
		exit(-1);
	}
	*tofree=t;
	strcpy(t,str);
	int i=0,j=1;
	for(;t[i]!='\0';i++)
	{
		if(t[i]==' ')
		{
			if((t[i+1]==' ')||(t[i+1]=='\0'))
				continue;
			else
			{
				j++;
			}
		}
	}
	i=0;
	if(t[0]==' ')
	{
		j--;
		for(;t[i]==' ';i++);
	}
	char **p=(char **)malloc((j+1)*sizeof(char *));
	if(p==NULL)
	{
		perror("malloc error\n");
		exit(0);
	}
	p[j]=NULL;
	p[0]=&t[i];
	j=1;
	for(;t[i]!='\0';i++)
	{
		if(t[i]==' ')
		{
			t[i]='\0';
			for(;t[i+1]==' ';i++)
			{
			}
			if(t[i+1]=='\0')
				break;
			p[j]=&t[i+1];
			j++;
		}
	}
	return p;
}

