#include "TypeLetterGame.h"



int main()
{

	//���������

	srand((unsigned int)time(NULL));

	//���ô��ڴ�С

	initgraph(690, 480);

	//���ر���ͼƬ

	Loadimage();

	//����ϵͳ�����ĸ

	struct SystemLetter words[MAX];


	//������������ַ���

	for (int n = 0; n < MAX; n++)
	{
		InitSystemLetter(words, n);

		words[n].y = -100 - n * 30;
	}
	int i = 0;


	//��Ϸ��ʼ
	//��ʱ��ʼ��
	auto start = std::chrono::steady_clock::now();

	while (1)
	{
		//��������ֹ���濨��
		BeginBatchDraw();

		//������ͼ
		putimage(0, 0, &Tree);

		//���ڻ���
		drowwindow();


		//��ĸ���紦��
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


		//����������ɫ
		for (int n = 0; n < MAX; n++)
		{
			settextcolor(WHITE);
			
		}


		//�����������


		//kbhit������Ϻ���������ʱ������ͣ����
		//���������м������룬�򷵻������ֵ��Ӧ���Ǽ�ֵת����������0����û���򷵻�0��
		
		if (_kbhit())

		{
			char usertarget;

			//�����ڿո�Ϊ�棬ִ�иó��򣬴洢�û���������
			//���ڿո�Ϊ�٣������ó��򣬽�����һ���ж��û������Ƿ���ȷ

			if ((usertarget = _getch()) != ' ')
			{
				userletter.uch = usertarget;
			}
			else
			{
				//�÷ֻ���
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

		//��ӡ����

		drawScore();

		//���廭���ֹ���濨��

		EndBatchDraw();

		//ÿһ����ĸ����ʱ����60����
		Sleep(50);


		//ͳ��ʱ�������������ʮ���ֹͣ����

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



	//�رջ���
	closegraph();

	return 0;
}




//���庯��ʵ��


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

	outtextxy(610, 225, "��ȷ����");
	outtextxy_int(610, 250, right);

	outtextxy(610, 285, "��������");
	outtextxy_int(610, 310, error);

	outtextxy(610, 345, "��ȷ��");

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