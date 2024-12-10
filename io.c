/*
* raw(?) I/O
*/
#include "io.h"

// 위치로 커서 이동
void gotoxy(POSITION pos) { 
	printf("\033[%d;%dH", pos.row, pos.column);
	COORD coord = { pos.column, pos.row }; // 행, 열 반대로 전달
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 색 설정 함수
void set_color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 화면에 문자를 출력
void printc(POSITION pos, char ch, int color) {
	if (color >= 0) {
		set_color(color);
	}
	gotoxy(pos); // 커서 이동
	printf("%c", ch);
}

KEY get_key(void) {
	if (_kbhit()) {  // 입력된 키가 있는지 확인
		
	}

	int byte = _getch();    // 입력된 키를 전달 받기
	switch (byte) {
	case 'q': return k_quit;  // 'q'를 누르면 종료
	case 224:
		byte = _getch();  // MSB 224가 입력 되면 1바이트 더 전달 받기
		switch (byte) {
		case 72: return k_up;
		case 75: return k_left;
		case 77: return k_right;
		case 80: return k_down;
		default: return k_undef;
		}
	default: return k_undef;
	}
}
	



