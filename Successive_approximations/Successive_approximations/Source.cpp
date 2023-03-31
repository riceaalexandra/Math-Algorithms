#include <iostream>
#include <math.h>
using namespace std;

float g(float x)
{

    return sqrt(10 - x * x * x) / 2;
}

int main()
{
    float x0, x1, dif, eps = 0.0001;
    int itmax;
    int it = 0;

    cout << "Introduceti numarul de iteratii in care vreti sa aflati solutia aproximata: ";
    cin >> itmax;

    cout << "Introduceti aproximatia initiala a solutiei exacte: ";
    cin >> x0;

    do
    {
        x1 = g(x0);
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
    cout << endl << "Pentru ecuatia x*x*x + 4*x*x - 10 = 0 cu functia contractie  sqrt(10-x*x*x) / 2 pornind cu x0 = " << x0 << " s-a obtinut solutia " << x1 << " in " << it << " iteratii, cu eroarea " << eps;

}
