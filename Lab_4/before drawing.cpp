#include"graphics.h"

extern void zone(void);//�˵��߿���
extern void clearMenu(void);//������˵�������
extern int readFile(void);//��ȡ�����ļ�
extern 	int readResult;

void before_drawing(void)
{
	char a;

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
		clearMenu();
		readResult = readFile();
	}
	else if (a == '2')//����ȡ
	{
		clearMenu();

		zone();
		outtextxy(3, 3, "δ��ȡ");
		outtextxy(3, 21, "�����������");
		readResult = 2;
		getch();
	}
	else//����
	{
		clearMenu();

		zone();
		outtextxy(3, 3, "�������");
		outtextxy(3, 21, "�����������");
		readResult = 2;
		getch();
	}
}