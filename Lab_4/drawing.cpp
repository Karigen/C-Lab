#include"graphics.h"
#include<math.h>

extern void zone(void);//菜单边框函数
extern void clearBoard(void);//清理画板作图区域函数
extern void clearMenu(void);//清理画板菜单区域函数
extern char chooseColor(void);//选择边框颜色函数
extern void rechooseColor(char color);//撤销时输出保存的颜色
extern char chooseFillColor(void);//选择填充颜色函数
extern void rechooseFillColor(char fillColor);//撤销时输出保存的填充颜色
extern int num;
extern int readResult;
extern struct shape
{
	char id;
	char color;
	char fillColor;
	int p_num;
	int coor[100];
};
extern shape graph[100];
extern shape* graphArr;
extern void writeToFile(shape* graphArr);

void drawing(void)
{
	char b, c;
	for (; is_run;)//画图的主循环
	{
		if (readResult == 1)
		{
			clearMenu();
			zone();
			outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");//主菜单
			outtextxy(3, 21, "1.输入1作画 4.输入4保存");
			outtextxy(3, 39, "2.输入2重画 5.输入0退出");
			outtextxy(3, 57, "3.输入3撤销");
			readResult++;
		}
		else
		{
			clearMenu();
			zone();
			outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");//主菜单
			outtextxy(3, 21, "1.输入1作画     4.输入4保存");
			outtextxy(3, 39, "2.输入2清除屏幕 5.输入0退出");
			outtextxy(3, 57, "3.输入3撤销");
		}

		b = getch();

		switch (b)
		{
		case '1':
			for (; is_run; delay_fps(60))
			{
				clearMenu();
				zone();
				outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");//画图菜单
				outtextxy(3, 21, "1.输入1画矩形 4.输入4画多变形");
				outtextxy(3, 39, "2.输入2画圆形");
				outtextxy(3, 57, "3.输入3画线");

				c = getch();

				switch (c)
				{
				case '1'://矩形
					graph[num].id = '1';
					graph[num].color = chooseColor();
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
				case '2'://圆形
					graph[num].id = '2';
					graph[num].color = chooseColor();
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
				case '3'://线
					graph[num].id = '3';
					graph[num].color = chooseColor();
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
				case '4'://多边形
				{
					int count = 0;
					int com_count = 0;
					char cxy[100] = { 0 };//存输入
					int polyxy[100] = { 0 };//输入转化为数字
					char* codn;
					bool flag = TRUE;
					graph[num].id = '4';
					graph[num].fillColor = chooseFillColor();
					inputbox_getline("绘制多边形", "请输入坐标(格式：x1,y1,x2,y2...)\n0<x<1200,76<y<700\n坐标至少为3个", cxy, 100);
					int t_count = sizeof(cxy) / sizeof(cxy[0]);
					for (int i = 0; i < t_count; i++)
					{
						if (cxy[i] == ',')
							com_count++;
						if ((cxy[i] < '0' || cxy[i]>'9') && cxy[i] != ',' && cxy[i] != 0)
						{
							flag = FALSE;
							clearMenu();
							zone();
							outtextxy(3, 3, "输入错误");
							outtextxy(3, 21, "按任意键继续");
							graph[num].id = 0;
							graph[num].fillColor = 0;
							getch();
							break;
						}
					}
					if (flag)
					{
						if (com_count % 2 != 1 || com_count < 5)
						{
							flag = FALSE;
							clearMenu();
							zone();
							outtextxy(3, 3, "输入错误");
							outtextxy(3, 21, "按任意键继续");
							getch();
							graph[num].id = 0;
							graph[num].fillColor = 0;
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
				default://选择画图形时按错时显示
					clearMenu();
					zone();
					outtextxy(3, 3, "输入错误");
					outtextxy(3, 21, "按任意键继续");
					getch();
				}
				break;
			}
			break;
		case '2'://清除屏幕
			clearBoard();
			graph[num].id = '0';
			graph[num].fillColor = 'G';
			graph[num].p_num = 2;
			graph[num].coor[0] = 0;
			graph[num].coor[1] = 76;
			graph[num].coor[2] = 1200;
			graph[num].coor[3] = 700;
			num++;
			break;
		case '3'://撤销
		{
			int n;
			if (num > 0)
			{
				clearBoard();
				num--;
				graph[num].id = 0;
				graph[num].color = 0;
				graph[num].fillColor = 0;
				for (int count = 0; count < 2 * graph[num].p_num; count++)
					graph[num].coor[count] = 0;
				graph[num].p_num = 0;
				for (n = 0; n <= num - 1; n++)
				{
					switch (graph[n].id)
					{
					case '0':
						rechooseFillColor(graph[n].fillColor);
						bar(graph[n].coor[0], graph[n].coor[1], graph[n].coor[2], graph[n].coor[3]);
						break;
					case '1':
						rechooseColor(graph[n].color);
						rectangle(graph[n].coor[0], graph[n].coor[1], graph[n].coor[2], graph[n].coor[3]);
						break;
					case '2':
						rechooseColor(graph[n].color);
						circle(graph[n].coor[0], graph[n].coor[1], sqrt((graph[n].coor[2] - graph[n].coor[0]) * (graph[n].coor[2] - graph[n].coor[0]) + (graph[n].coor[3] - graph[n].coor[1]) * (graph[n].coor[3] - graph[n].coor[1])));
						break;
					case '3':
						rechooseColor(graph[n].color);
						line(graph[n].coor[0], graph[n].coor[1], graph[n].coor[2], graph[n].coor[3]);
						break;
					case '4':
						rechooseFillColor(graph[n].fillColor);
						fillpoly(graph[n].p_num, graph[n].coor);
						break;
					}
				}
			}
		}
		break;
		case '4'://保存至文件
			writeToFile(graphArr);
			break;
		case '0'://退出画板
			break;
		default://主选项按错时显示
			clearMenu();
			zone();
			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
		}
		if (b == '0')//接case '0'退出画板
			break;
	}
}