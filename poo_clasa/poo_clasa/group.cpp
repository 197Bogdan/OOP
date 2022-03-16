#include <iostream>
#include "group.h"
#include <vector>
#include <string>
Teacher::Teacher(int birth_year, std::string name, std::string subject, int experience_years)
{
	this->birth_year = birth_year;
	this->name = name;
	this->subject = subject;
	this->experience_years = experience_years;
}

Teacher::Teacher()
{
	name = "";
	experience_years = 0;
	subject = "";
	birth_year = 0;
}

void Teacher::SetBirthYear(int age)
{
	birth_year = age;
}
int Teacher::GetBirthYear()
{
	return birth_year;
}
void Teacher::SetName(std::string name)
{
	this->name = name;
}
std::string Teacher::GetName()
{
	return name;
}
void Teacher::SetSubject(std::string subject)
{
	this->subject = subject;
}
std::string Teacher::GetSubject()
{
	return subject;
}
void Teacher::SetExperienceYears(int years)
{
	experience_years = years;
}
int Teacher::GetExperienceYears()
{
	return experience_years;
}



std::istream& operator>>(std::istream& in, Teacher& teacher)
{
	std::cout << "Introduceti datele profesorului. Format: <Nume> <An_nastere> <Materie> <ani_experienta>" << std::endl;
	std::string nume, materie;
	int nastere, experienta;
	in >> nume;
	in >> nastere;
	in >> materie;
	in >> experienta;
	teacher.SetName(nume);
	teacher.SetBirthYear(nastere);
	teacher.SetSubject(materie);
	teacher.SetExperienceYears(experienta);

	return in;
}
std::ostream& operator<<(std::ostream& out, Teacher& teacher)
{
	out << teacher.GetName() << ", " << teacher.GetBirthYear() << ", " << teacher.GetSubject() << ", " << teacher.GetExperienceYears() << " ani experienta." << std::endl;
	return out;
}
bool Teacher::operator==(Teacher& teacher)
{
	if (this->name == teacher.name and this->experience_years == teacher.experience_years and this->subject == teacher.subject)
		return true;
	return false;
}
bool Teacher::operator!=(Teacher& teacher)
{
	return !(*this == teacher);
}


//////////////////////////

Student::Student(std::string name, int birth_year, int credits_number, double grades_average)
{
	this->name = name;
	this->birth_year = birth_year;
	this->credits_number = credits_number;
	this->grades_average = grades_average;
}

Student::Student()
{
	name = "";
	birth_year = 0;
	credits_number = 0;
	grades_average = 0;
}

void Student::SetBirthYear(int year)
{
	birth_year = year;
}
int Student::GetBirthYear()
{
	return birth_year;
}
void Student::SetName(std::string name)
{
	this->name = name;
}
std::string Student::GetName()
{
	return name;
}
void Student::SetCredits(int c)
{
	credits_number = c;
}
int Student::GetCredits()
{
	return credits_number;
}
void Student::SetGradeAvg(double g)
{
	grades_average = g;
}
double Student::GetGradeAvg()
{
	return grades_average;
}

std::istream& operator>>(std::istream& in, Student& student)
{
	std::cout << "Introduceti datele studentului. Format: <Nume> <An_nastere> <Medie> <Credite>" << std::endl;
	std::string nume;
	double medie;
	int credite, an;
	in >> nume;
	in >> an;
	in >> medie;
	in >> credite;
	student.SetName(nume);
	student.SetBirthYear(an);
	student.SetGradeAvg(medie);
	student.SetCredits(credite);

	return in;
}
std::ostream& operator<<(std::ostream& out, Student& student)
{
	out << student.GetName() << ", " << student.GetBirthYear() << ", " << student.GetGradeAvg() << ", " << student.GetCredits() << " credite." << std::endl;
	return out;
}
bool Student::operator==(Student& student)
{
	if (this->name == student.name and this->birth_year == student.birth_year and this->credits_number == student.credits_number and this->grades_average == student.grades_average)
		return true;
	return false;
}
bool Student::operator!=(Student& student)
{
	return !(*this == student);
}




