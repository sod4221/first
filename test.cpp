#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "member.h"
#include "resource.h"
using namespace std;
int main()
{
	member m;
	resource r;
	m.init("what");
	freopen("input.dat","r",stdin);
	int t=0;
	int year;
	int month;
	int day;
	string date;
	string resource_type;
	string resource_name;
	char operation;
	string member_type;
	string member_name;
	cin>>date>>resource_type>>resource_name>>member_type>>member_type>>member_name;

	cout<<"Op_#	Return_code	Description"<<endl;
	do
	{
		resource_type.clear();
		cin>>date>>resource_type>>resource_name>>operation>>member_type>>member_name;
		if(resource_type.size()!=0)
		{
			if(resource_type=="Book")
				cout<<"what"<<endl;
			cout<<t<<"	";
			t++;
			stringstream ss(date);
			int temp;
			cout<<date<<endl;
			ss>>year;
			date.erase(0,3);
			ss.str(date);
			ss>>month;					
			date.erase(0,3);
			ss.str(date);
			ss>>day;
			
			if(operation=='B')
			{
				cout<<"borrow"<<endl;
			}
			else if(operation=='R')
			{					
				cout<<"return"<<endl;				
			}
			else
			{
				cout<<"error"<<endl;
			}
		}
	}while(resource_type.size()!=0);
}

class n
{
	private:
		int xx;
	public:
		int in(int x){
			xx = x;
		}
		int out()
		{
			cout<<xx<<endl;
		}
		int out2()
		{
			return xx;
		}

};



