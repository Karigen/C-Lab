#define _CRT_SECURE_NO_WARNINGS 1

#include"graphics.h"
#include<stdio.h>
#include<math.h>

void zone(void);
void choosecolor(void);
void choosefillcolor(void);
void clearmenu(void);
void clearboard(void);
void menu(int readresult);
int readfile(void);

int main(void)
{
	char a, b, c, d;
	int readresult;
	mouse_msg msg = { 0 };
	initgraph(1200, 700, 0);
	setcaption("宇宙无敌吊炸天画板");
	setbkcolor(WHITE);
	setfont(18, 0, "宋体");

	zone();                                         //画图前的相关操作
	outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：（选不读取进入画板）");
	outtextxy(3, 21, "1.输入1读取文件");
	outtextxy(3, 39, "2.输入2不读取文件");
	outtextxy(3, 57, "请输入您的选择：");

	a = getch();

	if (a == '1')
	{
		cleardevice();
		readresult = readfile();
	}
	else if (a == '2')
	{
		cleardevice();

		zone();
		outtextxy(3, 3, "未读取");
		outtextxy(3, 21, "按任意键继续");
		readresult = 2;
		getch();
	}
	else
	{
		cleardevice();

		zone();
		outtextxy(3, 3, "输入错误");
		outtextxy(3, 21, "按任意键继续");
		readresult = 2;
		getch();
	}

	menu(readresult);

	for (; is_run;)                                      //画图主循环
	{
		clearmenu();
		zone();
		outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");
		outtextxy(3, 21, "1.输入1作画");
		outtextxy(3, 39, "2.输入2清除屏幕");
		outtextxy(3, 57, "3.输入0退出");

		b = getch();

		switch (b)
		{
		case '1':
			for (; is_run; delay_fps(60))
			{
				clearmenu();
				zone();
				outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");
				outtextxy(3, 21, "1.输入1画矩形");
				outtextxy(3, 39, "2.输入2画圆形");
				outtextxy(3, 57, "3.输入3画线");

				c = getch();

				switch (c)
				{
				case '1':                                         //矩形
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
						if (x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0)
						{
							rectangle(x1, y1, x2, y2);
							break;
						}
					}
					break;
				case '2':                                      //圆形
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
						if (x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0)
						{
							circle(x1, y1, sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
							break;
						}
					}
					break;
				case '3':                                         //线
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
						if (x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0)
						{
							line(x1, y1, x2, y2);
							break;
						}
					}
					break;
				default:
					clearmenu();
					zone();
					outtextxy(3, 3, "输入错误");
					outtextxy(3, 21, "按任意键继续");
					getch();
				}
				break;
			}
			break;
		case '2':
			clearboard();
			break;
		case '0':
			break;
		default:
			clearmenu();
			zone();
			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
		}
		if (b == '0')
			break;
	}
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

void zone(void)
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
}

void choosecolor(void)
{
	char a;
	do
	{
		clearmenu();

		zone();
		outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请选择颜色：");
		outtextxy(3, 21, "1.输入1黑色 4.输入4青色 7.输入7棕色 A.输入A浅蓝 D.输入D浅红   G.输入G白色");
		outtextxy(3, 39, "2.输入2蓝色 5.输入5红色 8.输入8浅灰 B.输入B浅绿 E.输入E浅品红");
		outtextxy(3, 57, "3.输入3绿色 6.输入6品红 9.输入9暗灰 C.输入C浅青 F.输入F黄色");

		a = getch();

		switch (a)
		{
		case '1':setcolor(BLACK); break;
		case '2':setcolor(BLUE); break;
		case '3':setcolor(GREEN); break;
		case '4':setcolor(CYAN); break;
		case '5':setcolor(RED); break;
		case '6':setcolor(MAGENTA); break;
		case '7':setcolor(BROWN); break;
		case '8':setcolor(LIGHTGRAY); break;
		case '9':setcolor(DARKGRAY); break;
		case 'A':setcolor(LIGHTBLUE); break;
		case 'B':setcolor(LIGHTGREEN); break;
		case 'C':setcolor(LIGHTCYAN); break;
		case 'D':setcolor(LIGHTRED); break;
		case 'E':setcolor(LIGHTMAGENTA); break;
		case 'F':setcolor(YELLOW); break;
		case 'G':setcolor(WHITE); break;
		default:
			cleardevice();
			line(1, 1, 1198, 1);
			line(1198, 1, 1198, 75);
			line(1198, 75, 1, 75);
			line(1, 75, 1, 1);
			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
		}
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9' && a != 'A' && a != 'B' && a != 'C' && a != 'D' && a != 'E' && a != 'F' && a != 'G');
}

void choosefillcolor(void)
{
	char a;
	do
	{
		clearmenu();

		zone();
		outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请选择填充颜色：");
		outtextxy(3, 21, "1.输入1黑色 4.输入4青色 7.输入7棕色 A.输入A浅蓝 D.输入D浅红   G.输入G白色");
		outtextxy(3, 39, "2.输入2蓝色 5.输入5红色 8.输入8浅灰 B.输入B浅绿 E.输入E浅品红");
		outtextxy(3, 57, "3.输入3绿色 6.输入6品红 9.输入9暗灰 C.输入C浅青 F.输入F黄色");

		a = getch();

		switch (a)
		{
		case '1':setfillcolor(BLACK); break;
		case '2':setfillcolor(BLUE); break;
		case '3':setfillcolor(GREEN); break;
		case '4':setfillcolor(CYAN); break;
		case '5':setfillcolor(RED); break;
		case '6':setfillcolor(MAGENTA); break;
		case '7':setfillcolor(BROWN); break;
		case '8':setfillcolor(LIGHTGRAY); break;
		case '9':setfillcolor(DARKGRAY); break;
		case 'A':setfillcolor(LIGHTBLUE); break;
		case 'B':setfillcolor(LIGHTGREEN); break;
		case 'C':setfillcolor(LIGHTCYAN); break;
		case 'D':setfillcolor(LIGHTRED); break;
		case 'E':setfillcolor(LIGHTMAGENTA); break;
		case 'F':setfillcolor(YELLOW); break;
		case 'G':setfillcolor(WHITE); break;
		default:
			cleardevice();
			line(1, 1, 1198, 1);
			line(1198, 1, 1198, 75);
			line(1198, 75, 1, 75);
			line(1, 75, 1, 1);
			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
		}
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9' && a != 'A' && a != 'B' && a != 'C' && a != 'D' && a != 'E' && a != 'F' && a != 'G');
}

void clearmenu(void)
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);
}

void clearboard(void)
{
	setcolor(WHITE);
	bar(0, 76, 1200, 700);
}

void menu(int readresult)
{
	if (readresult == 1)
	{
		cleardevice();
		zone();
		outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");
		outtextxy(3, 21, "1.读取文件成功");
		outtextxy(3, 39, "2.按任意键继续");

		getch();
	}
	else if (readresult == 0)
	{
		cleardevice();
		zone();
		outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");
		outtextxy(3, 21, "1.文件不存在");
		outtextxy(3, 39, "2.按任意键继续");
		getch();
	}
	else
		;
}

int readfile(void)
{
	char a;
	char str[100];
	inputbox_getline("请输入", "请输入要读取的文件名", str, 100);

	if (str[0] != '0')
		;
	else
	{
		cleardevice();

		zone();
		outtextxy(3, 3, "文件不存在");
		outtextxy(3, 21, "按任意键继续");

		getch();
	}

	if (str[0] != '0')
		return 1;
	else
		return 0;
}