#include"graphics.h"
#include<stdio.h>
#include<math.h>


extern void zone(void);//菜单边框函数
extern void choosecolor(void);//选择边框颜色函数
extern void choosefillcolor(void);//选择填充颜色函数
extern void clearmenu(void);//清理画板菜单区域函数
extern void clearboard(void);//清理画板作图区域函数
extern char a, b, c;
extern int readresult;

void drawing(void)
{
	for (; is_run;)//画图的主循环
	{
		if (readresult == 1)
		{
			clearmenu();
			zone();
			outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");//主菜单
			outtextxy(3, 21, "1.输入1作画");
			outtextxy(3, 39, "2.输入2重画");
			outtextxy(3, 57, "3.输入0退出");
			readresult++;
		}
		else
		{
			clearmenu();
			zone();
			outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");//主菜单
			outtextxy(3, 21, "1.输入1作画");
			outtextxy(3, 39, "2.输入2清除屏幕");
			outtextxy(3, 57, "3.输入0退出");
		}

		b = getch();

		switch (b)
		{
		case '1':
			for (; is_run; delay_fps(60))
			{
				clearmenu();
				zone();
				outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");//画图菜单
				outtextxy(3, 21, "1.输入1画矩形");
				outtextxy(3, 39, "2.输入2画圆形");
				outtextxy(3, 57, "3.输入3画线");

				c = getch();

				switch (c)
				{
				case '1'://矩形
					choosecolor();
					for (int x1 = 0, x2 = 0, y1 = 0, y2 = 0, count = 1; is_run; delay_fps(60))
					{
						mouse_msg msg = { 0 };
						while (mousemsg())
						{
							msg = getmouse();
						}
						if (msg.is_left() && msg.is_down() && count == 1)
						{
							x1 = msg.x;
							y1 = msg.y;
							count++;
						}
						else if (msg.is_left() && msg.is_down() && count == 2)
						{
							x2 = msg.x;
							y2 = msg.y;
							count++;
						}
						if (count == 3)
						{
							rectangle(x1, y1, x2, y2);
							break;
						}
					}
					break;
				case '2'://圆形
					choosecolor();
					for (int x1 = 0, x2 = 0, y1 = 0, y2 = 0, count = 1; is_run; delay_fps(60))
					{
						mouse_msg msg = { 0 };
						while (mousemsg())
						{
							msg = getmouse();
						}
						if (msg.is_left() && msg.is_down() && count == 1)
						{
							x1 = msg.x;
							y1 = msg.y;
							count++;
						}
						else if (msg.is_left() && msg.is_down() && count == 2)
						{
							x2 = msg.x;
							y2 = msg.y;
							count++;
						}
						if (count == 3)
						{
							circle(x1, y1, sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
							break;
						}
					}
					break;
				case '3'://线
					choosecolor();
					for (int x1 = 0, x2 = 0, y1 = 0, y2 = 0, count = 1; is_run; delay_fps(60))
					{
						mouse_msg msg = { 0 };
						while (mousemsg())
						{
							msg = getmouse();
						}
						if (msg.is_left() && msg.is_down() && count == 1)
						{
							x1 = msg.x;
							y1 = msg.y;
							count++;
						}
						else if (msg.is_left() && msg.is_down() && count == 2)
						{
							x2 = msg.x;
							y2 = msg.y;
							count++;
						}
						if (count == 3)
						{
							line(x1, y1, x2, y2);
							break;
						}
					}
					break;
				default://选择画图形时按错时显示
					clearmenu();
					zone();
					outtextxy(3, 3, "输入错误");
					outtextxy(3, 21, "按任意键继续");
					getch();
				}
				break;
			}
			break;
		case '2'://清除屏幕
			clearboard();
			break;
		case '0'://退出画班
			break;
		default://主选项按错时显示
			clearmenu();
			zone();
			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
		}
		if (b == '0')//接case '0'退出画板
			break;
	}
}