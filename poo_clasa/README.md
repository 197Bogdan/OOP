Sunt implementate 3 clase: Group, Student, Teacher.
O grupa este formata din studenti si profesori, fiind folosita compunerea.

Functionalitati:
Constructor cu/fara parametri si de copiere pentru Group
Constructor cu/fara parametri pentru Teacher si Student
Destructor pentru Group

Setteri/Getteri pentru toate atributele tuturor claselor

Overload al operatorilor de citire/afisare pentru toate clasele
Overload al operatorilor de scadere/adunare (inclusiv cele compuse) pentru Group atat in relatie cu Group cat si cu Student/Teacher
Overload al operatorilor relationali pentru toate clasele

Metode specifice clasei Group:
AddStudent, AddTeacher adauga student/profesor in grupa
AddStudents adauga mai multi studenti (argumentul fiind un vector de studenti) in grupa
RemoveStudent, RemoveTeacher elimina un student/profesor din grupa. 
(Poate primi ca parametru atat un obiect de tip student/teacher, cat si atributul "name" al obiectului care va fi eliminat)
IsStudent, IsTeacher verifica apartenenta unui student/profesor la grupa

Media generala a unei grupe este recalculata automat de fiecare data cand sunt adaugati/eliminati studenti.

Sunt implementate 2 fluxuri de testare care prezinta metodele implementate.

Exemplu input, scris de asemenea in codul sursa sub forma de comentarii:
Flux 1:
dan 1997 5.5 20
denis 1998 7.25 40
max 1996 8.1 45
Jim 1944 Mate 20
James 1945 Info 25

Flux 2:
134A 
3 
marius 1999 7.5 20 
alex 2001 8.1 54 
paul 2000 9 60
2
Dumitran 1981 Info 7
Teius 1976 Mate 12
