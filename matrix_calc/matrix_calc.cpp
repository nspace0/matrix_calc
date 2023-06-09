﻿#include <iostream>
#include "conio.h"
using namespace std;
int action, m0, n0, m1, n1;

int matrixA[3][3] = {
					1,4,7,
					6,9,10,
					2,3,5
};
int matrixB[3][3] = {
					5,3,2,
					10,9,6,
					7,4,1
};
int matrixC[3][3];

void print(int matrixC[3][3]) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << "\t" << matrixC[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void sumMatrix(int matrixA[3][3], int matrixB[3][3]) {

	cout << "Сложение матриц: \n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j]; // сложение матрицы А и В
		}
	}

}
void subtraction(int matrixA[3][3], int matrixB[3][3]) {
	cout << "Вычитание матриц : \n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrixC[i][j] = matrixA[i][j] - matrixB[i][j]; // вычитание
		}
	}
}
void multiplication(int matrixA[3][3], int matrixB[3][3]) {
	cout << "Умножение матриц: \n";

	//умножение строк на столбцы
	matrixC[0][0] = matrixA[0][0] * matrixB[0][0] + matrixA[0][1] * matrixB[1][0] + matrixA[0][2] * matrixB[2][0];
	matrixC[0][1] = matrixA[0][0] * matrixB[0][1] + matrixA[0][1] * matrixB[1][1] + matrixA[0][2] * matrixB[2][1];
	matrixC[0][2] = matrixA[0][0] * matrixB[0][2] + matrixA[0][1] * matrixB[1][2] + matrixA[0][2] * matrixB[2][2];

	matrixC[1][0] = matrixA[1][0] * matrixB[0][0] + matrixA[1][1] * matrixB[1][0] + matrixA[1][2] * matrixB[2][0];
	matrixC[1][1] = matrixA[1][0] * matrixB[0][1] + matrixA[1][1] * matrixB[1][1] + matrixA[1][2] * matrixB[2][1];
	matrixC[1][2] = matrixA[1][0] * matrixB[0][2] + matrixA[1][1] * matrixB[1][2] + matrixA[1][2] * matrixB[2][2];

	matrixC[2][0] = matrixA[2][0] * matrixB[0][0] + matrixA[2][1] * matrixB[1][0] + matrixA[2][2] * matrixB[2][0];
	matrixC[2][1] = matrixA[2][0] * matrixB[0][1] + matrixA[2][1] * matrixB[1][1] + matrixA[2][2] * matrixB[2][1];
	matrixC[2][2] = matrixA[2][0] * matrixB[0][2] + matrixA[2][1] * matrixB[1][2] + matrixA[2][2] * matrixB[2][2];

}
void scalarMultiplication(int matrixA[3][3]) {
	int num;
	cout << "Введите число: ";
	cin >> num;
	cout << "Умножение матрицы на число " << num << " : \n";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrixC[i][j] = matrixA[i][j] * num;
		}
	}
}
void transposeMatrix(int matrixA[3][3]) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixC[j][i] = matrixA[i][j];
		}
	}
}
bool isIdentityMatrix(int matrixA[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i = j) {
				if (matrixA[i][j] != 1) {
					return false;
				}
			}
			else {
				if (matrixA[i][j] != 0) {
					return false;
				}
			}
		}
	}
	return true;
}
bool isDiagonalMatrix(int matrixA[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				continue;
			}
			else {
				if (matrixA[i][j] != 0)
				{
					return false;
				}
			}
		}
	}
	return true;
}
bool isSymmetric(int matrixA[3][3]) {
	transposeMatrix(matrixA);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (matrixC[i][j] != matrixA[i][j]) {
				return false;
			}
		}
	}
	return true;
}



char menu() {

	cout << "******************************************" << endl;
	cout << "*            MATRIX CALCULATOR           *" << endl;
	cout << "******************************************" << endl << endl;
	cout << "1. Сложение матриц. \n";
	cout << "2. Вычитание матриц. \n";
	cout << "3. Умножение матриц. \n";
	cout << "4. Умножение матрицы на число. \n";
	cout << "5. Транспонирование матриц. \n";
	cout << "6. Свойства матрицы. \n";
	cout << "0. Exit.\n";

	cin >> action;

	return action;
}



int main()
{
	setlocale(LC_ALL, "ru");
	char action;
	action = menu();
	switch (action)
	{
	case 1:
		sumMatrix(matrixA, matrixB);
		print(matrixC);
		break;

	case 2:
		subtraction(matrixA, matrixB);
		print(matrixC);
		break;

	case 3:
		multiplication(matrixA, matrixB);
		print(matrixC);
		break;

	case 4:
		scalarMultiplication(matrixA); // умножение матрицы на число
		print(matrixC);
		break;

	case 5:
		transposeMatrix(matrixA);
		cout << " Transpose Matrix \n";
		print(matrixC);
		break;

	case 6:
		if (isIdentityMatrix(matrixA)) {
			cout << " Identity matrix \n";
		}
		else
		{
			cout << " Not identity matrix \n";
		}

		if (isDiagonalMatrix(matrixA)) {
			cout << " Diagonal Matrix \n";
		}
		else {
			cout << " Not diagonal matrix \n";
		}

		if (isSymmetric(matrixA)) {
			cout << " Symmetric matrix \n";
		}
		else {
			cout << " Not symmetric matrix " << endl;
		}
		break;

	default:
		cout << "Пон\n";
		break;
	}
	cout << "Press Any key to continue...";
	_getch();




	return 0;
}

