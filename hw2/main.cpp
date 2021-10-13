#include "mytar.h"
using namespace std;

int main(int argc,char *argv[]) //int argc 指令長度; char *argv[] 字串
{
    mytar tar(argv[1]); //argv[1]檔名 ;argv[0]->./mytar
    tar.readfile();
    tar.print();
}
