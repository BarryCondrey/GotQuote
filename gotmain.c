#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define		QUOTECOUNT 192 
//
//------------------------------------------------------------------------------
//	gotmain.c  - The main source for gotquote - the Game of Thrones quote generator. 
//	Passed:
//		-d Debug output. 
//		-a Print all quotes
//		<default> Print one randomly selected quote to stdout. 
// 	Returns:
//		 0 = Success, 1 = Error. 
//
//	Notes: 	This is meant to be a very simple, and easily ported program.  
//		See quotes.c for notes on the quotes.  
//	Author:	Barry@Condrey.org 
//------------------------------------------------------------------------------
// 
void 	print_all(); 
char	*get_quote(int); 
// int	read(); 		// Cause -Wall compiler option complains w/o this 

int main(argc, argv)
int  argc;
char *argv[];
{
int rand_num=0; 
int rand_fd, ret; 
int debug=0,all=0; 
char	c; 

// Process the args 

while ((c = getopt (argc, argv, "ad")) != (char) -1) {
	switch (c) {
		printf("\n %d", c); 
		case 'd':
			debug = 1;
			break;
		case 'a':
			all= 1;
			break;
		case '?':
		default:
			printf("\nUsage: gotquote -a -d (-a = print all -d = debug output) \n");
			break; 
	}
}

if(all) { 
	print_all();
	exit(0);
} 

if((rand_fd = open("/dev/urandom",O_RDONLY)) == -1) { 
	printf("\nError opening /dev/urandom\n"); 
	exit(1); 
} 

if((ret=read(rand_fd,&rand_num,1)) == -1) { 
	printf("\nError reading random number\n");
	close(rand_fd);
	exit(1);
} else { 
	close(rand_fd); 
}

rand_num= rand_num % QUOTECOUNT; 

if(debug)
	printf("\nQuote #%d - %s\n",rand_num,get_quote(rand_num));
else
	printf("%s\n",get_quote(rand_num));

exit(0); 
}
//------------------------------------------------------------------------------
//	printall()  - Dump all the quotes. 
//	Passed:	Nothing. 
// 	Returns:Nothing 
//------------------------------------------------------------------------------
// 
void 	print_all(); 
void print_all()
{ 
char	*get_quote(int); 
int	i=0;

	for(i=0;i<QUOTECOUNT;i++) printf("%s\n",get_quote(i));

}
