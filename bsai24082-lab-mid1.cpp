#include<iostream>
using namespace std;

void hehe(char ch) {

	int up, lw, digit, sc, ff=0;
	up = 0; lw = 0; digit = 0; sc = 0;

	int i = 0;
	while (ch != '.') {
		if (ch >= 'A' and ch <= 'Z')
			up++;
		else if (ch >= 'a' and ch <= 'z')
			lw++;
		 else if (ch >= '0' and ch <= '9')
			digit++;
		else
			sc++;

		i++;
		cin >> ch;
	}

	if (i >= 8)
		ff++;
	if (up >= 1)
		ff++;
	if (lw >= 1)
		ff++;
	if (sc >= 1)
		ff++;
	if (digit >= 1)
		ff++;


	switch (ff) {

	case 5:
		cout << "Strong" << endl;
		break;
	case 4:
	case 3:
		cout << "Mediem" << endl;
		break;

	case 2:
	case 1:
	case 0:
		cout << "weak" << endl;

	}

}
int main () {

	char ch;
	cout << "Enter your Password" << endl;
	cin >> ch;

	hehe(ch);

	return 0;
}
