#include "member.h"

member::member()
{
	borrow_number = 0;
}

//member::~member()
//{
//	cout<<"end"<<endl;
//}

int member :: check_name(string check_name)
{
	if(name==check_name)
			return 1;
	else
			return 0;

}

int member :: check_borrow(string source_name,string source_type)
{
//	cout<<"check_borrow"<<endl;
	int temp;
	for(temp=0;temp<borrow_number;temp++)
	{
		if(borrow.at(temp)==source_name && borrow_type.at(temp)==source_type)
		{
			cout<<"4	You already borrowed this book at "<<year.at(temp)<<"/"<<month.at(temp)<<"/"<<day.at(temp)<<endl;
			return 0;
		}
	}
	return 1;
}

int member :: borrow_resource(string resource_name,string resource_type,int y,int m,int d)
{
//	cout<<"borrow_resource"<<endl;	
	borrow.push_back(resource_name);
	borrow_type.push_back(resource_type);
	day.push_back(d);
	month.push_back(m);
	year.push_back(y);
	borrow_number++;
	return 1;
	
}
int member :: return_resource(string resource_name,string resource_type)
{
	int temp;
	int check=0;
	for(temp=0;temp<borrow_number;temp++)
	{	
		if(borrow.at(temp)==resource_name){
			check = 1;
			break;
		}
	}
	if(check==0)
	{
		cout<<"3	You did not borrow this book"<<endl;
		return 0;
	}
	else
	{
		borrow_number=0;
		borrow.at(temp)="";
		year.at(temp)=0;
		month.at(temp)=0;
		day.at(temp)=0;
//		cout<<"success"<<endl;
		return 1;
	}
}
void member::init(string user_name)
{
	name = user_name;
	return;
}

void undergraduate :: init(string user_name)
{
	name = user_name;
	delay_day = 0;
	delay_month = 0;
	delay_year = 0;
}

int undergraduate :: check_name(string n,int x)
{
//	cout<<borrow_number<<"undergraduate_check_name"<<x<<endl;
	if(name==n)
	{
		if((borrow_number>=limit_undergraduate) && (x==1)) //when borrow
		{
			cout<<"2	Exceeds your possible number of borrow. Possible # of borrows: "<<limit_undergraduate<<endl;
			return -1; //error
		}
		else
			return 1;  //there is reg
	}
	else
		return 0;  //no reg
}

int undergraduate :: check_delay(int y,int m,int d)
{
//	cout<<"check_delay"<<endl;
	int delay = (y-delay_year)*360 + (m-delay_month)*30+(d-delay_day);
//	cout<<"delay is"<<delay<<endl;
	if(delay<=0)
	{
		cout<<"6	Restricted member until ";
		cout.width(2);
		cout<<delay_year;
		cout<<"/";
		cout.width(2);
		cout<<delay_month;
		cout<<"/";
		cout.width(2);
		cout<<delay_day<<endl;
		return -1;
			
	}
	return 1;
}
int undergraduate :: borrow_resource(string resource_name,string resource_type,int y,int m,int d)
{
//	cout<<"borrow_resource"<<endl;
	if(borrow_number==1)
	{
		cout<<"2	Exceeds your possible number of borrow. Possible # of borrows:"<<limit_undergraduate<<endl;
		return 0;
	}
	else
	{
		borrow_number=1;
//		cout<<"success"<<endl;
		borrow.push_back(resource_name);
		borrow_type.push_back(resource_type);
		year.push_back(y);
		month.push_back(m);
		day.push_back(d);
		return 1;
	}
}
int undergraduate :: return_resource(string resource_name,string resource_type,int y,int m,int d)
{
	int return_value = 1;
	if(borrow_number==0)
	{
		cout<<"3	You did not borrow this "<<resource_type<<"."<<endl;
		return 0;
	}
	else
	{
		int temp=0;
		if(borrow.at(0)==resource_name && borrow_type.at(0)==resource_type)
		{
			int temp_delay=0;
			temp_delay = (y-year.at(0))*360+(m-month.at(0))*30+(d-day.at(0))-13;
//			cout<<"delay is  "<<temp_delay<<endl;
			if(temp_delay<=0)
			{
				delay_year = 0;
				delay_month = 0;
				delay_day = 0;
			}
			else
			{
				delay_day = d+temp_delay;
				delay_month = m+delay_day/31;
				delay_year = y+delay_month/13;
				delay_month = delay_month%13;
				delay_day = delay_day%31;	
				cout<<"7	Delayed return. You'll be restricted until ";
				cout.width(2);
				cout<<delay_year;
				cout<<"/";
				cout.width(2);
				cout<<delay_month;
				cout<<"/";
				cout.width(2);
				cout<<delay_day<<endl;
			return_value = -1;
			}
			borrow_number = 0;
//			cout<<"undergraduate return success"<<endl;
			borrow_type.pop_back();
			borrow.pop_back();
			day.pop_back();
			month.pop_back();
			year.pop_back();
			return return_value;
			
		}
		else
		{
			cout<<"3	You did not borrow this "<<resource_type<<"."<<endl;
			return 0;
		}
	}

}
