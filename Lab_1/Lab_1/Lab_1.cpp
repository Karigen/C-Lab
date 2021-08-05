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
	setcaption("�����޵е�ը�컭��");
	setbkcolor(WHITE);
	setfont(18, 0, "����");

	zone();                                         //��ͼǰ����ز���
	outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�������ѡ����ȡ���뻭�壩");
	outtextxy(3, 21, "1.����1��ȡ�ļ�");
	outtextxy(3, 39, "2.����2����ȡ�ļ�");
	outtextxy(3, 57, "����������ѡ��");

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
		outtextxy(3, 3, "δ��ȡ");
		outtextxy(3, 21, "�����������");
		readresult = 2;
		getch();
	}
	else
	{
		cleardevice();

		zone();
		outtextxy(3, 3, "�������");
		outtextxy(3, 21, "�����������");
		readresult = 2;
		getch();
	}

	menu(readresult);

	for (; is_run;)                                      //��ͼ��ѭ��
	{
		clearmenu();
		zone();
		outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");
		outtextxy(3, 21, "1.����1����");
		outtextxy(3, 39, "2.����2�����Ļ");
		outtextxy(3, 57, "3.����0�˳�");

		b = getch();

		switch (b)
		{
		case '1':
			for (; is_run; delay_fps(60))
			{
				clearmenu();
				zone();
				outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");
				outtextxy(3, 21, "1.����1������");
				outtextxy(3, 39, "2.����2��Բ��");
				outtextxy(3, 57, "3.����3����");

				c = getch();

				switch (c)
				{
				case '1':                                         //����
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
				case '2':                                      //Բ��
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
				case '3':                                         //��
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
					outtextxy(3, 3, "�������");
					outtextxy(3, 21, "�����������");
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
			outtextxy(3, 3, "�������");
			outtextxy(3, 21, "�����������");
			getch();
		}
		if (b == '0')
			break;
	}
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
		outtextxy(3, 3, "��ӭ������������ܻ��壬��ѡ����ɫ��");
		outtextxy(3, 21, "1.����1��ɫ 4.����4��ɫ 7.����7��ɫ A.����Aǳ�� D.����Dǳ��   G.����G��ɫ");
		outtextxy(3, 39, "2.����2��ɫ 5.����5��ɫ 8.����8ǳ�� B.����Bǳ�� E.����EǳƷ��");
		outtextxy(3, 57, "3.����3��ɫ 6.����6Ʒ�� 9.����9���� C.����Cǳ�� F.����F��ɫ");

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
			outtextxy(3, 3, "�������");
			outtextxy(3, 21, "�����������");
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
		outtextxy(3, 3, "��ӭ������������ܻ��壬��ѡ�������ɫ��");
		outtextxy(3, 21, "1.����1��ɫ 4.����4��ɫ 7.����7��ɫ A.����Aǳ�� D.����Dǳ��   G.����G��ɫ");
		outtextxy(3, 39, "2.����2��ɫ 5.����5��ɫ 8.����8ǳ�� B.����Bǳ�� E.����EǳƷ��");
		outtextxy(3, 57, "3.����3��ɫ 6.����6Ʒ�� 9.����9���� C.����Cǳ�� F.����F��ɫ");

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
			outtextxy(3, 3, "�������");
			outtextxy(3, 21, "�����������");
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
		outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");
		outtextxy(3, 21, "1.��ȡ�ļ��ɹ�");
		outtextxy(3, 39, "2.�����������");

		getch();
	}
	else if (readresult == 0)
	{
		cleardevice();
		zone();
		outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");
		outtextxy(3, 21, "1.�ļ�������");
		outtextxy(3, 39, "2.�����������");
		getch();
	}
	else
		;
}

int readfile(void)
{
	char a;
	char str[100];
	inputbox_getline("������", "������Ҫ��ȡ���ļ���", str, 100);

	if (str[0] != '0')
		;
	else
	{
		cleardevice();

		zone();
		outtextxy(3, 3, "�ļ�������");
		outtextxy(3, 21, "�����������");

		getch();
	}

	if (str[0] != '0')
		return 1;
	else
		return 0;
}