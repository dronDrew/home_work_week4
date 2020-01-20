#include "dependies.h"
#include "Function_template.h"
#include "Matrix_template.h"
#include "string_check.h"
#include "Bus_stop.h"
#include "Printing_server.h"

using namespace std;

int main() {
	Printing_server a;
	a.Add(12, 1, 123);
	a.Add(15, 2, 124);
	a.Show();
	return 0;
}