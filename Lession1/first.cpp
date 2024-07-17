#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(void)
{
    // son process
    // int flag = system("ping www.baidu.com");
    // if(flag != 0)
    // {
    //     cout << "Son runing";
    // }

    //cout << getpid() << endl;

    int *sonStatus;
    pid_t pid = fork();

    cout << "current process Pid: " << pid << endl;

    if(pid != 0)
        sleep(2);
    else
        waitpid(pid,sonStatus,0);


    cout << pid << " I've got you in my sight" << endl;
    
}