//класс квадратных матриц 2 на 2
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
using namespace std;

  

class Matrix2d {
private:
	const int N = 2, M = 2;
	float **arr;
public:
	Matrix2d();//конструктор без параметров
	Matrix2d(int N, int M);//конструктор с параметрами
	Matrix2d(const Matrix2d& mtrx);//конструктор копирования
	~Matrix2d();//деструктор
	void initRandMatrix();//инициализация рандомными числами
	void initMatrix(float a, float b, float c, float d);//инициализация заданными числами
	friend ostream& operator<<(ostream& out, const Matrix2d& mtrx);//оператор вывода
	friend istream& operator>>(istream& in, Matrix2d& mtrx);//оператиор ввода
	const Matrix2d operator=(const Matrix2d& mtrx); //оператор присваивания
	Matrix2d operator+(float number);//сложение с числом
	Matrix2d operator+(Matrix2d& mtrx);//сложение с матрицей
	Matrix2d operator+=(float number);//сложение с числом с присваиванием
	Matrix2d operator+=(Matrix2d& mtrx);//сложение с матрицей с присваиванием
	Matrix2d operator-(float number);//вычитание числа
	Matrix2d operator-(Matrix2d& mtrx);//вычитание матрицы
	Matrix2d operator-=(float number);//вычитание числа с присваиванием
	Matrix2d operator-=(Matrix2d& mtrx);//вычитание матрицы с присваиванием
	Matrix2d operator*(float number);//умножение на число
	Matrix2d operator*(Matrix2d& mtrx);//умножение на матрицу
	Matrix2d operator*=(float number);//умножение на число с присваиванием
	Matrix2d operator*=(Matrix2d& mtrx);//умножение на матрицу  с присваиванием
	float getValueAt(int row, int col);//получение значения элемента матрицы
	bool operator==(Matrix2d& mtrx);//сравнение матриц
	float countDeterminant();//подсчет определителя
};

//-----------------------------------------------------------

int main() {
	srand(time(0));
	Matrix2d a;
	a.initRandMatrix();
	cout << a <<"\n";
	cout << a.countDeterminant() << "\n\n";
	Matrix2d* p = new (nothrow) Matrix2d[5];
	(*p).initMatrix(100,1.4,3,-9.7);
	(*(p + 1)).initMatrix(10, 10, 10,10);
	cout << (*p) << "\n";
	cout << (*(p + 1)) << "\n";
	Matrix2d b;
	Matrix2d c;
	c = a + 2;
	cout << c<< "\n";
	b = a - c;
	cout << b << "\n";
	a += b;
	cout << a << "\n" << b << "\n";
	a *= b;
	cout << a << "\n";
	cout << c.getValueAt(1, 1) << "\n";
	a = b;
	cout << (a == b) << "\n";
	cout << (c == b) << "\n";
	
	delete[] p;

}

//-----------------------------------------------------------

Matrix2d::Matrix2d() {
	arr = new (nothrow) float* [N];
	if (!arr) exit(404);
	for (int i = 0; i < N; i++) {
		arr[i] = new (nothrow) float[M];
		if (!arr[i]) exit(404);
	}
}

Matrix2d::Matrix2d(int N, int M) {
	arr = new (nothrow) float* [N];
	if (!arr) exit(404);
	for (int i = 0; i < N; i++) {
		arr[i] = new (nothrow) float[M];
		if (!arr[i]) exit(404);
	}
}
Matrix2d::Matrix2d(const Matrix2d& mtrx) {
	arr = new (nothrow) float* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new (nothrow) float[M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			arr[i][j] = mtrx.arr[i][j];
	}
}


Matrix2d::~Matrix2d() {
	for (int i = 0; i < N; ++i) {
		delete[] this->arr[i];
	}
	delete[] this->arr;
}

 ostream& operator<<(ostream& out, const Matrix2d& mtrx) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j)
			out << mtrx.arr[i][j] << " ";
		out << "\n";
	}
	return out;
};

 istream& operator>>(istream& in, Matrix2d& mtrx) {
	 for (int i = 0; i < 2; ++i) {
		 for (int j = 0; j < 2; ++j) {
			 cout << "Enter element of " << i+1 << " row and " << j+1 << " col: ";
			 in >> mtrx.arr[i][j];
			 cout << "\n";
		 }
	 }
	 return in;
 };


void Matrix2d::initRandMatrix()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			arr[i][j] = (float)(rand() % 2001) / 100 - 10;
		}
	}
}


void Matrix2d::initMatrix(float a, float b, float c, float d)
{
	this->arr[0][0] = a;
	this->arr[0][1] = b;
	this->arr[1][0] = c;
	this->arr[1][1] = d;
}

  const Matrix2d Matrix2d::operator=(const Matrix2d& mtrx) {
	  for (int i = 0; i < N; ++i)
		  for (int j = 0; j < M; ++j)
			 this->arr[i][j] = mtrx.arr[i][j];
	  return *this;
  }

  Matrix2d Matrix2d::operator+(float number)
  {
	  Matrix2d res;
	  for (int i = 0; i < N; ++i) {
		  for (int j = 0; j < M; ++j) {
			  res.arr[i][j]=this->arr[i][j] + number;
		  }
	  }
	  return res;
  }

  Matrix2d Matrix2d::operator+(Matrix2d& mtrx) {
	  Matrix2d res;
	  for (int i = 0; i < N; ++i) {
		  for (int j = 0; j < M; ++j) {
			res.arr[i][j] = this->arr[i][j] + mtrx.arr[i][j];
		  }
	  }
	  return res;
  }

  Matrix2d Matrix2d::operator+=(float number)
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			this->arr[i][j] += number;
		}
	}
	return *this;
}

Matrix2d Matrix2d::operator+=(Matrix2d& mtrx) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			this->arr[i][j] += mtrx.arr[i][j];
		}
	}
	return *this;
}


Matrix2d Matrix2d::operator-(float number) {
	Matrix2d res;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			res.arr[i][j]=this->arr[i][j] - number;
		}
	}
	return res;
}

Matrix2d Matrix2d::operator-(Matrix2d& mtrx) {
	Matrix2d res;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			res.arr[i][j]=this->arr[i][j] - mtrx.arr[i][j];
		}
	}
	return res;
}

Matrix2d Matrix2d::operator-=(float number) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			this->arr[i][j] -= number;
		}
	}
	return *this;
}

Matrix2d Matrix2d::operator-=(Matrix2d& mtrx){
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			this->arr[i][j] -= mtrx.arr[i][j];
		}
	}
	return *this;
}

Matrix2d Matrix2d::operator*(float number) {
	Matrix2d res;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			res.arr[i][j]+=this->arr[i][j] * number;
		}
	}
	return res;
}

Matrix2d Matrix2d::operator*(Matrix2d& mtrx) {
	Matrix2d res;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				res.arr[i][j] +=this-> arr[i][k] * mtrx.arr[k][j];
			}
		}
	}
	return res;
}

Matrix2d Matrix2d::operator*=(float number) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			this->arr[i][j] *= number;
		}
	}
	return *this;
}

Matrix2d Matrix2d::operator*=(Matrix2d& mtrx){
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				this->arr[i][j] += arr[i][k] * mtrx.arr[k][j];
			}
		}
	}
	return *this;
}

float Matrix2d::getValueAt(int row, int col) {
	if (row > 2 && col > 2 && col < 1 && row < 1) exit(41);
	return arr[row-1][col-1];
}

bool Matrix2d::operator==(Matrix2d& mtrx) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == mtrx.arr[i][j]) {
				continue;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

float Matrix2d::countDeterminant() {
	float det = 0;
	det = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	return det;
}