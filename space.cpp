#include <iostream>
#include <vector>

using namespace std;
/*space room policy
1.time limit is 3 hours for all member
2. available time : 09 ~ 18
3. Maximum user : 6
4. No expiration by empty condition
*/

class space_time
{
	private:
		int year;
		int month;
		int day;
		int hour;

	public:
		void insert(int y,int m,int d,int h)
		{
			year=y;
			month=m;
			day=d;
			hour =h;
		}
		int check(int y,int m,int d,int h)
		{
			int check=0;

			if(year!=y)
				check = 0;
			if(month!=m)
				check = 0;
			if(day!=d)
				check = 0;
	

			
		}


}
class space
{
	public:
		virtual	int borrow_space() = 0;
		virtual	int return_space() = 0;
		virtual	int check_space() = 0;
		virtual	int reset_space() = 0; // when 24:00 reset all space
};
/*space room policy
1.time limit is 3 hours for all member
2. available time : 09 ~ 18
3. Maximum user : 6
4. No expiration by empty condition
*/
class study_room : public space
{
	public:
		
		void init()
		{
			remain = 10;
			for(int i=0;i<10;i++)
			{
				room_borrow[i]=0;

			}
		}


		int borrow_space(string name, string type,int room_number, int time )	
		{

		}
		int return_space(string name,string type, int roome_number)
		{
			
		}
		int check_space(string name,string type)
		{

		}
		int reset_space()
		{
			

		}
	private:

		string room_member_type[10];
		string room_member_name[10];
		
		int room_borrow[10];
		space_time borrow_time[10];
		int remain;
};

/*Seat policy
1. Time limit max 3hours for 'undergraduate'
2. 1st floor is always
3. 2nd 09~21
4. 3rd 09~18
5. if the user don't come back in 1 hour, the seat expires
*/

class seat : public space
{	
	public:

		void init()
		{
			remain = 50;
		}
		void clear(space_time time,int start,int end)
		{
			int size = borrow_size.size();
			borrow_time.erase(0,size);
			borrow_type.erase(0,size);
			borrow_name.erase(0,size);
			empty.erase(0,size); // 0 is not borrow 1 is borrow 2 is 자리비움
			empty_hour.erase(0,size);
			remain=50;

		}
		int check_seat(string name,string type,int y,int m,int d,int h)
		{
			int size = borrow_name.size();
			for(int i=0;i<size;i++)
			{

			}
			for(int i=0;i<size;i++)
			{
				if(borrow_name.at(i)==name&& borrow_type.at(i)==type)
					return 11;
			}
			return 0;
		}
		int borrow_space(string name, string type,int room_number,int member_number,int y,int m,int d,int h)	
		{
			if(remain==0)
				return 12;

		}
		int return_space(string name,string type, int roome_number)
		{
			
		}
		int check_space(string name,string type)
		{

		}
		int reset_space()
		{
			

		}
	
	private:
		vector<space_time> borrow_time;
		vector<string> borrow_type;
		vector<string> borrow_name;
		vector<int> empty; // 0 is not borrow 1 is borrow 2 is 자리비움
		vector<int> empty_hour;
		int remain;
}
