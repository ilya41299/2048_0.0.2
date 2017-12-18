#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

void input_mas(unsigned int  mas[4][4]) {

	for (int k = 0; k < 3;) {
		unsigned int i = rand() % 4;
		unsigned int j = rand() % 4;
		unsigned int r = rand() % 11;
		if (mas[i][j] == 0) {
			if (r < 10) {
				mas[i][j] = 2;
				k++;
			}
			else
			mas[i][j] = 4;
			k++;
		}
	}
}
void dobavlenie_chisla(unsigned int  mas[4][4]) {
	int k = 0;
	while (k != 1) {
		unsigned int i = rand() % 4;
		unsigned int j = rand() % 4;
		unsigned int r = rand() % 11;
		if (mas[i][j] == 0) {
			if (r < 10) {
				mas[i][j] = 2;
				k = 1;
			}
			else
				mas[i][j] = 4;
			k = 1;
		}
	}
}
void output_mas(unsigned int mas[4][4], unsigned int score) {
	cout << endl;
	for (unsigned int i = 0; i<4; ++i) {
		for (unsigned int j = 0; j<4; ++j) {
			if (mas[i][j] == 0) {
				cout << '*' << ' ';
			}
			else {
				cout << mas[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "Score: " << score << endl;
}

bool sdvig_vniz(unsigned int mas[4][4], unsigned int &score) {
	unsigned int sdvig=0;
	for (unsigned int j = 0; j < 4; j++) {
		for (unsigned int i = 3; i > 0; i--) {
			if (mas[i][j] == 0) {
				for (int k = i - 1; k >= 0; k--) {
					if (mas[k][j] != 0) {
						mas[i][j] = mas[k][j];
						mas[k][j] = 0;
						sdvig++;
						break;
					}
				}
			}
		}
	}
	for (unsigned int j = 0; j < 4; j++) {
		for (unsigned int i = 3; i > 0; i--) {
			if (mas[i][j] == mas[i - 1][j] && mas[i][j]!=0) {
				score += mas[i][j];
				mas[i][j] *= 2;
				mas[i - 1][j] = 0;
				sdvig++;
			}
		}
	}
	if (sdvig == 0) {
		return false;
	}
	for (unsigned int j = 0; j < 4; j++) {
		for (unsigned int i = 3; i > 0; i--) {
			if (mas[i][j] == 0) {
				for (int k = i - 1; k >= 0; k--) {
					if (mas[k][j] != 0) {
						mas[i][j] = mas[k][j];
						mas[k][j] = 0;
						break;
					}
				}
			}
		}
	}
	return true;
}

	


bool sdvig_vverh(unsigned int mas[4][4], unsigned int &score) {
	unsigned int sdvig = 0; 
	for (unsigned int j = 0; j < 4; j++) {
		for (unsigned int i = 0; i < 4; i++) {
			if (mas[i][j] == 0) {
				for (int k = i + 1; k < 4; k++) {
					if (mas[k][j] != 0) {
						mas[i][j] = mas[k][j];
						mas[k][j] = 0;
						sdvig++;
						break;
					}
				}
			}
		}
	}
	for (unsigned int j = 0; j<4; j++) {
		for (unsigned int i = 0; i<4; i++) {
			if (mas[i][j] == mas[i + 1][j] && mas[i][j] != 0) {
				score += mas[i][j];
				mas[i][j] *= 2;
				mas[i + 1][j] = 0;
				sdvig++;
			}
		}
	}
	if (sdvig == 0) {
		return false;
	}
	for (unsigned int j = 0; j<4; j++) {
		for (unsigned int i = 0; i < 4; i++) {
			if (mas[i][j] == 0) {
				for (int k = i + 1; k < 4; k++) {
					if (mas[k][j] != 0) {
						mas[i][j] = mas[k][j];
						mas[k][j] = 0;
						break;
					}
				}
			}
		}
	}
	return true;
}

bool sdvig_vlevo(unsigned int mas[4][4], unsigned int &score) {
	unsigned int sdvig = 0;
	for (unsigned int i = 0; i < 4; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			if (mas[i][j] == 0) {
				for (int k = j + 1; k <= 3; k++) {
					if (mas[i][k] != 0) {
						mas[i][j] = mas[i][k];
						mas[i][k] = 0;
						sdvig++;
						break;
					}
				}
			}
		}
	}

	for (unsigned int i = 0; i<4; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			if (mas[i][j] == mas[i][j + 1] && mas[i][j] != 0) {
				score += mas[i][j];
				mas[i][j] *= 2;
				mas[i][j + 1] = 0;
				sdvig++;
			}
		}
	}
	if (sdvig == 0) {
		return false;
	}
	for (unsigned int i = 0; i < 4; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			if (mas[i][j] == 0) {
				for (int k = j + 1; k <= 3; k++) {
					if (mas[i][k] != 0) {
						mas[i][j] = mas[i][k];
						mas[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

bool sdvig_vpravo(unsigned int mas[4][4], unsigned int &score) {
	unsigned int sdvig = 0;
	for (unsigned int i = 0; i < 4; i++) {
		for (unsigned int j = 3; j > 0; j--) {
			if (mas[i][j] == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (mas[i][k] != 0) {
						mas[i][j] = mas[i][k];
						mas[i][k] = 0;
						sdvig++;
						break;
					}
				}
			}
		}
	}

	for (unsigned int i = 0; i < 4; i++) {
		for (unsigned int j = 3; j > 0; j--) {
			if (mas[i][j] == mas[i][j - 1] && mas[i][j] != 0) {
				score += mas[i][j];
				mas[i][j] *= 2;
				mas[i][j - 1] = 0;
				sdvig++;
			}
		}
	}
	if (sdvig == 0) {
		return false;
	}
	for (unsigned int i = 0; i < 4; i++) {
		for (unsigned int j = 3; j > 0; j--) {
			if (mas[i][j] == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (mas[i][k] != 0) {
						mas[i][j] = mas[i][k];
						mas[i][k] = 0;
						break;
					}
				}
			}
		}
	}
	return true;
}
bool the_eng_game(unsigned mas[4][4]) {

}
int main()
{
	srand(time(NULL));
	unsigned int mas[4][4] = {  {0, 0, 0, 0},
								{0, 0, 0, 0},
								{0, 0, 0, 0}, 
								{0, 0, 0, 0}};
	int exit=0;
	unsigned int score = 0;
	input_mas(mas);
	output_mas(mas, score);
	char op;
	unsigned int ;
	while (cin >> op) {
		switch (op) {
		case 'j': {
			if (sdvig_vniz(mas, score)) {
				dobavlenie_chisla(mas);
				output_mas(mas, score);
			}
			else {
				cout << endl;
				cout << "Make another move" << endl;
			}
			break;
		}
		case 'k': {
			if (sdvig_vverh(mas, score)) {
				dobavlenie_chisla(mas);
				output_mas(mas, score);
			}
			else {
				cout << endl;
				cout << "Make another move" << endl;
			}
			break;
		}
		case 'h': {
			if (sdvig_vlevo(mas, score)) {
				dobavlenie_chisla(mas);
				output_mas(mas, score);
			}
			else {
				cout << endl;
				cout << "Make another move" << endl;
			}
			break;
		}
		case 'l': {
			if (sdvig_vpravo(mas, score)) {
				dobavlenie_chisla(mas);
				output_mas(mas, score);
			}
			else {
				cout << endl;
				cout << "Make another move" << endl;
			}
			break;
		}
		case 'q': {
			exit = 1;
			break;
		}
		default: {
			cout << " Error move" << endl; 
			break;
		}
		}
		if (exit == 1) {
			break;
		}
	}
	if (exit == 1) {
		cout << endl;
		cout << "Game over" << endl;
		cout << "Your score: " << score << endl;
		return -1;
	}
return 0;
}

