#include "resource.h"

int resource :: add_resource(string source_name)
{
	name.push_back(source_name);
	year.push_back(0);
	month.push_back(0);
	day.push_back(0);
	borrow.push_back(0);
}
int resource :: check_name(string n)
{
	int temp;
	int check=0;
	int limit = year.size();
	for(temp=0;temp<limit;temp++)
	{
		if(name.at(temp)==n)
		{
			check=1;
			break;
		}
	}
	if(check==0)
	{
		cout<<"1 Non exist resource."<<endl;
		return 0;
	}
	else
	{
		if(borrow.at(temp)==1)
		{
			int temp_y;
			cout<<"5 Other member already borrowed this book. This book will be returned at "<<year.at(temp)<<"/"<<month.at(temp)<<"/"<<day.at(temp);
			return 0;
		}
		else
		{
		//	cout<<"you can borrow it"<<endl;
			return 1;
		}

	}
}
int resource :: req_borrow(string resource_name,string resource_type,int y,int m,int d)
{
	int temp;
	int check=0;
	int limit =year.size();
	for(temp=0;temp<limit;temp++)
	{
		if(name.at(temp)==resource_name)
		{
			check=1;
			break;
		}
	}
	if(check==0)
	{
	//	cout<<"no resource"<<endl;
		return -1;
	}
	if(borrow.at(temp) == 0)
	{
		borrow.at(temp) = 1;
		int temp_y,temp_m,temp_d;
		
		temp_d = d+14;
		temp_m = m+temp_d/31;
		temp_y = y+temp_m/13;
		temp_d = temp_d%31;
		temp_m = temp_m%13;
		day.at(temp) = temp_d;
		month.at(temp) = temp_m;
		year.at(temp) = temp_y;
//			cout<<temp_y<<"/"<<temp_m<<"/"<<temp_d<<"will be returned"<<endl;
		return 1;
	}
	else
	{
		cout<<"5	other member already borrwed"<<resource_type<<". This "<<resource_type<<" will be returned at"<<year.at(temp)<<"/"<<month.at(temp)<<"/"<<day.at(temp)<<endl;
		return 0;
	}

}
int resource :: req_return(string resource_name)
{
	int temp;
	int check=1;
	int limit = year.size();
	for(temp=0;temp<limit;temp++)
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


