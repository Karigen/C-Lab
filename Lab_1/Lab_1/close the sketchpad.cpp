#include"graphics.h"

int close_sketchpad()
{
	cleardevice();
	setfont(128, 0, "宋体");
	setcolor(RED);
	outtextxy(140, 150, "have a good day");

	setfont(18, 0, "宋体");
	setcolor(BLACK);
	outtextxy(555, 440, "杨宇航制作");

	delay_ms(2500);

	closegraph();
	return 0;
}