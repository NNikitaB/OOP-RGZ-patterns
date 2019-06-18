#include "pch.h"

#define N 4 //кол-во пар в день
#define M 5 //кол-во дней в неделю

//std::ostream& operator<<(std::ostream& s, std::string& n) { return std::cout << n; }

enum Occupation
{
	LABORATORY,PRACTICE,LECTIRE
};

class Sabject
{
	std::string name;
	int code;
	int lab;
	int pr;
	int lec;
public:
	Sabject(std::string name, int code):name(name), code(code){}
	Sabject(std::string name, int code, int lab,int pr,int lec):name(name), code(code), lab(lab), pr(pr),lec(lec){}
	Sabject() = default;
	void Show() { std::cout << "name " << name << " code" << " lab" << lab << "pr" << pr << "lec" << lec; }
	void operator=(Sabject&a) { this->name = a.name; this->code = a.code; this->lab = a.lab;this->pr = a.pr; this->lec = a.lec;	}
};

class Plan
{
	std::vector<Sabject > p;
	int id;
	std::string name;

public:
	Plan() = default;
	Plan(std::string &name_group, int id_group) :name(name_group), id(id_group){}
	~Plan() = default;
	void add(std::string name_Sabject, int code_Sabject, int lab, int pr, int lec)
	{
		Sabject sab(name_Sabject, code_Sabject, lab, pr, lec);
		p.push_back(sab);
	}
	void Show() { std::cout << "plan :" << name << " id " << id <<std::endl; }

private:

};
class Shedle;

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
	int nimber;
	int statis;
public:
	Room() = default;
	Room(int nim,int stat):nimber(nim),statis(stat){}
	~Room() = default;
	void Show() { std::cout << "№ " << nimber << " statis " << statis <<std::endl; }


};

class Group
{
	int id;
	std::string name;
	std::vector<std::string> names;
public:
	Group() = default;
	Group(int id,std::string &name):id(id),name(name){}
	void add(std::string & name) { names.push_back(name); }
	void Show() {
		std::cout << "Group " << name << "id=" << id << std::endl;
		for (auto it = names.begin(); it != names.end(); it++) std::cout << *it << std::endl; 
	}
	~Group() = default;

private:

};



class Teacher
{
	std::string name;
	Sabject * sbj;

public:
	void Show() { std::cout << "teacher " << name << " Sabject"; sbj->Show(); std::cout << std::endl; }
	Teacher()=default;
	Teacher(std::string name, Sabject * sbj):name(name),sbj(sbj){}
	~Teacher() { //delete sbj;
	}

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
	void Show() {
		teacher->Show(); room->Show(); std::cout << "Occupation ";
		switch (iob)
		{
		case LABORATORY:std::cout << "LAB ";
			break;
		case PRACTICE:std::cout << "PR ";
			break;
		case LECTIRE:std::cout << "LEC";
			break;
		default:std::cout << "NONE";
			break;
		}
		group->Show();  std::cout << "Sabjec "; sbj->Show();
	}
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
	Para& operator[](int i) { return arr[i]; }
	void Show() { for (auto it = arr.begin(); it != arr.end(); it++)it->Show(); }
 
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
	void Show() { for (auto it = arr.begin(); it != arr.end(); it++)it->Show(); }
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
	void Show() { for (auto it = arr.begin(); it != arr.end(); it++)it->Show(); }
	~Shedle() { arr.clear(); };

};
class Fitnsess
{
public:
	Fitnsess();
	~Fitnsess();

private:

};
class data_base {
public:
	data_base() = default;
	~data_base() = default;
	//virtual int operator[](int i)
	virtual int size() = 0;
};
class Base_group_student_teacher
{
	std::vector<Plan>plans;
	std::vector < Group >groups;
	std::vector < Teacher >teachers;
	std::vector < Room >rooms;
	std::vector < Sabject >sbj;

public:
	void add_plan(Plan &plan) { plans.push_back(plan); }
	void add_group(Group& group) { groups.push_back(group); }
	void add_teacher(Teacher & teacher) { teachers.push_back(teacher); }
	void add_room(Room & room) { rooms.push_back(room); }
	void add_Sabject(Sabject & sab) { sbj.push_back(sab); }
	Base_group_student_teacher() = default;
	void operator=(Base_group_student_teacher&a) { this->groups = a.groups; this->plans = a.plans; this->teachers = a.teachers; this->rooms = a.rooms; }
	~Base_group_student_teacher() = default;
	std::tuple<std::vector<Plan>, std::vector < Group >, std::vector < Teacher >, std::vector < Room >, std::vector < Sabject > > operator[](int i){
		return make_tuple(plans,groups,teachers,rooms,sbj);
	}


};
class institite
{
	Base_group_student_teacher database;
	Shedle * my_sheld;
public:
	institite();
	~institite();
private:

};

void  generate_BD(Base_group_student_teacher &BD) {
	
	std::string tmp;
	tmp = "WT-22";
	Group g1(22, tmp);
	Plan p1(tmp, 22);
	tmp = "WT-21";
	Group g2(22, tmp);
	Plan p2(tmp, 21);
	p1.Show();
	p2.Show();
	p1.add(tmp = "FZ", 2, 1, 1, 1); p1.add(tmp = "EN", 4, 1, 1, 1); p1.add(tmp = "TI", 5, 1, 1, 1); p1.add(tmp = "SM", 7, 1, 1, 1);
	//Sabject s1(tmp = "FZ", 2, 1, 1, 1), s2(tmp = "EN", 4, 1, 1, 1), s3(tmp = "TI", 5, 1, 1, 1), s4(tmp = "SM", 7, 1, 1, 1);
	p2.add(tmp = "FZ", 2, 1, 1, 1); p2.add(tmp = "EN", 4, 1, 1, 1); p2.add(tmp = "TI", 5, 1, 1, 1); p2.add(tmp = "SM", 7, 1, 1, 1);
	//Sabject s10(tmp = "FZ", 2, 1, 1, 1), s20(tmp = "EN", 4, 1, 1, 1), s30(tmp = "TI", 5, 1, 1, 1), s40(tmp = "SM", 7, 1, 1, 1);
	BD.add_plan(p1);
	BD.add_plan(p2);

	tmp = "DIMA";
	g1.add(tmp);
	tmp = "SANYA";
	g2.add(tmp);
	g1.Show();
	g2.Show();
	BD.add_group(g1);
	BD.add_group(g2);
	Sabject s1(tmp = "FZ", 2), s2(tmp = "EN", 4), s3(tmp = "TI", 5), s4(tmp = "SM", 7);
	BD.add_Sabject(s1);
	BD.add_Sabject(s2);
	BD.add_Sabject(s3);
	BD.add_Sabject(s4);

	Room r1(1, 1), r2(2, 1), r3(3, 1), r4(4, 1);
	BD.add_room(r1);
	BD.add_room(r4);
	BD.add_room(r3);
	BD.add_room(r2);


	//Teacher;
	Teacher t1(tmp="E.N",)
	
}

int main()
{
	Base_group_student_teacher BD;
	generate_BD(BD);
    std::cout << "Hello World!\n" ; 
}
