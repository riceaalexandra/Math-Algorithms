#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	int n, m;
	double xi[100], fi[100], N, s, p;
	vector<double> z; //am folosit STL deoarece trebuia sa sterg din vector si este mai usor cu ajutorul vectorilor din STL
	cout << "n = ";
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cout << "x" << i << " = ";
		cin >> xi[i];
	}
	for (int i = 0; i <= n; i++) {
		cout << "f" << i << " = ";
		cin >> fi[i];
	}
	cout << "Introduceti numarul de z-uri: ";
	cin >> m;
	for (int i = 0; i < m; i++) {
		double x;
		cout << "z" << i + 1 << " = ";
		cin >> x;
		z.push_back(x);
	}
	//Observatia1: verificare daca toate z-urile sunt in intervalul [x0, xn], Observatia2: verificare daca zi este egal cu unul din xi, daca da atunci nu il mai calculam
	for (int i = 0; i < z.size(); i++) {
		if (z[i] < xi[0] || z[i] > xi[n]) {
			cout << "Valoarea " << z[i] << " nu este in intervalul [" << xi[0] << ", " << xi[n] << "]" << endl;
			z.erase(z.begin() + i); //daca indeplineste conditia l-am sters din vector, pentru a nu calcula iar
			i--;
			continue;
		}
		for (int j = 0; j <= n; j++) {
			if (z[i] == xi[j]) {
				cout << "Valoarea exacta a functiei f in " << z[i] << " (fara sa o calculam) este " << fi[j] << endl;
				z.erase(z.begin() + i);
				i--;
			}
		}
	}
	//Observatia 3: calculul polinomului Lagrange si evaluarea acestuia in fiecare din cele m puncte date
	for (int j = 0; j < z.size(); j++) {
		N = fi[0];
		for (int k = 1; k <= n; k++) {
			s = 0;
			for (int l = 0; l <= k; l++) {
				p = 1;
				for (int i = 0; i <= k; i++) {
					if (i != l) {
						p = p * (xi[l] - xi[i]);
					}
				}
				s = s + fi[l] / p;
			}
			p = 1;
			for (int i = 0; i <= k - 1; i++) {
				p = p * (z[j] - xi[i]);
			}
			N = N + s * p;
		}
		cout << "Valoarea aproximativa a functiei f in " << z[j] << " este " << N << endl;
	}
	return 0;
}