#include <iostream>
#include <vector>
#include <string>
#include "group.h"

using namespace std;

void FluxTestare1()
{
	Student s1, s2, s3, s4;
	Teacher t1, t2;
	string nume = "134";
	Group g(nume);	// cream o grupa goala, doar pe baza numelui

	cin >> s1;		// dan 1997 5.5 20
	cout << s1;		// afisam informatiile studentului
	cout << "--------------------" << endl;

	cin >> s2 >> s3;		// denis 1998 7.25 40		// citim 2 studenti pe o linie
							// max 1996 8.1 45
	cout << "--------------------" << endl;

	cin >> t1;		// Jim 1944 Mate 20
	cout << t1;		// afisam informatiile profesorului
	cout << "--------------------" << endl;

	cin >> t2;		// James 1945 Info 25
	cout << "--------------------" << endl;

	g.AddStudent(s1);	// adaugam un student
	g.AddTeacher(t1);	// adaugam un profesor
	vector<Student> studenti = { s2, s3 };
	g.AddStudents(studenti);	// adaugam un vector de studenti
	g = g + t2;	// adaugam un profesor folosind +
	cout << g;	// afisam infomatiile grupei
	cout << "--------------------" << endl;
	system("pause");	// press any key to continue
	cout << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;

	g.RemoveStudent(s2);		// eliminam un student pe baza obiectului
	g.RemoveTeacher("Jim");		// eliminam un profesor pe baza numelui
	g.RemoveTeacher("Karl");	// incercam sa eliminam un profesor care nu exista
	g -= s1;					// elimiinam un student folosind -=
	cout << "--------------------" << endl;

	s3.SetBirthYear(s1.GetBirthYear());
	s3.SetCredits(s2.GetCredits());			// folosim setter/getter pentru a accesa/modifica atributele studentului
	s3.SetGradeAvg(s1.GetGradeAvg());
	s3.SetName("Daniel");
	if (s3 != s1)		// folosim != si afisam informatiile studentului
		cout << s3 << endl;
	cout << "--------------------" << endl;
	cout << g;		// afisam informatiile grupei
}
void FluxTestare2()
{
	Group g1;
	cin >> g1;	// citim toate informatiile unei grupe
	//	134A 
	//	3 
	//	marius 1999 7.5 20 
	//	alex 2001 8.1 54 
	//	paul 2000 9 60
	// 2
	// Dumitran 1981 Info 7
	// Teius 1976 Mate 12
	cout << "--------------------" << endl;
	g1.SetGroupName("151B"); // redenumim grupa
	Teacher t(1966, "Damian", "Mate", 15);		// cream un profesor folosind constructorul parametrizat
	g1 += t;		// adaugam un profesor la grupa folosind +=
	g1.RemoveStudent("alex");	// eliminam un student dupa nume
	cout << "--------------------" << endl;
	cout << g1; // afisam informatiile despre grupa
	system("pause");	// press any key to continue
	cout << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
	Student s1("Dan", 1997, 30, 5.5), s2("Denis", 2000, 45, 6.1);
	Teacher t1(1967, "Karl", "Mate", 5);
	Group g2("140F", { s1, s2 }, { t1 });	// initializam o grupa folosind constructorul parametrizat

	cout << g1 + g2;		// concatenam studentii si profesorii grupei 2 la grupa 1 si afisam

	system("pause");	// press any key to continue
	Group g3;
	vector<Student> students;
	vector<Teacher> teachers;
	g3.SetGroupName(g1.GetGroupName());			// modificam grupa 3 astfel incat sa devina identica cu grupa 1 folosind get/set
	g1.GetStudents(students);
	g3.SetStudents(students);
	g1.GetTeachers(teachers);
	g3.SetTeachers(teachers);
	if (g1 == g3)
		cout << "Grupele sunt identice." << endl;
	if (g1 != g3)
		cout << "Grupele sunt diferite." << endl;
	Group g4(g3);		// initializare cu operatorul de copiere
	if (g4 == g3)
		cout << "Grupele sunt identice." << endl;

}
int main()
{
	int x;
	cout << "Flux testare (1 sau 2): " << endl;
	cin >> x;
	cout << endl << endl << endl;
	
	if (x == 1)
		FluxTestare1();
	else if (x == 2)
		FluxTestare2();


}
