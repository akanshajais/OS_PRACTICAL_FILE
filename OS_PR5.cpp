//PRACTICAL 5 : Write a program to copy files using system calls.
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ifstream fs;
ofstream ft;
char ch;
fs.open("OS_practical2.txt");
if(!fs){
cout<<"~~~~~~~ERROR in opening~~~~~~~~";
exit(1);
}
ft.open("copy.txt");
if(!ft){
cout<<"~~~~~~~~~~ERROR in opening~~~~~~~~~~~~~";
fs.close();
exit(2); }
while(fs.eof()==0){
fs>>ch;
ft<<ch;
}
cout<<"Copied Successfully!!!!!!!!";
fs.close();
ft.close();
return 0;
}
