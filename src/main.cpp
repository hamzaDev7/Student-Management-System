#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// --------------------- STUDENT MODULE ---------------------
struct Student {
    int id;
    string name;
    int age;
    string className;
    string section;
};

void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);
    cout << "Enter ID: "; cin >> s.id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, s.name);
    cout << "Enter Age: "; cin >> s.age;
    cin.ignore();
    cout << "Enter Class: "; getline(cin, s.className);
    cout << "Enter Section: "; getline(cin, s.section);
    file << s.id << " " << s.name << " " << s.age << " " << s.className << " " << s.section << endl;
    file.close();
    cout << "Student Added!\n";
}

void viewStudents() {
    ifstream file("students.txt");
    Student s;
    cout << "ID Name Age Class Section\n";
    while(file >> s.id >> s.name >> s.age >> s.className >> s.section) {
        cout << s.id << " " << s.name << " " << s.age << " " << s.className << " " << s.section << endl;
    }
    file.close();
}

void updateStudent() {
    int id; cout << "Enter ID to update: "; cin >> id;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    Student s;
    bool found = false;
    while(file >> s.id >> s.name >> s.age >> s.className >> s.section) {
        if(s.id == id) {
            found = true;
            cin.ignore();
            cout << "Enter new Name: "; getline(cin, s.name);
            cout << "Enter new Age: "; cin >> s.age;
            cin.ignore();
            cout << "Enter new Class: "; getline(cin, s.className);
            cout << "Enter new Section: "; getline(cin, s.section);
        }
        temp << s.id << " " << s.name << " " << s.age << " " << s.className << " " << s.section << endl;
    }
    file.close(); temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if(found) cout << "Student Updated!\n";
    else cout << "ID Not Found!\n";
}

void deleteStudent() {
    int id; cout << "Enter ID to delete: "; cin >> id;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    Student s;
    bool found = false;
    while(file >> s.id >> s.name >> s.age >> s.className >> s.section) {
        if(s.id != id) temp << s.id << " " << s.name << " " << s.age << " " << s.className << " " << s.section << endl;
        else found = true;
    }
    file.close(); temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if(found) cout << "Student Deleted!\n";
    else cout << "ID Not Found!\n";
}

// --------------------- COURSE MODULE ---------------------
struct Course {
    int courseID;
    string courseName;
    int studentID;
};

void addCourse() {
    Course c;
    ofstream file("courses.txt", ios::app);
    cout << "Enter Course ID: "; cin >> c.courseID;
    cin.ignore();
    cout << "Enter Course Name: "; getline(cin, c.courseName);
    cout << "Enter Student ID: "; cin >> c.studentID;
    file << c.courseID << " " << c.courseName << " " << c.studentID << endl;
    file.close();
    cout << "Course Added!\n";
}

void viewCourses() {
    ifstream file("courses.txt");
    Course c;
    cout << "CourseID CourseName StudentID\n";
    while(file >> c.courseID >> c.courseName >> c.studentID) {
        cout << c.courseID << " " << c.courseName << " " << c.studentID << endl;
    }
    file.close();
}

void updateCourse() {
    int id; cout << "Enter Course ID to update: "; cin >> id;
    ifstream file("courses.txt");
    ofstream temp("temp.txt");
    Course c;
    bool found = false;
    while(file >> c.courseID >> c.courseName >> c.studentID) {
        if(c.courseID == id) {
            found = true;
            cin.ignore();
            cout << "Enter new Course Name: "; getline(cin, c.courseName);
            cout << "Enter new Student ID: "; cin >> c.studentID;
        }
        temp << c.courseID << " " << c.courseName << " " << c.studentID << endl;
    }
    file.close(); temp.close();
    remove("courses.txt");
    rename("temp.txt", "courses.txt");
    if(found) cout << "Course Updated!\n";
    else cout << "ID Not Found!\n";
}

void deleteCourse() {
    int id; cout << "Enter Course ID to delete: "; cin >> id;
    ifstream file("courses.txt");
    ofstream temp("temp.txt");
    Course c;
    bool found = false;
    while(file >> c.courseID >> c.courseName >> c.studentID) {
        if(c.courseID != id) temp << c.courseID << " " << c.courseName << " " << c.studentID << endl;
        else found = true;
    }
    file.close(); temp.close();
    remove("courses.txt");
    rename("temp.txt", "courses.txt");
    if(found) cout << "Course Deleted!\n";
    else cout << "ID Not Found!\n";
}

