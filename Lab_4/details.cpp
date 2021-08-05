#include"graphics.h"
#include<math.h>
#include<stdio.h>

void zone(void);//�˵��߿���
char chooseColor(void);//ѡ��߿���ɫ����
void rechooseColor(char color);//����ʱ����������ɫ
char chooseFillColor(void);//ѡ�������ɫ����
void rechooseFillColor(char fillColor);//����ʱ�������������ɫ
void clearMenu(void);//������˵�������
void clearBoard(void);//��������ͼ������
void menu(int readResult);//�˵��ļ�
int readFile(void);//��ȡ�����ļ�
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

void zone(void)//�˵��߿���
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
}

char chooseColor(void)//ѡ��߿���ɫ����
{
	char a;
	do
	{
		clearMenu();

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
			clearMenu();
			zone();
			outtextxy(3, 3, "�������");
			outtextxy(3, 21, "�����������");
			getch();
		}
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9' && a != 'A' && a != 'B' && a != 'C' && a != 'D' && a != 'E' && a != 'F' && a != 'G');
	return a;
}

void rechooseColor(char color)//����ʱ����������ɫ
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

char chooseFillColor(void)//ѡ�������ɫ����
{
	char a;
	do
	{
		clearMenu();

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
			clearMenu();
			zone();
			outtextxy(3, 3, "�������");
			outtextxy(3, 21, "�����������");
			getch();
		}
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9' && a != 'A' && a != 'B' && a != 'C' && a != 'D' && a != 'E' && a != 'F' && a != 'G');
	return a;
}

void rechooseFillColor(char fillColor)//����ʱ�������������ɫ
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

void clearMenu(void)//������˵�������
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);
}

void clearBoard(void)//��������ͼ������
{
	setfillcolor(WHITE);
	bar(0, 76, 1200, 700);
}

void menu(int readresult)//�˵��ļ�
{
	if (readresult == 1)
	{
		clearMenu();
		zone();
		outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");
		outtextxy(3, 21, "1.��ȡ�ļ��ɹ�");
		outtextxy(3, 39, "2.�����������");

		getch();
	}
	else if (readresult == 0)
	{
		clearMenu();
		zone();
		outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");
		outtextxy(3, 21, "1.δ��ȡ");
		outtextxy(3, 39, "2.�����������");
		getch();
	}
	else
		;
}

int readFile(void)//��ȡ�����ļ�
{
	char fileName[5] = { 0 };
	FILE* file;
	int flag;
	inputbox_getline("������", "������Ҫ��ȡ���ļ���", fileName, 5);
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
		outtextxy(3, 3, "�ļ�������");
		outtextxy(3, 21, "�����������");

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
	inputbox_getline("������", "������Ҫ��ȡ���ļ���", fileName, 5);
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