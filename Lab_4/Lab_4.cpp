#define _CRT_SECURE_NO_WARNINGS 1

#include"graphics.h"
#include<stdio.h>
#include<math.h>

extern void menu(int readresult);//�˵��ļ�
extern void before_drawing(void);
extern void drawing();
extern int close_sketchpad();
extern int readResult;

int main(void)
{
	before_drawing();//ת��before drawing.cpp

	menu(readResult);//ת��detail.cpp

	drawing();//ת��drawing.cpp

	close_sketchpad();//ת��close the sketchpad.cpp
}