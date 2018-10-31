#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
	string temp_type,temp_name;
	ifstream read_resource;
	read_resource.open("resource.dat");
	read_resource>>temp_type>>temp_name;
	do
	{
		temp_type.clear();
		temp_name.clear();
		read_resource>>temp_type>>temp_name;
		if(temp_type.size()!=0)
		{
			if(temp_type=="Book")
			{
				cout<<temp_type<<" "<<temp_name<<endl;
			}
			else if(temp_type=="E_book")
			{
				cout<<temp_type<<" "<<temp_name<<endl;
			}
			else if(temp_type=="Magazine")
			{
				cout<<temp_type<<" "<<temp_name<<endl;			
			}
		}
	}	
	while(temp_type.size()!=0);
	read_resource.close();

	ifstream read_input;
	read_input.open("input.dat");
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
	read_input>>date>>resource_type>>resource_name>>member_type>>member_type>>member_name;
	
	cout<<"why!"<<date<<resource_type<<resource_name<<operation<<member_type<<member_name<<endl;
	cout<<"Op_#	Return_code	Description"<<endl;
	do
	{
		resource_type.clear();
		read_input>>date>>resource_type>>resource_name>>operation>>member_type>>member_name;
		if(resource_type.size()!=0)
		{
		cout<<"why!"<<date<<resource_type<<resource_name<<operation<<member_type<<member_name<<endl;
			cout<<"if station!"<<endl;
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
				cout<<"operation is B"<<endl;
			}
			else if(operation=='R')
			{					
				cout<<"operation is R"<<endl;				
			}
			else
			{
				cout<<"error"<<endl;
			}
		}
	}while(resource_type.size()!=0);

	fclose(stdin);

}