// --------------------- MARKS MODULE ---------------------
struct Mark {
    int studentID;
    int courseID;
    float marks;
};

void addMark() {
    Mark m;
    ofstream file("marks.txt", ios::app);
    cout << "Enter Student ID: "; cin >> m.studentID;
    cout << "Enter Course ID: "; cin >> m.courseID;
    cout << "Enter Marks: "; cin >> m.marks;
    file << m.studentID << " " << m.courseID << " " << m.marks << endl;
    file.close();
    cout << "Marks Added!\n";
}

void viewMarks() {
    ifstream file("marks.txt");
    Mark m;
    cout << "StudentID CourseID Marks\n";
    while(file >> m.studentID >> m.courseID >> m.marks) {
        cout << m.studentID << " " << m.courseID << " " << m.marks << endl;
    }
    file.close();
}

void updateMark() {
    int studentID, courseID;
    cout << "Enter Student ID: "; cin >> studentID;
    cout << "Enter Course ID: "; cin >> courseID;
    ifstream file("marks.txt");
    ofstream temp("temp.txt");
    Mark m;
    bool found = false;
    while(file >> m.studentID >> m.courseID >> m.marks) {
        if(m.studentID == studentID && m.courseID == courseID) {
            found = true;
            cout << "Enter new Marks: "; cin >> m.marks;
        }
        temp << m.studentID << " " << m.courseID << " " << m.marks << endl;
    }
    file.close(); temp.close();
    remove("marks.txt");
    rename("temp.txt", "marks.txt");
    if(found) cout << "Marks Updated!\n";
    else cout << "Record Not Found!\n";
}

void deleteMark() {
    int studentID, courseID;
    cout << "Enter Student ID: "; cin >> studentID;
    cout << "Enter Course ID: "; cin >> courseID;
    ifstream file("marks.txt");
    ofstream temp("temp.txt");
    Mark m;
    bool found = false;
    while(file >> m.studentID >> m.courseID >> m.marks) {
        if(m.studentID != studentID || m.courseID != courseID) {
            temp << m.studentID << " " << m.courseID << " " << m.marks << endl;
        } else found = true;
    }
    file.close(); temp.close();
    remove("marks.txt");
    rename("temp.txt", "marks.txt");
    if(found) cout << "Marks Deleted!\n";
    else cout << "Record Not Found!\n";
}

// --------------------- ATTENDANCE MODULE ---------------------
struct Attendance {
    int studentID;
    string date;
    string status; // Present / Absent
};

void addAttendance() {
    Attendance a;
    ofstream file("attendance.txt", ios::app);
    cout << "Enter Student ID: "; cin >> a.studentID;
    cin.ignore();
    cout << "Enter Date (YYYY-MM-DD): "; getline(cin, a.date);
    cout << "Enter Status (Present/Absent): "; getline(cin, a.status);
    file << a.studentID << " " << a.date << " " << a.status << endl;
    file.close();
    cout << "Attendance Added!\n";
}

void viewAttendance() {
    ifstream file("attendance.txt");
    Attendance a;
    cout << "StudentID Date Status\n";
    while(file >> a.studentID >> a.date >> a.status) {
        cout << a.studentID << " " << a.date << " " << a.status << endl;
    }
    file.close();
}

void updateAttendance() {
    int studentID;
    string date;
    cout << "Enter Student ID: "; cin >> studentID;
    cin.ignore();
    cout << "Enter Date to Update (YYYY-MM-DD): "; getline(cin, date);
    ifstream file("attendance.txt");
    ofstream temp("temp.txt");
    Attendance a;
    bool found = false;
    while(file >> a.studentID >> a.date >> a.status) {
        if(a.studentID == studentID && a.date == date) {
            found = true;
            cout << "Enter new Status: "; getline(cin, a.status);
        }
        temp << a.studentID << " " << a.date << " " << a.status << endl;
    }
    file.close(); temp.close();
    remove("attendance.txt");
    rename("temp.txt", "attendance.txt");
    if(found) cout << "Attendance Updated!\n";
    else cout << "Record Not Found!\n";
}

