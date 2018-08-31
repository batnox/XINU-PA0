#include<stdio.h>
#include<conf.h>
#include<kernel.h>
#include<proc.h>

unsigned long *ptr;

void printprocstks(int priority){
	
	kprintf("\nprintprocstks\n\n");	
	struct pentry *p;
	int i=0;
	
	for(i=0; i<NPROC; i++){
	
	p = &proctab[i];
	if(p->pprio  > priority){
	
		kprintf("Process [%s]\n", p->pname);
		kprintf("\tpid: %d\n", i);
		kprintf("\tpriority: %d\n",p->pprio);
		kprintf("\tbase: 0x%08x\n",p->pbase);
		kprintf("\tlimit: 0x%08x\n",p->plimit);
		kprintf("\tlen: %d\n",p->pstklen);
		 if( i == currpid) { 
			asm("movl %esp,ptr");
			kprintf("\tpointer: 0x%08x\n",ptr);
		}	
		else{
			kprintf("\tpointer: 0x%08x\n",p->pesp);
		}
	}
	}

}
