#pragma once


#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h> 
#include <chrono>
#include <iostream>

#define MAX 3


//加载背景图片（包括窗口背景以及字母背景及掩码图）
IMAGE apple[2];

IMAGE Tree;


//设置游戏数据以及窗口大小
int width = 700;

int height = 500;

int right = 0;

int error = 0;


//系统随机字母结构体
struct SystemLetter
{
	int x;

	int y;

	char sch;
};


//用户输入字母结构体
struct USERLETTER
{
	int x;

	int y;

	char uch;

}userletter = { 320,460,' ' };



//使outtextxy能够输出整型
void outtextxy_int(int x, int y, int num);

//使outtextxy能够输出浮点型计算正确率
void outtextxy_double(int x, int y, double num);

//窗口划线
void drowwindow();

//初始化系统随机字母
void InitSystemLetter(struct SystemLetter words[], int n);

//输出分数错误数及正确率
void drawScore();

//铺设背景图片
void Loadimage();

//铺设字母图片
void Loadletter(struct SystemLetter words);