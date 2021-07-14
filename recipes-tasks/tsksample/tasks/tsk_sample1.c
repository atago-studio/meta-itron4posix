#include <stdio.h>
#include "itron.h"

extern int xActive;

TASK tsk_sample1(VP_INT exinf)
{
	ER res;
	UB cnt;
	
	printf("tsk_sample1 start\n");
	cnt = 0;
	if ((res = snd_mbf(2, &cnt, sizeof(cnt))) != E_OK){
		printf("tsk_sample1 snd_mbf error : %d\n", res);
		xActive &= ~1;
		exd_tsk();
	}
	
	while (1){
		if ((res = rcv_mbf(1, &cnt)) != E_OK){
			printf("tsk_sample1 rcv_mbf error : %d\n", res);
			break;
		}
		
		printf("tsk_sample1 wakeup. cnt=%d\n", cnt);
		cnt++;
		
		if ((res = snd_mbf(2, &cnt, sizeof(cnt))) != E_OK){
			printf("tsk_sample1 snd_mbf error : %d\n", res);
			break;
		}
		
		if (cnt > 200){
			break;
		}
	}

	xActive &= ~1;
	exd_tsk();
}
