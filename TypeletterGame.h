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


//���ر���ͼƬ���������ڱ����Լ���ĸ����������ͼ��
IMAGE apple[2];

IMAGE Tree;


//������Ϸ�����Լ����ڴ�С
int width = 700;

int height = 500;

int right = 0;

int error = 0;


//ϵͳ�����ĸ�ṹ��
struct SystemLetter
{
	int x;

	int y;

	char sch;
};


//�û�������ĸ�ṹ��
struct USERLETTER
{
	int x;

	int y;

	char uch;

}userletter = { 320,460,' ' };



//ʹouttextxy�ܹ��������
void outtextxy_int(int x, int y, int num);

//ʹouttextxy�ܹ���������ͼ�����ȷ��
void outtextxy_double(int x, int y, double num);

//���ڻ���
void drowwindow();

//��ʼ��ϵͳ�����ĸ
void InitSystemLetter(struct SystemLetter words[], int n);

//�����������������ȷ��
void drawScore();

//���豳��ͼƬ
void Loadimage();

//������ĸͼƬ
void Loadletter(struct SystemLetter words);