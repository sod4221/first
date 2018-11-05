#include "library.h"


void library :: init() //resource download
{
	freopen("output.dat","w",stdout);
	cout.fill('0');
	ifstream read_resource;
	read_resource.open("resource.dat");
//	cout<<"init start"<<endl;
	
	undergraduate_number=0;
	graduate_number=0;
	faculty_number=0;
	book_number=0;
	magazine_number=0;
	ebook_number=0;
	string temp_type,temp_name;
//	cout<<temp_type<<temp_name<<endl;
	do
	{
		temp_type.clear();
		temp_name.clear();
		read_resource>>temp_type>>temp_name;
		if(temp_type.size()!=0)
		{
			if(temp_type=="Book")
			{
				book_number++;
//				cout<<temp_type<<" "<<temp_name<<book_number<<endl;
				resource_book.add_resource(temp_name);
			}
			else if(temp_type=="E_book")
			{
				ebook_number++;
//				cout<<temp_type<<" "<<ebook_number<<endl;
				resource_ebook.add_resource(temp_name);
			}
			else if(temp_type=="Magazine")
			{
				magazine_number++;
//				cout<<temp_type<<" "<<magazine_number<<endl;
				resource_magazine.add_resource(temp_name);					
			}
		}
	}	
	while(temp_type.size()!=0);
	read_resource.close();
}


