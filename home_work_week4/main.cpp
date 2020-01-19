#include "dependies.h"
#include "Function_template.h"
#include "Matrix_template.h"

using namespace std;

int main() {

	Matrix<int>a(2,3);
	a.RandInit();
	a.Show();
	cout << "_______________________\n";
	Matrix<int>b(2,3);
	b.RandInit();
	b.Show();
	cout << "_______________________\n";
	Matrix<int>c;
	c = b;
    c=b + a;
	c.Show();
	return 0;
}