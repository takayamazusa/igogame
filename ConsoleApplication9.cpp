// ConsoleApplication9.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "stdio.h"
int a, b;
int win;

int igo[3][3] = { { 0,0,0 },
{ 0, 0, 0},
{ 0, 0, 0} };

/*先攻の置く場所を選ぶ*/
void player1() {

	printf("縦を選んでください\n");
	scanf_s("%d", &a);
	printf("横を選んでください\n");
	scanf_s("%d", &b);

	igo[a][b] = 1;
	//return a, b;
	
}

/*後攻の置く場所を選ぶ*/
void player2() {
	
	printf("縦を選んでください\n");
	scanf_s("%d", &a);
	printf("横を選んでください\n");
	scanf_s("%d", &b);

	igo[a][b] = 2;
	//return a, b;
}

/*勝敗判定をする*/
int judge() {
	/*たて*/

	int win = 0;

	if (igo[0][0] == igo[0][1] == igo[0][2]) {
		win = 1;
	}
	else if (igo[1][0] == igo[1][1] == igo[1][2]) {
		win = 1;
	}
	else if (igo[2][0] == igo[2][1] == igo[2][2]) {
		win = 1;
	}

	/*よこ*/
	else if (igo[0][0] == igo[1][0] == igo[2][0]) {
		win = 1;
	}
	else if (igo[0][1] == igo[1][1] == igo[2][1]) {
		win = 1;
	}
	else if (igo[0][2] == igo[1][2] == igo[2][2]) {
		win = 1;
	}

	/*ななめ*/
	else if (igo[0][0] == igo[1][1] == igo[2][2]) {
		win = 1;
	}
	else if (igo[2][0] == igo[1][1] == igo[0][2]) {
		win = 1;
	}

	return win;
}

/*碁盤の状況を出力*/
int output() {
	for (a = 0; a < 3; a++) {
		for (b = 0; b < 3; b++) {
			printf("%d", igo[a][b]);
		}
		printf("\n");
	}
	return igo[a][b];
}



int main()
{
	int i = 1; //今何回目かカウントする変数

	output(); //一番最初の状態を出力

	for (i = 1; i <= 9; i++) {
		int count = i % 2;

		/*先攻*/
		if (count = 1) {
			printf("%d回目\n", i);
			player1();
			output();
			
			/*勝敗判定：最短5回目で勝てるため(i >= 5)*/
			if (i >= 5) {
				judge();
				if (win == 1) {
					printf("player 1の勝ち");
					break;
				}
			}
		}

		/*後攻*/
		else {
			printf("%d回目\n", i);
			player2();
			output();

			/*勝敗判定：最短6回目で勝てるため(i >= 6)*/
			if (i >= 6) {
				judge();
				if (win == 1) {
					printf("player 2の勝ち");
					break;
				}
			}
		}
	}
	
    return 0;
}

