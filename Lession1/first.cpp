#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

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

    pid_t pid = fork();

    cout << "current process Pid: " << pid << endl;

    cout << "I've got you in my sight " << endl;
    
    return 0;
}