#include"graphics.h"
#include<math.h>
#include<stdio.h>

void zone(void);//菜单边框函数
char chooseColor(void);//选择边框颜色函数
void rechooseColor(char color);//撤销时输出保存的颜色
char chooseFillColor(void);//选择填充颜色函数
void rechooseFillColor(char fillColor);//撤销时输出保存的填充颜色
void clearMenu(void);//清理画板菜单区域函数
void clearBoard(void);//清理画板作图区域函数
void menu(int readResult);//菜单文件
int readFile(void);//读取函数文件
int readResult;
int num = 0;
struct shape
{
	char id;
	char color;
	char fillColor;
	int p_num;
	int coor[100];
};
shape graph[100] = { 0 };
shape* graphArr = graph;
void writeToFile(shape* graphArr);

void zone(void)//菜单边框函数
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
}

char chooseColor(void)//选择边框颜色函数
{
	char a;
	do
	{
		clearMenu();

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
			clearMenu();
			zone();
			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
		}
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9' && a != 'A' && a != 'B' && a != 'C' && a != 'D' && a != 'E' && a != 'F' && a != 'G');
	return a;
}

void rechooseColor(char color)//撤销时输出保存的颜色
{
	switch (color)
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
	}
}

char chooseFillColor(void)//选择填充颜色函数
{
	char a;
	do
	{
		clearMenu();

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
			clearMenu();
			zone();
			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
		}
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9' && a != 'A' && a != 'B' && a != 'C' && a != 'D' && a != 'E' && a != 'F' && a != 'G');
	return a;
}

void rechooseFillColor(char fillColor)//撤销时输出保存的填充颜色
{
	switch (fillColor)
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
	}
}

void clearMenu(void)//清理画板菜单区域函数
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);
}

void clearBoard(void)//清理画板作图区域函数
{
	setfillcolor(WHITE);
	bar(0, 76, 1200, 700);
}

void menu(int readresult)//菜单文件
{
	if (readresult == 1)
	{
		clearMenu();
		zone();
		outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");
		outtextxy(3, 21, "1.读取文件成功");
		outtextxy(3, 39, "2.按任意键继续");

		getch();
	}
	else if (readresult == 0)
	{
		clearMenu();
		zone();
		outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：");
		outtextxy(3, 21, "1.未读取");
		outtextxy(3, 39, "2.按任意键继续");
		getch();
	}
	else
		;
}

int readFile(void)//读取函数文件
{
	char fileName[5] = { 0 };
	FILE* file;
	int flag;
	inputbox_getline("请输入", "请输入要读取的文件名", fileName, 5);
	file = fopen(fileName, "r");
	if (file != NULL)
	{
		fscanf(file, "%d\n", &num);
		for (int n = 0; n < num; n++)
		{
			fscanf(file, "%c     %c     %c     %d     ", &graph[n].id, &graph[n].color, &graph[n].fillColor, &graph[n].p_num);
			for (int m = 0; m < 2 * graph[n].p_num; m++)
				fscanf(file, "%d     ", &graph[n].coor[m]);
			fscanf(file, "\n");
		}
		fclose(file);
		for (int n = 0; n <= num - 1; n++)
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
	else
	{
		cleardevice();

		zone();
		outtextxy(3, 3, "文件不存在");
		outtextxy(3, 21, "按任意键继续");

		getch();
	}

	if (file != NULL)
		return 1;
	else
		return 0;
}

void writeToFile(shape* graphArr)
{
	FILE* file;
	char fileName[5] = { 0 };
	inputbox_getline("请输入", "请输入要读取的文件名", fileName, 5);
	file = fopen(fileName, "w");
	fprintf(file, "%d\n", num);
	for (int n = 0; n < num; n++)
	{
		fprintf(file, "%c     %c     %c     %d     ", graph[n].id, graph[n].color, graph[n].fillColor, graph[n].p_num);
		for (int m = 0; m < 2 * graph[n].p_num; m++)
			fprintf(file, "%d     ", graph[n].coor[m]);
		fprintf(file, "\n");
	}
	fclose(file);
}