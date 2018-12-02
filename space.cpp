#include "space.h"

int study_room:: borrow_space(string name,string type,int room_number,int member_number,int y,int m,int d,int h,int end_h)	
{
	if(room_borrow[room_number]==1)
	{
		return end_hour[room_number];
	}
	else
	{
		remain --;
		room_borrow[room_number]=1;
		room_member_name[room_number]=name;
		room_member_type[room_number]=type;
		year[room_number] = y;
		month[room_number] = m;
		day[room_number] = d;
		hour[room_number] = h;
		end_hour[room_number] = end_h;
		return 0;
	}
}
int study_room:: return_space(string name,string type, int room_number)
{
	if(room_borrow[room_number]==0 || room_member_name[room_number]!=name || room_member_type[room_number]!=type)
	{
		return 10;
	}
	else
	{
		room_borrow[room_number]=0;
		return 0;

	}
}
int study_room:: check_space(string name,string type)
{
	for(int i=0;i<10;i++)
	{
		if(room_borrow[i]==1 && room_member_name[i]==name && room_member_type[i]==type)
			return -end_hour[i];
		else
			continue;
	}
	return 0;
}
int study_room:: reset_space()
{
	for(int i=0;i<10;i++)
	{
		room_borrow[i]=0;
	
	}
	remain = 10;
}
int study_room:: empty_space(string name,string type,int number)
{
	if(room_borrow[number]==0 || room_member_name[number]!=name || room_member_type[number]!=type)
	{
		return 10;
	}
	else{
		empty[number] = 1;
		return 0;
	}
}
int study_room:: comeback_space(string name,string type,int number)
{
	if(room_borrow[number]==0 || room_member_name[number]!=name || room_member_type[number]!=type)
	{
		return 10;
	}

	empty[number] = 0;
	return 0;

}
/*Seat policy
1. Time limit max 3hours for 'undergraduate'
2. 1st floor is always
3. 2nd 09~21
4. 3rd 09~18
5. if the user don't come back in 1 hour, the seat expires
*/

int seat:: check_space(string name,string type)
{
	int size = borrow_name.size();
	for(int i=0;i<size;i++)
	{
		if(borrow_name.at(i)==name && borrow_type.at(i)==type)
			return 11;
	}
	if(remain==0)
	{
		int temp = 24;
		for(int i=0;i<size;i++)
		{
			if(end_hour.at(i)>=0 && end_hour.at(i)<temp)
				temp = end_hour.at(i);
		}
		return -temp;
	}
	return 0;
}
int seat:: borrow_space(string name, string type,int member_number,int y,int m,int d,int h,int end_h)	
{
	cout<<"seat borrow!!"<<endl;
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
	return 0;
}
int seat:: return_space(string name,string type)
{
	int temp=-1;
	for(int i=0;i<50-remain;i++)
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
	borrow_name.erase(borrow_name.begin()+temp);
	borrow_type.erase(borrow_type.begin()+temp);
	borrow_number.erase(borrow_number.begin()+temp);
	year.erase(year.begin()+temp);
	month.erase(month.begin()+temp);
	day.erase(day.begin()+temp);
	hour.erase(hour.begin()+temp);
	empty.erase(empty.begin()+temp);
	empty_hour.erase(empty_hour.begin()+temp);
	return 0;
}

int seat:: reset_space()
{
	cout<<"reset!"<<endl;
	borrow_type.erase(borrow_type.begin(),borrow_type.end());
	borrow_name.erase(borrow_name.begin(),borrow_name.end());
	empty.erase(empty.begin(),empty.end()); // 0 is 자리비움 1 is not 자리비움
	empty_hour.erase(empty_hour.begin(),empty_hour.end());
	remain=50;

	return 0;
}
int seat:: check_empty(int h)
{
	cout<<"check empty remain"<<remain<<endl;
	for(int temp=0;temp<50-remain;temp++)
	{
		cout<<temp;
		if(empty_hour.at(temp)!=h&&empty.at(temp)==2)
		{
			remain++;
			borrow_name.erase(borrow_name.begin()+temp);
			borrow_type.erase(borrow_type.begin()+temp);
			borrow_number.erase(borrow_number.begin()+temp);
			year.erase(year.begin()+temp);
			month.erase(month.begin()+temp);
			day.erase(day.begin()+temp);
			hour.erase(hour.begin()+temp);
			empty.erase(empty.begin()+temp);
			empty_hour.erase(empty_hour.begin()+temp);
		}
		else
		{
			continue;
		}
	}
	cout<<endl;
	return 0;
}
int seat:: empty_space(string name,string type,int h)
{
	cout<<"empty_space"<<endl;
	int temp=-1;
	for(int i=0;i<50-remain;i++)
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
	for(;temp<50-remain;temp++)
	{
		if(borrow_name.at(temp)==name && borrow_type.at(temp)==type)
		{
			empty.at(temp) = 2;
			empty_hour.at(temp) = h;
			return 0;
		}
	}

}
int seat:: comeback_space(string name,string type)
{
	int check=0;
	int temp=0;
	for(;temp<50-remain;temp++)
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