void deleteAttendance() {
    int studentID;
    string date;
    cout << "Enter Student ID: "; cin >> studentID;
    cin.ignore();
    cout << "Enter Date to Delete (YYYY-MM-DD): "; getline(cin, date);
    ifstream file("attendance.txt");
    ofstream temp("temp.txt");
    Attendance a;
    bool found = false;
    while(file >> a.studentID >> a.date >> a.status) {
        if(a.studentID != studentID || a.date != date) temp << a.studentID << " " << a.date << " " << a.status << endl;
        else found = true;
    }
    file.close(); temp.close();
    remove("attendance.txt");
    rename("temp.txt", "attendance.txt");
    if(found) cout << "Attendance Deleted!\n";
    else cout << "Record Not Found!\n";
}

// --------------------- FEES MODULE ---------------------
struct Fee {
    int studentID;
    float amount;
    string status; // Paid / Unpaid
};

void addFee() {
    Fee f;
    ofstream file("fees.txt", ios::app);
    cout << "Enter Student ID: "; cin >> f.studentID;
    cout << "Enter Fee Amount: "; cin >> f.amount;
    cin.ignore();
    cout << "Enter Status (Paid/Unpaid): "; getline(cin, f.status);
    file << f.studentID << " " << f.amount << " " << f.status << endl;
    file.close();
    cout << "Fee Record Added!\n";
}

void viewFees() {
    ifstream file("fees.txt");
    Fee f;
    cout << "StudentID Amount Status\n";
    while(file >> f.studentID >> f.amount >> f.status) {
        cout << f.studentID << " " << f.amount << " " << f.status << endl;
    }
    file.close();
}

void updateFee() {
    int studentID;
    cout << "Enter Student ID to Update: "; cin >> studentID;
    ifstream file("fees.txt");
    ofstream temp("temp.txt");
    Fee f;
    bool found = false;
    while(file >> f.studentID >> f.amount >> f.status) {
        if(f.studentID == studentID) {
            found = true;
            cout << "Enter new Fee Amount: "; cin >> f.amount;
            cin.ignore();
            cout << "Enter new Status (Paid/Unpaid): "; getline(cin, f.status);
        }
        temp << f.studentID << " " << f.amount << " " << f.status << endl;
    }
    file.close(); temp.close();
    remove("fees.txt");
    rename("temp.txt", "fees.txt");
    if(found) cout << "Fee Record Updated!\n";
    else cout << "Student Not Found!\n";
}

void deleteFee() {
    int studentID;
    cout << "Enter Student ID to Delete: "; cin >> studentID;
    ifstream file("fees.txt");
    ofstream temp("temp.txt");
    Fee f;
    bool found = false;
    while(file >> f.studentID >> f.amount >> f.status) {
        if(f.studentID != studentID) temp << f.studentID << " " << f.amount << " " << f.status << endl;
        else found = true;
    }
    file.close(); temp.close();
    remove("fees.txt");
    rename("temp.txt", "fees.txt");
    if(found) cout << "Fee Record Deleted!\n";
    else cout << "Student Not Found!\n";
}

// --------------------- TEACHER MODULE ---------------------
struct Teacher {
    int teacherID;
    string name;
    int courseID;
};

void addTeacher() {
    Teacher t;
    ofstream file("teachers.txt", ios::app);
    cout << "Enter Teacher ID: "; cin >> t.teacherID;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, t.name);
    cout << "Enter Course ID: "; cin >> t.courseID;
    file << t.teacherID << " " << t.name << " " << t.courseID << endl;
    file.close();
    cout << "Teacher Added!\n";
}

void viewTeachers() {
    ifstream file("teachers.txt");
    Teacher t;
    cout << "TeacherID Name CourseID\n";
    while(file >> t.teacherID >> t.name >> t.courseID) {
        cout << t.teacherID << " " << t.name << " " << t.courseID << endl;
    }
    file.close();
}

