#include <iostream>
#include <vector>

using namespace std;
/*space room policy
1.time limit is 3 hours for all member
2. available time : 09 ~ 18
3. Maximum user : 6
4. No expiration by empty condition
*/
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
			for(int i=0;i<10;i++)
			{
				room_borrow[i]=0;
			
			}
			remain = 10;
	
		}
		int empty_space(int number)
		{

		}
		int comeback_space(int number)
		{


		}
	private:

		string room_member_type[10];
		string room_member_name[10];
		
		int room_borrow[10];	//0 is not borrow 1 is borrow
		int year[10];
		int month[10];
		int day[10];
		int hour[10];
		int remain;
		int end_hour[10];

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

		int check_space(string name,string type)
		{
			int size = borrow_name.size();
			for(int i=0;i<size;i++)
			{
				if(borrow_name.at(i)==name&& borrow_type.at(i)==type)
					return 11;
			}
			if(remain==0)
			{
				int t=24;
				for(int i=0;i<borrow_name.size();i++)
				{


				}
			}
			return 0;
		}
		int borrow_space(string name, string type,int member_number,int y,int m,int d,int h,int end_h)	
		{
			borrow_name.push_back(name);
			borrow_type.push_back(type);
			borrow_number.push_back(member_number);

		}
		int return_space(string name,string type, int room_number)
		{
			
		}
		int reset_space()
		{
		int size = borrow_size.size();
			borrow_type.erase(0,size);
			borrow_name.erase(0,size);
			empty.erase(0,size); // 0 is 자리비움 1 is not 자리비움
			empty_hour.erase(0,size);
			remain=50;
		}
		int check_empty(int hour)
		{
			for(int i=0;i<year.size();i++)
			{
				if(hour.at(i)!=hour)
				{
					remain++;
					hour.erase(i);
					month.erase(i);
					year.erase(i);
					day.erase(i);
					empty.erase(i);
					empty_hour.erase(i);
					borrow_name.erase(i);
					borrow_type.erase(i);
				}
				else
				{
					continue;
				}
			}

		}
		int empty_space(string name,string type,int hour)
		{
			int temp=0;
			for(;temp<borrow_time;temp++)
			{
				if(borrow_name.at(temp==name && borrow_type.at(temp)==type))
				{
					empty.at(temp) = 2;
					empty_hour.at(temp) = hour;
					return 0;
				}
			}

		}
		int comeback_space(string name,string type)
		{


		}
	private:
		vector<int> year,month,day,hour;
		vector<string> borrow_type;
		vector<string> borrow_name;
		vector<int> borrow_number;
		vector<int> empty; // 0 is not borrow 1 is borrow 2 is 자리비움
		vector<int> empty_hour;
		vector<int> end_hour;
		int remain;
}
