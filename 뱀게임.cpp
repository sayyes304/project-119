#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

int score = 0;
int length; //�����̸� ��� 
int bend_no;
int len;
char key; //�Է���  key ���� 
//void record(); // ��� ���� -> ���� ���� 
void load();
int life; //��� 
void Delay(long double);
void Move();// �� �Ӹ� �̵� 
void Food();// ���� ���� 
int Score();// ���� ���� 
void Print();// ���� ��� ���  
void gotoxy(int x, int y);//Ŀ���� ���ϴ� ���� �ű� 
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();// ���� ������ 
int Scoreonly();


struct coordinate
{
	int x;
	int y;
	int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500], food, body[30];

int main()
{

	char key;

	Print();

	system("cls");

	length = 5;

	head.x = 25;

	head.y = 20;

	head.direction = RIGHT;

	Boarder();

	Food();

	life = 3; //��� ��  

	bend[0] = head;

	Move();

	return 0;

}


void Move()
{
	int a, i;

	do
	{

		Food();
		fflush(stdin);

		len = 0;

		for (i = 0; i < 30; i++)

		{

			body[i].x = 0;

			body[i].y = 0;

			if (i == length)

				break;

		}

		Delay(length);

		Boarder();

		if (head.direction == 119)

			Up();

		else if (head.direction == 115)

			Down();

		else if (head.direction == 100)

			Right();

		else if (head.direction == 97)

			Left();

		ExitGame();

	} while (!kbhit());

	a = getch();

	if (a == 27)

	{

		system("cls");

		exit(0);

	}
	key = getch();

	if ((key == RIGHT && head.direction != LEFT && head.direction != RIGHT) || (key == LEFT && head.direction != RIGHT && head.direction != LEFT) || (key == UP && head.direction != DOWN && head.direction != UP) || (key == DOWN && head.direction != UP && head.direction != DOWN))

	{

		bend_no++;

		bend[bend_no] = head;

		head.direction = key;

	  if(key==UP) // �� 

            head.y--; //y �������� ����  

        if(key==DOWN) //�� 

            head.y++; // y�������� ����  

        if(key==RIGHT) //�� 

            head.x++; // x�������� ����  

        if(key==LEFT)//�� 

            head.x--; // x�������� ���� 
        Move();
	}

	else if (key == 27)

	{

		system("cls");

		exit(0);

	}

	else if (key == 112)

	{
		printf("\a");
		Move();

	}
}

void gotoxy(int x, int y)
{

	COORD coord;

	coord.X = x;

	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void GotoXY(int x, int y)
{
	HANDLE a;
	COORD b;
	fflush(stdout);
	b.X = x;
	b.Y = y;
	a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a, b);
}


void Delay(long double k)
{
	Score();
	long double i;
	for (i = 0; i <= (1000000); i++);
}
void ExitGame()
{
	int i, check = 0;
	for (i = 4; i < length; i++)
		if (body[0].x == body[i].x&&body[0].y == body[i].y)
		{
			check++;
		}

	if (head.x <= 10 || head.x >= 70 || head.y <= 10 || head.y >= 30 || check != 0)
	{
		life--;
		if (life >= 0)
		{
			head.x = 25;
			head.y = 20;
			bend_no = 0;
			head.direction = RIGHT;
			Move();
		}
		else
		{
			system("cls");
			printf("���� �� \n�ƹ��ų� ������ ������ �����ϴ�.. \n");

			exit(0);
		}
	}
}
void Food()
{
	if (head.x == food.x&&head.y == food.y) // x,y ���̸� ����
	{
		score += 1; // 1���� = 1 �� 
		time_t a;
		a = time(0);
		srand(a);
		food.x = rand() % 70;
		if (food.x <= 10)
			food.x += 11;
		food.y = rand() % 30;
		if (food.y <= 10)

			food.y += 11;
	}
	else if (food.x == 0)
	{
		food.x = rand() % 70;
		if (food.x <= 10)
			food.x += 11;
		food.y = rand() % 30;
		if (food.y <= 10)
			food.y += 11;
	}
	//  Ư�� ���� �ε��� �� 100��ȹ��  
	if (head.x == 11 && (11 <= head.y <= 13)) {
		score += 100;
	}
	GotoXY(food.x, food.y);
	printf("S");
}

