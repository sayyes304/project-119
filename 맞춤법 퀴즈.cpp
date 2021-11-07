#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void gotoxy(int x, int y);
void kakao();
void menu();
void Quiz(); 
void Education();
void gotoxy(int x, int y)
{

	COORD coord;

	coord.X = x;

	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);}
	void kakao()
{

  printf(" ━━━━━━━━━━━━━━━\n");
printf("┃　　===    ●  ┃\n");
 printf("┃               ┃\n");
 printf("┃  ━━━━━━ ━━━   ┃\n");
 printf("┃ ┃    카     ┃ ┃\n");
 printf("┃ ┃    톡     ┃ ┃\n");
 printf("┃ ┃    알     ┃ ┃\n");
 printf("┃ ┃    람     ┃ ┃\n");
 printf("┃ ┃           ┃ ┃\n");
 printf("┃  ━━━━━━ ━━━   ┃\n");
 printf("┃　　　○　　   ┃\n");
 printf(" ━━━━━━━━━━━━━━━\n");
  system("pause");
 system("cls");
}
void menu()
{
	gotoxy(10,10);
	printf("1. 게임 시작\n");
	gotoxy(10,12);
	printf("2. 맞춤법 교실\n");
	gotoxy(10,14);
	printf("3. 게임 나가기\n");
	gotoxy(10,18);
	printf("번호를 선택하세요 : ");
	
	int number;
	scanf("%d",&number);
	system("cls");
	switch(number)
	{
		case 1:
			Quiz();
			break;
		case 2:
			Education();
			break;	
		case 3:
			exit(0);
			break;	
	}
 } 
