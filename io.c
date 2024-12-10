/*
* raw(?) I/O
*/
#include "io.h"

// ��ġ�� Ŀ�� �̵�
void gotoxy(POSITION pos) { 
	printf("\033[%d;%dH", pos.row, pos.column);
	COORD coord = { pos.column, pos.row }; // ��, �� �ݴ�� ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// �� ���� �Լ�
void set_color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ȭ�鿡 ���ڸ� ���
void printc(POSITION pos, char ch, int color) {
	if (color >= 0) {
		set_color(color);
	}
	gotoxy(pos); // Ŀ�� �̵�
	printf("%c", ch);
}

KEY get_key(void) {
	if (_kbhit()) {  // �Էµ� Ű�� �ִ��� Ȯ��
		
	}

	int byte = _getch();    // �Էµ� Ű�� ���� �ޱ�
	switch (byte) {
	case 'q': return k_quit;  // 'q'�� ������ ����
	case 224:
		byte = _getch();  // MSB 224�� �Է� �Ǹ� 1����Ʈ �� ���� �ޱ�
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
	



