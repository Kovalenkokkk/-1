#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    Student(string name) : name(name) {}
    string GetName() const { return name; }
private:
    string name;
};

class Group {
public:
    Group() : name(""), course(0), startDate(0, 0, 0) {}
    void SetName(string name) { this->name = name; }
    void SetCourse(int course) { this->course = course; }
    void SetStartDate(int day, int month, int year) {
        startDate.day = day;
        startDate.month = month;
        startDate.year = year;
    }
    void AddStudent(const Student& student) {
        students.push_back(student);
    }
    string ToString() const {
        string result = "Група " + name + ", " + to_string(course) + " курс, дата початку навчання " + to_string(startDate.day) + "." + to_string(startDate.month) + "." + to_string(startDate.year);
        return result;
    }
    friend ostream& operator<<(ostream& os, const Group& group) {
        os << group.ToString();
        return os;
    }
private:
    string name;
    int course;
    struct {
        int day;
        int month;
        int year;
    } startDate;
    vector<Student> students;
};

int main() {
    Student s("Alex");
    Group g;
    g.SetName("KND-221");
    g.SetCourse(2);
    g.SetStartDate(1, 9, 2022);
    g.AddStudent(s);
    cout << g << "\n";
    return 0;
}
