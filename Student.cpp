#include "Student.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>

Student::Student(std::string fn, std::string ln, int y, Major m)
  : _first_name(fn), _last_name(ln), _grad_year(y), _major(m) {}

Student::~Student() {}

float Student::getGpa() {
  float sum = 0;
	for (int i = 0; i <_grades.size();i++) {
		sum = _grades[i] + sum;
	}
	return sum / _grades.size();
}

void Student::addGrade(float grade) {
	_grades.push_back(grade);
	return;
}

std::string Student::majorString(Major m) {
	switch (m) {
		case Major::EE: 
			return "EE";
			break;
		case Major::ME:
			return "ME";
			break;
		case Major::CE:
			return "CE";
			break;
		case Major::CHE:
			return "CHE";
			break;
		case Major::BSE:
			return "BSE";
			break;
		case Major::ART:
			return "ART";
			break;
		case Major::ARCH:
			return "ARCH";
			break;
	}
		
}
const std::string& Student::getLastName() {
  // TODO Fill in real implementation
  return _last_name;
}

void Student::printInfo() {
 	std::cout << _last_name << ", " << _first_name << std::endl;
	std::cout << majorString(_major) <<" " <<_grad_year << std::endl;
	std::cout << "GPA: " << std::fixed << std::setprecision(2) << getGpa() << std::endl;
  	
}