int main()
{


 printf("맞춤법 퀴즈! \n\n\n");
 printf(" ━━━━━━━━━━━━━━━\n");
 printf("┃　　===    ●  ┃\n");
 printf("┃  맞춤법 퀴즈  ┃\n");
 printf("┃  ━━━━━━ ━━━   ┃\n");
 printf("┃ ┃    訓     ┃ ┃\n");
 printf("┃ ┃    民     ┃ ┃\n");
 printf("┃ ┃    正     ┃ ┃\n");
 printf("┃ ┃    音     ┃ ┃\n");
 printf("┃ ┃           ┃ ┃\n");
 printf("┃  ━━━━━━ ━━━   ┃\n");
 printf("┃　　　○　　   ┃\n");
 printf(" ━━━━━━━━━━━━━━━\n");


 system("pause");
 system("cls");
 printf("\n\n\n");
  menu();
 }
 
 void Quiz()
{
 char str[15];
 printf("이름을 입력하세요:\n");
 
 scanf("%s",&str);
 system("cls");



 char a[32];
kakao();

int an;
 printf("   _____________________________________________ \n");
 printf("\n  |%s야(아) 나 담주에 시험인데 잘할 수 있을까? |\n",str);
 printf(" < _____________________________________________\n");
 printf("   ");
 printf("\n");
 printf("1. 잘할 수 있을거야!\n");
 printf("2. 잘할 수 있을꺼야!\n\n");
 printf(" 정답:  ");
 scanf("%d",&an);
 system("pause");
 system("cls");
 if(an==1)
 {
 	gotoxy(30,8);
 	 printf("   ______________________________________ \n");
 	gotoxy(30,9);
 	printf("  |           잘할 수 있을거야!          |\n");
 	gotoxy(30,10);
 	printf("  _______________________________________ >\n\n\n");
 	printf("   ____________________________________ \n");
 	printf("\n  |고마워\( ´●V ●`*)/               |\n");
 	printf(" < _____________________________________\n\n\n");
 
 	printf("정답입니다!\n 발음은 [꺼]로 나지만, 표기는 ‘거’로 합니다.\n\n\n");
 
 system("pause");
 system("cls");}
 else
 {
 	gotoxy(30,8);
 	 printf("   ______________________________________ \n");
 	gotoxy(30,9);
 	printf("  |           잘할 수 있을꺼야!          |\n");
 	gotoxy(30,10);
 	printf("  _______________________________________ >\n\n\n");
 	printf("   ____________________________________ \n");
 	printf("\n  |고마워 근데 꺼가 아니라 거야..ㅎ    |\n");
 	printf(" < _____________________________________\n\n\n");
 printf("틀렸습니다.\n발음은 [꺼]로 나지만, 표기는 ‘거’로 합니다.\n\n\n");
system("pause");
 system("cls");}
 
 char b[32];
 kakao();
 int bn;
 printf("   ------------------------------------------ \n");
 printf("\n  |  %s야(아) 너 내일 나올 수 있어?         |\n",str);
 printf("  < -----------------------------------------\n\n\n");
 printf("1. 당연히 돼지!\n");
 printf("2. 당연히 되지!\n");
 printf(" 정답: ");
 scanf("%d",&bn);
 system("pause");
 system("cls");
 if(bn==1)
  {
 	gotoxy(30,8);
 	 printf("   ______________________________________ \n");
 	gotoxy(30,9);
 	printf("  |           당연히 돼지!               |\n");
 	gotoxy(30,10);
 	printf("  _______________________________________ >\n\n\n");
 	printf("   ____________________________________ \n");
 	printf("\n  | 뭐? 내가 돼지라고?!               |\n");
 	printf(" < ____________________________________\n\n\n");
 	printf("틀렸습니다,!\n 돼는 '되어' 의 준말로 돼에 '해'를 넣으면 됩니다.\n 예) 안돼->안해\n\n\n");
 
 system("pause");
 system("cls");}
 else
 {
 	gotoxy(30,8);
 	 printf("   ______________________________________ \n");
 	gotoxy(30,9);
 	printf("  |           당연히 되지!               |\n");
 	gotoxy(30,10);
 	printf("  _______________________________________ >\n\n\n");
 	printf("   ____________________________________ \n");
 	printf("\n  |그랭 그럼 내일 7시에 보자!         |\n");
 	printf(" < ____________________________________\n\n\n");
 printf("정답입니다!.\n 되는 되다의 준말로 '되'에 '하'를 덯으면 됩니다\n 예)안되나요?-> 안하나요?\n\n\n");
system("pause");
 system("cls");}

 char c[32];
 kakao();
int cn;
 printf("   _____________________________________________ \n");
 printf("\n  |%s야(아) 우리 에슐리 언제 갔더라?            |\n",str);
 printf(" < _____________________________________________\n");
 printf("   ");
 printf("\n");
 printf("1. 재작년에 갔어.\n");
 printf("2. 제작년에 갔어.\n\n");
 printf(" 정답: ");
 scanf("%d",&cn);
 system("pause");
 system("cls");
 if(cn==1)
 {
 	gotoxy(30,8);
 	 printf("   ______________________________________ \n");
 	gotoxy(30,9);
 	printf("  |           재작년에 갔어.             |\n");
 	gotoxy(30,10);
 	printf("  _______________________________________ >\n\n\n");
 	printf("   ____________________________________ \n");
 	printf("\n  |아항 땡큐 다음에 또 가자!          |\n");
 	printf(" < ____________________________________\n\n\n");
 
 	printf("정답입니다!\n 한자 ‘다시 재(再)’자를 쓰므로 '재작년'으로 표기해야 합니다.\n\n\n");
 
 system("pause");
 system("cls");}
 else
 {
 	gotoxy(30,8);
 	 printf("   ______________________________________ \n");
 	gotoxy(30,9);
 	printf("  |           제작년에 갔어.            |\n");
 	gotoxy(30,10);
 	printf("  _______________________________________ >\n\n\n");
 	printf("   ____________________________________ \n");
 	printf("\n  |오호 근데 재작년 아니야..?          |\n");
 	printf(" < _____________________________________\n\n\n");
 printf("틀렸습니다.\n한자 ‘다시 재(再)’자를 쓰므로 '재작년'으로 표기해야 합니다.\n\n\n");
system("pause");
 system("cls");}

 char d[32];
 kakao();
int dn;
 printf("   _____________________________________________ \n");
 printf("\n  | %s야(아) 너 오늘 학교 갔니?                |\n",str);
 printf(" < _____________________________________________\n");
 printf("   ");
 printf("\n");
 printf("1. 아니 학교 않갔어\n");
 printf("2. 아니 학교 안갔어 \n\n");
 printf(" 정답: ");
 scanf("%d",&an);
 system("pause");
 system("cls");
 if(dn==1)
 {
 	gotoxy(30,8);
 	 printf("   ______________________________________ \n");
 	gotoxy(30,9);
 	printf("  |          아니 학교 않갔어            |\n");
 	gotoxy(30,10);
 	printf("  _______________________________________ >\n\n\n");
 	printf("   ____________________________________ \n");
 	printf("\n  | ㅇㅋ 근데 않(X) 안(o) 이단다^^     |\n");
 	printf(" < _____________________________________\n\n\n");
 
 	printf("틀렸습니다. '않'은 아니하다의 준말이므로 '안갔어'라고 해야합니다 .\n\n\n");
 
 system("pause");
 system("cls");}
 else
 {
 	gotoxy(30,8);
 	 printf("   ______________________________________ \n");
 	gotoxy(30,9);
 	printf("  |           아니 학교 안갔어          |\n");
 	gotoxy(30,10);
 	printf("  _______________________________________ >\n\n\n");
 	printf("   ____________________________________ \n");
 	printf("\n  |ㅇㅋㅇㅋ 알겠어! 다음에 보자!       |\n");
 	printf(" < _____________________________________\n\n\n");
 printf("정답입니다! '안'은 아니의 준말이므로 '안갔어'라고 해야합니다.\n\n\n");
system("pause");
 system("cls");}
 

 printf("\n\n\n\n");
 printf("====================");
 printf("\n퀴즈가 끝났습니다. \n 메뉴로 돌아갑니다.\n");
 printf("====================");
 printf("\n\n");
 system("pause");
 system("cls");
 menu();
}

