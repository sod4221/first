#include "resource.h"

int resource :: add_resource(string source_name)
{
	name.push_back(source_name);
	year.push_back(0);
	month.push_back(0);
	day.push_back(0);
	name.push_back(0);
}
int resource :: check_name(string n)
{
//	cout<<"resource_check_name"<<endl;
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
		cout<<"1	Non exist resource."<<endl;
		return 0;
	}
	return 1;

}
int book :: check_borrow(string resource_name)
{
	int temp;
	int limit =year.size();
	for(temp=0;temp<limit;temp++)
	{
		if(name.at(temp)==resource_name)
		{
			break;
		}
	}
	if(borrow.at(temp) == 0)
	{
		return 1;
	}
	else
	{
		cout<<"5	Other member already borrwed this book. This book will be returned at ";
		cout.width(2);
		cout<<year.at(temp);
		cout<<"/";
		cout.width(2);
		cout<<month.at(temp);
		cout<<"/";
		cout.width(2);
		cout<<day.at(temp)<<endl;
		return 0;
	}



}


int book :: req_borrow(string resource_name,int y,int m,int d,int time)
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
		
		temp_d = d+time;
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
		return 0;
	}

}
int book :: req_return(string resource_name)
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
		return 0;
	}
}

int magazine :: check_borrow(string resource_name,int resource_year,int resource_month)
{
	int temp;
	int check=0;
	int limit = name.size();
	for(temp=0;temp<limit;temp++)
	{
		if(name.at(temp)==resource_name)
		{
			check=1;
			break;
		}
	}
	if(check==0)		//non-exist
	{
	//	cout<<"no resource"<<endl;
		return -1;
	}
	check=0;
	int temp2=0;
	limit = (borrow.at(temp)).size();
	for(;temp2<limit;temp2++)
	{
		if(public_year.at(temp).at(temp2)==resource_year && public_month.at(temp).at(temp2)==resource_month)
		{
			check = 1;
			break;
		}
	}
	
	if(check==1)
	{
		cout<<"5	Other member already borrwed this magazine. This magazine will be returned at ";
		cout.width(2);
		cout<<year.at(temp).at(temp2);
		cout<<"/";
		cout.width(2);
		cout<<month.at(temp).at(temp2);
		cout<<"/";
		cout.width(2);
		cout<<day.at(temp).at(temp2)<<endl;
		return 0;

	}
	else
		return 1;

}

int magazine :: req_return(string resource_name,int resource_year,int resource_month)
{
	int temp;
	int check=0;
	int limit = name.size();
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
	check=0;
	int temp2=0;
	limit = (borrow.at(temp)).size();
	for(;temp2<limit;temp2++)
	{
		if(public_year.at(temp).at(temp2)==resource_year && public_month.at(temp).at(temp2)==resource_month)
		{
			public_month.at(temp).erase(public_month.at(temp).begin()+temp2);
			public_year.at(temp).erase(public_year.at(temp).begin()+temp2);
			borrow.at(temp).erase(borrow.at(temp).begin()+temp2);
			
			year.at(temp).erase(year.at(temp).begin()+temp2);
			month.at(temp).erase(month.at(temp).begin()+temp2);
			day.at(temp).erase(day.at(temp).begin()+temp2);
			check = 1;
			break;
		}
	}
	return 0;

}

int magazine :: req_borrow(string resource_name,int resource_year,int resource_month,int y,int m,int d,int time)
{
	int temp;
	int check=0;
	int limit = name.size();
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
	check=0;
	int temp2=0;
	limit = (borrow.at(temp)).size();
	for(;temp2<limit;temp2++)
	{
		if(public_year.at(temp).at(temp2)==resource_year && public_month.at(temp).at(temp2)==resource_month)
		{
			check = 1;
			break;
		}
	}
	if(check==1)
	{
		return 0;
	}
	else
	{
		public_year.at(temp).push_back(resource_year);
		public_month.at(temp).push_back(resource_month);
		borrow.at(temp).push_back(1);
		int temp_y,temp_m,temp_d;
		temp_d = d+time;
		temp_m = m+temp_d/31;
		temp_y = y+temp_m/13;
		temp_d = temp_d%31;
		temp_m = temp_m%13;
		day.at(temp).push_back(temp_d);
		month.at(temp).push_back(temp_m);
		year.at(temp).push_back(temp_y);
//			cout<<temp_y<<"/"<<temp_m<<"/"<<temp_d<<"will be returned"<<endl;
		return 1;

	}

}
int magazine :: add_resource(string resource_name)
{
	vector<int> temp;
	name.push_back(resource_name);
	year.push_back(temp);
	month.push_back(temp);
	day.push_back(temp);
	borrow.push_back(temp);
	public_year.push_back(temp);
	public_month.push_back(temp);
}

int e_book :: add_resource(string resource_name,int s)
{
	name.push_back(resource_name);
	year.push_back(0);
	month.push_back(0);
	day.push_back(0);
	size.push_back(s);
}

int e_book :: return_size(string resource_name)
{
	int temp;
	int check=1;
	int limit = year.size();
	for(temp=0;temp<limit;temp++)
	{
		if(name.at(temp)==resource_name)
		{
			return size.at(temp);
		}

	}

}
