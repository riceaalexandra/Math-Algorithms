#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n, i, j, k, piv, lin;
	float a[10][10];
	cout << "Introduceti numarul de necunoscute: ";
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n + 1; j++)
		{
			cout << "a" << "[" << i << "]""[" << j << "]= ";
			cin >> a[i][j];
		}
	}
	cout << "Matricea este: \n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n + 1; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (k = 1; k <= n - 1; k++)
	{
		piv = fabs(a[k][k]);
		lin = k;
		for (i = k + 1; i <= n; i++)
		{
			if (piv < fabs(a[i][k]))
			{
				piv = fabs(a[i][k]);
				lin = i;
			}
		}
		if (piv == 0)
		{
			cout << "sistemul nu are solutie unica";
			return 0;
		}
		if (lin != k)
		{
			for (j = k; j <= n + 1; j++)
			{
				float aux;
				aux = a[k][j];
				a[k][j] = a[lin][j];
				a[lin][j] = aux;
			}

		}
		for (i = k + 1; i <= n; i++)
		{
			a[i][k] = a[i][k] / a[k][k];
			for (j = k + 1; j <= n + 1; j++)
			{
				a[i][j] = a[i][j] - a[i][k] * a[k][j];
			}
		}
	}
	if (a[n][n] == 0)
	{
		cout << "sistemul nu are solutie unica";
		return 0;
	}
	a[n][n + 1] = a[n][n + 1] / a[n][n];
	float s;
	for (i = n - 1; i >= 1; i--)
	{
		s = 0;
		for (j = i + 1; j <= n; j++)
		{
			s = s + a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = (a[i][n + 1] - s) / a[i][i];

	}
	cout << "Solutiile sunt: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "=" << a[i][n + 1] << endl;
	}
}


