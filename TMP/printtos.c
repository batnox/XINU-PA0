#include<stdio.h>

unsigned long *ebp, *esp;

void printtos(){
	
	asm("movl %ebp, ebp");
	asm("movl %esp, esp");
	
	kprintf("\nprinttos\n\n");	
	kprintf("\nBefore[0x%08x]: 0x%08x\n", ebp + 2, *(ebp+2));
	kprintf("After[0x%08x]: 0x%08x\n", ebp, *ebp);
	
	int i=0;
	int x=5, y=6, z=1, p=2;
	
	for(i=1; i<5; i++){
		if(ebp>=esp)
			kprintf("\telement[0x%08x]=0x%08x\n", ebp-i, *(ebp-i));
	}
	
	//printf("address of x 0x%08x value of 0x%08x\n",&x, x);
	
	

}
