#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[]){
if(argc<2){
printf("invalid");
return 1;
}
int fd;
char ch;
fd=open(argv[1],O_RDONLY);
if(fd==-1){printf("INVALID");
return 1;}
while(read(fd,&ch,1)>0){
putchar(ch);
}
close(fd);
return 0;
}
