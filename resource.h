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
		vector<string> name;

	public:
		int add_resource(string source_name);
		int check_name(string n);
		int req_borrow(string resource_name,string resource_type,int y,int m,int d,int time);
};

class book : public resource
{
	private:
		vector<int> borrow;
	public:
		int req_return(string resource_name);
		int check_borrow(string resource_name);
		int req_borrow(string resource_name,int y,int m,int d,int time);
};

class magazine : public resource	//input에 resource_name에 public year과 month 있음
{
	private:
		vector<vector<int>> public_month;
		vector<vector<int>> public_year;
		vector<vector<int>> borrow;
		vector<vector<int>> year;
		vector<vector<int>> month;
		vector<vector<int>> day;
	public:
		
		int req_return(string name,int resource_year,int resource_month);
		int check_borrow(string resource_name,int resource_year,int resource_month);
		int add_resource(string name);
		int req_borrow(string resource_name,int resource_year,int resource_month,int y,int m,int d,int time);
};

class e_book : public resource //resource_name에 size 있음(.dat file)
{
	private:
		vector<int> size;

	public:
		int return_size(string resource_name);
		int add_resource(string resource_name,int s);
};
