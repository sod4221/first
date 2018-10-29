#include <string>
#include <iostream>
#include <vector>
#define delay_day = 14;
#define one_year = 360;
using namespace std;

class undergraduate : public member
{
	private:
		int delay_day;
		int delay_month;
		int delay_year;
	public:
		void init(string user_name)
		{
			name = user_name;
			delay_day = 0;
			delay_month = 0;
			delay_year = 0;
		}
		
		int check_name(string n)
		{
			if(name==n)
			{
				if(borrow.at(0)==1)
				{
					cout<<"you can not borrow"<<endl
					return -1; //error
				}
				else
					return 1;  //there is reg
			}
			else
				return 0;  //no reg
		}

		int check_delay(int y,int m,int d)
		{
			int delay = (y-delay_year)*360 + (m-delay_month)*30+(d-delay_day);
			return delay;

		}
		int borrow_resource(string resource_name,int y,int m,int d)
		{
			if(borrow_number==1)
			{
				cout<<"you can not borrow"<<endl;
				return 0;
			}
			else
			{
				borrow_number=0;
				cout<<"success"<<endl;
				borrow.push_back(resource_name);
				year.push_back(y);
				month.push_back(m);
				day.pusb_back(d);
				return 1;
			}
		}
		int return_resource(string resource_name,int y,int m,int d)
		{
			if(borrow_number==0)
			{
				cout<<"you did not borrow this book"<<endl;
			}
			else
			{
				int temp=0;
				if(borrow.at(0)==resource_name)
				{
					int temp_delay=0;
					temp_delay = (y-year.at(0))*360+(m-month.at(0))*30+(d-day.at(0))-14;
					if(temp_delay<=0)
					{
						delay_year = y;
						delay_month = m;
						delay_day = d;
					}
					else
					{
						delay_day = d+temp_delay;
						delay_month = m+delay_day/31;
						delay_year = y+delay_moth/13;
						delay_month = delay_month%13;
						delay_day = delay_day%31;	
						cout<<"you can't borrow untill "<<delay_year"/"<<delay_month<<"/"<<delay_day<<endl;
					}
					borrow_number = 0;
					cout<<"success"<<endl;
					borrow.pop_back();
					day.pop_back();
					month.pop_back();
					year.pop_back();
				}
				else
				{
					cout<<"you did not borrow this source"<<endl;
				}


			}

		}
};

class graduate : public member
{
	public:
		void init(string user_name)
		{
			name = user_name;
		}
};

class faculty : public member
{
	public:
		void init(string user_name)
		{
			name = user_name;
		}
};

class member
{
	protected:
		string name;
		vector<string> borrow;
		vector<int> day;
		vector<int> month;
		vector<int> year;
		int borrow_number;
	public:

		member()
		{
			borrow_number = 0;
		}

		int check_name(string check_name)
		{
			if(name==check_name)
					return 1;
			else
					return 0;


		}

		int borrow_resource(string resource_name,int y,int m,int d)
		{
			
			borrow.push_back(resource_name);
			day.push_back(d);
			month.push_back(m);
			year,push_back(y);
			borrow_number++;
			return 1;
			
		}
		int return_resource(string resource_name)
		{
			int temp;
			int check=0;
			for(temp=0;temp<borrow_number;temp++)
			{	
				if(borrow.at(temp)==resource_name)
				{
					check = 1;
					break;
				}
			}
			if(check==0)
			{
				cout<<"you did not borrow this book"<<endl;
				return 0;
			}
			else
			{
				borrow_number--;
				borrow.erase(temp);
				year.erase(temp);
				month.erase(temp);
				day.erase(temp);
				cout<<"success"<<endl;
				return 1;
			}
		}
};
