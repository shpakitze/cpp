#include <iostream>
#include <direct.h>
#include <io.h>
using namespace std;
void copyf(char path[]){
	
}
void remdir(char newpath[],char oldpath[]){
	_finddata_t *fileinfo=new _finddata_t;
	char mask[]="*.*";
	char fullp[250];
	strcpy(fullp,oldpath);
	strcat(fullp,"*.*");
	_mkdir(newpath);
	long done =_findfirst(fullp,fileinfo);
	int findrez=done;
	char oldname[260],newname[260];
	strcpy(oldname,oldpath);
	while (findrez!=-1){
		cout<<fileinfo->name<<endl;
		if ((fileinfo->attrib!=_A_SUBDIR)&&((strcmp(fileinfo->name,".")||(strcmp(fileinfo->name,".."))))){
		strcpy(oldname,oldpath);
		strcat(oldname,fileinfo->name);
		cout <<oldname<<endl;
		strcpy(newname,newpath);
		strcat(newname,fileinfo->name);
		cout <<newname<<endl;
		rename(oldname,newname);
		}
		if((fileinfo->attrib==_A_SUBDIR)&&(!(strcmp(fileinfo->name,".")==0||(strcmp(fileinfo->name,"..")==0)))){
		char spath[260],dpath[260];
		strcpy(spath,oldpath);
		strcpy(dpath,newpath);
		strcat(spath,fileinfo->name);
		strcat(dpath,fileinfo->name);
		strcat(spath,"\\");
		strcat(dpath,"\\");
		remdir(dpath,spath);
		if (_rmdir(spath)==-1) cout <<"error del dir"<<endl;
		cout <<errno;
		}
		findrez=_findnext(done,fileinfo);
	}
}
int main(int argc, char *argv[]){
	int findrez;
	char path[260];
	strcpy(path,argv[1]);
	strcat(path,"*.*");
	cout <<path<<endl;
remdir(argv[2],argv[1]);	
if (_rmdir(argv[1])==-1) cout <<"error del dir"<<endl;
	getchar();
	return 0;
}