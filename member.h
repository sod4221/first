#include <cstring>
#include <iostream>
#include <vector>
const int limit_faculty = 10;
const int limit_graduate = 5;
const int limit_undergraduate = 1;
using namespace std;
class member
{
	protected:
		string name;
		vector<string> borrow;
		vector<string> borrow_type;
		vector<string> e_book;
		vector<int> size;
		vector<int> e_year;
		vector<int> e_month;
		vector<int> e_day;
		vector<int> day;
		vector<int> month;
		vector<int> year;
		int borrow_number;
		int memory;	
		int delay_day;
		int delay_month;
		int delay_year;
		int limit;
	public:
		int check_name(string n,int x);
		int check_delay(int y,int m,int d);
		int check_overdue(int y,int m,int d);
		int check_memory(int insert,int year,int month,int day);// for e_book
		int check_borrow(string source_name,string source_type);
		int borrow_resource(string resource_name,string resource_type,int y,int m,int d,int size);
		int return_resource(string resource_name,string resource_type,int y,int m,int d,int delay,int size);
		void init(string user_name);
};

class undergraduate : public member
{
	public:
		void init(string user_name);
};
//
class graduate : public member
{
	public:
		void init(string user_name);

};
class faculty : public member
{
	public:
		void init(string user_name);


};