void Bend()
{
	int i, j, diff;
		for (i = bend_no; i >= 0 && len < length; i--)
		{
			if (bend[i].x == bend[i - 1].x)
			{
				diff = bend[i].y - bend[i - 1].y;
				if (diff < 0)
					for (j = 1; j <= (-diff); j++)
					{
						body[len].x = bend[i].x;
						body[len].y = bend[i].y + j;
						GotoXY(body[len].x, body[len].y);
						printf("0");
						len++;
						if (len == length)
							break;
					}
				else if (diff > 0) 
					for (j = 1; j <= diff; j++)
					{

						body[len].x = bend[i].x;
						body[len].y = bend[i].y - j;
						GotoXY(body[len].x, body[len].y);
						printf("0");
						len++;
						if (len == length)
							break;
					}
			}
			else if (bend[i].y == bend[i - 1].y)
			{
				diff = bend[i].x - bend[i - 1].x;
				if (diff < 0)
					for (j = 1; j <= (-diff) && len < length; j++)
					{

						body[len].x = bend[i].x + j;
						body[len].y = bend[i].y;
						GotoXY(body[len].x, body[len].y);
						printf("0");
						len++;
						if (len == length)
							break;
					}
				else if (diff > 0) 
					for (j = 1; j <= diff && len < length; j++)
					{

						body[len].x = bend[i].x - j;
						body[len].y = bend[i].y;
						GotoXY(body[len].x, body[len].y);
						printf("0");
						len++;
						if (len == length)
							break;
					}
			}
		}
}
void Boarder() // ��  
{
	system("cls");
	int i;
	for (i = 10; i < 71; i++)
	{
		GotoXY(i, 10);
		printf("Q");
		GotoXY(i, 30);
		printf("Q");
	}
	for (i = 10; i < 31; i++)
	{
		GotoXY(10, i);
		printf("Q");
		GotoXY(70, i);
		printf("Q");
	}
}
void Print()
{
	int row,col,r,c,q,k;
     gotoxy(7,5);
	printf("*--------------------------*");
    gotoxy(7,6);
	printf("|       ����� �� ����     |");
    gotoxy(7,7);
	printf("*--------------------------*");
    gotoxy(7,9);
	printf("  �Ѵ���ȭ������(�ƹ�Ű�� ��������)  ");
    gotoxy(7,11);
	printf("   �� ����Ű:  w,a,s,d     ");
    gotoxy(7,12);
	printf("   �� P : �Ͻ�����           ");    
    gotoxy(7,13);
	printf("   �� ESC : ������              "); 
    getch();
    system("cls");
    printf("\n ���� ���\n");
	printf("\n\n������ �����w:��,s:�Ʒ�, a: ����,  d:������ �Դϴ�.\n\n �ѽ�ũ���� ��Ÿ�� ���̸� ��������! ���̸� ���� ������ ���� ���̰� 1��ŭ ������ϴ�.\n\n �Ѹ��̸� ���� ������ ������ �ö󰩴ϴ�.\n\n �Ѹ���� 3���Դϴ�. ���̳� ���� ���뿡 �ε��� �� ����� 1���� ������ϴ�.\n\n �� �Ͻ������� �ϰ� ������ p�� ��������. �ٽ� �����ϰ� �ʹٸ� �ٽ� p�� ��������. \n\n�� ������ �����ôٸ� ESC�� ��������");
	printf("\n\n�ƹ� Ű�� ������ �����մϴ�");
    if(getch()==27)
        exit(0);
}

int Score()
{
	GotoXY(20, 8);
	printf("SCORE : %d", score);

	GotoXY(50, 8);
	printf("Life : %d", life);
	return score;
}
void Up()
{
	int i;
	for (i = 0; i <= (bend[bend_no].y - head.y) && len < length; i++)
	{
		GotoXY(head.x, head.y + i);
		{
			if (len == 0)
				printf("@");
			else
				printf("0");
		}
		body[len].x = head.x;
		body[len].y = head.y + i;
		len++;
	}
	Bend();
	if (!kbhit())
		head.y--;
}
void Down()
{
	int i;
	for (i = 0; i <= (head.y - bend[bend_no].y) && len < length; i++)
	{
		GotoXY(head.x, head.y - i);
		{
			if (len == 0)
				printf("@");
			else
				printf("0");
		}
		body[len].x = head.x;
		body[len].y = head.y - i;
		len++;
	}
	Bend();
	if (!kbhit())
		head.y++;
}
void Left()
{
	int i;
	for (i = 0; i <= (bend[bend_no].x - head.x) && len < length; i++)
	{
		GotoXY((head.x + i), head.y);
		{
			if (len == 0)
				printf("@");
			else
				printf("0");
		}
		body[len].x = head.x + i;
		body[len].y = head.y;
		len++;
	}
	Bend();
	if (!kbhit())
		head.x--;

}
void Right()
{
	int i;
	for (i = 0; i <= (head.x - bend[bend_no].x) && len < length; i++)
	{
		body[len].x = head.x - i;
		body[len].y = head.y;
		GotoXY(body[len].x, body[len].y);
		{
			if (len == 0)
				printf("@");//�Ӹ� ���  
			else
				printf("0");//���� ���  
		}
		len++;
	}
	Bend();
	if (!kbhit())
		head.x++;
}
