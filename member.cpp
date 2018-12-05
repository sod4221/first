#include "member.h"

int member :: check_name(string n,int x)
{
//	cout<<borrow_number<<"undergraduate_check_name"<<x<<endl;
	if(name==n)
	{
		if(borrow_number>=limit && (x==1)) //when borrow x=1
		{
			cout<<"2	Exceeds your possible number of borrow. Possible # of borrows: "<<limit<<endl;
			return 2; //error
		}
		else{
			return 1;  //there is reg
			}
	}
	else{
		return 0;  //no reg
		}
}

int member :: check_delay(int y,int m,int d)
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
		return 6;
			
	}
	return 0;
}
int member :: check_overdue(int y,int m,int d)		//for graduate and faculty
{
	int temp_delay;
	for(int i=0;i<borrow_number;i++)
	{
		temp_delay = (y-year.at(i))*360+(m-month.at(i))*30+(d-day.at(i))-29;
		if(temp_delay>0)
		{
			cout<<"16	Previously borrowed books are overdue, so borrow is limited."<<endl;
			return 16;
		}
	}

	return 0;
}

int member :: check_memory(int insert,int year,int month,int day)// for e_book
{
	int loan;
	int temp = e_book.size();
	for(int i=0;i<temp;i++)
	{
		loan =  (year-e_year.at(i))*360+(month-e_month.at(i))*30+(day-e_day.at(i))-limit+1;
		if(loan>0) // expired
		{
			e_book.erase(e_book.begin()+i);
			e_year.erase(e_year.begin()+i);
			e_month.erase(e_month.begin()+i);
			e_day.erase(e_day.begin()+i);
			memory+=size.at(i);
			size.erase(size.begin()+i);
			i--;
		}
	}

	if(memory-insert<0)
	{
		cout<<"15	Exceeds your storage capacity"<<endl;
		return 15;
	}
	else
	{
		return 0;
	}
}


int member :: check_borrow(string source_name,string source_type)
{
//	cout<<"check_borrow"<<endl;
	int temp;
	if(source_type!="E_book")
	{
		for(temp=0;temp<borrow_number;temp++)
		{
			if(borrow.at(temp)==source_name && borrow_type.at(temp)==source_type)
			{
				cout<<"4	You already borrowed this ";
				if(source_type=="Book")
					cout<<"book";
				else
					cout<<"magazine";
				cout<<" at "<<year.at(temp)<<"/"<<month.at(temp)<<"/"<<day.at(temp)<<endl;
				return 4;
			}
		}
		return 0;
	}
	else
	{
		int t=e_book.size();
		for(temp=0;temp<t;temp++)
		{
			if(e_book.at(temp)==source_name)
			{
				cout<<"4	You already borrowed this e_book at "<<year.at(temp)<<"/"<<month.at(temp)<<"/"<<day.at(temp)<<endl;
				return 4;
			}
		}
		return 0;

	}
}
 
int member :: return_resource(string resource_name,string resource_type,int y,int m,int d,int delay,int s)
{
	if(resource_type!="E_book")
	{
		int temp;
		int check=0;
		for(temp=0;temp<borrow_number;temp++)
		{	
			if(borrow.at(temp)==resource_name && borrow_type.at(temp)==resource_type){
				check = 1;
				break;
			}
		}
		if(check==0)
		{
			cout<<"3	You did not borrow this ";
			if(resource_type=="Book")
				cout<<"book."<<endl;
			else
				cout<<"magazine."<<endl;
			return 3;
		}
		int temp_delay=0;
		temp_delay = (y-year.at(temp))*360+(m-month.at(temp))*30+(d-day.at(temp))-delay+1;
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
		}
		borrow_number--;
		borrow_type.erase(borrow_type.begin()+temp);
		borrow.erase(borrow.begin()+temp);
		year.erase(year.begin()+temp);
		month.erase(month.begin()+temp);
		day.erase(day.begin()+temp);
//		
//		cout<<"success"<<endl;
		return 0;
	}
	else
	{
		int check=0;
		int temp;
		int t = e_book.size();
		for(temp=0;temp<t;temp++)
		{
			if(e_book.at(temp)==resource_name){
				check = 1;
				break;
			}
		}
		if(check==0)
		{
			cout<<"3	You did not borrow this e_book"<<endl;
			return 3;
		}
		else
		{
			e_book.erase(e_book.begin()+temp);
			e_year.erase(e_year.begin()+temp);
			e_month.erase(e_month.begin()+temp);
			e_day.erase(e_day.begin()+temp);
			memory+=size.at(temp);
			size.erase(size.begin()+temp);
			return 0;
		}
	}
}
void undergraduate :: init(string user_name)
{
	limit = 1;
	borrow_number=0;
	name = user_name;
	delay_day = 0;
	delay_month = 0;
	delay_year = 0;
	memory = limit*100;
}


void graduate :: init(string user_name)
{
	limit = 5;
	borrow_number=0;
	name = user_name;
	delay_day = 0;
	delay_month = 0;
	delay_year = 0;
	memory = limit*100;
}

void faculty :: init(string user_name)
{
	limit = 10;
	borrow_number=0;
	name = user_name;
	delay_day = 0;
	delay_month = 0;
	delay_year = 0;
	memory = limit*100;
}

int member:: borrow_resource(string resource_name,string resource_type,int y,int m,int d,int s)
{
	if(resource_type!="E_book")
	{
	borrow_number++;
//		cout<<"success"<<endl;
	borrow.push_back(resource_name);
	borrow_type.push_back(resource_type);
	year.push_back(y);
	month.push_back(m);
	day.push_back(d);
	}
	else
	{
		e_book.push_back(resource_name);
		e_year.push_back(y);
		e_month.push_back(m);
		e_day.push_back(d);
		size.push_back(s);
		memory-=s;	
	}
	return 0;
}