void Education()
{
	printf("<자주 틀리는 맞춤법 10가지>\n\n ");
	printf("1) 안되(X)\n 안돼(O)\n\n='되'에는 '하'를, '돼'자리에 '해'를 넣어보세요!\n\n 2)어의없다(X)\n 어이없다(O)\n\n='어의'란 임금이 입던 옷입니다.\n\n  3)금새(X)\n 금세(O)\n\n='금새'란 물건의 값입니다. ");
	printf("\n\n5)왠만하면(X)\n 웬만하면(O)\n\n='왠'은 '왠지'일때만 쓰입니다.\n\n6)건들이다(X)\n건드리다(O)\n\n=건들이다는 사전에 없는 단어입니다.\n\n7)요세(X)\n요새(O)\n\n='요세'란 요역과 세금이란 뜻입니다."); 
	printf("\n\n8)어떻해(X)\n어떡해(O)\n\n='어떡해'는 어떻게 해의 줄임말 입니다.\n\n9)빨리 낳아(X)\n빨리 나아(O)\n\n='낳다'는 아이, 새끼를 몸 밖으로 내놓다 또는 결과를 가져오다라는 뜻입니다. 병세가 좋아지다는 '낫다' 즉, '나아'를 써야합니다.");
	printf("\n\n10)짜집기(X)\n 짜깁기(O)\n\n= '짜집기'란 '짜깁기'의 잘못된 말입니다.\n\n");
	system("pause");
	system("cls");  
	int num;
	printf("이대로 끝내실 겁니까?\n 게임을 끝낸다: 1\n 메뉴로 돌아간다: 2\n");
	scanf("%d",&num);
	if(num==2)
	{
		system("pause");
		system("cls");
		menu();
	}
	else
	{
		
	}
}
