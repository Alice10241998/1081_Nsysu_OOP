#include "mytar.h"
mytar::mytar(const char *file) //讀檔
{
	blocksize=512;
	input.open(file, ifstream::in|ifstream::binary);

	if(!input.is_open())
	{
		cout<<"mytar: "<<file<<": Cannot open: No such file or directory"<<endl;
		cout<<"mytar: Error is not recoverable: exiting now"<<endl;
		exit(0);
	}
}
void mytar::readBlock() //檔案資料
{
	struct TarHeader tempHeader;
	input.read(tempHeader.filename,100);
	input.read(tempHeader.filemode,8);
	input.read(tempHeader.userid,8);
	input.read(tempHeader.groupid,8);
	input.read(tempHeader.filesize,12);
	input.read(tempHeader.mtime,12);
	input.read(tempHeader.checksum,8);
	input.read(&tempHeader.type,1);
	input.read(tempHeader.lname,100);
	input.read(tempHeader.USTAR_id,6);
	input.read(tempHeader.USTAR_ver,2);
	input.read(tempHeader.username,32);
	input.read(tempHeader.groupname,32);
	input.read(tempHeader.devmajor,8);
	input.read(tempHeader.devminor,8);
	input.read(tempHeader.prefix,155);
	input.read(tempHeader.pad,12);

	tarVector.push_back(tempHeader);
}

int mytar::readfile()
{
	int i,size,jumpblock;
	readBlock();
	
	for(i=0;i<11;i++)
		size+=(int(tarVector[tarVector.size()-1].filesize[i])-48)*pow(8,10-i); //八進位
	//跳幾個block
	if(size%512==0) 
		jumpblock=size/512;
	else
		jumpblock=size/512+1;

	size=0; //檔案大小

	while(input.seekg(512*jumpblock,input.cur)) //從跳到指定的位置開始讀
	{
		readBlock();
		for (i=0;i<11;i++)
			size+=(int(tarVector[tarVector.size()-1].filesize[i])-48)*pow(8,10-i);
		
		if(size%512==0)
			jumpblock=size/512;
		else
			jumpblock=size/512+1;
		
		size=0;
	}
	
	return 1;
}

void mytar::print()
{
	int mode;
	bool modeselect[3];
	char dictionary[3]={'r','w','x'};
	for(int i=0;i<tarVector.size()-1;i++)
	{
		//mode
		if (tarVector[i].type=='5') //5->dictionary
		    cout<<'d';
		else
		    cout<<'-';
		
		for(int j=4;j<7;j++)
		{
		    	//init
			for(int k=0;k<3;k++)
			        modeselect[k]=0;

		    	mode=int(tarVector[i].filemode[j])-'0';
		    	if(mode>=4)
			{
		        	modeselect[0]=1;
		        	mode-=4;
		    	}
		    	if(mode>=2)
			{
			        modeselect[1]=1;
			        mode-=2;
			}
		    	if(mode)
		        	modeselect[2]=1;
		    
		    	//output
		    	for(int k=0;k<3;k++)
		        {
				if(modeselect[k])
		            		cout<<dictionary[k];
		        
		        	else
		            		cout<<'-';
		        }
		        
		}

		//name/group
		cout<<" "<<tarVector[i].username<<"/"<<tarVector[i].groupname;
		//size
		int size=0;
		for(int j=0;j<11;j++)
		    	size+=(int(tarVector[i].filesize[j])-48)*pow(8,10-j);
		
		cout<<setw(6)<<size<<" ";
		//time
		int timecnt=0;
		for(int j=0;j<11;j++)
		    timecnt+=(int(tarVector[i].mtime[j])-48)*pow(8,10-j);
		
		time_t temp=timecnt+28800; //1970y~now 'sec
		tm *t=gmtime(&temp);
		stringstream ss;
		ss<<put_time(t,"%Y-%m-%d %H:%M"); //year month day min sec
		string output =ss.str();
		cout<<output<<" ";

		//filename
		cout<<tarVector[i].filename<<" ";
		//done
		cout<<endl;
	}
}
