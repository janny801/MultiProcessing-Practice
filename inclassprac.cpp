//from class lec 9/5


#include <pthread.h>
#include <sys/wait.h>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;


int main()
{
    int pid; 
    cout<<"i am the parent process" <<endl; 
    for (int i=0; i< 4; i++)
    {
        pid = fork(); 
        if (pid==0)
        {
            cout<<"this is child process: " <<i+1<<endl; 
            sleep(1); 

            int numgrandchildren ; 
            if (i==0)
            {
                //
                numgrandchildren =1; 
            }
            else if (i==1)
            {
                //
                numgrandchildren =0; 
            }
            else if (i==2)
            {
                //
                numgrandchildren =0; 
            }
            else
            {
                //
                numgrandchildren =2; 
            }

            for (int j =0; j< numgrandchildren; j++)
            {
                pid = fork(); 
                if (pid ==0)
                {
                    cout<<"this is grandchild: "<<j+1<<" from child thread: "<<i+1<<endl; 
                    sleep(1); 
                    _exit(0) ;
                }
            }
            for (int j=0; j<numgrandchildren; j++)
            {
                wait(nullptr); 
            }










            _exit(0); 
        }
    }
    for (int i=0; i< 4; i++)
    {
        wait (nullptr); 
    }







    return 0; 
}