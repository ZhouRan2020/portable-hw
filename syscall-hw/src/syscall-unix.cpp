#include <iostream>
#include <cerrno>
#include <unistd.h>
#include <sys/syscall.h>//for marco SYS_*
int main(int argc, char** argv){
/*	register int syscall_no asm("rax")=1;
	register int arg1 asm("rdi")=1;
	register int arg3 asm("rdx")=14;
	asm("syscall");
	return 0;
*/
	char buf[]="hello, world!\n";
	int bufsz=sizeof(buf);
	int fd=1;
	long cr=syscall(SYS_write,fd,buf,bufsz);
	if(cr==-1){
		std::cout<<"syscall "<<SYS_write<<" failed with "<<errno<<std::endl;
		return -1;
	}
	std::cout<<"syscall "<<SYS_write<<" succeed with "<<cr<<std::endl;
}

