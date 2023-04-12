#include <iostream>
#include "gauss.h"
void gauss(float a[][100], int n, bool *unic) {
    for (int k = 0; k < n - 1; k++)
    {
        if (a[k][k] != 0)
        {
            for (int i = k + 1; i < n; i++)
            {
                for (int j = k + 1; j < n + 1; j++)
                {
                    a[i][j] = (a[k][k] * a[i][j] - a[i][k] * a[k][j]) / a[k][k];
                }
            }

            for (int coloana_pivot = k + 1; coloana_pivot < n; coloana_pivot++)
            {
                a[coloana_pivot][k] = 0;
            }

        }
        else
        {
            bool gasire_element_nenul = false;
            for (int contor_linie = k; contor_linie < n; contor_linie++)
            {
                int aux;
                if (a[contor_linie][k] != 0)
                {
                    gasire_element_nenul = true;
                    for (int contor_coloana = 0; contor_coloana <= n; contor_coloana++)
                    {
                        std::swap(a[k][contor_coloana], a[contor_linie][contor_coloana]);
                    }
                    break;
                }
            }

            if (gasire_element_nenul == false)
            {
                std::cout << "Sistemul nu are solutie unica" << std::endl;
                std::cout << "introduceti alte valori ale lui y0" << std::endl;
                *unic = false;
            }

            for (int i = k + 1; i < n; i++)
            {
                for (int j = k + 1; j < n + 1; j++)
                {
                    a[i][j] = (a[k][k] * a[i][j] - a[i][k] * a[k][j]) / a[k][k];
                }
            }
            for (int coloana_pivot = k + 1; coloana_pivot < n; coloana_pivot++)
            {
                a[coloana_pivot][k] = 0;
            }

        }
        std::cout << "\nDupa pasul " << k << " matricea este: " << std::endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                std::cout << a[i][j] << "   ";
            }
            std::cout << std::endl;
        }

    }

    if (a[n - 1][n - 1] == 0)
    {
        std::cout << "Sistemul nu are solutie unica" << std::endl;
        std::cout << "introduceti alte valori ale lui y0" << std::endl;
        *unic = false;
    }

    std::cout << "Dupa aplicarea metodei lui Gauss se obtine matricea: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            std::cout << a[i][j] << "   ";
        }
        std::cout << std::endl;
        *unic = true;
    }


    a[n - 1][n] = a[n - 1][n] / a[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        int s = 0;
        for (int j = n - 1; j >= i + 1; j--)
        {
            s = s + a[i][j] * a[j][n];
        }

        a[i][n] = (a[i][n] - s) / a[i][i];
    }

    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "c" << i << " = " << a[i][n] << std::endl;
    }

}