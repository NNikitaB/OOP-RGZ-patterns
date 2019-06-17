#include "pch.h"

#define N 4 //кол-во пар в день
#define M 5 //кол-во дней в неделю



enum Occupation
{
	LABORATORY,PRACTICE,LECTIRE
};

class Plan
{
public:
	Plan();
	~Plan();

private:

};
class Shedle;
class institite
{
	Base_group_student_teacher database;
	Shedle * my_sheld;
	Plan my_plan;
public:
	institite();
	~institite();
private:

};


class Singleton
{
public:
	Singleton& get_instatse() {
		static Singleton inst;
		return inst;
	}
	~Singleton()=default;

private:
	Singleton(Singleton*) = delete;
	Singleton &operator=(Singleton&) = delete;
	Singleton() = default;

};
class Room
{
	static int size;
	int nimber;
	int statis;
public:
	Room();
	~Room();

private:в

};

class Group
{
public:
	Group();
	~Group();

private:

};


class Sabject
{
	static int size;
	std::string name;
	int code;
};
class Teacher
{
	std::string name;
	Sabject * sbj;

public:
	Teacher();
	~Teacher();

private:

};

class Para
{
	Teacher * teacher;
	Room * room;
	Occupation iob;
	Group* group;
	Sabject * sbj;

public:
	Para()=default;
	Para(Teacher * teacher,Room * room,Occupation iob,Group* group,Sabject * sbj):teacher(teacher), room(room), iob(iob), group(group), sbj(sbj){}
	~Para() = default;

private:

};
class Day
{
	std::vector<Para> arr;
public:
	Day()=default;
	void add(Teacher * teacher, Room * room, Occupation iob, Group* group, Sabject * sbj) { Para par(teacher, room, iob, group, sbj); arr.push_back(par);  }
	void add(Para& par) { arr.push_back(par);  }
	Para& operator[](int i) { return arr[i];
 }
	~Day() { arr.clear(); };

private:

};
class Week
{
	std::vector<Day> arr;
public:
	Week() = default;
	void add(Day& day) { arr.push_back(day); }
	Day& operator[](int i) { return arr[i]; }
	~Week() { arr.clear(); };

private:

};
class Shedle
{
	Plan * plan;
	std::vector<Week> arr;

public:
	Shedle() = default;
	Shedle(Plan * plan):plan(plan){}
	void add(Week& week) { arr.push_back(week); }
	void add_plan(Plan * plan) { this->plan = plan; }
	Week& operator[](int i) { return arr[i]; }
	~Shedle() { arr.clear(); };

};
class Fitnsess
{
public:
	Fitnsess();
	~Fitnsess();

private:

};

class Base_group_student_teacher
{
	std::vector<Plan>plans;
	std::vector < Group >groups;
	std::vector < Teacher >teachers;
	std::vector < Room >rooms;

public:
	Base_group_student_teacher() = default;
	~Base_group_student_teacher() = default;

private:

};

int main()
{
    std::cout << "Hello World!\n"; 
}
