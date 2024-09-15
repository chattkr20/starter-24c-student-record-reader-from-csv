#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Student ReadStudentRecFromStream(std::istream& ifs) {
  if (ifs.good()) {
    std::string first_name;
    std::string last_name;
    unsigned int uin = 0;
    double gpa = 0.0;

    char throw_away = '\0';

    Student error = Student{};

    ifs >> first_name;
    if (ifs.fail()) {
      return error;
    }

    ifs >> last_name;
    // if (last_name.at(last_name.size() - 1) != ',' || ifs.fail()) {
    //   return error;
    // }

    ifs >> uin >> throw_away;
    if (throw_away != ',' || ifs.fail()) {
      return error;
    }

    ifs >> gpa;
    if (ifs.fail()) {
      return error;
    }

    // std::cout << first_name << " --- " << last_name << " ---- \n";

    return Student{first_name + " " + last_name, uin, gpa};
  }

  return Student{};
}