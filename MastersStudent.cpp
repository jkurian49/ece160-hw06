#include "MastersStudent.h"
#include <iostream>
#include <iomanip>

// Constructor Implementations
MastersStudent::MastersStudent(Student ug, int msy):
    Student(ug), _ms_grad_year(msy) {}
  
MastersStudent::MastersStudent(std::string fn, std::string ln,
    int ugy, int msy, Major m):
    Student(fn, ln, ugy, m), _ms_grad_year(msy) {}

// New methods specific to MastersStudent
float MastersStudent::getMsGpa() {
  	float sum = 0;
	for (int i = 0; i <_ms_grades.size();i++) {
		sum = _ms_grades[i] + sum;
	}
	return sum / _ms_grades.size();
}

void MastersStudent::addMsGrade(float grade) {
   _ms_grades.push_back(grade);
	return;
}

// Override Student's printInfo to include new fields
void MastersStudent::printInfo() {
  Student::printInfo(); {
	std::cout << "MS " << majorString(_major) << ": " << _ms_grad_year << std::endl;
	std::cout << "MS GPA: " << std::fixed << std::setprecision(2) << getMsGpa() << std::endl;
  }
}
