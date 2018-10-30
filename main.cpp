#include "library.h"

int main()
{
	freopen("output.dat","w",stdout);
	library lib;
	lib.init();
	lib.input();
	fclose(stdout);
	return 0;
}
