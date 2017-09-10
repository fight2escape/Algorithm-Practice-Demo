//
// Created by Shinelon on 2017/9/10.
//

#ifndef LEETCODE_DEMO_STUDENT_H
#define LEETCODE_DEMO_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {

    string name;
    int score;

    bool operator<(const Student &otherStudent) {
        return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
    }

    friend ostream& operator<<(ostream &os, const Student &student) {
        os << "Student:" << student.name << " " << student.score << endl;
        return os;
    }
};

#endif //LEETCODE_DEMO_STUDENT_H
