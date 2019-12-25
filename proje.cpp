#include <iostream> 
#include <fstream>
#include <string> 
using namespace std;

void Csvtoxls();

int main() 
{ 
    Csvtoxls(); // this function is called for converting given CVS file to XLS file.
    return 0; 
} 

void Csvtoxls(){

    string str;
     printf("Please input xls file name : ");
     cin>>str;
     ifstream ifs(str.c_str()); 
    
     if(!ifs) 
    {  cerr <<"input file name is incorrect" <<endl;   exit(1);     } 
   
     ofstream ofs("new.xls");  
      
   ofs<<ifs.rdbuf(); 
    if (!ofs) 
    {   cerr <<"error: can not open \"new.xls\" for output\n";  exit(1);}                               
      ifs.close();
    
    ofs.close();
    cout<<"copied one file！"<<endl; 
    cin.get();
}