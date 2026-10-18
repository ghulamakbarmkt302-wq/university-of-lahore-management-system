#include <iostream>
#include <string>
using namespace std;
class person
{
public:
   string name;
   int age;
   person()
   {
      name = "";
      age = 0;
   }
   person(string n, int a)
   {
      name = n;
      age = a;
   }
};
class Qualification
{
public:
   string degree;
   int experience;

   Qualification()
   {
      degree = "";
      experience = 0;
   }
   Qualification(string deg, int expr)
   {
      degree = deg;
      experience = expr;
   }
};
class Teacher : public person
{
public:
   Qualification qual;
   Teacher()
   {
   }
   Teacher(string n, int a, string deg, int expr) : person(n, a), qual(deg, expr)
   {
   }
   void display()
   {
      cout << "Name: " << name << ", Age: " << age << endl;
      cout << "Degree: " << qual.degree << ", Years of Experience: " << qual.experience << endl;
   
   }
   };

   class Student : public person
   {
   public:
      int studentID;
      Student()
      {
         studentID = 0;
      }

      Student(string n, int a, int stid) : person(n, a), studentID(stid)
      {
      }
      void stddisplay()
      {
         cout << "Student ID: " << studentID << ", Name: " << name << ", Age: " << age << endl;
      }
   };
   class Course
   {
   public:
      string coursename;
      int coursecode;
      Course()
      {
         coursename = "";
         coursecode = 0;
      }

      Course(string crName, int crCOde)
      {
         coursename = crName;
         coursecode = crCOde;
      }
      void coursedisplay()
      {
         cout << "Course: " << coursename << ", Code: " << coursecode << endl;
      }
   };

   class Department
   {

      string name;
      int choice;
      Student students[10];
      Teacher teachers[10];
      Course courses[10];

      int tchrcount = 0;
      int stdcount = 0;
      int crsecount = 0;

   public:
      Department() {}
      Department(string nm)
      {
         name = nm;
      }

      string n, d;
      int a, e;
      int id;
      string cn;
      int cc;

      void addTeacher()
      {
         if (tchrcount < 10)
         {
            cout << "Enter details for teacher #" << tchrcount + 1 << ":" << endl;
            cout << "Enter name: ";
            getline(cin, n);

            cout << "Enter age: ";
            cin >> a;

            cin.ignore();
            cout << "Enter degree: ";
            getline(cin, d);

            cout << "Enter years of experience: ";
            cin >> e;
            cin.ignore();

            teachers[tchrcount] = Teacher(n, a, d, e);
            tchrcount++;
            cout << "Teacher added successfully!" << endl;
         }
         else
         {
            cout << " Max Limit reached !!" << endl;
         }
      }

      void addStudent()
      {
         if (stdcount < 10)
         {
         cout << "Enter details for student #" << stdcount + 1 << ":" << endl;
            cout << "Enter name: ";
            getline(cin, n);

          cout << "Enter age: ";
            cin >> a;

            cin.ignore();

            cout << "Enter student ID: ";
            cin >> id;
            cin.ignore();

            for (int i = 0; i < stdcount; i++)
            {
               if (students[i].studentID == id)
               {
                  cout << "This student ID already exists!" << endl;
                  return;
               }
            }

            students[stdcount] = Student(n, a, id);
            stdcount++;
            cout << "Student added successfully!" << endl;
         }

         else
         {
            cout << " Max Limit reached !!" << endl;
         }
      }

      void addCourse()
      {
         if (crsecount < 10)
         {
           cout << "Enter details for course #" << crsecount + 1 << ":" << endl;
            cout << "Enter course name: ";
            getline(cin, cn);

            cout << "Enter course code: ";
            cin >> cc;
            cin.ignore();
            courses[crsecount] = Course(cn, cc);
            crsecount++;
            cout << "Course added successfully!" << endl;
         }
         else
         {
            cout << " Max Limit reached !!" << endl;
         }
      }

      void displayTeachers()
      {
         if (tchrcount == 0)
         {
            cout << "No teachers available." << endl;
         }
         else
         {
            cout << "Teachers in " << name << " Department: " << endl;
            for (int i = 0; i < tchrcount; i++)
            {
               cout << "Teacher : " << i + 1 << ":" << endl;
               teachers[i].display();
            }
         }
      }
      void displayStudent()
      {
         if (stdcount == 0)
         {
            cout << "No students available." << endl;
         }
         else
         {
            cout << "Students in " << name << " Department: " << endl;
            for (int i = 0; i < stdcount; i++)
            {
               cout << "Student #" << i + 1 << ":" << endl;
               students[i].stddisplay();
            }
         }
      }
      void displayCourse()
      {
         if (crsecount == 0)
         {
            cout << "No courses available." << endl;
         }
         else
         {
            cout << "Courses in " << name << " Department: " << endl;
            for (int i = 0; i < crsecount; i++)
            {
               cout << "Course #" << i + 1 << ":" << endl;
               courses[i].coursedisplay();
            }
         }
      }
      string getName()
      {
         return name;
      }

      void departmentMenu()
      {
         int choice;
         do
         {
            cout << "--- " << name << " Department Menu ---" << endl;
            cout << "1. Add Teacher" << endl;
            cout << "2. Add Student" << endl;
            cout << "3. Add Course" << endl;
            cout << "4. Display All Teachers" << endl;
            cout << "5. Display All Students" << endl;
            cout << "6. Display All Courses" << endl;
            cout << "0. Go Back" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1)
               addTeacher();
            else if (choice == 2)
               addStudent();
            else if (choice == 3)
               addCourse();
            else if (choice == 4)
               displayTeachers();
            else if (choice == 5)
               displayStudent();
            else if (choice == 6)
               displayCourse();
            else if (choice == 0)
               cout << "Going back to main menu" << endl;
            else
               cout << "Invalid choice!" << endl;
         } while (choice != 0);
      }
   };
   class University
   {
      Department departments[10];
      int deptcount = 0;

   public:
      void addDepartment()
      {
         if (deptcount < 10)
         {
            string dname;
            cout << "Enter department name: ";
            getline(cin, dname);

            for (int i = 0; i < deptcount; i++)
            {
               if (departments[i].getName() == dname)
               {
                  cout << "Department already exists!" << endl;
                  return;
               }
            }

            departments[deptcount] = Department(dname);
            deptcount++;
            cout << "Department added successfully!" << endl;
         }
         else
         {
            cout << " Max Limit reached !!" << endl;
         }
      }

      void showDepartments()
      {
         if (deptcount == 0)
         {
            cout << "No departments available." << endl;
         }
         else
         {
            for (int i = 0; i < deptcount; i++)
            {
               cout << i + 1 << ". " << departments[i].getName() << endl;
            }
         }
      }

      void enterDepartment()
      {
         if (deptcount == 0)
         {
            cout << "No departments available." << endl;
            return;
         }
         showDepartments();
         int num;
         cout << "Enter department number to manage: ";
         cin >> num;
         cin.ignore();
         if (num < 1 || num > deptcount)
         {
            cout << "Invalid department number!" << endl;
            return;
         }
         departments[num - 1].departmentMenu();
      }

      void mainMenu()
      {
         int choice;
         do
         {
            cout << "--- University of Lahore Main Menu ---" << endl;
            cout << "1. Add Department" << endl;
            cout << "2. Show Departments" << endl;
            cout << "3. Enter Department" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1)
               addDepartment();
            else if (choice == 2)
               showDepartments();
            else if (choice == 3)
               enterDepartment();
            else if (choice == 0)
               cout << "Goodbye!" << endl;
            else
               cout << "Invalid choice!" << endl;
         } while (choice != 0);
      }
   };

   int main()
   {
      University uni;
      uni.mainMenu();
      return 0;
   }
