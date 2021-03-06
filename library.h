#include "member.h"
#include "resource.h"
#include "space.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


class library
{
	private:
		seat first_seat,second_seat,third_seat;
		study_room studyroom;
		vector<undergraduate> member_undergraduate;
		vector<graduate> member_graduate;
		vector<faculty> member_faculty;
		book resource_book;
		magazine resource_magazine;
		e_book resource_ebook;
		int undergraduate_number;
		int graduate_number;
		int faculty_number;
		int book_number;
		int magazine_number;
		int ebook_number;
		int b_year,b_month,b_day,b_hour;	
	public:	
		void init();
		int input();
		int request_borrow(string member_name,string member_type,string resource_name,string resource_type,int year,int month,int day);
		int request_return(string member_name,string member_type,string resource_name,string resource_type,int year,int month,int day);

		int space_comeback(string space_type,int space_number, string member_name, string member_type);

		int space_empty(string space_type,int space_number, string member_name, string member_type,int hour);

		int space_return(string space_type,int space_number,string member_type,string member_name,int member_number);

		int space_borrow(string space_type,int space_number,string member_type,string member_name,int member_number,int year,int month,int day,int hour,int time);

		int space_reset();
};
