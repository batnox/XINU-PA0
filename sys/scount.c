/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <sem.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
	int myrank=10;
        int t_begin;
        if(tracing == 1) {
                sys_count[currpid][myrank]++;
                t_begin = ctr1000;
        }

extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		return(SYSERR);
	if(tracing == 1) {
                exec_time[currpid][myrank] += ctr1000 - t_begin;
        }

	return(semaph[sem].semcnt);
}
