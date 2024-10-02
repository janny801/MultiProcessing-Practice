#include <iostream>
#include <pthread.h>
#include <sys/wait.h>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std; 

int main()
{
    cout<<"this is parent process\n" <<endl; 

    int pid ; 

    for (int i=0; i< 3; i++)
    {
        pid = fork(); 
        if (pid ==0)
        {
            //
            cout<<"i am child thread: "<<i+1<<endl; 


            int numgrandchildren; 

            if (i==0)
            {
                numgrandchildren = 2; 
            }
            else if(i==1)
            {
                numgrandchildren =1; 
            }
            else{
                numgrandchildren =3; 
            }

            for (int j =0; j< numgrandchildren; j++)
            {
                pid = fork(); 
                if (pid ==0)
                {
                    cout<<"i am grandchild thread "<<j+1<<"- from child thread: "<<i+1<<endl; 
                    _exit(0); 
                }
                else
                {
                    wait (nullptr); 
                }

                
            }



            _exit(0); //no more child threads 
        }
        
        else
        {
            wait(nullptr); //wait for child threads to finish 
        }


        
    }
}