#include <member.h>
#include <resource.h>
#include <library.h>

class library
{
	private:
		
		vector<undergraduate> member_undergraduate;
		vector<graduate> member_graduate;
		vector<faculty> member_faculty;
		book resourece_book;
		magazine resource_magazine;
		e_book resource_ebook;
		int undergraduate_number;
		int graduate_number;
		int faculty_number;
		int book_number;
		int magazine_number;
		int ebook_number;

	public:
		void init() //resource download
		{
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
		}
		void requst_borrow(string member_name,string member_type,string resource_name,strinig resource_type,int year,int month,int day)
		{
			int temp;
			int check=0;

			if(member_type=="Undergraduate")
			{
				for(temp=0;temp<undergraduate_number;temp++)
				{
					check = (member_undergraduate.at(temp)).check_name(member_name);
					if(check==1)
					{
						break;
					}
				}
				if((check<0)||check_delay(year,month,day)>=0)  //you already borrow something
				{
					cout<<"you can not borrow"<<endl;
					return -1;
				}
				if(check==0) //there is no reg
				{
					temp ++;
					undergraduate t;
					t.init(member_name);
					member_undergraduate.push_back(t);
				}
				if(resource_type=="Book")
				{
					if(resource_book.check_name(resource_name,year,month,day)==0)
					{
						return 0;
					}

				}
				else if(resource_type=="E_book")
				{
					if(resource_ebook.check_name(resource_name)==0)
					{
						cout<<"no resource"<<endl;
						return 0;
					}
				}
				else if(resource_type=="Magazine")
				{
					if(resource_magazine.check_name(resource_name)==0)
					{
						cout<<"no resource"<<endl;
					}
				}
				else
				{
					cout<<"resource type error"<<endl;
				}

					
			}
			else if(member_type=="Graduate")
			{

			}
			else if(member_type=="Faculty")
			{

			}
			else
			{
				cout<<"member_type error"<<endl;
			}

		}
		void request_return(string member_name,string member_type,string resource_name,string resource_type,int year,int month,int day)
		{


		}

		int input()
		{
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
						borrow(member_name,member_type,resource_name,resource_type,year,month,day);
					}
					else if(operation=='R')
					{					
						returned(member_name,member_type,resource_name,resource_type,year,month,day);					
					}
					else
					{
						cout<<"error"<<endl;
					}
				}
			}while(resource_type.size()!=0);
		}		
}
