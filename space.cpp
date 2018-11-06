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

class study_room : public space
{
	public:
		int borrow_space(int room_number, int time )	
		{

		}
		int return_space(int roome_number)
		{
			
		}
		int check_space()
		{

		}
		int reset_space()
		{



		}
	private:

		string room_member_type[10];
		string room_member_name[10];
		
		int room_borrow[10];
		int room_borrow_time[10];

};

/*Seat policy
1. Time limit max 3hours for 'undergraduate'
2. 1st floor is always
3. 2nd 09~21
4. 3rd 09~18
5. if the user don't come back in 1 hour, the seat expires
*/

class 	seat : public space
{	
	public:
	
		

	private:
		string borrow_type[50];
		string borrow_name[50];
		int borrow_time[50];
		int empty[50];
}
