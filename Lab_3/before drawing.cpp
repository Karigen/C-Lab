#include"graphics.h"
#include<stdio.h>
#include<math.h>

extern void zone(void);//�˵��߿���
extern int readfile(void);//��ȡ�����ļ�
char a, b, c;//��ͼ֮ǰ��һЩԤ�趨
int readresult;

void before_drawing(void)
{
	initgraph(1200, 700, 0);
	setcaption("�����޵е�ը�컭��");
	setbkcolor(WHITE);
	setfont(18, 0, "����");

	zone();//��ͼǰ��ҳ��
	outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�������ѡ����ȡ���뻭�壩");
	outtextxy(3, 21, "1.����1��ȡ�ļ�");
	outtextxy(3, 39, "2.����2����ȡ�ļ�");
	outtextxy(3, 57, "����������ѡ��");

	a = getch();
	//��ȡ�ļ��벻��ȡ�ļ��ĺ�������
	if (a == '1')//��ȡ
	{
		cleardevice();
		readresult = readfile();
	}
	else if (a == '2')//����ȡ
	{
		cleardevice();

		zone();
		outtextxy(3, 3, "δ��ȡ");
		outtextxy(3, 21, "�����������");
		readresult = 2;
		getch();
	}
	else//����
	{
		cleardevice();

		zone();
		outtextxy(3, 3, "�������");
		outtextxy(3, 21, "�����������");
		readresult = 2;
		getch();
	}
}