/* getprio.c - getprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */
SYSCALL getprio(int pid)
{
	int myrank=3;
        int t_begin;
        if(tracing == 1) {
                sys_count[currpid][myrank]++;
                t_begin = ctr1000;
        }


	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		return(SYSERR);
	}
	restore(ps);
	if(tracing == 1) {
                exec_time[currpid][myrank] += ctr1000 - t_begin;
        }

	return(pptr->pprio);
}
