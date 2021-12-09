// practical 1 (b): same program, different code

#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;
int main(){
int x;
x=fork();
if(x==0){
execlp("/home/kali/Desktop/OS_practical2","OS_practical2",NULL);
}
else{
wait(NULL);
cout<<"Child completed!!\n";
}
return(0);
}