void updateTeacher() {
    int teacherID;
    cout << "Enter Teacher ID to Update: "; cin >> teacherID;
    ifstream file("teachers.txt");
    ofstream temp("temp.txt");
    Teacher t;
    bool found = false;
    while(file >> t.teacherID >> t.name >> t.courseID) {
        if(t.teacherID == teacherID) {
            found = true;
            cin.ignore();
            cout << "Enter new Name: "; getline(cin, t.name);
            cout << "Enter new Course ID: "; cin >> t.courseID;
        }
        temp << t.teacherID << " " << t.name << " " << t.courseID << endl;
    }
    file.close(); temp.close();
    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");
    if(found) cout << "Teacher Updated!\n";
    else cout << "Teacher Not Found!\n";
}

void deleteTeacher() {
    int teacherID;
    cout << "Enter Teacher ID to Delete: "; cin >> teacherID;
    ifstream file("teachers.txt");
    ofstream temp("temp.txt");
    Teacher t;
    bool found = false;
    while(file >> t.teacherID >> t.name >> t.courseID) {
        if(t.teacherID != teacherID) temp << t.teacherID << " " << t.name << " " << t.courseID << endl;
        else found = true;
    }
    file.close(); temp.close();
    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");
    if(found) cout << "Teacher Deleted!\n";
    else cout << "Teacher Not Found!\n";
}

// --------------------- MAIN MENU ---------------------
int main() {
    int choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Student Module\n2. Course Module\n3. Marks Module\n4. Attendance Module\n5. Fees Module\n6. Teacher Module\n0. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int ch;
                do {
                    cout << "\n--- Student Module ---\n1.Add Student\n2.View Students\n3.Update Student\n4.Delete Student\n0.Back\nChoice: ";
                    cin >> ch;
                    switch(ch) {
                        case 1: addStudent(); break;
                        case 2: viewStudents(); break;
                        case 3: updateStudent(); break;
                        case 4: deleteStudent(); break;
                    }
                } while(ch != 0);
                break;
            }
            case 2: {
                int ch;
                do {
                    cout << "\n--- Course Module ---\n1.Add Course\n2.View Courses\n3.Update Course\n4.Delete Course\n0.Back\nChoice: ";
                    cin >> ch;
                    switch(ch) {
                        case 1: addCourse(); break;
                        case 2: viewCourses(); break;
                        case 3: updateCourse(); break;
                        case 4: deleteCourse(); break;
                    }
                } while(ch != 0);
                break;
            }
            case 3: {
                int ch;
                do {
                    cout << "\n--- Marks Module ---\n1.Add Marks\n2.View Marks\n3.Update Marks\n4.Delete Marks\n0.Back\nChoice: ";
                    cin >> ch;
                    switch(ch) {
                        case 1: addMark(); break;
                        case 2: viewMarks(); break;
                        case 3: updateMark(); break;
                        case 4: deleteMark(); break;
                    }
                } while(ch != 0);
                break;
            }
            case 4: {
                int ch;
                do {
                    cout << "\n--- Attendance Module ---\n1.Add Attendance\n2.View Attendance\n3.Update Attendance\n4.Delete Attendance\n0.Back\nChoice: ";
                    cin >> ch;
                    switch(ch) {
                        case 1: addAttendance(); break;
                        case 2: viewAttendance(); break;
                        case 3: updateAttendance(); break;
                        case 4: deleteAttendance(); break;
                    }
                } while(ch != 0);
                break;
            }
            case 5: {
                int ch;
                do {
                    cout << "\n--- Fees Module ---\n1.Add Fee\n2.View Fees\n3.Update Fee\n4.Delete Fee\n0.Back\nChoice: ";
                    cin >> ch;
                    switch(ch) {
                        case 1: addFee(); break;
                        case 2: viewFees(); break;
                        case 3: updateFee(); break;
                        case 4: deleteFee(); break;
                    }
                } while(ch != 0);
                break;
            }
            case 6: {
                int ch;
                do {
                    cout << "\n--- Teacher Module ---\n1.Add Teacher\n2.View Teachers\n3.Update Teacher\n4.Delete Teacher\n0.Back\nChoice: ";
                    cin >> ch;
                    switch(ch) {
                        case 1: addTeacher(); break;
                        case 2: viewTeachers(); break;
                        case 3: updateTeacher(); break;
                        case 4: deleteTeacher(); break;
                    }
                } while(ch != 0);
                break;
            }
        }
    } while(choice != 0);

    cout << "Exiting Student Management System. Goodbye!\n";
    return 0;
}