#include"graphics.h"
#include<stdio.h>
#include<math.h>


extern void zone(void);//�˵��߿���
char choosecolor(void);//ѡ��߿���ɫ����
void rechoosecolor(char color);//����ʱ����������ɫ
char choosefillcolor(void);//ѡ�������ɫ����
void rechoosefillcolor(char fillcolor);//����ʱ�������������ɫ
extern void clearmenu(void);//������˵�������
extern void clearboard(void);//��������ͼ������
extern char a, b, c;
extern int readresult;

void drawing(void)
{
	int num = 0;//ͼ�ͽṹ������
	struct shape
	{
		char id;
		char color;
		char fillcolor;
		int p_num;
		int coor[100];
	};
	shape graph[100] = { 0 };
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
			outtextxy(3, 21, "1.����1����     4.����0�˳�");
			outtextxy(3, 39, "2.����2�����Ļ");
			outtextxy(3, 57, "3.����3����");
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
				outtextxy(3, 21, "1.����1������ 4.����4�������");
				outtextxy(3, 39, "2.����2��Բ��");
				outtextxy(3, 57, "3.����3����");

				c = getch();

				switch (c)
				{
				case '1'://����
					graph[num].id = '1';
					graph[num].color = choosecolor();
					graph[num].p_num = 2;
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
							graph[num].coor[0] = x1;
							y1 = msg.y;
							graph[num].coor[1] = y1;
							count++;
						}
						else if (msg.is_left() && msg.is_down() && count == 2)
						{
							x2 = msg.x;
							graph[num].coor[2] = x2;
							y2 = msg.y;
							graph[num].coor[3] = y2;
							count++;
						}
						if (count == 3)
						{
							rectangle(x1, y1, x2, y2);
							num++;
							break;
						}
					}
					break;
				case '2'://Բ��
					graph[num].id = '2';
					graph[num].color = choosecolor();
					graph[num].p_num = 2;
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
							graph[num].coor[0] = x1;
							y1 = msg.y;
							graph[num].coor[1] = y1;
							count++;
						}
						else if (msg.is_left() && msg.is_down() && count == 2)
						{
							x2 = msg.x;
							graph[num].coor[2] = x2;
							y2 = msg.y;
							graph[num].coor[3] = y2;
							count++;
						}
						if (count == 3)
						{
							circle(x1, y1, sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
							num++;
							break;
						}
					}
					break;
				case '3'://��
					graph[num].id = '3';
					graph[num].color = choosecolor();
					graph[num].p_num = 2;
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
							graph[num].coor[0] = x1;
							y1 = msg.y;
							graph[num].coor[1] = y1;
							count++;
						}
						else if (msg.is_left() && msg.is_down() && count == 2)
						{
							x2 = msg.x;
							graph[num].coor[2] = x2;
							y2 = msg.y;
							graph[num].coor[3] = y2;
							count++;
						}
						if (count == 3)
						{
							line(x1, y1, x2, y2);
							num++;
							break;
						}
					}
					break;
				case '4'://�����
				{
					int count = 0;
					int com_count = 0;
					char cxy[100] = { 0 };//������
					int polyxy[100] = { 0 };//����ת��Ϊ����
					char* codn;
					bool flag = TRUE;
					graph[num].id = '4';
					graph[num].fillcolor = choosefillcolor();
					inputbox_getline("���ƶ����", "����������(��ʽ��x1,y1,x2,y2...)\n0<x<1200,76<y<700\n��������Ϊ3��", cxy, 100);
					int t_count = sizeof(cxy) / sizeof(cxy[0]);
					for (int i = 0; i < t_count; i++)
					{
						if (cxy[i] == ',')
							com_count++;
						if ((cxy[i] < '0' || cxy[i]>'9') && cxy[i] != ',' && cxy[i] != 0)
						{
							flag = FALSE;
							clearmenu();
							zone();
							outtextxy(3, 3, "�������");
							outtextxy(3, 21, "�����������");
							graph[num].id = 0;
							graph[num].fillcolor = 0;
							getch();
							break;
						}
					}
					if (flag)
					{
						if (com_count % 2 != 1||com_count<5)
						{
							flag = FALSE;
							clearmenu();
							zone();
							outtextxy(3, 3, "�������");
							outtextxy(3, 21, "�����������");
							graph[num].id = 0;
							graph[num].fillcolor = 0;
							getch();
						}
					}
					if (flag)
					{
						codn = strtok(cxy, ",");
						while (codn != NULL)
						{
							polyxy[count] = atoi(codn);
							graph[num].coor[count] = polyxy[count];
							codn = strtok(NULL, ",");
							count++;
						}
						graph[num].p_num = (count + 1) / 2;
						fillpoly((count + 1) / 2, polyxy);
						num++;
					}
					break;
				}
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
			graph[num].id = '0';
			graph[num].fillcolor = 'G';
			graph[num].p_num = 2;
			graph[num].coor[0] = 0;
			graph[num].coor[1] = 76;
			graph[num].coor[2] = 1200;
			graph[num].coor[3] = 700;
			num++;
			break;
		case '3'://����
		{
			int n;
			if (num > 0)
			{
				clearboard();
				num--;
				graph[num].id = 0;
				graph[num].color = 0;
				graph[num].fillcolor = 0;
				for (int count = 0; count <2* graph[num].p_num; count++)
					graph[num].coor[count] = 0;
				graph[num].p_num = 0;
				for (n = 0; n <= num - 1; n++)
				{
					switch (graph[n].id)
					{
					case '0':
						rechoosefillcolor(graph[n].fillcolor);
						bar(graph[n].coor[0], graph[n].coor[1], graph[n].coor[2], graph[n].coor[3]);
						break;
					case '1':
						rechoosecolor(graph[n].color);
						rectangle(graph[n].coor[0], graph[n].coor[1], graph[n].coor[2], graph[n].coor[3]);
						break;
					case '2':
						rechoosecolor(graph[n].color);
						circle(graph[n].coor[0], graph[n].coor[1], sqrt((graph[n].coor[2] - graph[n].coor[0]) * (graph[n].coor[2] - graph[n].coor[0]) + (graph[n].coor[3] - graph[n].coor[1]) * (graph[n].coor[3] - graph[n].coor[1])));
						break;
					case '3':
						rechoosecolor(graph[n].color);
						line(graph[n].coor[0], graph[n].coor[1], graph[n].coor[2], graph[n].coor[3]);
						break;
					case '4':
						rechoosefillcolor(graph[n].fillcolor);
						fillpoly(graph[n].p_num, graph[n].coor);
						break;
					}
				}
			}
		}
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