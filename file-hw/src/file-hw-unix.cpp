#include <iostream>
#include <string.h>//for memset
#include <fcntl.h>//for open()
#include <errno.h>//for errno
#include <unistd.h>//for read(),write(),and close(),lseek()
int main(int argc, char** argv){
	constexpr int RB_SZ=1<<10;
//-------------------------------------------------------------------------
	if(argc!=2){
		std::cout<<"usage: plusone word"<<std::endl;
		return -1;
	}
	char *writebuf =argv[1];
//----------------------------------------------------------------------------
	int fd=-1;
//--------------------------------------------------------------------------
	char fn[] ="wordswords";
	fd=open(fn,O_RDWR|O_APPEND|O_CREAT,S_IRWXU);
	if(fd==-1){
		std::cout<<"opening failed: "<<errno<<std::endl;
		return -1;
	}
	std::cout<<"file is opened, fd: "<<fd<<std::endl;
//------------------------------------------------------------
	int nw=write(fd,writebuf,strlen(writebuf));
	if(nw==-1){
		std::cout<<"write failed: "<<errno<<std::endl;
		return -1;
	}
	std::cout<<"write "<<nw<<" chars."<<std::endl;
//---------------------------------------------------------------------------
	int of=lseek(fd,0,SEEK_SET);
	if(of==-1){
		std::cout<<"move failed: "<<errno<<std::endl;
		return -1;
	}
	std::cout<<"curser moved to "<<of<<" loc."<<std::endl;
//-------------------------------------------------------------------------
	char readbuf[RB_SZ];
	memset(readbuf,0,RB_SZ);
	//------------------------------------
	int nr=read(fd,readbuf,RB_SZ);
	if(nr==-1){
		std::cout<<"read failed: "<<errno<<std::endl;
		return -1;
	}
	if(nr==0&&strlen(readbuf)==0){
		std::cout<<"nothing to read."<<std::endl;
		return -1;
	}
	if(nr==0){
		std::cout<<"read "<<sizeof(readbuf)<<" bytes."<<std::endl;

	}
	else{
		std::cout<<"read "<<nr<<" chars."<<std::endl;
	}
		std::cout<<"content: "<<readbuf<<std::endl;
//---------------------------------------------------------------------------
	int cr=close(fd);
	if(cr==-1){
		std::cout<<"close failed."<<std::endl;
		return -1;
	}
	std::cout<<"file closed."<<std::endl;
//----------------------------------------------------------------------------
	return 0;
}
