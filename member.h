#include <cstring>
#include <iostream>
#include <vector>
#define can_delay_day  14;
#define one_year  360;
#define one_month 30;
const int limit_undergraduate = 1;

using namespace std;
class member
{
	protected:
		string name;
		vector<string> borrow;
		vector<string> borrow_type;
		vector<int> day;
		vector<int> month;
		vector<int> year;
		int borrow_number;
		
	public:
		member();
		~member();
		int check_name(string n);
		int check_borrow(string source_name,string source_type);
		int borrow_resource(string resource_name,string resource_type,int y,int m,int d);
		int return_resource(string resource_name,string resource_type);
		void init(string user_name);
		
};
		
class undergraduate : public member
{
	private:
		int delay_day;
		int delay_month;
		int delay_year;
	
	public:		
		int check_delay(int y,int m,int d);
		int check_name(string n);
		int borrow_resource(string resource_name,string resource_type,int y,int m,int d);
		int return_resource(string resource_name,string resource_type,int y,int m,int d);
		void init(string user_name);

};
class graduate : public member
{

};
class faculty : public member
{

};
