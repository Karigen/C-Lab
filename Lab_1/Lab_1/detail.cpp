#include"graphics.h"

extern void zone(void);//�˵��߿���
extern void choosecolor(void);//ѡ��߿���ɫ����
extern void choosefillcolor(void);//ѡ�������ɫ����
extern void clearmenu(void);//������˵�������
extern void clearboard(void);//��������ͼ������
extern void menu(int readresult);//�˵��ļ�
extern int readfile(void);//��ȡ�����ļ�


void zone(void)//�˵��߿���
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
}

void choosecolor(void)//ѡ��߿���ɫ����
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

void choosefillcolor(void)//ѡ�������ɫ����
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

void clearmenu(void)//������˵�������
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);
}

void clearboard(void)//��������ͼ������
{
	setcolor(WHITE);
	bar(0, 76, 1200, 700);
}

void menu(int readresult)//�˵��ļ�
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

int readfile(void)//��ȡ�����ļ�
{
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