Group::Group(std::string group_name, std::vector<Student> students, std::vector<Teacher> teachers)
{
	this->group_name = group_name;
	student_count = students.size();
	this->students = students;
	double suma_note = 0;
	if (students.size() > 0)
	{
		for (Student student : students)
			suma_note += student.GetGradeAvg();
		average_grade = suma_note / student_count;
	}
	else average_grade = 0;
	this->teachers = teachers;
}

Group::Group(Group& group)
{
	group_name = group.group_name;
	student_count = group.student_count;
	students = group.students;
	teachers = group.teachers;
	average_grade = group.average_grade;
}

Group::Group()
{
	group_name = "";
	student_count = 0;
	students = {};
	teachers = {};
	average_grade = 0;
}

Group::~Group()
{
	students.empty();
	teachers.empty();
	average_grade = 0;
	student_count = 0;
}


void Group::GetStudents(std::vector<Student>& v)
{
	v = students;
}
void Group::SetStudents(std::vector<Student>& v)
{
	students = v;
	student_count = students.size();
	double suma = 0;
	if (student_count > 0)
	{
		for (Student s : v)
			suma += s.GetGradeAvg();
		average_grade = suma / student_count;;
	}
	else average_grade = 0;

}
void Group::GetTeachers(std::vector<Teacher>& t)
{
	t = teachers;
}
void Group::SetTeachers(std::vector<Teacher>& t)
{
	teachers = t;
}
std::string Group::GetGroupName()
{
	return group_name;
}
void Group::SetGroupName(std::string name)
{
	group_name = name;
}
const int Group::GetStudentCount()
{
	return student_count;
}
double Group::GetGradeAvg()
{
	return average_grade;
}
int Group::GetTeacherCount()
{
	return teachers.size();
}



void Group::AddStudent(Student& student)
{
	if (student.GetName() == "")
		return;
	students.push_back(student);
	average_grade = (average_grade * student_count + student.GetGradeAvg()) / (student_count + 1);
	student_count++;
	std::cout << "Studentul a fost adaugat." << std::endl;
}

void Group::AddStudents(std::vector<Student>& students)
{
	this->students.insert(this->students.end(), students.begin(), students.end());
	double suma = 0;
	for (Student student : students)
		suma += student.GetGradeAvg();
	average_grade = (average_grade * student_count + suma) / (student_count + students.size());
	student_count += students.size();
	std::cout << "Studentii au fost adaugati." << std::endl;

}

void Group::RemoveStudent(Student& student)
{
	for (unsigned int i = 0; i < students.size(); i++)
		if (students[i] == student)
		{
			if (student_count > 1)
				average_grade = (average_grade * student_count - student.GetGradeAvg()) / (student_count - 1);
			else average_grade = 0;
			students.erase(students.begin() + i);
			student_count--;
			std::cout << "Studentul a fost eliminat." << std::endl;
			return;
		}
	std::cout << "Studentul nu face parte din grupa." << std::endl;

}

void Group::RemoveStudent(std::string name)
{
	for (unsigned int i = 0; i < students.size(); i++)
		if (students[i].GetName() == name)
		{
			if (student_count > 1)
				average_grade = (average_grade * student_count - students[i].GetGradeAvg()) / (student_count - 1);
			else average_grade = 0;
			students.erase(students.begin() + i);
			student_count--;
			std::cout << "Studentul a fost eliminat." << std::endl;
			return;
		}
	std::cout << "Studentul nu face parte din grupa." << std::endl;
}

bool Group::IsStudent(std::string name)
{
	for (Student student : students)
		if (student.GetName() == name)
			return true;
	return false;
}
void Group::AddTeacher(Teacher& teacher)
{
	if (teacher.GetName() == "")
		return;
	teachers.push_back(teacher);
	std::cout << "Profesorul a fost adaugat." << std::endl;
}
void Group::RemoveTeacher(std::string name)
{
	for (unsigned int i = 0; i < teachers.size(); i++)
		if (teachers[i].GetName() == name)
		{
			teachers.erase(teachers.begin() + i);
			std::cout << "Profesorul a fost eliminat." << std::endl;
			return;
		}
	std::cout << "Profesorul nu face parte din grupa." << std::endl;
}

