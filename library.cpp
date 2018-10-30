#include "library.h"


void library :: init() //resource download
{
	freopen("resource.dat","r",stdin);
	undergraduate_number=0;
	graduate_number=0;
	faculty_number=0;
	book_number=0;
	magazine_number=0;
	ebook_number=0;
	string temp_type,temp_name;
	cin>>temp_type,temp_name;
	do
	{
		temp_type.clear();
		temp_name.clear();
		cin>>temp_type,temp_name;
		if(temp_type.size()!=0)
		{
			if(temp_type=="Book")
			{
				book_number++;
				resource_book.add_resource(temp_name);
			}
			else if(temp_type=="E_book")
			{
				ebook_number++;
				resource_ebook.add_resource(temp_name);
			}
			else if(temp_type=="Magazine")
			{
				magazine_number++;
				resource_magazine.add_resource(temp_name);					
			}
		}
	}	
	while(temp_type.size()==0);
	fclose(stdin);
}

int library :: request_borrow(string member_name,string member_type,string resource_name,string resource_type,int year,int month,int day)
{
	int temp;
	int check=0;
	if(member_type=="Undergraduate")
	{
		for(temp=0;temp<undergraduate_number;temp++)  //find member
		{
			check = (member_undergraduate.at(temp)).check_name(member_name);
			if(check==1)
			{
				break;
			}
		}
		if((check<0))  //you already borrow something
		{
			return 0;
		}
		if(check==0) //there is no member reg
		{
			temp ++;
			undergraduate t;
			t.init(member_name);
			member_undergraduate.push_back(t);
		}
		if(member_undergraduate.at(temp).check_borrow(resource_name,resource_type)==0)
					return 0;
					
		if(resource_type=="Book")
		{
			if(resource_book.req_borrow(resource_name,year,month,day)==0)
			{
				return 0;
			}
			(member_undergraduate.at(temp)).borrow_resource(resource_name,"Book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="E_book")
		{
			if(resource_ebook.req_borrow(resource_name,year,month,day)==0)
			{
				return 0;
			}
			(member_undergraduate.at(temp)).borrow_resource(resource_name,"E_book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="Magazine")
		{
			if(resource_magazine.req_borrow(resource_name,year,month,day)==0)
			{
				return 0;
			}
			(member_undergraduate.at(temp)).borrow_resource(resource_name,"Magazine",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else
		{
			cout<<"resource type error"<<endl;
			return 0;
		}					
	}
	else if(member_type=="Graduate")
	{
		for(temp=0;temp<graduate_number;temp++)  //find member
		{
			check = (member_graduate.at(temp)).check_name(member_name);
			if(check==1)
			{
				break;
			}
		}
		if(check==0) //there is no member reg
		{
			temp ++;
			graduate t;
			t.init(member_name);
			member_graduate.push_back(t);
		}
		
		if(member_graduate.at(temp).check_borrow(resource_name,resource_type)==0)
			return 0;
		if(resource_type=="Book")
		{
			if(resource_book.req_borrow(resource_name,year,month,day)==0)
			{
				return 0;
			}
			(member_graduate.at(temp)).borrow_resource(resource_name,"Book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="E_book")
		{
			if(resource_ebook.req_borrow(resource_name,year,month,day)==0)
			{
				return 0;
			}
			(member_graduate.at(temp)).borrow_resource(resource_name,"E_book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="Magazine")
		{
			if(resource_magazine.req_borrow(resource_name,year,month,day)==0)
			{
				return 0;
			}
			(member_graduate.at(temp)).borrow_resource(resource_name,"Magazine",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else
		{
			cout<<"resource type error"<<endl;
			return 0;
		}					


	}
	else if(member_type=="Faculty")
	{
		for(temp=0;temp<faculty_number;temp++)  //find member
		{
			check = (member_faculty.at(temp)).check_name(member_name);
			if(check==1)
			{
				break;
			}
		}
		if(check==0) //there is no member reg
		{
			temp ++;
			faculty t;
			t.init(member_name);
			member_faculty.push_back(t);
		}
		if(member_faculty.at(temp).check_borrow(resource_name,resource_type)==0)
			return 0;
		if(resource_type=="Book")
		{
			if(resource_book.req_borrow(resource_name,year,month,day)==0)
			{
				return 0;
			}
			(member_faculty.at(temp)).borrow_resource(resource_name,"Book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="E_book")
		{
			if(resource_ebook.req_borrow(resource_name,year,month,day)==0)
			{
				return 0;
			}
			(member_faculty.at(temp)).borrow_resource(resource_name,"E_book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="Magazine")
		{
			if(resource_magazine.req_borrow(resource_name,year,month,day)==0)
			{
				return 0;
			}
			(member_faculty.at(temp)).borrow_resource(resource_name,"Magazine",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else
		{
			cout<<"resource type error"<<endl;
			return 0;
		}					

	}
	else
	{
		cout<<"member_type error"<<endl;
		return 0;
	}

}
int library :: request_return(string member_name,string member_type,string resource_name,string resource_type,int year,int month,int day)
{
	int temp;
	int check=0;

	//book check
	if(resource_name=="Book")
	{
		if(resource_book.check_name(resource_name)!=0) //borrowed
		{
			cout<<"it does not borrowed"<<endl;
			return 0;
		}

	}
	else if(resource_name=="Magizine")
	{
		if(resource_magazine.check_name(resource_name)!=0) //borrowed
		{
			cout<<"it does not borrowed"<<endl;
			return 0;
		}

	}
	else if(resource_name=="E_book")
	{
		if(resource_ebook.check_name(resource_name)!=0) //borrowed
		{
			cout<<"it does not borrowed"<<endl;
			return 0;
		}

	}
	else
	{
		cout<<"resource type error"<<endl;
		return 0;
	}


	//member check
	if(member_type=="Undergraduate")
	{	
		for(temp=0;temp<undergraduate_number;temp++)  //find member
		{
			check = (member_faculty.at(temp)).check_name(member_name);
			if(check==1)
			{
				break;
			}
		}
		if(check==0)
		{
			cout<<"there is no people who has name"<<endl;
			return 0;
		}
		member_undergraduate.at(temp).return_resource(resource_name,resource_type,year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
	}
	else if(member_type=="Graduate")
	{	
		for(temp=0;temp<graduate_number;temp++)  //find member
		{
			check = (member_faculty.at(temp)).check_name(member_name);
			if(check==1)
			{
				break;
			}
		}
		if(check==0)
		{
			cout<<"there is no people who has name"<<endl;
			return 0;
		}
		(member_graduate.at(temp)).return_resource(resource_name,resource_type);
			cout<<"0	Success."<<endl;
			return 1;
	}
	else if(member_type=="Faculty")
	{
		for(temp=0;temp<faculty_number;temp++)  //find member
		{
			check = (member_faculty.at(temp)).check_name(member_name);
			if(check==1)
			{
				break;
			}
		}
		if(check==0)
		{
			cout<<"there is no people who has name"<<endl;
			return 0;
		}
		member_faculty.at(temp).return_resource(resource_name,resource_type);
			cout<<"0	Success."<<endl;
			return 1;
	}
	else
	{
		cout<<"member_type error"<<endl;
		return 0;
	}
}

int library :: input()
{
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
				request_borrow(member_name,member_type,resource_name,resource_type,year,month,day);
			}
			else if(operation=='R')
			{					
				request_return(member_name,member_type,resource_name,resource_type,year,month,day);					
			}
			else
			{
				cout<<"error"<<endl;
			}
		}
	}while(resource_type.size()!=0);

	fclose(stdin);
}		

