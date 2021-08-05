#define _CRT_SECURE_NO_WARNINGS 1

#include"graphics.h"
#include<stdio.h>
#include<math.h>

extern void menu(int readresult);//菜单文件
extern void before_drawing(void);
extern void drawing();
extern int close_sketchpad();
extern int readResult;

int main(void)
{
	before_drawing();//转到before drawing.cpp

	menu(readResult);//转到detail.cpp

	drawing();//转到drawing.cpp

	close_sketchpad();//转到close the sketchpad.cpp
}