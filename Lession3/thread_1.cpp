#include <pthread.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int shared_data = 0;

void *increateData(void *)
{
    while(shared_data < 10000)
    {
        shared_data++;
    }
    pthread_testcancel();
    pthread_exit(&shared_data);
}

void *ReadData(void *)
{
    while(shared_data < 10000)
    {
        cout << shared_data << endl;
    }

    pthread_exit(&shared_data);
}

int main()
{
    int **res = NULL;
    int **res_p = NULL;

    pthread_t tid_p,tid_c;

    pthread_create(&tid_p,NULL,increateData,NULL);
    pthread_create(&tid_c,NULL,ReadData,NULL);

    pthread_join(tid_p,(void **)res);
    pthread_join(tid_c,(void **)&res_p);

    cout << "get your ass " << **res << endl;
    cout << "all the thing " << **res_p << endl;
}