#include"graphics.h"

int close_sketchpad()
{
	cleardevice();
	setfont(128, 0, "����");
	setcolor(RED);
	outtextxy(140, 150, "have a good day");

	setfont(18, 0, "����");
	setcolor(BLACK);
	outtextxy(555, 440, "�������");

	delay_ms(2500);

	closegraph();
	return 0;
}