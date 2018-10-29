#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class book : public resource
{
};
class magazine : public resource
{
};

class e_book : public resource
{
};

class resource{
	protected:
		vector<int> year;
		vector<int> month;
		vector<int> day;
		vector<int> borrow;
		vector<string> name;
	public:
		int add_resource(string source_name)
		{
			name.push_back(source_name);
			year.push_back(0);
			month.push_back(0);
			day.push_back(0);
			borrow.push_back(0);
		}
		int check_name(string n)
		{
			int temp;
			int check=0;
			for(temp=0;temp<year.size();temp++)
			{
				if(name.at(temp)==source_name)
				{
					check=1;
					break;
				}
			}
			if(check==0)
			{
				cout<<"no resource"<<endl;
				return 0;
			}
			else
			{
				if(borrow.at(temp)==1)
				{
					cout<<"already borrowed"<<endl;
					return 0;
				}
				else
				{
					cout<<"you can borrow it"<<endl;
					return 1;
				}

			}
		}
		int req_borrow(string resource_name,int y,int m,int d)
		{
			int temp;
			int check=0;
			for(temp=0;temp<year.size();temp++)
			{
				if(name.at(temp)==resource_name)
				{
					check=1;
					break;
				}
			}
			if(check==0)
			{
				cout<<"no resource"<<endl;
				return 0;
			}
			if(borrow.at(temp) == 0)
			{
				borrow.at(temp) = 1;
				int temp_y,temp_m,temp_d;
				day.at(temp) = d;
				month.at(temp) = m;
				year.at(temp) = y;
				
				temp_d = d+14;
				temp_m = m+temp_d/31;
				temp_y = y+temp_m/13;
				temp_d = temp_d%31;
				temp_m = temp_m%13;
				
				cout<<temp_y<<"/"<<temp_m<<"/"<<temp_d<<"will be returned"<<endl;
				return 1;
			}
			else
			{
				cout<<"this resource is already borrowed"<<endl;
				return 0;
			}

		}
		int req_return(string resource_name)
		{
			int temp;
			int check=1;

			for(temp=0;temp<year.size();temp++)
			{
				if(name.at(temp)==resource_name)
				{
					check=1;
					break;
				}
			}

			if(borrow.at(temp)==1)
			{
				borrow.at(temp) = 0;
				return 1;
			}
			else
			{
				cout<<"this book is not borrowed"<<endl;
				return 0;
			}
		}
};
