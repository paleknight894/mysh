#include<stdio.h>
#include<pwd.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
void cmdline()
{
	int i,n;
	struct passwd *pwd;
	char a[289],*p1;
	pwd = getpwuid(getuid());
	strncpy(a,pwd->pw_name,32);
	i=strlen(a);
	a[i++]='@';
	gethostname(&a[i],255);
	i+=strlen(&a[i]);
	p1=getcwd(NULL,0);
	n=strlen(p1);
	a[i++]=' ';
	write(1,a,i);
	write(1,p1,n);
	free(p1);
	if(!(strcmp(pwd-> pw_name,"root")))
	{
		write(1," # ",3);
	}
	else
	{
		write(1," $ ",3);
	}
}
