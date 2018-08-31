/* receive.c - receive */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  receive  -  wait for a message and return it
 *------------------------------------------------------------------------
 */
SYSCALL	receive()
{
	
	int myrank=6;
        int t_begin;
        if(tracing == 1) {
                sys_count[currpid][myrank]++;
                t_begin = ctr1000;
        }

	STATWORD ps;    
	struct	pentry	*pptr;
	WORD	msg;

	disable(ps);
	pptr = &proctab[currpid];
	if ( !pptr->phasmsg ) {		/* if no message, wait for one	*/
		pptr->pstate = PRRECV;
		resched();
	}
	msg = pptr->pmsg;		/* retrieve message		*/
	pptr->phasmsg = FALSE;
	restore(ps);
	if(tracing == 1) {
                exec_time[currpid][myrank] += ctr1000 - t_begin;
        }

	return(msg);
}
