#include "TypeLetterGame.h"



int main()
{

	//设置随机数

	srand((unsigned int)time(NULL));

	//设置窗口大小

	initgraph(690, 480);

	//加载背景图片

	Loadimage();

	//定义系统随机字母

	struct SystemLetter words[MAX];


	//产生随机掉落字符串

	for (int n = 0; n < MAX; n++)
	{
		InitSystemLetter(words, n);

		words[n].y = -100 - n * 30;
	}
	int i = 0;


	//游戏开始
	//计时开始；
	auto start = std::chrono::steady_clock::now();

	while (1)
	{
		//缓冲界面防止界面卡顿
		BeginBatchDraw();

		//贴背景图
		putimage(0, 0, &Tree);

		//窗口划线
		drowwindow();


		//字母出界处理
		for (int n = 0; n < MAX; n++)
		{
			words[n].y += 5;

			Loadletter(words[n]);

			if (words[n].y > (height - 50 - textheight(words[n].sch)))
			{
				InitSystemLetter(words, n);

				error++;

			}
		}


		//设置字体颜色
		for (int n = 0; n < MAX; n++)
		{
			settextcolor(WHITE);
			
		}


		//键盘输入控制


		//kbhit：非阻断函数，运行时不会暂停程序，
		//作用是若有键盘输入，则返回输入的值（应该是键值转换）反正非0，若没有则返回0。
		
		if (_kbhit())

		{
			char usertarget;

			//不等于空格为真，执行该程序，存储用户键盘输入
			//等于空格为假，跳过该程序，进入下一步判断用户输入是否正确

			if ((usertarget = _getch()) != ' ')
			{
				userletter.uch = usertarget;
			}
			else
			{
				//得分机制
				int flagError = 0;

				for (i = 0; i < MAX; i++)
				{
					if (userletter.uch == words[i].sch)
					{
						InitSystemLetter(words, i);

						right++;

						flagError = 1;

					}

				}

				if (flagError == 0)
				{
					error++;
				}
				i = 0;


				//userletter.x = 320;

			}

		}

		outtextxy(userletter.x, userletter.y, userletter.uch);

		//打印分数

		drawScore();

		//缓冲画面防止画面卡顿

		EndBatchDraw();

		//每一次字母下落时间间隔60毫秒
		Sleep(50);


		//统计时长，如果到了三十秒就停止程序。

		auto now = std::chrono::steady_clock::now();
		auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
		if (elapsed_seconds >= 30) {

			for (int n = 0; n < MAX; n++) {

				words[n].y = -100;
			}

			outtextxy(290, 50, "GameOver");

			system("pause");
		}

	}



	//关闭画面
	closegraph();

	return 0;
}




//具体函数实现


void outtextxy_int(int x, int y, int num)
{
	char str[20];
	sprintf(str, "%d", num);
	outtextxy(x, y, str);

}

void outtextxy_double(int x, int y, double num)
{
	char str[20];
	sprintf(str, "%f", num);
	outtextxy(x, y, str);

}

void drowwindow()
{
	line(600, 0, 600, 450);
	line(0, 450, 750, 450);
	line(600, 130, 750, 130);

}

void InitSystemLetter(struct SystemLetter words[], int n)
{
	static char str[26] = { 'A','B','C','D','E','F','G',
							'H','I','J','K','L','M','N',
							'O','P','Q','R','S','T','U',
							'V','W','X','Y','Z' };


	words[n].sch = str[rand() % 26];


	while (words[n].sch == words[(n + 1)].sch
		|| words[n].sch == words[(n + 2)].sch				
											)

	{
		words[n].sch = str[rand() % 26];

	}
	words[n].x = rand() % (550);
	words[n].y = -50;

};



void drawScore()
{

	outtextxy(610, 225, "正确数：");
	outtextxy_int(610, 250, right);

	outtextxy(610, 285, "错误数：");
	outtextxy_int(610, 310, error);

	outtextxy(610, 345, "正确率");

	if (right + error == 0)
	{
		outtextxy_double(610, 370, 0.0);
	}
	else
	{
		double sum = right + error;
		outtextxy_double(610, 370, right / sum * 100);
	}
}



void Loadimage() {

	loadimage(&Tree, _T("tree.jpg"), 690, 480);
	loadimage(&apple[0], _T("appley.jpg"), 50, 50);
	loadimage(&apple[1], _T("appleb.jpg"), 50, 50);

}



void Loadletter(struct SystemLetter words) {

	putimage(words.x, words.y, &apple[0], SRCAND);
	putimage(words.x, words.y, &apple[1], SRCPAINT);
	setbkmode(TRANSPARENT);
	outtextxy(words.x + 20, words.y + 17, words.sch);

}