int library :: request_borrow(string member_name,string member_type,string resource_name,string resource_type,int year,int month,int day)
{
//	cout<<"request_borrow!!!"<<endl;
	int temp;
	int check=0;

	//1	non check
	if(resource_type=="Book")
	{
		if(resource_book.check_name(resource_name)==0) //there is book named this?
		{
//			cout<<"it does borrowed"<<endl;
			return 0;
		}

	}
	else if(resource_type=="Magazine")
	{
		if(resource_magazine.check_name(resource_name)==0) //there is maga
		{
//			cout<<"it does not borrowed"<<endl;
			return 0;
		}

	}
	else if(resource_type=="E_book")
	{
		if(resource_ebook.check_name(resource_name)==0) //borrowed or non existed
		{
//			cout<<"it does not borrowed"<<endl;
			return 0;
		}

	}
	else
	{
//		cout<<"resource type error 1"<<resource_type<<endl;
		return 0;
	}


//resource check done
//
//member check
	if(member_type=="Undergraduate")
	{
//		cout<<"Undergraduate!!"<<endl;
		for(temp=0;temp<undergraduate_number;temp++)  //find member
		{
			check = (member_undergraduate.at(temp)).check_name(member_name,1);
//			cout<<"check!!    "<<check<<endl;
			if(check==1)
			{
				break;
			}
			if(check==-1)
			{
				return 0; //exceed number of borrow
			}
		}
		if(check==0) //there is no member reg
		{
//			cout<<"---------------member add----------"<<endl;
			undergraduate_number++;
			undergraduate t;
			t.init(member_name);
			member_undergraduate.push_back(t);
		}
		//4	already borrow check		
		if(member_undergraduate.at(temp).check_borrow(resource_name,resource_type)==0)
			return 0;
		if(resource_type=="Book")
		{
			//5 other member borrow check
			if(resource_book.check_borrow(resource_name,"book")==0)
			{
//				cout<<"check_book_borrow"<<endl;
				return 0;
			}
			//6	restrict check
			if(member_undergraduate.at(temp).check_delay(year,month,day)==-1)
				return 0;

			if(resource_book.req_borrow(resource_name,"book",year,month,day)==0)
			{
				return 0;
			}
			(member_undergraduate.at(temp)).borrow_resource(resource_name,"Book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="E_book")
		{
			//5 other member borrow check
			if(resource_ebook.check_borrow(resource_name,"book")==0)
			{
//				cout<<"check_book_borrow"<<endl;
				return 0;
			}
			//6	restrict check
			if(member_undergraduate.at(temp).check_delay(year,month,day)==-1)
				return 0;


			if(resource_ebook.req_borrow(resource_name,"e_book",year,month,day)==0)
			{
				return 0;
			}
			(member_undergraduate.at(temp)).borrow_resource(resource_name,"E_book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="Magazine")
		{
			//5 other member borrow check
			if(resource_magazine.check_borrow(resource_name,"book")==0)
			{
//				cout<<"check_book_borrow"<<endl;
				return 0;
			}
			//6	restrict check
			if(member_undergraduate.at(temp).check_delay(year,month,day)==-1)
				return 0;


			if(resource_magazine.req_borrow(resource_name,"magazine",year,month,day)==0)
			{
				return 0;
			}
			(member_undergraduate.at(temp)).borrow_resource(resource_name,"Magazine",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else
		{
	//		cout<<resource_type<<" resource type error"<<endl;
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
		//4	already borrow check		
		if(member_graduate.at(temp).check_borrow(resource_name,resource_type)==0)
			return 0;
		if(resource_type=="Book")
		{
			//5 other member borrow check
			if(resource_book.check_borrow(resource_name,"book")==0)
			{
//				cout<<"check_book_borrow"<<endl;
				return 0;
			}

			if(resource_book.req_borrow(resource_name,"book",year,month,day)==0)
			{
				return 0;
			}
			(member_graduate.at(temp)).borrow_resource(resource_name,resource_type,year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="E_book")
		{
			//5 other member borrow check
			if(resource_ebook.check_borrow(resource_name,"book")==0)
			{
//				cout<<"check_book_borrow"<<endl;
				return 0;
			}

			if(resource_ebook.req_borrow(resource_name,"book",year,month,day)==0)
			{
				return 0;
			}
			(member_graduate.at(temp)).borrow_resource(resource_name,resource_type,year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="Magazine")
		
		{			//5 other member borrow check
			if(resource_magazine.check_borrow(resource_name,"book")==0)
			{
//				cout<<"check_book_borrow"<<endl;
				return 0;
			}

			if(resource_magazine.req_borrow(resource_name,"magazine",year,month,day)==0)
			{
				return 0;
			}
			(member_graduate.at(temp)).borrow_resource(resource_name,resource_type,year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else
		{
			cout<<resource_type<<" resource type error"<<endl;
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
		//4	already borrow check		
		if(member_faculty.at(temp).check_borrow(resource_name,resource_type)==0)
			return 0;
		if(resource_type=="Book")
		{
			//5 other member borrow check
			if(resource_book.check_borrow(resource_name,"book")==0)
			{
//				cout<<"check_book_borrow"<<endl;
				return 0;
			}

			if(resource_book.req_borrow(resource_name,"book",year,month,day)==0)
			{
				return 0;
			}
			(member_faculty.at(temp)).borrow_resource(resource_name,resource_type,year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="E_book")
		{
			//5 other member borrow check
			if(resource_ebook.check_borrow(resource_name,"book")==0)
			{
//				cout<<"check_book_borrow"<<endl;
				return 0;
			}

			if(resource_ebook.req_borrow(resource_name,"book",year,month,day)==0)
			{
				return 0;
			}
			(member_faculty.at(temp)).borrow_resource(resource_name,resource_type,year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="Magazine")
		
		{			//5 other member borrow check
			if(resource_magazine.check_borrow(resource_name,"book")==0)
			{
//				cout<<"check_book_borrow"<<endl;
				return 0;
			}

			if(resource_magazine.req_borrow(resource_name,"magazine",year,month,day)==0)
			{
				return 0;
			}
			(member_faculty.at(temp)).borrow_resource(resource_name,resource_type,year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else
		{
			cout<<resource_type<<" resource type error"<<endl;
			return 0;
		}					

	}
/*
		if(member_faculty.at(temp).check_borrow(resource_name,resource_type)==0)
			return 0;
		if(resource_type=="Book")
		{
			if(resource_book.req_borrow(resource_name,"book",year,month,day)==0)
			{
				return 0;
			}
			(member_faculty.at(temp)).borrow_resource(resource_name,"Book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="E_book")
		{
			if(resource_ebook.req_borrow(resource_name,"ebook",year,month,day)==0)
			{
				return 0;
			}
			(member_faculty.at(temp)).borrow_resource(resource_name,"E_book",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else if(resource_type=="Magazine")
		{
			if(resource_magazine.req_borrow(resource_name,"magazine",year,month,day)==0)
			{
				return 0;
			}
			(member_faculty.at(temp)).borrow_resource(resource_name,"Magazine",year,month,day);
			cout<<"0	Success."<<endl;
			return 1;
		}
		else
		{
			cout<<resource_type<<"resource type error"<<endl;
			return 0;
		}					

	}*/
	else
	{
//		cout<<member_type<<"member_type error"<<endl;
		return 0;
	}

}
int library :: request_return(string member_name,string member_type,string resource_name,string resource_type,int year,int month,int day)
{
//	cout<<"request_return!!!"<<endl;
	int temp;
	int check=0;

	//book check
	if(resource_type=="Book")
	{
		if(resource_book.check_name(resource_name)==0) //borrowed
		{
//			cout<<"it does borrowed"<<endl;
			return 0;
		}

	}
	else if(resource_type=="Magazine")
	{
		if(resource_magazine.check_name(resource_name)==0) //borrowed
		{
//			cout<<"it does not borrowed"<<endl;
			return 0;
		}

	}
	else if(resource_type=="E_book")
	{
		if(resource_ebook.check_name(resource_name)==0) //borrowed or non existed
		{
//			cout<<"it does not borrowed"<<endl;
			return 0;
		}

	}
	else
	{
	//	cout<<"resource type error 1"<<resource_type<<endl;
		return 0;
	}


	//member check
	if(member_type=="Undergraduate")
	{	
		for(temp=0;temp<undergraduate_number;temp++)  //find member
		{
			check = (member_undergraduate.at(temp)).check_name(member_name,0);
			if(check==1)
			{
				break;
			}
		}
		if(check==0)
		{
//			cout<<"there is no people who has name "<<member_name<<endl;
			return 0;
		}
		check = member_undergraduate.at(temp).return_resource(resource_name,resource_type,year,month,day);
			if(check==1)
				cout<<"0	Success."<<endl;
		
			return 1;
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
		if(check==0)
		{
//			cout<<"there is no people who has name "<<member_name<<endl;
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
//			cout<<"there is no people who has name "<<member_name<<endl;
			return 0;
		}
		member_faculty.at(temp).return_resource(resource_name,resource_type);
			cout<<"0	Success."<<endl;
			return 1;
	}
	else
	{
//		cout<<"member_type error "<<member_type<<endl;
		return 0;
	}

	if(resource_type=="Book")
	{
		resource_book.req_return(resource_name);
	}
	else if(resource_type=="Magazine")
	{
		resource_magazine.req_return(resource_name);
	}
	else if(resource_type=="E_book")
	{
		resource_ebook.req_return(resource_name);
	}
	else
	{
//		cout<<"resource type error 1"<<resource_type<<endl;
		return 0;
	}
}

int library :: input()
{
	ifstream read_input;
	read_input.open("input.dat");
//	cout<<"input start!"<<endl;
	int t=1;
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
	cout<<"Op_#	Return_code	Description"<<endl;
	do
	{
		resource_type.clear();
		read_input>>date>>resource_type>>resource_name>>operation>>member_type>>member_name;

	
		if(resource_type.size()!=0)
		{
//			cout<<"if station!"<<endl;
			cout<<t<<"	";
			t++;
			stringstream ss(date);
			int temp;
//			cout<<date<<endl;
			ss>>year;
			date.erase(0,3);
			ss.str(date);
			ss>>month;					
			date.erase(0,3);
			ss.str(date);
			ss>>day;
			
			if(operation=='B')
			{
//				cout<<"operation is B"<<endl;
				request_borrow(member_name,member_type,resource_name,resource_type,year,month,day);
			}
			else if(operation=='R')
			{					
//				cout<<"operation is R"<<endl;
				request_return(member_name,member_type,resource_name,resource_type,year,month,day);					
			}
			else
			{
//				cout<<"error"<<endl;
			}
		}
	}while(resource_type.size()!=0);

}		

