//Practical 1( C ) : before terminating, the parent waits for the child to finish its task.
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main()
{
pid_t id = fork();
// child process
if(id == 0)
{
cout<<"\n Child Terminated!!";
}
// parent process
else
{
wait(NULL);
cout<<"\n Parent Terminated!!!";
}
return 0;
}
