#include <iostream>
#include <fstream>   
using namespace std;

struct ColorLeft { unsigned char b; unsigned char g; unsigned char r; } cl;
struct ColorRight { unsigned char r; unsigned char g; unsigned char b; } cr;


int main() {
	char tmp[255];
	int width, height;
	int oldR, oldG, oldB, newR, newG, newB;
	int steps = 128;
	float rstep, gstep, bstep, widthSteps, tmpWidthSteps, heightSteps, tmpHeightSteps;
	int menu;

	ifstream fffff("d:\\1.bmp", ios::binary);
	ofstream ggggg("d:\\rez.bmp", ios::binary);
	if (!fffff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggggg) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	fffff.read((char*)&tmp, 18); 
	ggggg.write((char*)&tmp, 18);
	fffff.read((char*)&width, 4); cout << "we know the width: " << width;
	fffff.read((char*)&height, 4); cout << "\nwe know the height: " << height;

	width = 256; height = 256;
	ggggg.write((char*)&width, 4);
	ggggg.write((char*)&height, 4);

	fffff.read((char*)&tmp, 28);
	ggggg.write((char*)&tmp, 28);
	
	again1:
	cout << "\n\nEnter RGB of the first colour: \n";
	cin >> oldR >> oldG >> oldB;
	if (oldR > 255 || oldG > 255 || oldB > 255 || oldR < 0 || oldG < 0 || oldB < 0) { cout << "Try number from 0 to 255\n"; goto again1; }
	again2:
	cout << "\nEnter RGB of the second colour: \n";
	cin >> newR >> newG >> newB;
	if (newR > 255 || newG > 255 || newB > 255 || newR < 0 || newG < 0 || newB < 0) { cout << "Try number from 0 to 255\n"; goto again2; }

	rstep = (newR - oldR) / steps;
	gstep = (newG - oldG) / steps;
	bstep = (newB - oldB) / steps;
	widthSteps = width / steps;
	tmpWidthSteps = widthSteps;
	heightSteps = height / steps;
	tmpHeightSteps=heightSteps;

	int tmpR=oldR, tmpG=oldG, tmpB=oldB;

	again3:
	cout << "\n\nWhat gradient do you want?\n 1-horizontal left->right\n 2-horizontal right->left\n 3-vertical down->up\n 4-vertical up->down\n";
	cin >> menu;
	if (menu != 1 && menu != 2 && menu != 3 && menu!=4) { cout << "\nTry again but 1/2/3/4\n"; goto again3; }
	switch (menu) {

		//слева направо
	case (1):
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {

				if (j == widthSteps) {
					widthSteps += tmpWidthSteps;
					tmpR += rstep;
					tmpG += gstep;
					tmpB += bstep;
				}
				cl.r = tmpR;
				cl.g = tmpG;
				cl.b = tmpB;
				ggggg.write((char*)&cl, sizeof(cl));
			}
			tmpR = oldR;
			tmpG = oldG;
			tmpB = oldB;
			widthSteps = tmpWidthSteps;
		}
		break;

		//справа налево
	case(2):
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {

				if (j == widthSteps) {
					widthSteps += tmpWidthSteps;
					tmpR += rstep;
					tmpG += gstep;
					tmpB += bstep;
				}
				cr.r = tmpR;
				cr.g = tmpG;
				cr.b = tmpB;
				ggggg.write((char*)&cr, sizeof(cr));
			}
			tmpR = oldR;
			tmpG = oldG;
			tmpB = oldB;
			widthSteps = tmpWidthSteps;
		}
		break;

		
		//вертикально снизу вверх
	case 3:
		for (int i = 1; i <= height; ++i) {
			for (int j = 1; j <= width; ++j) {
				ggggg.write((char*)&cl, sizeof(cl));
			}
			if (i == heightSteps) {
				tmpR += rstep;
				tmpG += gstep;
				tmpB += bstep;
				heightSteps += tmpHeightSteps;
			}
			cl.r = tmpR;
			cl.g = tmpG;
			cl.b = tmpB;
		}
		break;

		//вертикально сверху вниз
	case 4:
		tmpR = newR;
		tmpG = newG;
		tmpB = newB;
		for (int i = 1; i <= height; ++i) {
			for (int j = 1; j <= width; ++j) {
				ggggg.write((char*)&cl, sizeof(cl));
			}
			if (i==heightSteps) {
				tmpR -= rstep;
				tmpG -= gstep;
				tmpB -= bstep;
				heightSteps += tmpHeightSteps;
			}
			cl.r = tmpR;
			cl.g = tmpG;
			cl.b = tmpB;
		}
		break;
		}
	}

	fffff.close();//закрыли файл
	ggggg.close();//закрыли файл

	return 0;
}