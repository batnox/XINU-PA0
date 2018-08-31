#include <stdio.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

int tracing=0;
int sys_count[NPROC][27];
int exec_time[NPROC][27];
char *sys_name[27] = { "freemem", "chprio", "getpid", "getprio", "gettime", "kill", "receive", "recvclr", " recvtim", "resume", "scount", "sdelete", "send", "setdev", "setnok", "screate", "signal", "signaln", "sleep", "sleep10", "sleep100", "sleep1000", "sreset", "stacktrace", "suspend", "unsleep", "wait" };

void syscallsummary_start()
{
	int i, j;
	tracing = 1;
	for(i = 0; i < NPROC; ++i) {
		for(j = 0; j < 27; ++j) {
	    		sys_count[i][j] = 0;
    	    		exec_time[i][j] = 0;
		}
    	}

}

void syscallsummary_stop(){
	tracing = 0;
}

void printsyscallsummary(){
	kprintf("\nprintsyscallsummary\n\n");
	int i=0;
	int flag=0;

	int k = 0;
	int j=0;
	for(i=0;i<NPROC; i++){
		flag=0;
		for(j=0; j<27; j++){
			if(sys_count[i][j]!=0){
				flag=1;
				break;
			}		
		}
		
		if(flag!=0){
			kprintf("Process [pid:%d]\n", i);
			for(k=0; k<27; k++){
				if(sys_count[i][k] > 0) {
		    
             	    			kprintf("\tSyscall: %s, count: %d, average execution time: %d (ms)\n", sys_name[k], sys_count[i][k], exec_time[i][k]/sys_count[i][k]);

				}
			}
		}	

	}
}
	
