#include <iostream>
#include <cstring>

const int space_number = 10;

class space
{
	public:
		virtual int borrow_space();
		virtual int return_space();
		virtual int check_space();
		virtual int reset_space();
}
