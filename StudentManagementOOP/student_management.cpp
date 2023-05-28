#include "student_management.hpp"

void StudentManagement::ClearConsole() const
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void Student::setRoll(int& _roll)
{
	rollNo = _roll;
}
void Student::setAge(int& _age)
{
	age = _age;
}
void Student::setName(std::string& _name)
{
	name = _name;
}
void Student::setSurName(std::string& _surName)
{
	surName = _surName;
}

int	 Student::getRoll() const
{
	return rollNo;
}

int Student::getAge() const
{
	return age;
}
std::string Student::getName() const
{
	return name;
}
std::string Student::getSurName() const
{
	return surName;
}

bool StudentManagement::StudentControl()
{
	if (students.empty())
	{
		std::cout << "\t\t Student Not Found\n";
		return false;
	}
	return true;
}

void StudentManagement::Menu()
{
	int choice = 0;
	while (choice != EXIT)
	{
		std::cout << "\t\t----------------------------------------" << std::endl;
		std::cout << "\t\t	STUDENT MANAGEMENT MENU" << std::endl;
		std::cout << "\t\t----------------------------------------" << std::endl;
		std::cout << "\t\t1)Add New Student" << std::endl;
		std::cout << "\t\t2)Display All Student" << std::endl;
		std::cout << "\t\t3)Search Student" << std::endl;
		std::cout << "\t\t4)Update Student" << std::endl;
		std::cout << "\t\t5)Delete Student" << std::endl;
		std::cout << "\t\t6)Exit\n" << std::endl;
		std::cout << "\t\tEnter Your Choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case ADD:
			ClearConsole();
			AddStudent();
			break;
		case DISPLAY:
			ClearConsole();
			DisplayAllStudent();
			break;
		case SEARCH:
			ClearConsole();
			SearchStudent();
			break;
		case UPDATE:
			ClearConsole();
			UpdateStudent();
			break;
		case DELETE:
			ClearConsole();
			DeleteStudent();
			break;
		case EXIT:
			ClearConsole();
			std::cout << "\nExit Successfully";
			break;
		default:
			std::cout << "\t\t Invalid Input";
			break;
		}
	}

}

void StudentManagement::AddStudent()
{

	int _rollNo = 0, _age = 0;
	std::string _name, _surName;

	std::cout << "\n\nEnter User Name: ";
	std::cin >> _name;
	std::cout << "\n\nEnter SurName: ";
	std::cin >> _surName;
	std::cout << "\n\nEnter RollNo: ";
	std::cin >> _rollNo;
	std::cout << "\n\nEnter Age: ";
	std::cin >> _age;

	Student newStudent(_rollNo, _age, _name, _surName);

	students.push_back(newStudent);

	std::cout << "\t\tStudent Successfully Added\n";

}

bool StudentManagement::DisplayAllStudent()
{
	if (!StudentControl())
	{
		return false;
	}
	std::cout << "\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t	STUDENT INFORMATION\n\n";
	std::cout << "\t\t----------------------------------------" << std::endl;
	for (const auto& student : students)
	{
		std::cout << "\t\tStudent Name: " << student.getName() << std::endl;
		std::cout << "\t\tStudent SurName: " << student.getSurName() << std::endl;
		std::cout << "\t\tStudent Age: " << student.getAge() << std::endl;
		std::cout << "\t\tStudent RollNo: " << student.getRoll() << std::endl;
	}
	return true;
}

bool StudentManagement::SearchStudent()
{
	if (!StudentControl())
	{
		return false;
	}

	int _rollNo = 0;
	std::cout << "\n\n\tEnter Search Student RollNo: ";
	std::cin >> _rollNo;

	for (const auto& student : students)
	{
		if (student.getRoll() == _rollNo)
		{
			std::cout << "\t\t---------------------------" << std::endl;
			std::cout << "\t\t	USER FOUND\n\n";
			std::cout << "\t\t---------------------------" << std::endl;
			std::cout << "\t\tStudent Name: " << student.getName() << std::endl;
			std::cout << "\t\tStudent SurName: " << student.getSurName() << std::endl;
			std::cout << "\t\tStudent Age: " << student.getAge() << std::endl;
			std::cout << "\t\tStudent RollNo: " << student.getRoll() << std::endl;
			return  true;
		}
	}
	std::cout << "\t\RollNo Not Found\n";

	return false;
}

bool StudentManagement::UpdateStudent()
{

	if (!StudentControl())
	{
		return false;
	}

	int _rollNo = 0;
	std::cout << "\n\n\tEnter Update Student RollNo: ";
	std::cin >> _rollNo;

	for (auto& student : students)
	{
		if (student.getRoll() == _rollNo)
		{
			std::string newName, newSurName;
			int newAge;


			std::cout << "\n\n\tEnter New Student Name: ";
			std::cin >> newName;
			std::cout << "\n\n\tEnter New Student SurName: ";
			std::cin >> newSurName;
			std::cout << "\n\n\tEnter New Student Age: ";
			std::cin >> newAge;

			student.setName(newName);
			student.setSurName(newSurName);
			student.setAge(newAge);

			std::cout << "\t\tStudent Updated Successfully\n";
			return true;
		}
	}
	std::cout << "\t\tInvalid RollNo\n";
	return false;

}

bool StudentManagement::DeleteStudent()
{

	if (!StudentControl())
	{
		return false;
	}

	int _rollNo = 0;
	std::cout << "\n\n\tEnter Search Student RollNo: ";
	std::cin >> _rollNo;

	for (auto it = students.begin(); it != students.end(); ++it)
	{
		if (it->getRoll() == _rollNo)
		{
			std::cout << "\t\t DELETED STUDENT\n";
			students.erase(it);
			return true;
		}
	}
	std::cout << "\t\tNo Student Found to be Deleted\n";
	return false;
}


