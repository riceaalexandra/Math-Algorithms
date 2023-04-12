#include <iostream>
#include "gauss.h"
#include "krylov.h"
#include "lr.h"
#define MAX 100

void krylov() {
	float a[MAX][MAX], y[MAX][MAX];
	int n;
	bool unic = false;
	std::cout << "Introduceti gradul matrciei: ";
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "a[" << i << "]" << "[" << j << "] = ";
			std::cin >> a[i][j];
		}
	}
	do //introduc y(0) pana cand gasecs unul care sa aiba solutie unica si sa indeplineasca conditia
	{
		for (int i = 0; i < n; i++) {
			std::cout << "y[" << i << "][" << n - 1 << "] = ";
			std::cin >> y[i][n - 1];
		}
		for (int j = n - 2; j >= 0; j--)
		{
			for (int i = 0; i < n; i++)
			{
				y[i][j] = 0;
				for (int k = 0; k < n; k++)
				{
					y[i][j] = y[i][j] + a[i][k] * y[k][j + 1];
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			y[i][n] = 0;
			for (int k = 0; k < n; k++)
			{
				y[i][n] = y[i][n] + a[i][k] * y[k][0];
			}
			y[i][n] = -y[i][n];
		}
		std::cout << "Matricea extinsa y este: " << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				std::cout << y[i][j] << "   ";
			}
			std::cout << std::endl;
		}
		lr(y, n, &unic);
	} while (unic == true);

}