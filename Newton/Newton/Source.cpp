#include <iostream>
#include <math.h>
using namespace std;

float f(float x)
{
    return x * x - 2;
}

float fderivat(float x)
{
    return 2*x;
}

int main()
{
    float x0, x1, dif, eps;
    int itmax;
    int it = 0;

    cout << "Introduceti erorea de precizie(epsilon): ";
    cin >> eps;


    cout << "Introduceti numarul de iteratii in care vreti sa aflati solutia aproximata: ";
    cin >> itmax;

    cout << "Introduceti aproximatia initiala a solutiei exacte: ";
    cin >> x0;

    do
    {
        x1 = x0 - f(x0) / fderivat(x0);
        dif = fabs(x1 - x0);
        x0 = x1;
        it++;
        cout << "Iteratia " << it << " are conditia de oprire " << dif << " cu x" << it << " = " << x0 << endl;
    } while (dif > eps && it <= itmax);

    if (it > itmax)
    {
        cout << "\nNu se poate obtine solutia in " << itmax << " iteratii cu precizia " << eps << endl;
        return 0;
    }
    cout << endl << "Pentru ecuatia x * x - 2 cu functia derivata 2*x pornind cu x0 = " << x0 << " s-a obtinut solutia " << x1 << " in " << it << " iteratii, cu eroarea " << eps;

}
