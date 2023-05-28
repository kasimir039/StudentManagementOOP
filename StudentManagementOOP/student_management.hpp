#pragma once
#include <string>
#include <iostream>
#include <vector>

class Student
{
private:
	int rollNo, age;
	std::string name, surName;
public:
	Student(int studentRollNo, int studentAge, const std::string& studentName, const std::string& studentSurName) :
		rollNo(studentRollNo), age(studentAge), name(studentName), surName(studentSurName) {}

	void setRoll(int& _roll);
	void setAge(int& _age);
	void setName(std::string& _name);
	void setSurName(std::string& _surName);

	int	 getRoll() const;
	int  getAge() const;
	std::string getName() const;
	std::string getSurName() const;


};

class StudentManagement
{
private:
	std::vector<Student> students;
public:
	void Menu();
	void AddStudent();
	bool DisplayAllStudent();
	bool StudentControl();
	bool SearchStudent();
	bool UpdateStudent();
	bool DeleteStudent();
	void ClearConsole() const;

	enum Choices
	{
		ADD = 1,
		DISPLAY,
		SEARCH,
		UPDATE,
		DELETE,
		EXIT
	};

};