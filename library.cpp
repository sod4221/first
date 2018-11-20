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
int library :: space_input()
{
/*	ifstream read_input;
	read_input.open("space.dat");
	int year,b_year;
	int month,b_month;
	int day,b_day;
	int time;
	string date;
	string space_type;
	string space_number;
	char operation;
	int member_number,time;
	string member_type;
	string member_name;
	for(int i=0;i<7;i++)
		read_input>>date; //
	cout<<"Op_#	Return_code Description"<<endl;
	do
	{
		member_name.clear();
		read_input>>date>>space_type>>space_number>>operation>>member_type>>member_name;
		if(member_name.size()!=0){
			cout<<t<<"	";
			t++;
			stringstream ss(date);
			ss>>year;
			date.erase(0,3);
			ss.str(date);
			ss>>month;					
			date.erase(0,3);
			ss.str(date);
			ss>>day;
			date.erase(0,3);
			ss.str(date);
			ss>>hour;

			if(operation=="B")
			{
				read_input>>member_number>>time;

				if(space_type=="Seat")
				{
					if(space_number==1)
					{
						if(year!=d_year || month!=d_month || day!=d_day)
							//초기화
						
					}
					else if(space_number==2)
					{	
						if(year!=d_year || month!=d_month || day!=d_day)
							//초기화

						if(hour<9 || hour>=21)
							cout<<"9	This space is not available now. Available form 09 to 18"<<endl;
						else
						{


						}
					}
					else if(space_number==3)
					{
						if(year!=d_year || month!=d_month || day!=d_day)
							//초기화

						if(hour<9 || hour>=21)
							cout<<"9	This space is not available now. Available form 09 to 18"<<endl;
						else
						{


						}

					}
					else{
						cout<<"8	Invalid space Id."<<endl;
					}

				}
				else if(space_type=="Studyroom")
				{


				} 
				else
				{
					cout<<"type error"<<endl;
				}
			}
			else if(operation=="R")
			{

			}
			else if(operation =="E")
			{

			}
			else if(operation=="C")
			{

			}
		}
	}
	while(member_name.size()!=0)
*/
}
int library :: input()
{
	int t=0;
	ifstream read_input;
	ifstream read_space;
	read_input.open("input.dat");
	read_sapce.open("space.dat");
	vector<string>resource_type,resource_name,member_type,member_name;
	vector<int> resource_year,resource_month,resource_day;
	vector<char> resource_operation;
	read_input>>date>>resource_type>>resource_name>>member_type>>member_type>>member_name;
	for(int i=0;i<8;i++)
		read_space>>date; 
	cout<<"Op_#	Return_code	Description"<<endl;
	int year,month,day,hour,s_number,sm_number,borrow_time;
	string d,r_type,r_name,m_type,m_name;
	string s_type;
	char op;
	do //resource input
	{
		r_type.clear();
		read_input>>d>>r_type>>r_name>>op>>m_type>>m_name;

	
		if(resource_type.size()!=0)
		{
			t++;
//			cout<<"if station!"<<endl;
			cout<<t<<"	";
			stringstream ss(d);
			int temp;
//			cout<<date<<endl;
			ss>>year;
			year += 2000;
			date.erase(0,3);
			ss.str(date);
			ss>>month;					
			date.erase(0,3);
			ss.str(date);
			ss>>day;
			resource_year.push_back(year);
			resource_month.push_back(month);
			resource_day.push_back((day);
			resource_type.push_back(r_type);
			resource_name.push_back(r_name);
			member_type.push_back(m_type);
			member_name.push_back(m_name);
			resource_operation.push_back(op);
		}
	}while(r_type.size()!=0);
	vector<string> space_type,smember_type,smember_name;
	vector<int> space_year,space_month,space_day,space_hour,space_number,smember_number,space_time;
	vector<char> space_operation;
	int defore_year,defore_month,defore_day,defor_hour;
	do
	{
		s_type.clear();
		read_space>>d>>s_type>>s_number>>op>>m_type>>m_name;
	
		if(s_type.size()!=0)
		{
			t++;
//			cout<<"if station!"<<endl;
			cout<<t<<"	";
			stringstream ss(d);
			int temp;
//			cout<<date<<endl;
			ss>>year;
			date.erase(0,5);
			ss.str(date);
			ss>>month;					
			date.erase(0,3);
			ss.str(date);
			ss>>day;
			date.erase(0,3);
			ss.str(date);
			ss>>hour;
			space_year.push_back(year);
			space_month.push_back(month);
			space_day.push_back(day);
			space_hour.push_back(hour);
			space_type.push_back(s_type);
			space_number.push_back(s_number);
			resource_operation.push_back(op);
			smember_type.push_back(m_type);
			smember_name.push_back(m_name);
			if(op=="B"){
				cout>>sm_number>>borrow_time;
				smember_number.push_back(sm_number);
				space_time.push_back(borrow_time);
			}
			else
			{
				smember_number.push_back(-1);
				space_time.push_back(-1);
			}

		}
	}while(s_type.size()!=0);
	int t = 1;
	do
	{

		if(space_year.size()==0 && resource_year.size()!=0)
			goto resource;
		else if(space_year.size()!=0 && resource_year.size()==0)
			goto space;
		else if(space_year.size()==0 && resource_year.size()==0)
			goto end;
		else{
		}
	
			//space first start
		if(space_year.front()<=resource_year.front() && space_month.front()<=resource_month.front() && space_day.front()<=resource_day.front())
		{
			resource:
			cout<<t<<"	";
			t++;
			if(resource_operation.front()=="B")
			{
				request_borrow(member_name.front(),member_type.front(),resource_name.fornt(),resource_type.front(),resource_year.front(),resource_month.front(),resource_day.front());

			}
			else if(resource_operation.front()=="R")
			{

				request_return(member_name.front(),member_type.front(),resource_name.fornt(),resource_type.front(),resource_year.front(),resource_month.front(),resource_day.front());


			}
			else
			{
				cout<<"ERROR"<<endl;
			}
			//pop
			member_name.pop();
			member_type.pop();
			resource_name.pop();
			resource_type.pop();
			resource_year.pop();
			resource_month.pop();
			resource_day.pop();



		}
		//resource start
		else
		{
				space:
				cout<<t<<"	";
				t++;
				if(space_type.front()=="Studyroom")
				{

					if(space_number.front()<0 || space_number.front()>10){
						cout<<"8	Invalid space Id."<<endl;
						return 0;
					}

					if(space_hour.front()<9 || space_hour.front()>=18){
						cout<<"9	This space is not available now. Available from 09 to 18."<<endl;
						return 0;
					}
					if(space_operation.front()=="B")
					{

						if(smemeber_number.front()>6)
						{
							cout<<"12 Exceed available number."<<endl;
							return 0;
						}
						if(borrow_time.front()>3)
						{
							cout<<"13 Exceed available time."<<endl;
							return 0;
						}

						cout<<"0	Success."<<endl;

					}
					else if(space_operation.front()=="R")
					{


					}
					else if(space_operation.front()=="E")
					{


					}
					else if(space_operation.front()=="C")
					{


					}
					else
					{
						cout<<"ERROR"<<endl;
					}
				}

				else if(space_type.front()=="Seat")
				{
					if(space_number.front()==1)
					{
						if(space_operation.front()=="B")
						{

						}
						else if(space_operation.front()=="R")
						{

						}
						else if(space_operation.front()=="E")
						{

						}
						else if(space_operation.front()=="C")
						{

						}
						else
						{
							cout<<"ERROR"<<endl;
						}

					}
					else if(space_number.front()==2)
					{
						if(space_hour.front()<9 || space_hour.front()>=21){
							cout<<"9	This space is ont available now. Available from 09 to 18."<<endl;
							return 0;
						}
						if(space_operation.front()=="B")
						{

						}
						else if(space_operation.front()=="R")
						{

						}
						else if(space_operation.front()=="E")
						{

						}
						else if(space_operation.front()=="C")
						{

						}
						else
						{
							cout<<"ERROR"<<endl;
						}

					}
					else if(space_number.front()==3)
					{
						if(space_hour.front()<9 || space_hour.front()>=18){
							cout<<"9	This space is ont available now. Available from 09 to 18."<<endl;
							return 0;
						}
						if(space_operation.front()=="B")
						{
			

						}
						else if(space_operation.front()=="R")
						{


						}
						else if(space_operation.front()=="E")
						{


						}
						else if(space_operation.front()=="C")
						{


						}
						else
						{
							cout<<"ERROR"<<endl;
						}
					}
					else
					{
						cout<<"8	Invalid space Id."<<endl;
						return 0
					}
				

				}
						cout<<"0	Success."<<endl;
			}
end:

	}
	while(resource_year.size()!=0||space_year.size()!=0)


}		

