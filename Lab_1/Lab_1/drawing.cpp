#include"graphics.h"
#include<stdio.h>
#include<math.h>


extern void zone(void);//�˵��߿���
extern void choosecolor(void);//ѡ��߿���ɫ����
extern void choosefillcolor(void);//ѡ�������ɫ����
extern void clearmenu(void);//������˵�������
extern void clearboard(void);//��������ͼ������
extern char a, b, c;
extern int readresult;

void drawing(void)
{
	for (; is_run;)//��ͼ����ѭ��
	{
		if (readresult == 1)
		{
			clearmenu();
			zone();
			outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");//���˵�
			outtextxy(3, 21, "1.����1����");
			outtextxy(3, 39, "2.����2�ػ�");
			outtextxy(3, 57, "3.����0�˳�");
			readresult++;
		}
		else
		{
			clearmenu();
			zone();
			outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");//���˵�
			outtextxy(3, 21, "1.����1����");
			outtextxy(3, 39, "2.����2�����Ļ");
			outtextxy(3, 57, "3.����0�˳�");
		}

		b = getch();

		switch (b)
		{
		case '1':
			for (; is_run; delay_fps(60))
			{
				clearmenu();
				zone();
				outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");//��ͼ�˵�
				outtextxy(3, 21, "1.����1������");
				outtextxy(3, 39, "2.����2��Բ��");
				outtextxy(3, 57, "3.����3����");

				c = getch();

				switch (c)
				{
				case '1'://����
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
				case '2'://Բ��
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
				case '3'://��
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
				default://ѡ��ͼ��ʱ����ʱ��ʾ
					clearmenu();
					zone();
					outtextxy(3, 3, "�������");
					outtextxy(3, 21, "�����������");
					getch();
				}
				break;
			}
			break;
		case '2'://�����Ļ
			clearboard();
			break;
		case '0'://�˳�����
			break;
		default://��ѡ���ʱ��ʾ
			clearmenu();
			zone();
			outtextxy(3, 3, "�������");
			outtextxy(3, 21, "�����������");
			getch();
		}
		if (b == '0')//��case '0'�˳�����
			break;
	}
}