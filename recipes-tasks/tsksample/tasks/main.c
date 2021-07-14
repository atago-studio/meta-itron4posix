#include <stdio.h>
#include "itron.h"

int xActive = 0x03;
extern FP tsk_sample1, tsk_sample2;

int main(int argc, char *argv[])
{
	ER res;
	T_CTSK pk_ctsk;
	T_CMBF pk_cmbf;
	
	if ((res = inz_knl()) != E_OK){
		printf("ITRON kernel init error: %d\n", res);
		return 1;
	}
	
	pk_cmbf.mbfatr = TA_TFIFO;
	pk_cmbf.maxmsz = 4;
	pk_cmbf.mbfsz = 16;
	pk_cmbf.mbf = NULL;
	if ((res = cre_mbf(1, &pk_cmbf)) != E_OK){
		printf("cre_mbf id:1 error=%d\n", res);
		return 1;
	}

	if ((res = cre_mbf(2, &pk_cmbf)) != E_OK){
		printf("cre_mbf id:2 error=%d\n", res);
		return 1;
	}
	
	pk_ctsk.tskatr = TA_HLNG | TA_ACT;
	pk_ctsk.exinf = 0;
	pk_ctsk.task = tsk_sample1;
	pk_ctsk.itskpri = 1;
	pk_ctsk.stksz = 4096;
	pk_ctsk.stk = NULL;
	if ((res = cre_tsk(1, &pk_ctsk)) != E_OK){
		printf("cre_tsk: id:1 err=%d\n", res);
		return -1;
	}
	
	pk_ctsk.task = tsk_sample2;
	if ((res = cre_tsk(2, &pk_ctsk)) != E_OK){
		printf("cre_tsk: id:2 err=%d\n", res);
		return -1;
	}

	while (xActive);
	return 0;
}

