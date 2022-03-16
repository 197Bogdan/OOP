#pragma once
#include <vector>
#include <string>
class Student
{
public:
	Student(std::string name, int birth_year, int credits_number, double grades_average);
	Student();

	void SetBirthYear(int);
	int GetBirthYear();
	void SetName(std::string);
	std::string GetName();
	void SetCredits(int);
	int GetCredits();
	void SetGradeAvg(double);
	double GetGradeAvg();

	friend std::istream& operator>>(std::istream& i, Student& student);
	friend std::ostream& operator<<(std::ostream& i, Student& student);
	bool operator==(Student& student);
	bool operator!=(Student& student);



private:
	int birth_year;
	std::string name;
	int credits_number;
	double grades_average;
};

class Teacher
{
public:
	Teacher(int birth_year, std::string name, std::string subject, int experience_years);
	Teacher();

	void SetBirthYear(int);
	int GetBirthYear();
	void SetName(std::string);
	std::string GetName();
	void SetSubject(std::string);
	std::string GetSubject();
	void SetExperienceYears(int years);
	int GetExperienceYears();

	friend std::istream& operator>>(std::istream& i, Teacher& teacher);
	friend std::ostream& operator<<(std::ostream& i, Teacher& teacher);
	bool operator==(Teacher& teacher);
	bool operator!=(Teacher& teacher);

private:
	static std::vector<std::string> valid_subjects;
	int birth_year;
	std::string name;
	std::string subject;
	int experience_years;
};


class Group
{
public:
	Group(std::string group_name, std::vector<Student> = {}, std::vector<Teacher> = {});
	Group(Group& group);
	Group();
	~Group();

	void GetStudents(std::vector<Student>& v);
	void SetStudents(std::vector<Student>& v);
	void GetTeachers(std::vector<Teacher>& t);
	void SetTeachers(std::vector<Teacher>& t);
	std::string GetGroupName();
	void SetGroupName(std::string name);
	const int GetStudentCount();
	double GetGradeAvg();
	int GetTeacherCount();


	void AddStudent(Student& student);
	void AddStudents(std::vector<Student>& students);
	void RemoveStudent(Student& student);
	void RemoveStudent(std::string name);
	bool IsStudent(std::string name);
	void AddTeacher(Teacher& teacher);
	void RemoveTeacher(Teacher& teacher);
	void RemoveTeacher(std::string name);
	bool IsTeacher(std::string name);

	friend std::istream& operator>>(std::istream& i, Group& group);
	friend std::ostream& operator<<(std::ostream& i, Group& group);
	Group& operator+(Group& group);
	Group& operator+(Student& student);
	void operator+=(Student& student);
	Group& operator-(Student& student);
	void operator-=(Student& student);
	bool operator==(Group& group);
	bool operator!=(Group& group);

	Group& operator+(Teacher& teacher);
	void operator+=(Teacher& teacher);
	Group& operator-(Teacher& teacher);
	void operator-=(Teacher& teacher);

private:
	std::vector<Student> students;
	std::vector<Teacher> teachers;
	std::string group_name;
	int student_count;
	double average_grade;
};