void Group::RemoveTeacher(Teacher& teacher)
{
	for (unsigned int i = 0; i < teachers.size(); i++)
		if (teachers[i] == teacher)
		{
			teachers.erase(teachers.begin() + i);
			std::cout << "Profesorul a fost eliminat." << std::endl;
			return;
		}
	std::cout << "Profesorul nu face parte din grupa." << std::endl;
}
bool Group::IsTeacher(std::string name)
{
	for (Teacher teacher : teachers)
		if (teacher.GetName() == name)
			return true;
	return false;
}

std::istream& operator>>(std::istream& in, Group& group)
{
	std::string nume;
	int numar;
	std::cout << "Numele grupei: ";
	in >> nume;
	group.SetGroupName(nume);
	std::cout << "Numarul de studenti: ";
	in >> numar;
	std::cout << "Introduceti " << numar << " linii. Format linie: <Nume> <An_nastere> <Credite> <Medie>" << std::endl;
	for (int i = 0; i < numar; i++)
	{
		Student student;
		std::cin >> student;
		group.AddStudent(student);
	}
	std::cout << "Numarul de profesori: ";
	in >> numar;
	for (int i = 0; i < numar; i++)
	{
		std::string nume_profesor, materie;
		int an;
		int ani_experienta;
		in >> nume;
		in >> an;
		in >> materie;
		in >> ani_experienta;
		Teacher teacher(an, nume, materie, ani_experienta);
		group.AddTeacher(teacher);
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, Group& group)
{
	out << "Numele grupei: " << group.GetGroupName() << std::endl;
	out << "Media grupei: " << group.GetGradeAvg() << std::endl << std::endl;
	out << "Numarul de studenti: " << group.GetStudentCount() << std::endl;
	std::vector<Student> students;
	group.GetStudents(students);
	for (Student student : students)
		out << student;
	out << std::endl;
	out << "Numarul de profesori: " << group.GetTeacherCount() << std::endl;

	std::vector<Teacher> teachers;
	group.GetTeachers(teachers);
	for (Teacher teacher : teachers)
		out << teacher;
	return out;
}

Group& Group::operator+(Group& group)
{
	average_grade = (average_grade * student_count + group.GetGradeAvg() * group.GetStudentCount()) / (student_count + group.GetStudentCount());
	student_count += group.student_count;
	students.insert(students.end(), group.students.begin(), group.students.end());
	teachers.insert(teachers.end(), group.teachers.begin(), group.teachers.end());

	return *this;
}
Group& Group::operator+(Student& student)
{
	AddStudent(student);

	return *this;
}
void Group::operator+=(Student& student)
{
	AddStudent(student);
}
Group& Group::operator-(Student& student)
{
	if (IsStudent(student.GetName()))
	{
		RemoveStudent(student);
		return *this;
	}
	else std::cout << "Studentul nu e parte din grupa." << std::endl;
	return *this;
}
void Group::operator-=(Student& student)
{
	if (IsStudent(student.GetName()))
		RemoveStudent(student);
	else std::cout << "Studentul nu e parte din grupa." << std::endl;
}

Group& Group::operator+(Teacher& teacher)
{
	AddTeacher(teacher);
	return *this;
}
void Group::operator+=(Teacher& teacher)
{
	AddTeacher(teacher);
}

Group& Group::operator-(Teacher& teacher)
{
	RemoveTeacher(teacher);
	return *this;
}
void Group::operator-=(Teacher& teacher)
{
	RemoveTeacher(teacher);
}
bool Group::operator==(Group& group)
{
	if (this->group_name == group.group_name && this->average_grade == group.average_grade
		&& this->student_count == group.student_count)
	{
		for (int i = 0; i < student_count; i++)
			if (!(this->students[i] == group.students[i]))
				return false;
		for (unsigned int i = 0; i < teachers.size(); i++)
			if (!(this->teachers[i] == group.teachers[i]))
				return false;
		return true;
	}


	return false;

}
bool Group::operator!=(Group& group)
{
	return !(*this == group);
}

//////////////////////////////////
