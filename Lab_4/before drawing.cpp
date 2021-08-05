#include"graphics.h"

extern void zone(void);//菜单边框函数
extern void clearMenu(void);//清理画板菜单区域函数
extern int readFile(void);//读取函数文件
extern 	int readResult;

void before_drawing(void)
{
	char a;

	initgraph(1200, 700, 0);
	setcaption("宇宙无敌吊炸天画板");
	setbkcolor(WHITE);
	setfont(18, 0, "宋体");

	zone();//画图前的页面
	outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请根据菜单选择您想进行的操作：（选不读取进入画板）");
	outtextxy(3, 21, "1.输入1读取文件");
	outtextxy(3, 39, "2.输入2不读取文件");
	outtextxy(3, 57, "请输入您的选择：");

	a = getch();
	//读取文件与不读取文件的后续函数
	if (a == '1')//读取
	{
		clearMenu();
		readResult = readFile();
	}
	else if (a == '2')//不读取
	{
		clearMenu();

		zone();
		outtextxy(3, 3, "未读取");
		outtextxy(3, 21, "按任意键继续");
		readResult = 2;
		getch();
	}
	else//按错
	{
		clearMenu();

		zone();
		outtextxy(3, 3, "输入错误");
		outtextxy(3, 21, "按任意键继续");
		readResult = 2;
		getch();
	}
}