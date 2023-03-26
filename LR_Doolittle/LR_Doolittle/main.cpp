#include<iostream>
using namespace std;

int main()
{
	int n, i, j, k, h;
	float a[10][10], s, piv, aux, l[10][10], r[10][10];
	cout << "n=  ";
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n + 1; j++)
		{
			cout << "a" << "[" << i << "]""[" << j << "]= ";
			cin >> a[i][j];
		}
	cout << endl;
	if (a[1][1] == 0)
	{
		i = 1;
		do
		{
			i++;
		} while (!(a[i][1] != 0 || i > n));
		if (i > n)
			cout << "Sistemul nu are solutie unica";
		else
			for (j = 1; j <= n + 1; j++)
			{
				aux = a[1][j];
				a[1][j] = a[i][j];
				a[i][j] = aux;
			}
	}
	for (i = 2; i <= n; i++)
	{
		a[i][1] = a[i][1] / a[1][1];
	}
	for (int k = 2; k <= n; k++)
	{
		i = k;
		do
		{
			s = 0;
			piv = 0;
			for (h = 1; h <= k - 1; h++)
				s = s + (a[i][h] * a[h][k]);
			piv = a[i][k] - s;
			i++;
		} while (!(piv != 0 || i > n));
		if (piv == 0)
			cout << "Sistemul nu are solutie unica";
		else
			if (i != k + 1)
			{
				for (j = 1; j <= n + 1; j++)
				{
					aux = a[k][j];
					a[k][j] = a[i - 1][j];
					a[i - 1][j] = aux;
				}
			}
		for (j = k; j <= n; j++)
		{
			s = 0;
			for (h = 1; h <= k - 1; h++)
				s = s + a[k][h] * a[h][j];
			a[k][j] = a[k][j] - s;
		}
		for (i = k + 1; i <= n; i++)
		{
			s = 0;
			for (h = 1; h <= k - 1; h++)
				s = s + a[i][h] * a[h][k];
			a[i][k] = (a[i][k] - s) / a[k][k];
		}
	}
	for (i = 2; i <= n; i++)
	{
		s = 0;
		for (k = 1; k <= i - 1; k++)
			s = s + a[i][k] * a[k][n + 1];
		a[i][n + 1] = a[i][n + 1] - s;
	}
	a[n][n + 1] = a[n][n + 1] / a[n][n];
	for (i = n - 1; i >= 1; i--)
	{
		s = 0;
		for (j = i + 1; j <= n; j++)
			s = s + a[i][j] * a[j][n + 1];
		a[i][n + 1] = (a[i][n + 1] - s) / a[i][i];
	}
	cout << endl;
	cout << "L= " << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{

			if (i == j)
				l[i][j] = 1;
			else if (i < j)
				l[i][j] = 0;
			else l[i][j] = a[i][j];
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			cout << l[i][j] << " ";
		cout << endl;
	}
	cout << "R =  " << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{

			if (i > j)
				r[i][j] = 0;
			else r[i][j] = a[i][j];
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			cout << r[i][j] << " ";
		cout << endl;
	}
	int d_l = 1, d_r = 1, d_a;
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (i == j)
				d_l = d_l * l[i][j];
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (i == j)
				d_r = d_r * r[i][j];
		}
	}
	d_a = d_l * d_r;
	cout << "Det A= " << d_a;
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "=" << a[i][n + 1] << endl;
	}
	return 0;
}

