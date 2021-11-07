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
int length; //몸길이를 기억 
int bend_no;
int len;
char key; //입력한  key 저장 
//void record(); // 기록 저장 -> 리셋 가능 
void load();
int life; //목숨 
void Delay(long double);
void Move();// 뱀 머리 이동 
void Food();// 먹이 생성 
int Score();// 점수 저장 
void Print();// 게임 방법 출력  
void gotoxy(int x, int y);//커서를 원하는 곳에 옮김 
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();// 게임 나가기 
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

	life = 3; //목숨 수  

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

	  if(key==UP) // ↑ 

            head.y--; //y 방향으로 감소  

        if(key==DOWN) //↓ 

            head.y++; // y방향으로 증가  

        if(key==RIGHT) //→ 

            head.x++; // x방향으로 증가  

        if(key==LEFT)//← 

            head.x--; // x방향으로 감소 
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
			printf("게임 끝 \n아무거나 누르면 게임을 나갑니다.. \n");

			exit(0);
		}
	}
}
void Food()
{
	if (head.x == food.x&&head.y == food.y) // x,y 먹이를 먹음
	{
		score += 1; // 1먹이 = 1 점 
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
	//  특수 벽에 부딪힐 시 100점획득  
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
void Boarder() // 벽  
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
	printf("|       배고픈 뱀 게임     |");
    gotoxy(7,7);
	printf("*--------------------------*");
    gotoxy(7,9);
	printf("  ☞다음화면으로(아무키나 누르세요)  ");
    gotoxy(7,11);
	printf("   ◇ 방향키:  w,a,s,d     ");
    gotoxy(7,12);
	printf("   ◇ P : 일시중지           ");    
    gotoxy(7,13);
	printf("   ◇ ESC : 나가기              "); 
    getch();
    system("cls");
    printf("\n 게임 방법\n");
	printf("\n\n☞조작 방법은w:위,s:아래, a: 왼쪽,  d:오른쪽 입니다.\n\n ☞스크린에 나타는 먹이를 먹으세요! 먹이를 먹을 때마다 뱀의 길이가 1만큼 길어집니다.\n\n ☞먹이를 먹을 때마다 점수가 올라갑니다.\n\n ☞목숨은 3개입니다. 벽이나 뱀의 몸통에 부딪힐 시 목숨이 1개씩 사라집니다.\n\n ☞ 일시정지를 하고 싶으면 p를 누르세요. 다시 시작하고 싶다면 다시 p를 누르세요. \n\n☞ 나가고 싶으시다면 ESC를 누르세요");
	printf("\n\n아무 키나 누르면 시작합니다");
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
				printf("@");//머리 모양  
			else
				printf("0");//몸통 모양  
		}
		len++;
	}
	Bend();
	if (!kbhit())
		head.x++;
}
