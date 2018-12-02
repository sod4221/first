#include "library.h"


void library :: init() //resource download
{
//	freopen("output.dat","w",stdout);
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

int library ::space_borrow(string space_type,int space_number,string member_type,string member_name,int member_number,int year,int month,int day,int hour,int time)
{
	int end_hour;
	int check = 0;
	
	
	if(space_type =="StudyRoom")
	{
		if(space_number<0 || space_number>10){
			cout<<"8	Invalid space Id."<<endl;
			return -1;
		}
		if(hour<9 || hour>=18){
			cout<<"9	This space is not available now. Available form 09 to 18"<<endl;
			return -1;
		}
		check = studyroom.check_space(member_name,member_type);
		if(check==11){
			cout<<"11	You already borrowed this kind of space."<<endl;
			return -1;
		}
		if(member_number>6)
		{
			cout<<"12	Exceed available number."<<endl;
			return -1;
		}
		if(time>3)
		{
			cout<<"13 Exceed available time."<<endl;
			return -1;
		}
		end_hour = hour+time;
		if(end_hour>18)
			end_hour=18;
		check = studyroom.borrow_space(member_name,member_type,space_number,member_number,year,month,day,hour,end_hour);
		if(check!=0)
		{
			cout<<"14 there is no remain space. This space is available after "<<check<<"."<<endl;
			return -1;
		}
		else
		{
			cout<<"0	Success."<<endl;
			return 0;
		}
	}
	else if(space_type =="Seat")
	{
		if(space_number==1)
		{
			check = first_seat.check_space(member_name,member_type);
			if(check==11){
				cout<<"11	You already borrowed this kind of space."<<endl;
				return 0;
			}
			if(member_number>1)
			{
				cout<<"12	Exceed available number."<<endl;
				return 0;
			}
			if(member_type=="Undergraduate" && time > 3)
			{
				cout<<"13 Exceed available time."<<endl;
				return 0;
			}
			if(check<0)
			{
				cout<<"14 there is no remain space. This space is available after "<<-check<<"."<<endl;
				return 0;
			}
			end_hour = hour+time;
			if(end_hour>24)
				end_hour=24;
			check = first_seat.borrow_space(member_name,member_type,member_number,year,month,day,hour,hour+time);

		}
		else if(space_number==2)
		{	

			if(hour<9 || hour>=21)
			{
				cout<<"9	This space is not available now. Available form 09 to 21"<<endl;
				return 9;
			}
				
			else
			{
				check = second_seat.check_space(member_name,member_type);

				if(check==11)
					cout<<"11	You already borrowed this kind of space."<<endl;
		
				if(member_number>1)
				{
					cout<<"12	Exceed available number."<<endl;
					return 0;
				}
				if(member_type=="Undergraduate" && time > 3)
				{
					cout<<"13 Exceed available time."<<endl;
					return 0;
				}
				if(check<0)
				{
					cout<<"14 there is no remain space. This space is available after "<<-check<<"."<<endl;
					return 0;
				}
	
			}
			end_hour = hour+time;
			if(end_hour>21)
				end_hour=21;
			check = second_seat.borrow_space(member_name,member_type,member_number,year,month,day,hour,hour+time);

	
		}
		else if(space_number==3)
		{

			if(hour<9 || hour>=21)
			{
				cout<<"9	This space is not available now. Available form 09 to 21"<<endl;
				return 9;
			}
			else
			{
				check = third_seat.check_space(member_name,member_type);

				if(check==11)
					cout<<"11	You already borrowed this kind of space."<<endl;
				if(member_number>1)
				{
					cout<<"12	Exceed available number."<<endl;
					return 0;
				}
	
				if(member_type=="Undergraduate" && time > 3)
				{
					cout<<"13 Exceed available time."<<endl;
					return 0;
				}
				if(check<0)
				{
					cout<<"14 there is no remain space. This space is available after "<<-check<<"."<<endl;
					return 0;
				}
			}
	
			end_hour = hour+time;
			if(end_hour>18)
				end_hour=18;
			check = third_seat.borrow_space(member_name,member_type,member_number,year,month,day,hour,hour+time);
		}
		else
		{
			cout<<"8	Invalid space Id."<<endl;
				return 0;
		}

	}
	else
	{
		cout<<"ERROR"<<endl;
	}

}

int library ::space_return(string space_type,int space_number,string member_type,string member_name,int member_number)
{
	int check;
	if(space_type =="StudyRoom")
	{
		if(space_number<0 || space_number >10)
		{
			cout<<"8	Invalid space Id."<<endl;
			return -1;
		}
		check=studyroom.return_space(member_name,member_type,space_number);
		if(check!=0){
			cout<<"10	You did not borrow this place"<<endl;
			return -1;
		}
		else
		{
			return 0;
			cout<<"0	Success."<<endl;
		}	
	}
	else if(space_type=="Seat")
	{

		if(space_number==1)
		{
			check = first_seat.return_space(member_name,member_type);
			if(check!=0)
			{

				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}

			return 0;
		}
		else if(space_number==2)
		{
			check = first_seat.return_space(member_name,member_type);
			if(check!=0)
			{

				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			return 0;
		}
		else if(space_number==3)
		{
			check = first_seat.return_space(member_name,member_type);
			if(check!=0)
			{

				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			return 0;
		}
		else
		{

			cout<<"8	Invalid space Id."<<endl;
			return -1;
		}
	}
	else
	{
		cout<<"ERROR"<<endl;
		return -1;
	}

}
int library ::space_empty(string space_type,int space_number, string member_name, string member_type,int hour)
{
	int check;
	if(space_type=="Seat")
	{
		if(space_number==1)
		{
			check = first_seat.empty_space(member_name,member_type,hour);
				if(check==10)
			{
				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			else
			{
				cout<<"0	Success."<<endl;
			}

		}
		else if(space_number==2)
		{

			check = first_seat.empty_space(member_name,member_type,hour);
					if(check==10)
			{
				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			else
			{
				cout<<"0	Success."<<endl;
			}

		}
		else if(space_number==3)
		{

			check = first_seat.empty_space(member_name,member_type,hour);
			if(check==10)
			{
				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			else
			{
				cout<<"0	Success."<<endl;
			}

		}
		else
		{
			cout<<"8	Invalid space Id."<<endl;
			return 0;
		}
	}
	else if(space_type=="StudyRoom")
	{
		if(space_number<0 || space_number >10)
		{
			cout<<"8	Invalid space Id."<<endl;
			return -1;
		}
		else
		{
			check = studyroom.empty_space(member_name,member_type,hour);
			if(check==10)
			{
				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			else
			{
				cout<<"0	Success."<<endl;
			}

		}
	}
	else
	{
		cout<<"ERROR"<<endl;
		return -1;
	}
	return 0;

}
int library ::space_comeback(string space_type,int space_number, string member_name, string member_type)
{
	int check = 0;
	if(space_type=="Seat")
	{
		if(space_number==1)
		{
			check = first_seat.comeback_space(member_name,member_type);	
			if(check==10)
			{
				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			else
			{
				cout<<"0	Success."<<endl;
			}

		}
		else if(space_number==2)
		{
			check = second_seat.comeback_space(member_name,member_type);	
			if(check==10)
			{
				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			else
			{
				cout<<"0	Success."<<endl;
			}


		}
		else if(space_number==3)
		{
			check = third_seat.comeback_space(member_name,member_type);	
			if(check==10)
			{
				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			else
			{
				cout<<"0	Success."<<endl;
			}


		}
		else
		{
			cout<<"8	Invalid space Id."<<endl;
			return 0;
		}
	
	}
	else if(space_type=="StudyRoom")
	{
		if(space_number<0 || space_number >10)
		{
			cout<<"8	Invalid space Id."<<endl;
			return 0;
		}
		else
		{
			check = studyroom.comeback_space(member_name,member_type,space_number);	

			if(check==10)
			{
				cout<<"10	You did not borrow this place."<<endl;
				return -1;
			}
			else
			{
				cout<<"0	Success."<<endl;
			}
		}
	
	}
	else
	{
		cout<<"ERROR"<<endl;
	}

}
int library ::space_reset()
{
	cout<<"reset!"<<endl;
	first_seat.reset_space();
	second_seat.reset_space();
	third_seat.reset_space();
	studyroom.reset_space();

}
int library :: input()
{
	int t = 1;
	int year,month,day,hour,s_number,sm_number,borrow_time;
	int b_year,b_month,b_day,b_hour;
	string date,r_type,r_name,m_type,m_name;
	string s_type;
	char op;
	
	vector<string> space_type,smember_type,smember_name;
	vector<int> space_year,space_month,space_day,space_hour,space_number,smember_number,space_time;
	vector<char> space_operation;
	
	vector<string>resource_type,resource_name,member_type,member_name;
	vector<int> resource_year,resource_month,resource_day;
	vector<char> resource_operation;
	
	ifstream read_input;
	ifstream read_space;
	read_input.open("input.dat");
	read_space.open("space.dat");
	
	read_input>>date>>r_type>>r_name>>m_type>>m_type>>m_name;
	for(int i=0;i<8;i++)
		read_space>>date; 
		
	cout<<"Op_#	Return_code	Description"<<endl;
	
	do //resource input
	{
		r_type.clear();
		read_input>>date>>r_type>>r_name>>op>>m_type>>m_name;
	
		if(r_type.size()!=0)
		{
			stringstream ss(date);
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
			resource_day.push_back(day);
			resource_type.push_back(r_type);
			resource_name.push_back(r_name);
			member_type.push_back(m_type);
			member_name.push_back(m_name);
			resource_operation.push_back(op);
		}
	}while(r_type.size()!=0);
	cout<<"read resource"<<endl;	
	
	do
	{
		s_type.clear();
		read_space>>date>>s_type>>s_number>>op>>m_type>>m_name;
		if(s_type.size()!=0)
		{
	//		cout<<"space!!"<<endl<<date<<s_type<<s_number<<" "<<op<<" "<<m_type<<m_name;

			stringstream ss(date);
			int temp;
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
			space_operation.push_back(op);
			smember_type.push_back(m_type);
			smember_name.push_back(m_name);
			if(op=='B'){
				read_space>>sm_number>>borrow_time;
				smember_number.push_back(sm_number);
				space_time.push_back(borrow_time);
			}
			else
			{
				smember_number.push_back(-1);
				space_time.push_back(-1);
			}
		cout<<smember_number.back()<<space_time.back()<<endl;
		}
	}while(s_type.size()!=0);

	cout<<"Read space"<<endl;
	
	do
	{

		int check = 0;
		if(space_year.size()==0 && resource_year.size()!=0)
			goto resource;
		else if(space_year.size()!=0 && resource_year.size()==0)
			goto space;
		else if(space_year.size()==0 && resource_year.size()==0)
			break;
		else{
		}


	read_input.close();
	read_space.close();
	

			//space first start
		if(resource_year.at(0)<=space_year.at(0))
			check = 1;
		if(resource_year.at(0)==space_year.at(0)&&resource_month.at(0)<=space_month.at(0))
			check = 1;				
		if(resource_year.at(0)==space_year.at(0)&&resource_month.at(0)==space_month.at(0)&&resource_day.at(0)<=space_day.at(0))
			check = 1;
		if(check == 1)	//resource start
		{
			cout<<"resource!!"<<endl;
			resource:
			cout<<t<<"	";
			t++;
			cout<<member_name.at(0)<<member_type.at(0)<<resource_name.at(0)<<resource_type.at(0)<<resource_year.at(0)<<resource_month.at(0)<<resource_day.at(0);

			if(resource_operation.at(0)=='B')
			{
				request_borrow(member_name.at(0),member_type.at(0),resource_name.at(0),resource_type.at(0),resource_year.at(0),resource_month.at(0),resource_day.at(0));

			}
			else if(resource_operation.at(0)=='R')
			{
				request_return(member_name.at(0),member_type.at(0),resource_name.at(0),resource_type.at(0),resource_year.at(0),resource_month.at(0),resource_day.at(0));
			}
			else
			{
				cout<<"ERROR"<<endl;
			}
			//pop
			cout<<resource_year.at(0)<<resource_month.at(0)<<resource_day.at(0)<<endl;
			member_name.erase(member_name.begin());
			member_type.erase(member_type.begin());
			resource_name.erase(resource_name.begin());
			resource_type.erase(resource_type.begin());
			resource_year.erase(resource_year.begin());
			resource_month.erase(resource_month.begin());
			resource_day.erase(resource_day.begin());
			resource_operation.erase(resource_operation.begin());
		}
		//resource start
		else
		{
			cout<<"space!!"<<endl;
			space:
			cout<<t<<"	";
			t++;
			if(space_year.at(0)!=b_year || space_month.at(0)!=b_month || space_day.at(0)!=b_day)
			{	//초기화

				cout<<"reset in library"<<endl;
				space_reset();
				b_year = year;
				b_month = month;
				b_day = day;
			}
			
			if(b_hour != space_hour.at(0))
			{
				cout<<"empty reset!"<<endl;
				first_seat.check_empty(hour);
				second_seat.check_empty(hour);
				third_seat.check_empty(hour);
				b_hour = hour;
			}
	
	
			if(space_operation.at(0)=='B')
			{
				cout<<"borrow"<<endl;
				space_borrow(space_type.at(0),space_number.at(0),smember_type.at(0),smember_name.at(0),smember_number.at(0),space_year.at(0),space_month.at(0),space_day.at(0),space_hour.at(0),space_time.at(0));
			}
			else if(space_operation.at(0)=='R')
			{
				cout<<"return"<<endl;
				space_return(space_type.at(0),space_number.at(0),smember_type.at(0),smember_name.at(0),smember_number.at(0));
			}
			else if(space_operation.at(0)=='E')
			{	
				cout<<"Empty!"<<endl;
				space_empty(space_type.at(0),space_number.at(0),smember_name.at(0),smember_type.at(0),space_hour.at(0));
			}
			else if(space_operation.at(0)=='C')
			{
				cout<<"comeback"<<endl;
				space_comeback(space_type.at(0),space_number.at(0),smember_name.at(0),smember_type.at(0));
			}
			else
			{
				cout<<"ERROR"<<endl;
			}			
			space_year.erase(space_year.begin());
			space_month.erase(space_month.begin());
			space_day.erase(space_day.begin());
			space_hour.erase(space_hour.begin());
			space_type.erase(space_type.begin());
			space_number.erase(space_number.begin());
			space_operation.erase(space_operation.begin());
			smember_type.erase(smember_type.begin());
			smember_name.erase(smember_name.begin());
			smember_number.erase(smember_number.begin());
			space_time.erase(space_time.begin());
		}
	}while(resource_year.size()!=0||space_year.size()!=0);

	return 0;
}		

