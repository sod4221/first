#include <iostream>
#include <vector>

const int space_number = 10;
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
		int borrow_space(string name,string type,int room_number,int member_number,int y,int m,int d,int h,int end_h);
		int return_space(string name,string type,int room_number);

		int check_space(string name,string type);

		int reset_space();

		int empty_space(string name,string type,int number,int hour);

		int comeback_space(string name,string type,int number);

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
		int check_space(string name,string type);
		int borrow_space(string name, string type,int member_number,int y,int m,int d,int h,int end_h);
		int return_space(string name,string type);
		int reset_space();
		int check_empty(int hour);
		int empty_space(string name,string type,int hour);
		int comeback_space(string name,string type);
	private:
		vector<int> year,month,day,hour;
		vector<string> borrow_type;
		vector<string> borrow_name;
		vector<int> borrow_number;
		vector<int> empty; // 0 is not borrow 1 is borrow 2 is 자리비움
		vector<int> empty_hour;
		vector<int> end_hour;
		int remain;

};
