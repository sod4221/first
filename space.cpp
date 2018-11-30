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
		virtual int empty_space() = 0;
		virtual int comeback_space() = 0;
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
		
		int borrow_space(string name,string type,int room_number,int member_number,int y,int m,int d,int h,int end_h)	
		{
			if(room_borrow[room_number]==1)
			{
				return end_hour[room_number];
			}
			else
			{
				remain --;
				room_borrow[room_number]=1;
				room_borrow_name[room_number]=name;
				room_borrow_type[room_number]=type;
				year[room_number] = y;
				month[room_number] = m;
				day[room_number] = d;
				hour[room_number] = h;
				end_hour[room_number] = end_h;
				return 0;
			}
		}
		int return_space(string name,string type, int roome_number)
		{
			if(room_borrow[room_number]==0 || room_borrow_name[room_number]!=name || room_borrow_type[room_number]!=type)
			{
				return 10;
			}
			else
			{
				room_borrow[room_number]=0;
				return 0;

			}
		}
		int check_space(string name,string type)
		{
			for(int i=0;i<10;i++)
			{
				if(room_borrow[i]==1 && room_borrow_name[i]==name && room_borrow_type[i]==type)
					return -end_hour[i];
				else
					continue;
			}
			return 0;
		}
		int reset_space()
		{
			for(int i=0;i<10;i++)
			{
				room_borrow[i]=0;
			
			}
			remain = 10;
		}
		int empty_space(string name,string type,int number,int hour)
		{
			if(room_borrow[room_number]==0 || room_borrow_name[room_number]!=name || room_borrow_type[room_number]!=type)
			{
				return 10;
			}
			else{
				empty[number] = 1;
				return 0;
			}
		}
		int comeback_space(string name,string type,int number)
		{
			if(room_borrow[room_number]==0 || room_borrow_name[room_number]!=name || room_borrow_type[room_number]!=type)
			{
				return 10;
			}

			empty[number] = 0;
			return 0;

		}
	private:

		string room_member_type[10];
		string room_member_name[10];
		int empty[10];
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
				int temp = 24;
				for(int i=0;i<size;i++)
				{
					if(end_hour.at(i)>=0 && end_hour.at(i)<temp)
						temp = end_hour;
				}
				return -temp;
			}
			return 0;
		}
		int borrow_space(string name, string type,int member_number,int y,int m,int d,int h,int end_h)	
		{
			remain--;
			borrow_name.push_back(name);
			borrow_type.push_back(type);
			borrow_number.push_back(member_number);
			year.push_back(y);
			month.push_back(m);
			day.push_back(d);
			hour.push_back(h);
			empty.push_back(1);
			empty_hour.push_back(-1);
		}
		int return_space(string name,string type)
		{
			int temp=-1;
			for(int i=0;i<hour.size();i++)
			{
				if(borrow_name.at(i)==name && borrow_type.at(i)==type)
				{
					temp = i;
					break;
				}
			}
			if(temp ==-1)
			{
				return 10;
			}
			remain++;
			borrow_name.erase(temp);
			borrow_type.erase(temp);
			borrow_number.erase(temp);
			year.erase(temp);
			month.erase(temp);
			day.erase(temp);
			hour.erase(temp);
			empty.erase(temp);
			empty_hour.erase(temp);
			return 0;
		}

		int reset_space()
		{
			int size = borrow_size.size();
			borrow_type.erase(borrow_type.begin(),borrow_type.end());
			borrow_name.erase(borrow_name.begin(),borrow_name.end());
			empty.erase(empty.begin(),empty.end()); // 0 is 자리비움 1 is not 자리비움
			empty_hour.erase(empty_hour.begin(),empty_hour.end());
			remain=50;
		}
		int check_empty(int hour)
		{
			for(int i=0;i<year.size();i++)
			{
				if(empty_hour.at(i)!=hour&&empty.at(i)==2)
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
			return 0;
		}
		int empty_space(string name,string type,int hour)
		{
			int temp=-1;
			for(int i=0;i<hour.size();i++)
			{
				if(borrow_name.at(i)==name && borrow_type.at(i)==type)
				{
					temp = i;
					break;
				}
			}
			if(temp ==-1)
			{
				return 10;
			}
			temp = 0;
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
			int check=0;
			int temp=0;
			for(;temp<borrow_time;temp++)
			{
				if(borrow_name.at(temp)==name && borrow_type.at(temp)==type)
				{
					empty.at(temp) = 1;
					empty_hour.at(temp) = -1;
					return 0;
				}
			}
			if(check==0)
				return 10;

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
