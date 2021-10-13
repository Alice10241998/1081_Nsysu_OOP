#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>
using namespace std;

struct TarHeader
{
	char filename[100]; //file name
	char filemode[8]; //permissions
	char userid[8]; //user id
	char groupid[8]; //group id
	char filesize[12]; //size
	char mtime[12]; //modification time
	char checksum[8]; 
	char type; //file type
	char lname[100]; //name of linked file
/* USTAR Section */
	char USTAR_id[6]; 
	char USTAR_ver[2];
	char username[32]; //user name
	char groupname[32]; //group name
	char devmajor[8]; //device major number
	char devminor[8]; //device minor number
	char prefix[155];
	char pad[12];
};

class mytar
{
	public:
    	mytar(const char *file);
    	vector<TarHeader> tarVector;
    	ifstream input;
    	int blocksize;
    	void readBlock();
    	int readfile();
    	void print();
};
