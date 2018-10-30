#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
class resource
{
	protected:
		vector<int> year;
		vector<int> month;
		vector<int> day;
		vector<int> borrow;
		vector<string> name;

	public:
		int add_resource(string source_name);
		int check_name(string n);
		int req_borrow(string resource_name,int y,int m,int d);
		int req_return(string resource_name);
};
class book : public resource
{
};
class magazine : public resource
{
};
class e_book : public resource
{
};
