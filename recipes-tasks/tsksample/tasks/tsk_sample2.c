#include <stdio.h>
#include "itron.h"

extern int xActive;

TASK tsk_sample2(VP_INT exinf)
{
	ER res;
	UB cnt;
	
	printf("tsk_sample2 start\n");
	while (1){
		if ((res = rcv_mbf(2, &cnt)) != E_OK){
			printf("tsk_sample2 rcv_mbf error : %d\n", res);
			break;
		}
		
		printf("tsk_sample2 wakeup. cnt=%d\n", cnt);
		cnt++;
		
		if ((res = snd_mbf(1, &cnt, sizeof(cnt))) != E_OK){
			printf("tsk_sample2 snd_mbf error : %d\n", res);
			break;
		}
		
		if (cnt > 200){
			break;
		}
	}

	xActive &= ~2;
	exd_tsk();
}
