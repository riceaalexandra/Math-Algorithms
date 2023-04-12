#include <iostream>
using namespace std; 

void lr(float a[][100], int n, bool* unic) {
    float s, piv, aux;
    *unic = false;
    if (a[0][0] == 0)
    {
        int i = 0;

        do
        {
            i = i + 1;
        } while (a[i][0] == 0 && i <= n - 1);

        if (i >= n)
        {
            cout << "Sistemul nu are solutie unica"<<endl;
            cout << "Incercati sa introduceti alte valori pentru y(0)" << endl;
            *unic = true;

        }

        for (int j = 0; j <= n; j++)
        {
            aux = a[0][j];
            a[0][j] = a[i][j];
            a[i][j] = aux;
        }
    }

    for (int i = 1; i <= n - 1; i++)
    {
        a[i][0] = a[i][0] / a[0][0];
    }

    for (int k = 1; k <= n - 1; k++)
    {
        int i = k;

        do
        {
            s = 0;
            piv = 0;

            for (int h = 0; h <= k - 1; h++)
            {
                s = s + a[i][h] * a[h][k];
            }

            piv = a[i][k] - s;
            i = i + 1;
        } while (piv == 0 && i <= n - 1);

        if (piv == 0)
        {
            cout << "Sistemul nu are solutie unica"<<endl;
            cout << "Incercati sa introduceti alte valori pentru y(0)" << endl;
            *unic = true;
        }

        if (i != k + 1)
        {
            for (int j = 0; j <= n; j++)
            {
                aux = a[k][j];
                a[k][j] = a[i - 1][j];
                a[i - 1][j] = aux;
            }


        }

        for (int j = k; j <= n - 1; j++)
        {
            s = 0;

            for (int h = 0; h <= k - 1; h++)
            {
                s = s + a[k][h] * a[h][j];
            }

            a[k][j] = a[k][j] - s;
        }


        for (int i = k + 1; i <= n - 1; i++)
        {
            s = 0;

            for (int h = 0; h <= k - 1; h++)
            {
                s = s + a[i][h] * a[h][k];
            }

            a[i][k] = (a[i][k] - s) / a[k][k];
        }

    }

    for (int i = 1; i <= n - 1; i++)
    {
        s = 0;
        for (int k = 0; k <= i - 1; k++)
        {
            s = s + a[i][k] * a[k][n];
        }
        a[i][n] = a[i][n] - s;
    }


    a[n - 1][n] = a[n - 1][n] / a[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        s = 0;
        for (int j = n - 1; j >= i + 1; j--)
        {
            s = s + a[i][j] * a[j][n];
        }

        a[i][n] = (a[i][n] - s) / a[i][i];
    }
    if (*unic == false) {
        for (int i = 0; i < n; i++)
        {
            cout << "c" << i << " = " << a[i][n] << endl;
        }
    }
}