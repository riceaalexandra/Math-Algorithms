#include <iostream>
#include <cmath>
using namespace std;

/*float f(float x) {
	return 1. / (x + 1);
}*/

float f(float x) {
	if (x >= -1 && x < 0)
		return 0.4 * pow((1 + x), 3) + 0.6 * (1 + x) - 5 * x;
	if (x >= 0 && x <= 1)
		return 1 / (1 + x);
}

int main() {
	float a, b, n = 1, epsilon, integrala, integrala0, h, s1, s2;
	//cout << "f(x) = 1/(x+1)" << endl;
	cout << "f(x) = 0.4(x+1)^3 + 0.6(x+1) - 5x pentru x in intervalul [-1,0)" << endl;
	cout << "f(x) = 1/(x+1) pentru x in intervalul [0,1]" << endl;
	cout << "Introduceti a: ";
	cin >> a;
	cout << "Introduceti b: ";
	cin >> b;
	cout << "Introduceti epsilon: ";
	cin >> epsilon;
	integrala = (f(a) + 4 * f((a + b)/2) + f(b)) * (b - a) / 6;
	do {
		n = 2 * n;
		h = (b - a) / n;
		integrala0 = integrala;
		s1 = 0;
		for (int i = 1; i <= n - 1; i++) {
			s1 = s1 + f(a + i * h);
		}
		s2 = 0;
		for (int i = 0; i <= n - 1; i++) {
			s2 = s2 + f(a + i * h + h / 2);
		}
		integrala = (f(a) + 2 * s1 + 4 * s2 + f(b)) * h / 6;
	} while (!(fabs(integrala - integrala0) <= epsilon));
	cout << "Valoarea obtinuta cu precizia " << epsilon << " este " << integrala;
}